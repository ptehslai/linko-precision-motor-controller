$ErrorActionPreference = 'Stop'
Set-Location (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
cmake -B build-host -DBUILD_HOST_TEST=ON -DLKS_SDK_LINK=OFF
cmake --build build-host
ctest --test-dir build-host --output-on-failure
