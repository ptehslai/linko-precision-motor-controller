#pragma once

#include <stdint.h>

#ifdef LKS_SDK_LINK

#include <stdbool.h>

void board_irq_init(void);

uint16_t board_adc_get_raw(uint32_t logical_channel);

bool board_can_take_rx(uint32_t *id, uint8_t *data, uint8_t *len);

#endif
