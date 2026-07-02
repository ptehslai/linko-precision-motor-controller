#!/usr/bin/env bash
set -e
cmake -B build-host -DBUILD_HOST_TEST=ON
cmake --build build-host
ctest --test-dir build-host --output-on-failure || true
