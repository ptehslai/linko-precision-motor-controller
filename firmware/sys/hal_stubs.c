/* Linker stubs for functions not provided by nosys.specs or when CMSIS inline fails */

#include <stdint.h>

/* SysTick_Config is __STATIC_INLINE in core_cm4.h; provide a weak fallback. */
uint32_t SysTick_Config(uint32_t ticks);

uint32_t __attribute__((weak)) SysTick_Config(uint32_t ticks)
{
    (void)ticks;
    return 0U;
}

/* end symbol for _sbrk — override weak definition from nosys */
__attribute__((used)) uint32_t end = 0x20000000;
