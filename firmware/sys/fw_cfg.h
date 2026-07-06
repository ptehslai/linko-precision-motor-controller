#pragma once
#include "config_generated.h"
#include "version.h"
#include <stdbool.h>

#define FW_HW_VERSION CFG_META_BOARD_NAME

/* Runtime configuration: base (from profile YAML) + runtime-tunable PID gains.
 * Initialised by config_init() in config_store.c, persisted to NVS flash. */
typedef struct runtime_config_t {
    app_config_t base;

    /* Speed PID (live-tunable via CAN) */
    float speed_kp;
    float speed_ki;
    float speed_kd;

    /* Position PID */
    float position_kp;
    float position_ki;
    float position_kd;

    /* Current-loop D/Q PID */
    float current_q_kp;
    float current_q_ki;
    float current_d_kp;
    float current_d_ki;

    /* CAN gain scalers (1000 = 1:1, range 10-2000) */
    uint16_t speed_gain_scale;
    uint16_t position_gain_scale;

    bool dirty; /* true when NVS needs saving */
} runtime_config_t;

/* Internal helpers - defined in config_store.c */
void config_init(runtime_config_t *cfg);
const app_config_t *config_get_base(const runtime_config_t *cfg);
void config_print(const runtime_config_t *cfg);
