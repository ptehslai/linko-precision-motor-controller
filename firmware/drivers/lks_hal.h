#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    HAL_OK = 0,
    HAL_ERROR = -1,
    HAL_BUSY = -2,
} hal_status_t;

void hal_systick_config(uint32_t tick_hz);
void hal_gpio_write(uint32_t pin, bool level);
bool hal_gpio_read(uint32_t pin);

void hal_mcpwm_init(uint32_t pwm_hz);
void hal_mcpwm_set_duty(uint32_t phase, float duty01);
void hal_mcpwm_enable(bool enable);

void hal_adc_init(void);
uint16_t hal_adc_read(uint32_t channel);

void hal_can_init(uint32_t bitrate_kbps);
bool hal_can_send(uint32_t id, const uint8_t *data, uint8_t len);
bool hal_can_recv(uint32_t *id, uint8_t *data, uint8_t *len);

void hal_uart_init(uint32_t baud);
void hal_uart_write(const char *s);
bool hal_flash_write(uint32_t addr, const void *data, uint32_t len);

#ifdef __cplusplus
}
#endif
