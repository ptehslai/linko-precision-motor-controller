# Bootloader

Dual-slot OTA bootloader for LKS32MC454 reference boards.

## Flash map (256 KiB)

| Region | Address | Size |
|--------|---------|------|
| Bootloader | `0x08000000` | 32 KiB (`0x8000`) |
| App slot A | `0x08008000` | 110 KiB (`0x1B800`) |
| App slot B | `0x08023800` | 110 KiB (`0x1B800`) |
| OTA metadata | `0x0803F000` | 2 KiB |
| NVS | `0x0803F800` | 2 KiB |

## Source layout

| Path | Role |
|------|------|
| `src/boot_main.c` | Entry: select slot, validate vectors, jump |
| `src/boot_ota.c` | Read OTA metadata, pick active/pending slot |
| `src/boot_jump.c` | Cortex-M vector table handoff |
| `linker/bootloader.ld` | Bootloader memory region |

Shared OTA record layout: `firmware/common/ota_layout.h` (addresses from `config_generated.h`).

Application images link with `boards/<board>/linker/app_slot.ld` (slot A base `0x08008000`).

## Build

```bash
cmake --build build --target bootloader bootloader_bin
cmake --build build --target firmware firmware_bin
```

Factory merge: `cmake --build build --target factory_image`
