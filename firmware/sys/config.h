#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "config_generated.h"
#include "nvs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    app_config_t base;
    float speed_kp;
    float speed_ki;
    float speed_kd;
    float position_kp;
    float position_ki;
    float position_kd;
    float current_q_kp;
    float current_q_ki;
    float current_d_kp;
    float current_d_ki;
    uint16_t speed_gain_scale;
    uint16_t position_gain_scale;
    bool dirty;
} runtime_config_t;

void config_init(runtime_config_t *cfg);
void config_apply_nvs(runtime_config_t *cfg, const nvs_data_t *nvs);
void config_apply_can_pid(runtime_config_t *cfg, float sp_kp, float sp_ki, float sp_kd,
                          float pos_kp, float pos_ki, float pos_kd);
void config_set_node_id(runtime_config_t *cfg, uint8_t node_id);
bool config_persist(runtime_config_t *cfg);
void config_print(const runtime_config_t *cfg);
const app_config_t *config_get_base(const runtime_config_t *cfg);

#ifdef __cplusplus
}
#endif
