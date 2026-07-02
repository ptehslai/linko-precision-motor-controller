#pragma once

#include <stdint.h>
#include "pid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    pid_t pid;
    float speed_filtered_rpm;
    float filter_alpha;
    float output_iq_max_a;
} speed_loop_t;

void speed_loop_init(speed_loop_t *sl, float kp, float ki, float kd, float iq_max, float filter_hz, float rate_hz);
void speed_loop_reset(speed_loop_t *sl);
float speed_loop_update(speed_loop_t *sl, float rpm_cmd, float rpm_meas, float dt_s);

#ifdef __cplusplus
}
#endif
