#include "position_loop.h"

void position_loop_init(position_loop_t *pl, float kp, float ki, float kd,
                        float rpm_max, float accel, float decel)
{
    if (pl == NULL) {
        return;
    }
    pid_init(&pl->pid, kp, ki, kd, rpm_max, rpm_max);
    pl->output_rpm_max = rpm_max;
    motion_profile_init(&pl->profile, rpm_max, accel, accel * 10.0f);
}

void position_loop_reset(position_loop_t *pl, float pos_counts)
{
    if (pl == NULL) {
        return;
    }
    pid_reset(&pl->pid);
    motion_profile_reset(&pl->profile, pos_counts, 0.0f);
}

float position_loop_update(position_loop_t *pl, float pos_cmd_counts, float pos_meas_counts, float dt_s)
{
    if (pl == NULL) {
        return 0.0f;
    }
    float profiled = motion_profile_update(&pl->profile, pos_cmd_counts, dt_s);
    return pid_update(&pl->pid, profiled, pos_meas_counts, dt_s, PID_AW_BACK_CALC);
}
