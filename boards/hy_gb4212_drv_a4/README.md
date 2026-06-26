# HY_GB4212 DRV A4 — reference board profile

**Included example board** for the Linko precision motor controller firmware. This is the PCB the default CMake build targets.

## Hardware summary

| Component | Detail |
|-----------|--------|
| PCB | Huayi HY_GB4212 DRV A4 |
| MCU | LKS32MC454NCQ8 @ 192 MHz (12 MHz HSE) |
| Inverter | EG3033 gate driver, MCPWM1 on GPIO1 P4–P9 |
| Current sense | Triple **7 mΩ** shunt, 10× OPA gain → ADC1 |
| Vbus divider | 11:1 |
| Encoder | **KTH7816** SSI (CLK/DI on GPIO2 P10/P11) |
| CAN | P0.1 TX / P0.2 RX (SIT65HVD232) |
| Debug | UART2 115200 baud |
| Flash / RAM | 256 KB / 40 KB |
| NVS sector | `0x0803F800` (last 2 KB) |

## Files in this profile

| File | Role |
|------|------|
| `board.yaml` | Board ID, hardware constants, 18 V protection thresholds |
| `include/board_pins.h` | Logical pin / ADC channel IDs |
| `include/lks_pinmap.h` | MCU port/pin mux (verify vs schematic) |
| `linker/LKS32MC454NCQ8.ld` | Memory map |
| `startup/startup_lks32mc454.S` | IRQ vector table |

## Paired motor profile

Use with **`config/motors/gb4212_18v.yaml`** (GB4212-18V motor, **100.6:1** gearbox, KTH7816 65536 CPR).

```bash
cmake -B build -DBOARD=hy_gb4212_drv_a4 -DMOTOR_PROFILE=gb4212_18v
```

Both are CMake defaults — plain `cmake -B build` selects this pair.

## Documentation

- Full example write-up: [docs/REFERENCE_EXAMPLE.md](../../docs/REFERENCE_EXAMPLE.md)
- Schematic PDF: place under `docs/` (see `docs/README.md`)
