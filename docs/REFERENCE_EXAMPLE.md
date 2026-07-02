# Reference example: HY_GB4212 + GB4212-18V

This repository ships a **complete, working profile set** for the Huayi joint motor system that motivated the project. CMake defaults build this combination out of the box — no extra `-D` flags required.

## Quick build (this example)

```bash
cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc.cmake
cmake --build build --target generate_config
cmake --build build
```

Equivalent explicit profile selection:

```bash
cmake -B build -DBOARD=hy_gb4212_drv_a4 -DMOTOR_PROFILE=gb4212_18v
```

Optional robotic-arm tuning overlay:

```bash
cmake -B build -DAPP_PROFILE=arm_joint
```

## What maps to what

| Piece | Product | Profile path | CMake variable |
|-------|---------|--------------|----------------|
| **Driver PCB** | HY_GB4212 DRV A4 | `boards/hy_gb4212_drv_a4/` | `BOARD=hy_gb4212_drv_a4` |
| **Board config** | 18 V bus, 7 mΩ shunts, KTH7816 pads | `boards/hy_gb4212_drv_a4/board.yaml` | *(merged automatically)* |
| **Motor + gearbox** | GB4212-18V, 8p12s, 100.6:1 | `config/motors/gb4212_18v.yaml` | `MOTOR_PROFILE=gb4212_18v` |
| **Control defaults** | FOC / loops / CAN | `config/platform.yaml` | *(always merged)* |

## Board — HY_GB4212 DRV A4

| Item | Value |
|------|-------|
| MCU | LKS32MC454NCQ8 (Cortex-M4F @ 192 MHz, 12 MHz HSE) |
| Gate driver | EG3033 (MCPWM1, GPIO1 P4–P9) |
| Current sense | Triple 7 mΩ shunt, on-chip OPA → ADC1 |
| Encoder interface | KTH7816 magnetic, SSI bit-bang (GPIO2 P10/P11) |
| CAN | SIT65HVD232 (P0.1 TX / P0.2 RX) |
| Debug UART | UART2 @ 115200 (GPIO2 P0/P1) |
| Cyphal board ID | `com.huayi.gb4212` |
| Pin map | `boards/hy_gb4212_drv_a4/include/lks_pinmap.h` |
| Schematic | HY_GB4212_DRV_A4 PDF (see `docs/README.md`) |

## Motor — GB4212-18V

| Item | Value |
|------|-------|
| Topology | 8 poles / 12 slots → **4 pole pairs** |
| Rated voltage | **18 V** |
| Phase R / L | 3.24 Ω / 0.87 mH |
| Rated / max current | 1.3 A / 1.5 A |
| Rated output speed | **46 RPM** (after gearbox) |
| Max output speed | **53 RPM** |

## Gearbox

| Item | Value |
|------|-------|
| Ratio | **100.6 : 1** (motor revs per one output rev) |
| Used by | `joint_axis` — encoder counts and RPM on the **output shaft** |
| Config key | `gearbox.ratio` in `config/motors/gb4212_18v.yaml` |

Example: 1° at the output ≈ 100.6 motor revolutions internally; speed loop `output_rpm_max: 53` is **output-shaft** RPM.

## Encoder — KTH7816 (on board)

| Item | Value |
|------|-------|
| Interface | SSI, bit-banged in `firmware/drivers/encoder_kth7816.c` |
| Resolution | 65536 counts/rev (16-bit) |
| SSI clock | 1 MHz (configurable in motor profile) |

## YAML profile files (this example)

```
config/platform.yaml                    # shared FOC / loop structure
boards/hy_gb4212_drv_a4/board.yaml      # PCB analog front-end, 18 V protection
config/motors/gb4212_18v.yaml           # motor + gearbox + encoder + RPM limits
config/applications/arm_joint.yaml      # optional: arm joint PID / torque cap
```

## Protection defaults (18 V system)

From merged board + motor profiles:

- Undervoltage: 15 V  
- Overvoltage: 22 V  
- Overcurrent: 1.5 A for 100 ms  

## Adding a *different* board or motor

Copy the reference directories and edit YAML — the generic firmware in `firmware/` stays unchanged:

1. `boards/hy_gb4212_drv_a4/` → `boards/my_board/`
2. `config/motors/gb4212_18v.yaml` → `config/motors/my_motor.yaml`
3. `cmake -DBOARD=my_board -DMOTOR_PROFILE=my_motor`

The HY_GB4212 example remains in-tree as the tested reference configuration.
