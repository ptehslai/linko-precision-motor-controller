# Architecture

## Layer dependency

`app/linko_precision_motor` -> `bsp` -> `drivers` -> `sys` -> `common`

`entry.c` executes startup protection, hardware probe, OTA boot notification, then enters app runtime.
