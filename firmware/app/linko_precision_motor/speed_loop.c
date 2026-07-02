#include "speed_loop.h"

#include <math.h>

void speed_loop_init(speed_loop_t *sl, float kp, float ki, float kd, float iq_max, float filter_hz, float rate_hz)
{
    if (sl == NULL) {
        return;
    }
    pid_init(&sl->pid, kp, ki, kd, iq_max, iq_max);
    sl->output_iq_max_a = iq_max;
    float tau = 1.0f / (2.0f * 3.1415926f * filter_hz);
    float dt = 1.0f / rate_hz;
    sl->filter_alpha = dt / (tau + dt);
    sl->speed_filtered_rpm = 0.0f;
}

void speed_loop_reset(speed_loop_t *sl)
{
    if (sl == NULL) {
        return;
    }
    pid_reset(&sl->pid);
    sl->speed_filtered_rpm = 0.0f;
}

float speed_loop_update(speed_loop_t *sl, float rpm_cmd, float rpm_meas, float dt_s)
{
    if (sl == NULL) {
        return 0.0f;
    }
    sl->speed_filtered_rpm += sl->filter_alpha * (rpm_meas - sl->speed_filtered_rpm);
    return pid_update(&sl->pid, rpm_cmd, sl->speed_filtered_rpm, dt_s, PID_AW_BACK_CALC);
}
