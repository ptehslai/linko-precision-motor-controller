project_name: linko_precision_motor_firmware
device_class: non_iot
production_profile: full
mcu: LKS32MC454NCQ8
vendor: linko
sdk: LKS32MC45x DevDriver 2.46
firmware_root: firmware
entry_file: firmware/entry.c
entry_symbol: main
rtos: bare_metal
active_profile: root
build: cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc.cmake
flash: cmake --build build --target flash
release_binary_pattern: '{product}_app_v{fw}_hw{hw}.bin'
factory_image_pattern: '{product}_factory_v{fw}_hw{hw}.bin'
bootloader_root: bootloader/
bootloader_flash_offset: 0x0
app_flash_offset: 0x8000
pre_build_script: tools/build/pre_build.sh
post_build_script: tools/build/post_build.sh
portable_storage_api: storage_store
forbidden_in_app_includes:
  - lks32mc45x_lib.h
  - lks32mc45x.h
third_party_policy: mixed
test_gate_unit_host: tools/ci/run_unit_tests.sh
test_gate_release: tools/ci/release_gate.sh
legacy_path_aliases:
  - src/* -> firmware/* (migrated physical paths)
