#include "protection.h"
#include "config_generated.h"
#include <math.h>

void protection_init(protection_state_t *ps)
{
    if (ps == NULL) {
        return;
    }
    ps->vbus_v = 0.0f;
    ps->oc_timer_s = 0.0f;
    ps->stall_timer_s = 0.0f;
}

void protection_update(protection_state_t *ps, float vbus_v, const adc_current_t *adc,
                       float speed_rpm, float dt_s)
{
    if (ps == NULL || adc == NULL || dt_s <= 0.0f) {
        return;
    }

    ps->vbus_v = vbus_v;

    if (vbus_v < CFG_PROTECTION_UNDERVOLTAGE_V) {
        fault_set(FAULT_UNDERVOLT);
    } else if (vbus_v > CFG_PROTECTION_OVERVOLTAGE_V) {
        fault_set(FAULT_OVERVOLT);
    }

    float i_abs = fmaxf(fmaxf(fabsf(adc->ia), fabsf(adc->ib)), fabsf(adc->ic));
    if (i_abs > CFG_PROTECTION_OVERCURRENT_A) {
        ps->oc_timer_s += dt_s;
        if (ps->oc_timer_s >= (float)CFG_PROTECTION_OVERCURRENT_MS * 0.001f) {
            fault_set(FAULT_OVERCURRENT);
        }
    } else {
        ps->oc_timer_s = 0.0f;
    }

    if (i_abs > CFG_PROTECTION_STALL_CURRENT_PCT * 0.01f * CFG_MOTOR_RATED_CURRENT_A
        && fabsf(speed_rpm) < CFG_PROTECTION_STALL_SPEED_RPM) {
        ps->stall_timer_s += dt_s;
        if (ps->stall_timer_s >= (float)CFG_PROTECTION_STALL_TIMEOUT_MS * 0.001f) {
            fault_set(FAULT_STALL);
        }
    } else {
        ps->stall_timer_s = 0.0f;
    }
}
