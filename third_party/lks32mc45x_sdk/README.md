# LKS32MC45x SDK (vendor)

Downloaded from [LKS45 series](https://www.lksmcu.com/index.php/LKS45Series/) (`sjk.lksmcu.com` CDN).

```powershell
powershell -ExecutionPolicy Bypass -File tools/fetch_third_party.ps1 -IncludeLksSdk
# optional ~350 MB reference demos:
powershell -ExecutionPolicy Bypass -File tools/fetch_third_party.ps1 -IncludeLksSdk -IncludePeripDemo
```

The fetch script installs DevDriver, the Keil pack, and copies **device headers** from the nested `.pack` into `device/Include/`.

## Layout

```
lks32mc45x_sdk/
  LKS32MC45x_DevDriver/     # peripheral driver (legacy source/ API)
  device/Include/           # lks32mc45x.h, basic.h (from Keil pack)
  Linko.LKS45x_Keil5/       # pyOCD / Keil device pack
  LKS32MC45x_PeripDemo/     # optional; not stored in git by default
```

## CMake

Firmware builds with the SDK by default (`LKS_SDK_LINK=ON`). Linking is handled by `cmake/LksSdk.cmake` — PeripDemo-style `source/` only, no HAL duplicate layer.

```bash
cmake -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc.cmake
cmake --build build
```

To build algorithm sources on the host without the SDK:

```bash
cmake -B build-host -DBUILD_HOST_TEST=ON
cmake --build build-host
```

`LKS_SDK_PATH` defaults to `third_party/lks32mc45x_sdk/LKS32MC45x_DevDriver`.
