#pragma once

#include <stdint.h>
#include "pid.h"
#include "motion_profile.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    pid_t pid;
    motion_profile_t profile;
    float output_rpm_max;
} position_loop_t;

void position_loop_init(position_loop_t *pl, float kp, float ki, float kd,
                        float rpm_max, float accel, float decel);
void position_loop_reset(position_loop_t *pl, float pos_counts);
float position_loop_update(position_loop_t *pl, float pos_cmd_counts, float pos_meas_counts, float dt_s);

#ifdef __cplusplus
}
#endif
