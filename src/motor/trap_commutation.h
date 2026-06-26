#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t step;
    float duty;
} trap_state_t;

void trap_commutation_init(trap_state_t *st);
void trap_commutation_step(trap_state_t *st, float elec_angle_rad, float duty);
void trap_commutation_apply(const trap_state_t *st, uint32_t phase_u, uint32_t phase_v, uint32_t phase_w);

#ifdef __cplusplus
}
#endif
