#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float ua;
    float ub;
    float uc;
} svpwm_out_t;

void svpwm_calc(float valpha, float vbeta, float vbus, svpwm_out_t *out);
float svpwm_clamp_mod(float m);

#ifdef __cplusplus
}
#endif
