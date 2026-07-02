# Third-party dependencies

Only **upstream libraries linked into the firmware** live here. Project-owned code (motion profiler, CRC helpers, board HAL) is under `firmware/`.

## Vendored (used by the build)

| Directory | Upstream | Files used |
|-----------|----------|------------|
| `libcanard/` | [OpenCyphal/libcanard](https://github.com/OpenCyphal/libcanard) | `canard.c`, headers |
| `o1heap/` | [pavel-kirienko/o1heap](https://github.com/pavel-kirienko/o1heap) | `o1heap.c`, `o1heap.h` |

## Vendor SDK (linked when `LKS_SDK_LINK=ON`, default for firmware)

| Path | Source |
|------|--------|
| `lks32mc45x_sdk/LKS32MC45x_DevDriver/` | LKS45 DevDriver v2.46 (`source/` + `include/`) |
| `lks32mc45x_sdk/device/Include/` | Keil pack `lks32mc45x.h`, `basic.h` |
| `lks32mc45x_sdk/Linko.LKS45x_Keil5/` | Keil device pack (pyOCD flash algo) |

`LKS32MC45x_PeripDemo` (~350 MB) is **not** kept in the tree; fetch with `-IncludePeripDemo` for reference only.

CMake links **only** `DevDriver/source/*.c` and `lks32mc45x_trim.s` (not the HAL umbrella or vendor startup). Board bring-up lives in `firmware/bsp/`.

## Update vendored libs

```powershell
powershell -ExecutionPolicy Bypass -File tools/fetch_third_party.ps1
powershell -ExecutionPolicy Bypass -File tools/fetch_third_party.ps1 -IncludeLksSdk
```

Optional reference archives (FlashDB, CMSIS-DSP, MotionGenerator, full libcrc) are downloaded to `.deps_cache/` only.
