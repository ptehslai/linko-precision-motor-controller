$ErrorActionPreference = 'Stop'
Set-Location (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
powershell -ExecutionPolicy Bypass -File tools/build/pre_build.ps1
powershell -ExecutionPolicy Bypass -File tools/ci/run_unit_tests.ps1
cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc.cmake -DLKS_SDK_LINK=OFF
cmake --build build --target generate_config bootloader_bin firmware_bin
powershell -ExecutionPolicy Bypass -File tools/build/post_build.ps1
if (-not (Test-Path dist/linko_precision_motor_factory_v0.1.0_hw_hy_gb4212.bin)) {
    throw 'Factory image missing'
}
