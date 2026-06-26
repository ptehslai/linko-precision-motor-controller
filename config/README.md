# Configuration profiles

Build-time YAML layers (merged by `tools/gen_config.py`):

| Layer | Path | Contents |
|-------|------|----------|
| Platform | `platform.yaml` | FOC, loops, CAN, protection defaults |
| Board | `boards/<BOARD>/board.yaml` | Identity, MCU, hardware analog front-end, NVS address |
| Motor | `motors/<name>.yaml` | Motor electrical params, **gearbox ratio**, encoder |
| Application | `applications/<name>.yaml` | Optional PID / joint tuning |

## Reference example (default merge)

```
config/platform.yaml
boards/hy_gb4212_drv_a4/board.yaml     # HY_GB4212 DRV A4, 18 V, 7 mΩ shunts
config/motors/gb4212_18v.yaml          # GB4212-18V, 100.6:1 gearbox, KTH7816
```

Optional: `config/applications/arm_joint.yaml` with `-DAPP_PROFILE=arm_joint`.

Full table: [docs/REFERENCE_EXAMPLE.md](../docs/REFERENCE_EXAMPLE.md).

CMake: `-DBOARD`, `-DMOTOR_PROFILE`, `-DAPP_PROFILE`. See `CONFIG.md` for PID tuning.
