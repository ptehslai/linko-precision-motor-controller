#include "pid.h"

#include <math.h>

static float clampf(float v, float lo, float hi)
{
    if (v < lo) {
        return lo;
    }
    if (v > hi) {
        return hi;
    }
    return v;
}

void pid_init(pid_t *p, float kp, float ki, float kd, float out_lim, float i_lim)
{
    if (p == NULL) {
        return;
    }
    p->kp = kp;
    p->ki = ki;
    p->kd = kd;
    p->integrator = 0.0f;
    p->integrator_limit = i_lim;
    p->output_limit = out_lim;
    p->last_error = 0.0f;
    p->last_output = 0.0f;
}

void pid_reset(pid_t *p)
{
    if (p == NULL) {
        return;
    }
    p->integrator = 0.0f;
    p->last_error = 0.0f;
    p->last_output = 0.0f;
}

float pid_update(pid_t *p, float setpoint, float measurement, float dt_s, pid_anti_windup_t aw)
{
    if (p == NULL || dt_s <= 0.0f) {
        return 0.0f;
    }

    float err = setpoint - measurement;
    float p_term = p->kp * err;
    float d_term = (p->kd * (err - p->last_error)) / dt_s;
    float i_term = p->ki * p->integrator;

    float out = p_term + i_term + d_term;
    float out_sat = clampf(out, -p->output_limit, p->output_limit);

    if (aw == PID_AW_BACK_CALC) {
        float aw_gain = (p->ki != 0.0f) ? p->kp / p->ki : 0.0f;
        p->integrator += (err + aw_gain * (out_sat - out)) * dt_s;
    } else {
        p->integrator += err * dt_s;
    }

    p->integrator = clampf(p->integrator, -p->integrator_limit, p->integrator_limit);
    out = p_term + p->ki * p->integrator + d_term;
    out_sat = clampf(out, -p->output_limit, p->output_limit);

    p->last_error = err;
    p->last_output = out_sat;
    return out_sat;
}
