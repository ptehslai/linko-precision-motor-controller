#include "board.h"
#include "lks_hal.h"

static volatile uint32_t s_tick_ms;
static volatile uint32_t s_tick_us;

void SysTick_Handler(void)
{
    s_tick_ms++;
    s_tick_us += 1000U;
}

void board_init(void)
{
    hal_adc_init();
    hal_systick_config(1000U);
    s_tick_ms = 0U;
    s_tick_us = 0U;
}

void board_reset(void)
{
#ifdef BUILD_HOST_TEST
    /* Host test executable cannot reset hardware. */
    return;
#else
    /* CMSIS NVIC_SystemReset when vendor headers are linked. */
    volatile uint32_t *aircr = (volatile uint32_t *)0xE000ED0CU;
    *aircr = (0x05FAU << 16) | (1U << 2);
    for (;;) {
    }
#endif
}

uint32_t sys_get_ms(void)
{
    return s_tick_ms;
}

uint32_t sys_get_us(void)
{
    return s_tick_us;
}

void sys_delay_ms(uint32_t ms)
{
    uint32_t start = s_tick_ms;
    while ((s_tick_ms - start) < ms) {
    }
}
