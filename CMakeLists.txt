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

file(GLOB BOARD_LINKER "${BOARD_DIR}/linker/app_slot.ld")
file(GLOB BOARD_BOOT_LINKER "${CMAKE_SOURCE_DIR}/bootloader/linker/bootloader.ld")
file(GLOB BOARD_STARTUP "${BOARD_DIR}/startup/*.S")
if(NOT BOARD_LINKER OR NOT BOARD_BOOT_LINKER OR NOT BOARD_STARTUP)
    message(FATAL_ERROR "Board ${BOARD} missing app_slot.ld, bootloader.ld, or startup assembly")
endif()
list(GET BOARD_LINKER 0 BOARD_LINKER_SCRIPT)
list(GET BOARD_BOOT_LINKER 0 BOARD_BOOT_LINKER_SCRIPT)
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

set(PRE_BUILD_SCRIPT_SH "${CMAKE_SOURCE_DIR}/tools/build/pre_build.sh")
set(PRE_BUILD_SCRIPT_PS "${CMAKE_SOURCE_DIR}/tools/build/pre_build.ps1")
set(POST_BUILD_SCRIPT_SH "${CMAKE_SOURCE_DIR}/tools/build/post_build.sh")
set(POST_BUILD_SCRIPT_PS "${CMAKE_SOURCE_DIR}/tools/build/post_build.ps1")
set(FACTORY_IMAGE "${CMAKE_SOURCE_DIR}/dist/linko_precision_motor_factory_v0.1.0_hw_hy_gb4212.bin")

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
    firmware/sys/sys_diag.c
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
    firmware/app/linko_precision_motor/runtime/main_loop.c
    firmware/app/linko_precision_motor/runtime/motor_fsm.c
    firmware/app/linko_precision_motor/runtime/fault.c
    firmware/app/linko_precision_motor/runtime/protection.c
    firmware/app/linko_precision_motor/runtime/commissioning.c
    firmware/app/linko_precision_motor/control/pid.c
    firmware/app/linko_precision_motor/control/speed_loop.c
    firmware/app/linko_precision_motor/control/position_loop.c
    firmware/app/linko_precision_motor/control/joint_axis.c
    firmware/app/linko_precision_motor/control/motion_profile.c
    firmware/app/linko_precision_motor/motor/foc.c
    firmware/app/linko_precision_motor/motor/svpwm.c
    firmware/app/linko_precision_motor/motor/trap_commutation.c
    firmware/app/linko_precision_motor/motor/angle_source.c
    firmware/app/linko_precision_motor/motor/observer/hfi.c
    firmware/app/linko_precision_motor/motor/observer/smo.c
    firmware/app/linko_precision_motor/comm/cyphal_can.c
    firmware/app/linko_precision_motor/comm/cyphal_can_recv.c
    firmware/app/linko_precision_motor/comm/cyphal_can_send.c
    firmware/app/linko_precision_motor/comm/huayi_services.c
    firmware/app/linko_precision_motor/comm/motor_status.c
)

set(BOOTLOADER_SRCS
    bootloader/src/boot_main.c
    bootloader/src/boot_jump.c
    bootloader/src/boot_ota.c
    firmware/common/crc32_mpeg2.c
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
    ${CMAKE_SOURCE_DIR}/firmware/app/linko_precision_motor/runtime
    ${CMAKE_SOURCE_DIR}/firmware/app/linko_precision_motor/control
    ${CMAKE_SOURCE_DIR}/firmware/app/linko_precision_motor/motor
    ${CMAKE_SOURCE_DIR}/firmware/app/linko_precision_motor/motor/observer
    ${CMAKE_SOURCE_DIR}/firmware/app/linko_precision_motor/comm
    ${BOARD_DIR}/include
    ${CMAKE_SOURCE_DIR}/third_party/libcanard
    ${CMAKE_SOURCE_DIR}/third_party/o1heap
)

if(BUILD_HOST_TEST)
    enable_testing()

    set(HOST_TEST_INCLUDES ${FW_INCLUDES})
    set(HOST_TEST_COMMON
        firmware/bsp/board.c
        firmware/drivers/hal_lks.c
        firmware/common/crc32_mpeg2.c
    )

    add_executable(test_startup_protection
        tests/unit/host/test_startup_protection.c
        firmware/sys/startup_protection.c
        firmware/sys/sys_diag.c
        firmware/app/linko_precision_motor/runtime/fault.c
        ${HOST_TEST_COMMON}
    )
    target_include_directories(test_startup_protection PRIVATE ${HOST_TEST_INCLUDES})
    target_compile_definitions(test_startup_protection PRIVATE BUILD_HOST_TEST=1)
    add_dependencies(test_startup_protection generate_config)
    add_test(NAME test_startup_protection COMMAND test_startup_protection)

    add_executable(test_hardware_probe
        tests/unit/host/test_hardware_probe.c
        firmware/sys/hardware_probe.c
        firmware/drivers/encoder_kth7816.c
        ${HOST_TEST_COMMON}
    )
    target_include_directories(test_hardware_probe PRIVATE ${HOST_TEST_INCLUDES})
    target_compile_definitions(test_hardware_probe PRIVATE BUILD_HOST_TEST=1)
    add_dependencies(test_hardware_probe generate_config)
    add_test(NAME test_hardware_probe COMMAND test_hardware_probe)

    add_executable(test_ota_state
        tests/unit/host/test_ota_state.c
        firmware/sys/ota_manager.c
        ${HOST_TEST_COMMON}
    )
    target_include_directories(test_ota_state PRIVATE ${HOST_TEST_INCLUDES})
    target_compile_definitions(test_ota_state PRIVATE BUILD_HOST_TEST=1)
    add_dependencies(test_ota_state generate_config)
    add_test(NAME test_ota_state COMMAND test_ota_state)

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

    if(WIN32 AND EXISTS ${PRE_BUILD_SCRIPT_PS})
        add_custom_target(pre_build
            COMMAND powershell -ExecutionPolicy Bypass -File ${PRE_BUILD_SCRIPT_PS}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Running pre-build generation (PowerShell)"
        )
    elseif(EXISTS ${PRE_BUILD_SCRIPT_SH})
        add_custom_target(pre_build
            COMMAND bash ${PRE_BUILD_SCRIPT_SH}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Running pre-build generation"
        )
    endif()
    if(TARGET pre_build)
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
    add_executable(bootloader ${BOOTLOADER_SRCS} ${BOARD_STARTUP_FILE})
    target_include_directories(bootloader PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/firmware/common
        ${CMAKE_SOURCE_DIR}/bootloader/src
    )
    target_compile_definitions(bootloader PRIVATE LKS32MC454 BUILD_BOOTLOADER=1)
    target_link_options(bootloader PRIVATE
        -T${BOARD_BOOT_LINKER_SCRIPT}
        -Wl,-Map=$<TARGET_FILE_DIR:bootloader>/bootloader.map
    )
    add_dependencies(bootloader generate_config)
    if(TARGET pre_build)
        add_dependencies(bootloader pre_build)
    endif()
    add_custom_target(bootloader_bin
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:bootloader> $<TARGET_FILE_DIR:bootloader>/bootloader.bin
        DEPENDS bootloader
        COMMENT "Generating bootloader.bin"
    )
    if(WIN32 AND EXISTS ${POST_BUILD_SCRIPT_PS})
        add_custom_target(factory_image
            COMMAND powershell -ExecutionPolicy Bypass -File ${POST_BUILD_SCRIPT_PS}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            DEPENDS firmware_bin bootloader_bin
            COMMENT "Generating factory image artifacts (PowerShell)"
        )
    elseif(EXISTS ${POST_BUILD_SCRIPT_SH})
        add_custom_target(factory_image
            COMMAND bash ${POST_BUILD_SCRIPT_SH}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            DEPENDS firmware_bin bootloader_bin
            COMMENT "Generating factory image artifacts"
        )
    endif()
    add_custom_target(flash_app
        COMMAND pyocd flash -t lks32mc454 $<TARGET_FILE:firmware>
        DEPENDS firmware
        COMMENT "Flash application slot image only (development)"
    )
    add_custom_target(flash_factory
        COMMAND pyocd flash -t lks32mc454 --base-address 0x08000000 ${FACTORY_IMAGE}
        DEPENDS factory_image
        COMMENT "Flash merged factory image (bootloader + app slot A)"
    )
    add_custom_target(flash
        DEPENDS flash_factory
        COMMENT "Default flash target uses factory image at 0x08000000"
    )
endif()

message(STATUS "Board profile: ${BOARD}")
message(STATUS "Motor profile: ${MOTOR_PROFILE}")
if(APP_PROFILE)
    message(STATUS "Application profile: ${APP_PROFILE}")
endif()
