#include "mcpwm_motor.h"
#include "lks_hal.h"

static bool s_enabled;

void mcpwm_motor_init(uint32_t pwm_hz)
{
    hal_mcpwm_init(pwm_hz);
    s_enabled = false;
}

void mcpwm_motor_enable(bool enable)
{
    s_enabled = enable;
    hal_mcpwm_enable(enable);
}

void mcpwm_motor_set_svpwm(float ua, float ub, float uc)
{
    if (!s_enabled) {
        hal_mcpwm_enable(true);
        s_enabled = true;
    }
    hal_mcpwm_set_duty(0U, ua);
    hal_mcpwm_set_duty(1U, ub);
    hal_mcpwm_set_duty(2U, uc);
}
