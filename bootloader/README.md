# Bootloader

Flash map and OTA slot selection are managed by the bootloader + `firmware/sys/ota_manager.c`.

- Bootloader base: `0x0000`
- App slot A: `0x8000`
- App slot B: board-defined OTA area (planned)
