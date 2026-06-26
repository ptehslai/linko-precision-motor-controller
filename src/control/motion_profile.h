#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Trapezoidal position profiler (C port; inspired by MotionGenerator). */

typedef struct {
    float max_vel;
    float max_accel;
    float max_jerk;
    float pos;
    float vel;
    float acc;
    bool finished;
} motion_profile_t;

void motion_profile_init(motion_profile_t *mp, float max_vel, float max_accel, float max_jerk);
void motion_profile_reset(motion_profile_t *mp, float pos, float vel);
float motion_profile_update(motion_profile_t *mp, float target_pos, float dt_s);

#ifdef __cplusplus
}
#endif
