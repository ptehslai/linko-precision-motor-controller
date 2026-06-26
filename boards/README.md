# Board profiles

Each subdirectory is one **PCB + MCU wiring** profile.

## Reference example: `hy_gb4212_drv_a4`

| | HY_GB4212 DRV A4 |
|---|------------------|
| MCU | LKS32MC454NCQ8 |
| Motor driver | EG3033 + MCPWM1 |
| Shunt | 7 mΩ triple |
| Encoder pad | KTH7816 SSI |
| Default motor | `gb4212_18v` (GB4212-18V, **100.6:1** gearbox) |

CMake default: `-DBOARD=hy_gb4212_drv_a4`. Details: [docs/REFERENCE_EXAMPLE.md](../docs/REFERENCE_EXAMPLE.md).

## All profiles

| Profile | MCU | Description |
|---------|-----|-------------|
| `hy_gb4212_drv_a4` | LKS32MC454NCQ8 | Huayi HY_GB4212 DRV A4 reference board |

Select at configure time:

```bash
cmake -B build -DBOARD=hy_gb4212_drv_a4 -DMOTOR_PROFILE=gb4212_18v
```

Add a new board by copying `hy_gb4212_drv_a4/` and editing pin map, linker, and `board.yaml`.
