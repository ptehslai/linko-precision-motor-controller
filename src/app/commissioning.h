#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    COMM_STEP_IDLE = 0,
    COMM_STEP_RL_ID,
    COMM_STEP_ENC_ALIGN,
    COMM_STEP_REPEATABILITY,
} comm_step_t;

struct runtime_config_t;
struct joint_axis_t;

void commissioning_init(void);
void commissioning_bind(struct runtime_config_t *cfg, struct joint_axis_t *joint);
void commissioning_start_rl_id(void);
void commissioning_start_enc_align(void);
void commissioning_start_repeatability(void);
comm_step_t commissioning_get_step(void);
bool commissioning_step(float dt_s);

#ifdef __cplusplus
}
#endif
