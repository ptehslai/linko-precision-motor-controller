#!/usr/bin/env bash
set -e
bash tools/build/pre_build.sh
bash tools/ci/run_unit_tests.sh
bash tools/build/post_build.sh
[ -f dist/linko_precision_motor_factory_v0.1.0_hw_hy_gb4212.bin ]
