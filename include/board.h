#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void board_init(void);
void board_reset(void);
uint32_t sys_get_ms(void);
uint32_t sys_get_us(void);
void sys_delay_ms(uint32_t ms);

#ifdef __cplusplus
}
#endif
