#include "trap_commutation.h"
#include "lks_hal.h"

#include <stddef.h>
#include <math.h>

void trap_commutation_init(trap_state_t *st)
{
    if (st == NULL) {
        return;
    }
    st->step = 0U;
    st->duty = 0.0f;
}

void trap_commutation_step(trap_state_t *st, float elec_angle_rad, float duty)
{
    if (st == NULL) {
        return;
    }
    float sector = fmodf(elec_angle_rad, 6.2831853f);
    if (sector < 0.0f) {
        sector += 6.2831853f;
    }
    st->step = (uint8_t)(sector / 1.0471976f);
    if (st->step > 5U) {
        st->step = 5U;
    }
    st->duty = duty;
}

void trap_commutation_apply(const trap_state_t *st, uint32_t phase_u, uint32_t phase_v, uint32_t phase_w)
{
    if (st == NULL) {
        return;
    }
    float off = 0.0f;
    float on = st->duty;
    float du = off, dv = off, dw = off;

    switch (st->step) {
    case 0U: du = on; dv = off; dw = off; break;
    case 1U: du = on; dv = on; dw = off; break;
    case 2U: du = off; dv = on; dw = off; break;
    case 3U: du = off; dv = on; dw = on; break;
    case 4U: du = off; dv = off; dw = on; break;
    default: du = on; dv = off; dw = on; break;
    }

    hal_mcpwm_set_duty(phase_u, du);
    hal_mcpwm_set_duty(phase_v, dv);
    hal_mcpwm_set_duty(phase_w, dw);
}
