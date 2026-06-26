#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float kp;
    float ki;
    float kd;
    float integrator;
    float integrator_limit;
    float output_limit;
    float last_error;
    float last_output;
} pid_t;

typedef enum {
    PID_AW_CLAMP = 0,
    PID_AW_BACK_CALC = 1,
} pid_anti_windup_t;

void pid_init(pid_t *p, float kp, float ki, float kd, float out_lim, float i_lim);
void pid_reset(pid_t *p);
float pid_update(pid_t *p, float setpoint, float measurement, float dt_s, pid_anti_windup_t aw);

#ifdef __cplusplus
}
#endif
