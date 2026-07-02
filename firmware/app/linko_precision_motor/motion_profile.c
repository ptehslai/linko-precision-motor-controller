#include "motion_profile.h"

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

void motion_profile_init(motion_profile_t *mp, float max_vel, float max_accel, float max_jerk)
{
    if (mp == NULL) {
        return;
    }
    mp->max_vel = max_vel;
    mp->max_accel = max_accel;
    mp->max_jerk = max_jerk;
    mp->pos = 0.0f;
    mp->vel = 0.0f;
    mp->acc = 0.0f;
    mp->finished = true;
}

void motion_profile_reset(motion_profile_t *mp, float pos, float vel)
{
    if (mp == NULL) {
        return;
    }
    mp->pos = pos;
    mp->vel = vel;
    mp->acc = 0.0f;
    mp->finished = true;
}

float motion_profile_update(motion_profile_t *mp, float target_pos, float dt_s)
{
    if (mp == NULL || dt_s <= 0.0f) {
        return 0.0f;
    }

    float err = target_pos - mp->pos;
    float dir = (err >= 0.0f) ? 1.0f : -1.0f;
    float dist = fabsf(err);

    float stop_dist = (mp->vel * mp->vel) / (2.0f * mp->max_accel + 1e-6f);
    float desired_acc = (dist > stop_dist) ? mp->max_accel * dir : -mp->max_accel * dir;

    float acc_err = desired_acc - mp->acc;
    float jerk = clampf(acc_err / dt_s, -mp->max_jerk, mp->max_jerk);
    mp->acc += jerk * dt_s;
    mp->acc = clampf(mp->acc, -mp->max_accel, mp->max_accel);

    mp->vel += mp->acc * dt_s;
    mp->vel = clampf(mp->vel, -mp->max_vel, mp->max_vel);
    mp->pos += mp->vel * dt_s;

    mp->finished = (fabsf(target_pos - mp->pos) < 1e-3f) && (fabsf(mp->vel) < 1e-3f);
    return mp->pos;
}
