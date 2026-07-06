# Link LKS32MC45x DevDriver (legacy source/ API — same as PeripDemo).
# Device headers (lks32mc45x.h, basic.h) come from the Keil pack under device/Include/.

function(target_link_lks_sdk target)
    if(NOT LKS_SDK_PATH OR NOT EXISTS "${LKS_SDK_PATH}")
        message(FATAL_ERROR "LKS_SDK_PATH not found: ${LKS_SDK_PATH}")
    endif()

    set(_device_inc "${CMAKE_SOURCE_DIR}/third_party/lks32mc45x_sdk/device/Include")
    if(NOT EXISTS "${_device_inc}/lks32mc45x.h")
        message(FATAL_ERROR "Missing ${_device_inc}/lks32mc45x.h — run tools/fetch_third_party.ps1 -IncludeLksSdk")
    endif()

    # CMSIS core_cm4.h — try toolchain bundled path, then fall back to project local copy
    set(_cmsis_local "${CMAKE_SOURCE_DIR}/third_party/cmsis")
    execute_process(
        COMMAND ${CMAKE_C_COMPILER} -print-file-name=include/cmsis/core_cm4.h
        OUTPUT_VARIABLE _core_cm4
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
    if(_core_cm4 AND EXISTS "${_core_cm4}")
        get_filename_component(_cmsis_inc "${_core_cm4}" DIRECTORY)
        get_filename_component(_cmsis_inc "${_cmsis_inc}" DIRECTORY)
    elseif(EXISTS "${_cmsis_local}/core_cm4.h")
        set(_cmsis_inc "${_cmsis_local}")
    else()
        set(_cmsis_inc "")
    endif()

    target_include_directories(${target} PRIVATE
        ${_device_inc}
        ${LKS_SDK_PATH}/include
    )
    if(_cmsis_inc)
        target_include_directories(${target} PRIVATE ${_cmsis_inc})
    endif()

    file(GLOB _lks_c_srcs ${LKS_SDK_PATH}/source/*.c)
    # lks32mc45x_trim.s is ARM Compiler 5 syntax (armcc), not GCC-compatible — skip.
    target_sources(${target} PRIVATE ${_lks_c_srcs})
    target_compile_definitions(${target} PRIVATE LKS_SDK_LINK=1)
endfunction()
