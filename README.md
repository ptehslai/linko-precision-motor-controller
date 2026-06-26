# Linko Precision Motor Controller

> **Repository folder:** `linko-precision-motor-controller` (rename from `motor-controller-with-encoder` when the IDE is closed — see `docs/PUBLISH.md`).

High-precision sensored FOC firmware for **Linko LKS32MC45x** motor driver boards. The codebase separates reusable control stack code from **board**, **motor/gearbox**, and **application** profiles so one tree can target different hardware and mechanisms.

**Version:** 0.1.0

This repo is a **generic** Linko LKS32MC45x motor-controller framework (profile-based board / motor / application layers). It ships with a **full reference example** for the Huayi system this project was built around — see [Reference example](docs/REFERENCE_EXAMPLE.md).

## Reference example (default build)

| | Product | Profile |
|---|---------|---------|
| **Board** | HY_GB4212 DRV A4 (LKS32MC454, EG3033, KTH7816, triple 7 mΩ shunt) | `boards/hy_gb4212_drv_a4/` |
| **Motor** | GB4212-18V (8p12s, 4 pole pairs, 18 V, 1.3 A rated) | `config/motors/gb4212_18v.yaml` |
| **Gearbox** | **100.6 : 1** planetary (output-shaft RPM/position in `joint_axis`) | `gearbox.ratio` in motor profile |
| **Encoder** | KTH7816 magnetic, 16-bit SSI | same motor profile |

CMake defaults (`BOARD=hy_gb4212_drv_a4`, `MOTOR_PROFILE=gb4212_18v`) build this combination with no extra flags. Output shaft: **46 RPM rated**, **53 RPM max**; Cyphal ID `com.huayi.gb4212`.

```bash
cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc.cmake
cmake --build build
```

Optional arm-joint tuning: `-DAPP_PROFILE=arm_joint`. Full specs: [docs/REFERENCE_EXAMPLE.md](docs/REFERENCE_EXAMPLE.md).

## Features

- Field-oriented control (FOC) + SVPWM
- Gearbox-aware output-side `joint_axis` position/speed loops
- Magnetic encoder (KTH7816 SSI bit-bang driver)
- Cyphal CAN + Huayi vendor services
- YAML profile merge at build time
- LKS DevDriver HAL (MCPWM, ADC, CAN, UART, flash)

## Architecture

```
┌──────────────────────────────────────────────────────────────┐
│  Generic firmware (src/)                                      │
│  motor/ control/ comm/ drivers/ app/ board HAL API            │
├──────────────────────────────────────────────────────────────┤
│  Profiles (selected at cmake configure time)                  │
│  boards/<name>/     pins, linker, startup, board.yaml         │
│  config/motors/     motor, gearbox, encoder                  │
│  config/applications/  optional tuning overlays               │
│  config/platform.yaml  shared loop / FOC defaults             │
└──────────────────────────────────────────────────────────────┘
```

| Layer | Location | Status |
|-------|----------|--------|
| FOC, Cyphal, loops | `src/` | Implemented |
| Board HAL | `src/board/` + `boards/<BOARD>/include/` | Wired for `hy_gb4212_drv_a4` |
| Profiles | `boards/`, `config/` | GB4212 reference profiles included |
| Hardware validation | — | Not yet done on target |

## Prerequisites

- `arm-none-eabi-gcc` 13.x (Cortex-M4F hard float)
- CMake 3.20+, Ninja
- Python 3 + PyYAML (`pip install pyyaml`)
- LKS32MC45x DevDriver + device headers (`tools/fetch_third_party.ps1 -IncludeLksSdk`)
- Optional: pyOCD for flash/debug

## Fetch dependencies

```powershell
powershell -ExecutionPolicy Bypass -File tools/fetch_third_party.ps1
powershell -ExecutionPolicy Bypass -File tools/fetch_third_party.ps1 -IncludeLksSdk
```

## Configure profiles

CMake cache variables:

| Variable | Default | Description |
|----------|---------|-------------|
| `BOARD` | `hy_gb4212_drv_a4` | Directory under `boards/` |
| `MOTOR_PROFILE` | `gb4212_18v` | YAML under `config/motors/` |
| `APP_PROFILE` | *(empty)* | Optional YAML under `config/applications/` |
| `LKS_SDK_LINK` | `ON` | Link vendor DevDriver |

Examples:

```bash
# Reference HY_GB4212 + GB4212 motor (defaults)
cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc.cmake

# Arm-joint application tuning overlay
cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc.cmake \
  -DAPP_PROFILE=arm_joint

# Bench derating overlay
cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc.cmake \
  -DAPP_PROFILE=bench_low_voltage
```

Config merge order: `config/platform.yaml` → `boards/<BOARD>/board.yaml` → `config/motors/<MOTOR>.yaml` → optional application YAML.

## Build

```bash
cmake --build build --target generate_config
cmake --build build
```

Outputs: `build/firmware`, `build/firmware.hex` (`firmware_hex` target).

Stub HAL (no SDK):

```bash
cmake -B build -DLKS_SDK_LINK=OFF ...
```

Host compile test:

```bash
cmake -B build-host -DBUILD_HOST_TEST=ON
cmake --build build-host
```

Flash:

```bash
cmake --build build --target flash
```

## Adding a new target

The **HY_GB4212 / GB4212-18V / 100.6:1** example stays in-tree as the reference. To target different hardware:

1. **Board** — copy `boards/hy_gb4212_drv_a4/`, edit `include/lks_pinmap.h`, linker, `board.yaml`.
2. **Motor** — copy `config/motors/gb4212_18v.yaml`, edit `motor`, `gearbox`, `encoder`.
3. **Application** — optional overlay in `config/applications/`.
4. Configure: `-DBOARD=... -DMOTOR_PROFILE=... -DAPP_PROFILE=...`.

See [docs/REFERENCE_EXAMPLE.md](docs/REFERENCE_EXAMPLE.md), `boards/README.md`, and `config/CONFIG.md`.

## Project layout

| Path | Purpose |
|------|---------|
| `boards/` | Per-PCB pin maps, linker, startup, `board.yaml` |
| `platforms/lks32mc454/` | MCU-family `SystemInit` |
| `config/platform.yaml` | Generic control defaults |
| `config/motors/` | Motor + gearbox + encoder profiles |
| `config/applications/` | Application tuning overlays |
| `src/board/` | Portable HAL implementation |
| `src/control/joint_axis.c` | Output-side joint (gearbox-scaled) loops |
| `cmake/LksSdk.cmake` | DevDriver linking (PeripDemo-style `source/` API) |
| `third_party/` | libcanard, o1heap, LKS SDK |

---

## Appendix A — Glossary

### Big picture

| Term | Meaning |
|------|---------|
| **MCU** | Microcontroller — Linko LKS32MC454 on reference boards |
| **HAL** | Hardware abstraction in `src/board/lks_hal.c` |
| **DevDriver** | Linko vendor peripheral library |
| **Board profile** | `boards/<name>/` — pins, linker, analog front-end metadata |
| **Motor profile** | `config/motors/<name>.yaml` — R/L, pole pairs, gearbox, encoder |
| **Application profile** | Optional overlay — e.g. arm joint PID tuning |
| **joint_axis** | Output-side position/speed control after gearbox ratio |
| **LKS_SDK_LINK** | CMake flag to link DevDriver vs HAL stubs |

### Motor control

| Term | Meaning |
|------|---------|
| **FOC** | Field-oriented control — torque via rotor-aligned current |
| **SVPWM** | Space-vector PWM — three phase duty outputs |
| **MCPWM** | Motor Control PWM — Linko hardware PWM for gate drivers |
| **Triple shunt** | Three resistors measuring phase currents |
| **Dead time** | MCPWM gap preventing shoot-through in the bridge |
| **Gearbox ratio** | Motor revs per output rev — from motor profile YAML |

### MCPWM

Dedicated motor PWM block: complementary half-bridge outputs, center-aligned PWM, dead time, ADC trigger points. Reference board uses **MCPWM1** → EG3033 gate driver. FOC sets duties via `hal_mcpwm_set_duty()`.

### Sensing & comms

| Term | Meaning |
|------|---------|
| **ADC1** | Current and Vbus sampling (often MCPWM-triggered) |
| **KTH7816** | Magnetic encoder; **SSI** bit-banged on GPIO |
| **Cyphal** | CAN protocol stack (libcanard) |
| **NVS** | Flash-backed PID / zero offset storage |

### Data flow

```
Encoder (SSI) ──► angle ──┐
                          ├──► FOC + SVPWM ──► MCPWM ──► gate driver ──► motor
ADC (shunts)  ──► current ┘
CAN (Cyphal) ◄──► commands / status
joint_axis ◄──► output-side position & speed (after gearbox)
```
