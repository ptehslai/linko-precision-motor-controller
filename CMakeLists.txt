cmake_minimum_required(VERSION 3.20)
project(linko_precision_motor_firmware C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(BUILD_HOST_TEST "Build firmware sources for native host compile test" OFF)
option(LKS_SDK_LINK "Link LKS32MC45x DevDriver SDK" ON)

set(BOARD "hy_gb4212_drv_a4" CACHE STRING "Board profile under boards/")
set(MOTOR_PROFILE "gb4212_18v" CACHE STRING "Motor profile under config/motors/")
set(APP_PROFILE "" CACHE STRING "Optional application profile under config/applications/")

set(BOARD_DIR "${CMAKE_SOURCE_DIR}/boards/${BOARD}")
set(PLATFORM_DIR "${CMAKE_SOURCE_DIR}/platforms/lks32mc454")
set(LKS_SDK_PATH "${CMAKE_SOURCE_DIR}/third_party/lks32mc45x_sdk/LKS32MC45x_DevDriver" CACHE PATH "Path to LKS32MC45x DevDriver root")

if(NOT EXISTS "${BOARD_DIR}/board.yaml")
    message(FATAL_ERROR "Board profile not found: ${BOARD_DIR}")
endif()

file(GLOB BOARD_LINKER "${BOARD_DIR}/linker/*.ld")
file(GLOB BOARD_STARTUP "${BOARD_DIR}/startup/*.S")
if(NOT BOARD_LINKER OR NOT BOARD_STARTUP)
    message(FATAL_ERROR "Board ${BOARD} missing linker script or startup assembly")
endif()
list(GET BOARD_LINKER 0 BOARD_LINKER_SCRIPT)
list(GET BOARD_STARTUP 0 BOARD_STARTUP_FILE)

set(CONFIG_PLATFORM "${CMAKE_SOURCE_DIR}/config/platform.yaml")
set(CONFIG_BOARD "${BOARD_DIR}/board.yaml")
set(CONFIG_MOTOR "${CMAKE_SOURCE_DIR}/config/motors/${MOTOR_PROFILE}.yaml")
set(CONFIG_HEADER "${CMAKE_SOURCE_DIR}/include/config_generated.h")
set(CONFIG_DEFAULTS_SRC "${CMAKE_SOURCE_DIR}/firmware/common/config_defaults.c")
set(GEN_CONFIG_SCRIPT "${CMAKE_SOURCE_DIR}/tools/gen_config.py")

set(CONFIG_GEN_ARGS
    --platform ${CONFIG_PLATFORM}
    --board ${CONFIG_BOARD}
    --motor ${CONFIG_MOTOR}
    --header ${CONFIG_HEADER}
    --source ${CONFIG_DEFAULTS_SRC}
)
set(CONFIG_GEN_DEPS ${GEN_CONFIG_SCRIPT} ${CONFIG_PLATFORM} ${CONFIG_BOARD} ${CONFIG_MOTOR})
if(APP_PROFILE)
    set(CONFIG_APPLICATION "${CMAKE_SOURCE_DIR}/config/applications/${APP_PROFILE}.yaml")
    list(APPEND CONFIG_GEN_ARGS --application ${CONFIG_APPLICATION})
    list(APPEND CONFIG_GEN_DEPS ${CONFIG_APPLICATION})
endif()

find_package(Python3 COMPONENTS Interpreter QUIET)

set(PRE_BUILD_SCRIPT "${CMAKE_SOURCE_DIR}/tools/build/pre_build.sh")
set(POST_BUILD_SCRIPT "${CMAKE_SOURCE_DIR}/tools/build/post_build.sh")

if(Python3_Interpreter_FOUND)
    add_custom_command(
        OUTPUT ${CONFIG_HEADER} ${CONFIG_DEFAULTS_SRC}
        COMMAND ${Python3_EXECUTABLE} ${GEN_CONFIG_SCRIPT} ${CONFIG_GEN_ARGS}
        DEPENDS ${CONFIG_GEN_DEPS}
        COMMENT "Generating config from platform + board + motor profiles"
        VERBATIM
    )
    add_custom_target(generate_config DEPENDS ${CONFIG_HEADER} ${CONFIG_DEFAULTS_SRC})
else()
    message(STATUS "Python3 not found — using committed config_generated.h / config_defaults.c")
    add_custom_target(generate_config)
endif()

set(COMMON_SRCS
    firmware/common/config_defaults.c
    firmware/common/crc16_ccitt.c
    firmware/common/crc32_mpeg2.c
)

set(SYS_SRCS
    firmware/entry.c
    firmware/sys/platform_init_lks.c
    firmware/sys/config_store.c
    firmware/sys/storage_store.c
    firmware/sys/startup_protection.c
    firmware/sys/hardware_probe.c
    firmware/sys/ota_manager.c
)

set(DRIVER_SRCS
    firmware/drivers/hal_lks.c
    firmware/drivers/irq_lks.c
    firmware/drivers/encoder_kth7816.c
    firmware/drivers/can_lks.c
    firmware/drivers/adc_current.c
    firmware/drivers/mcpwm_motor.c
)

set(BSP_SRCS
    firmware/bsp/board.c
)

set(APP_LINKO_PRECISION_MOTOR_SRCS
    firmware/app/linko_precision_motor/main_loop.c
    firmware/app/linko_precision_motor/motor_fsm.c
    firmware/app/linko_precision_motor/fault.c
    firmware/app/linko_precision_motor/protection.c
    firmware/app/linko_precision_motor/commissioning.c
    firmware/app/linko_precision_motor/pid.c
    firmware/app/linko_precision_motor/speed_loop.c
    firmware/app/linko_precision_motor/position_loop.c
    firmware/app/linko_precision_motor/joint_axis.c
    firmware/app/linko_precision_motor/motion_profile.c
    firmware/app/linko_precision_motor/foc.c
    firmware/app/linko_precision_motor/svpwm.c
    firmware/app/linko_precision_motor/trap_commutation.c
    firmware/app/linko_precision_motor/angle_source.c
    firmware/app/linko_precision_motor/hfi.c
    firmware/app/linko_precision_motor/smo.c
    firmware/app/linko_precision_motor/cyphal_can.c
    firmware/app/linko_precision_motor/cyphal_can_recv.c
    firmware/app/linko_precision_motor/cyphal_can_send.c
    firmware/app/linko_precision_motor/huayi_services.c
    firmware/app/linko_precision_motor/motor_status.c
)

set(FW_SOURCES
    ${COMMON_SRCS}
    ${SYS_SRCS}
    ${DRIVER_SRCS}
    ${BSP_SRCS}
    ${APP_LINKO_PRECISION_MOTOR_SRCS}
    third_party/libcanard/canard.c
    third_party/o1heap/o1heap.c
)

set(FW_INCLUDES
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/firmware
    ${CMAKE_SOURCE_DIR}/firmware/common
    ${CMAKE_SOURCE_DIR}/firmware/sys
    ${CMAKE_SOURCE_DIR}/firmware/drivers
    ${CMAKE_SOURCE_DIR}/firmware/bsp
    ${CMAKE_SOURCE_DIR}/firmware/app/linko_precision_motor
    ${BOARD_DIR}/include
    ${CMAKE_SOURCE_DIR}/third_party/libcanard
    ${CMAKE_SOURCE_DIR}/third_party/o1heap
)

if(BUILD_HOST_TEST)
    add_executable(firmware_host ${FW_SOURCES})
    target_include_directories(firmware_host PRIVATE ${FW_INCLUDES})
    target_compile_definitions(firmware_host PRIVATE BUILD_HOST_TEST=1)
    add_dependencies(firmware_host generate_config)
else()
    if(NOT CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arm-gcc.cmake CACHE FILEPATH "" FORCE)
    endif()

    add_executable(firmware ${FW_SOURCES} ${BOARD_STARTUP_FILE})
    target_include_directories(firmware PRIVATE ${FW_INCLUDES})
    target_compile_definitions(firmware PRIVATE
        LKS32MC454
        USE_FULL_ASSERT=0
        BOARD_HSE_MHZ=12
    )
    if(LKS_SDK_LINK)
        include(${CMAKE_SOURCE_DIR}/cmake/LksSdk.cmake)
        target_link_lks_sdk(firmware)
    endif()
    target_link_options(firmware PRIVATE
        -T${BOARD_LINKER_SCRIPT}
        -Wl,-Map=$<TARGET_FILE_DIR:firmware>/firmware.map
    )
    add_dependencies(firmware generate_config)

    if(EXISTS ${PRE_BUILD_SCRIPT})
        add_custom_target(pre_build
            COMMAND bash ${PRE_BUILD_SCRIPT}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Running pre-build generation"
        )
        add_dependencies(firmware pre_build)
    endif()

    add_custom_target(firmware_hex
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:firmware> $<TARGET_FILE_DIR:firmware>/firmware.hex
        DEPENDS firmware
        COMMENT "Generating firmware.hex"
    )
    add_custom_target(firmware_bin
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:firmware> $<TARGET_FILE_DIR:firmware>/firmware.bin
        DEPENDS firmware
        COMMENT "Generating firmware.bin"
    )
    if(EXISTS ${POST_BUILD_SCRIPT})
        add_custom_target(factory_image
            COMMAND bash ${POST_BUILD_SCRIPT}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            DEPENDS firmware_bin
            COMMENT "Generating factory image artifacts"
        )
    endif()
    add_executable(bootloader bootloader/src/boot_main.c)
    target_compile_definitions(bootloader PRIVATE LKS32MC454)
    target_link_options(bootloader PRIVATE
        -T${BOARD_LINKER_SCRIPT}
        -Wl,-Map=$<TARGET_FILE_DIR:bootloader>/bootloader.map
    )
    add_custom_target(flash
        COMMAND pyocd flash -t lks32mc454 $<TARGET_FILE:firmware>
        DEPENDS firmware
        COMMENT "Flash firmware via pyOCD (SWD)"
    )
endif()

message(STATUS "Board profile: ${BOARD}")
message(STATUS "Motor profile: ${MOTOR_PROFILE}")
if(APP_PROFILE)
    message(STATUS "Application profile: ${APP_PROFILE}")
endif()
