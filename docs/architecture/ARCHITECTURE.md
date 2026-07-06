# Architecture

## Layer dependency

`app/linko_precision_motor` -> `bsp` -> `drivers` -> `sys` -> `common`

Vendor SDK headers are forbidden under `app/**` (see `FOLDER_MAP.md`).

## Boot flow

```
bootloader (0x08000000)
  -> read OTA metadata @ 0x0803F000
  -> select slot A/B, validate vector table
  -> jump to app
firmware/entry.c
  -> startup_protection_run()
  -> hardware_probe_run()
  -> ota_manager_boot_notify() + ota_confirm_running_image()
  -> app_run_main() in runtime/main_loop.c
```

## App product modules (`firmware/app/linko_precision_motor/`)

| Module | Path | Responsibility |
|--------|------|----------------|
| `runtime/` | main loop, FSM, fault, protection, commissioning | Application orchestration |
| `control/` | PID, speed/position loops, joint axis, motion profile | Output-side control |
| `motor/` | FOC, SVPWM, commutation, angle source | Motor control algorithms |
| `motor/observer/` | HFI, SMO | Sensorless observers |
| `comm/` | Cyphal CAN, Huayi services, motor status | Field bus and telemetry |

## Flash layout (reference board)

See `bootloader/README.md` for bootloader + dual-slot app regions.
