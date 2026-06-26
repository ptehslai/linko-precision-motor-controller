# LKS32MC454 MCU platform

Shared early-init code for Linko LKS32MC454 (Cortex-M4F). Board profiles select linker/startup under `boards/<name>/`.

Clock setup uses the HSE option from the active board's `board.yaml` (`mcu.hse_mhz`). Today all profiles use 12 MHz HSE → 192 MHz SYSCLK.
