#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float id;
    float iq;
    float vd;
    float vq;
    float elec_angle_rad;
    float vbus;
    uint8_t pole_pairs;
} foc_state_t;

void foc_park(float ia, float ib, float ic, float theta, float *id, float *iq);
void foc_inv_park(float vd, float vq, float theta, float *valpha, float *vbeta);
void foc_run_current_loop(foc_state_t *st, float id_ref, float iq_ref, float kp, float ki, float dt_s);

#ifdef __cplusplus
}
#endif
