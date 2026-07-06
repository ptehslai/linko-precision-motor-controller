#!/usr/bin/env bash
set -e
bash tools/build/pre_build.sh
bash tools/ci/run_unit_tests.sh
cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc.cmake -DLKS_SDK_LINK=OFF
cmake --build build --target generate_config bootloader_bin firmware_bin
bash tools/build/post_build.sh
test -f dist/linko_precision_motor_factory_v0.1.0_hw_hy_gb4212.bin
