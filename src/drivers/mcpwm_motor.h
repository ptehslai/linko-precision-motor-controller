#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void mcpwm_motor_init(uint32_t pwm_hz);
void mcpwm_motor_enable(bool enable);
void mcpwm_motor_set_svpwm(float ua, float ub, float uc);

#ifdef __cplusplus
}
#endif
