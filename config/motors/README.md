# Motor profiles

YAML files for **motor electrical parameters**, **gearbox ratio**, and **encoder**.

## Reference example: `gb4212_18v.yaml`

Shipped as the default motor profile (`MOTOR_PROFILE=gb4212_18v`). Pairs with board `hy_gb4212_drv_a4`.

| | GB4212-18V example |
|---|-------------------|
| Motor | Huayi GB4212-18V, 8p12s, **4 pole pairs** |
| Voltage / current | 18 V rated, 1.3 A rated, 1.5 A max |
| Phase R / L | 3.24 Ω / 0.87 mH |
| **Gearbox** | **100.6 : 1** |
| Output speed | 46 RPM rated, 53 RPM max (after gearbox) |
| Encoder | KTH7816, 65536 counts/rev, 1 MHz SSI |

See [docs/REFERENCE_EXAMPLE.md](../../docs/REFERENCE_EXAMPLE.md) for the full board + motor + gearbox table.

## Adding another motor

Copy `gb4212_18v.yaml` → `my_motor.yaml`, edit `motor`, `gearbox`, and `encoder` sections, then:

```bash
cmake -B build -DMOTOR_PROFILE=my_motor
```
