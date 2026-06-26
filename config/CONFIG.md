# Configuration reference

Defaults are merged from profile YAML files at build time (see `config/README.md`). Generated symbols: `include/config_generated.h`.

## Motor profile example (`config/motors/gb4212_18v.yaml`)

Huayi GB4212-18V: 4 pole pairs, 100.6:1 gearbox, 18 V nominal.

## PID tuning (cascaded loops)

| Loop | Rate | Output | Start tuning |
|------|------|--------|--------------|
| Current q/d | 10 kHz | Vd/Vq | Set `foc.current_* .pid` or use `current_auto_tune` when kp=0 |
| Speed | 1 kHz | Iq (A) | `speed_loop.pid` — start Kp until response, add Ki for load |
| Position | 500 Hz | RPM cmd | `position_loop.pid` — small Ki; use profile limits for arm moves |

### Anti-windup

`pid_common.anti_windup: back_calculation` — integrator back-calculates when output saturates.

### Huayi gain scale (#87)

CAN multipliers (10–2000) scale YAML base gains at runtime without reflash.

## Reference example — GB4212-18V + 100.6:1 gearbox

Default motor profile `config/motors/gb4212_18v.yaml` (paired with board `hy_gb4212_drv_a4`):

| Parameter | Value |
|-----------|-------|
| Pole pairs | **4** (8p12s) |
| Gearbox | **100.6 : 1** |
| Rated voltage / current | 18 V / 1.3 A |
| Phase R / L | 3.24 Ω / 0.87 mH |
| Output speed (rated / max) | 46 / 53 RPM |
| Encoder | KTH7816, 65536 CPR, SSI 1 MHz |

`joint_axis` and speed-loop `output_rpm_*` limits refer to the **output shaft** (after the 100.6:1 reduction). See [docs/REFERENCE_EXAMPLE.md](../docs/REFERENCE_EXAMPLE.md).

## Motor constants (YAML keys)

Tune `protection.*` in YAML. Undervoltage 15 V, overvoltage 22 V, OC 1.5 A / 100 ms.

## NVS persistence

`COMMAND_STORE_PERSISTENT` (#88) saves node ID, zero offset, and PID via `src/config/nvs.c`.
