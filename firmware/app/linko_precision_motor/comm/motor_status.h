#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void motor_status_set(float voltage_v, float current_a, float temp_c, float speed_rpm, int32_t position);
uint8_t motor_status_pack(uint8_t *buf, uint8_t buflen);
float motor_status_get_voltage_v(void);
float motor_status_get_current_a(void);
float motor_status_get_temp_c(void);
float motor_status_get_speed_rpm(void);
int32_t motor_status_get_position(void);

#ifdef __cplusplus
}
#endif
