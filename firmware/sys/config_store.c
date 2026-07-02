#include "config.h"
#include "lks_hal.h"

#include <stdio.h>
#include <string.h>

void config_init(runtime_config_t *cfg)
{
    if (cfg == NULL) {
        return;
    }
    memset(cfg, 0, sizeof(*cfg));
    config_apply_defaults(&cfg->base);

    nvs_data_t nvs;
    if (nvs_load(&nvs)) {
        config_apply_nvs(cfg, &nvs);
    } else {
        nvs_fill_from_config(&nvs, &cfg->base);
    }

    cfg->speed_kp = CFG_SPEED_LOOP_PID_KP;
    cfg->speed_ki = CFG_SPEED_LOOP_PID_KI;
    cfg->speed_kd = CFG_SPEED_LOOP_PID_KD;
    cfg->position_kp = CFG_POSITION_LOOP_PID_KP;
    cfg->position_ki = CFG_POSITION_LOOP_PID_KI;
    cfg->position_kd = CFG_POSITION_LOOP_PID_KD;
    cfg->current_q_kp = CFG_FOC_CURRENT_Q_PID_KP;
    cfg->current_q_ki = CFG_FOC_CURRENT_Q_PID_KI;
    cfg->current_d_kp = CFG_FOC_CURRENT_D_PID_KP;
    cfg->current_d_ki = CFG_FOC_CURRENT_D_PID_KI;
    cfg->speed_gain_scale = 1000U;
    cfg->position_gain_scale = 1000U;
    cfg->dirty = false;
}

void config_apply_nvs(runtime_config_t *cfg, const nvs_data_t *nvs)
{
    if (cfg == NULL || nvs == NULL) {
        return;
    }
    cfg->base.can_node_id = nvs->node_id;
    cfg->base.joint_zero_offset = nvs->joint_zero_offset;
    cfg->speed_kp = nvs->speed_kp;
    cfg->speed_ki = nvs->speed_ki;
    cfg->speed_kd = nvs->speed_kd;
    cfg->position_kp = nvs->position_kp;
    cfg->position_ki = nvs->position_ki;
    cfg->position_kd = nvs->position_kd;
}

void config_apply_can_pid(runtime_config_t *cfg, float sp_kp, float sp_ki, float sp_kd,
                          float pos_kp, float pos_ki, float pos_kd)
{
    if (cfg == NULL) {
        return;
    }
    cfg->speed_kp = sp_kp;
    cfg->speed_ki = sp_ki;
    cfg->speed_kd = sp_kd;
    cfg->position_kp = pos_kp;
    cfg->position_ki = pos_ki;
    cfg->position_kd = pos_kd;
    cfg->dirty = true;
}

void config_set_node_id(runtime_config_t *cfg, uint8_t node_id)
{
    if (cfg == NULL) {
        return;
    }
    cfg->base.can_node_id = node_id;
    cfg->dirty = true;
}

bool config_persist(runtime_config_t *cfg)
{
    if (cfg == NULL) {
        return false;
    }
    nvs_data_t nvs;
    nvs_fill_from_config(&nvs, &cfg->base);
    nvs.node_id = cfg->base.can_node_id;
    nvs.joint_zero_offset = cfg->base.joint_zero_offset;
    nvs.speed_kp = cfg->speed_kp;
    nvs.speed_ki = cfg->speed_ki;
    nvs.speed_kd = cfg->speed_kd;
    nvs.position_kp = cfg->position_kp;
    nvs.position_ki = cfg->position_ki;
    nvs.position_kd = cfg->position_kd;
    bool ok = nvs_save(&nvs);
    if (ok) {
        cfg->dirty = false;
    }
    return ok;
}

const app_config_t *config_get_base(const runtime_config_t *cfg)
{
    return (cfg != NULL) ? &cfg->base : NULL;
}

void config_print(const runtime_config_t *cfg)
{
    if (cfg == NULL) {
        return;
    }
    char line[96];
    snprintf(line, sizeof(line), "node_id=%u can=%ukbps\r\n",
             cfg->base.can_node_id, (unsigned)cfg->base.can_bitrate_kbps);
    hal_uart_write(line);
    snprintf(line, sizeof(line), "speed_pid=%.3f %.3f %.3f\r\n",
             cfg->speed_kp, cfg->speed_ki, cfg->speed_kd);
    hal_uart_write(line);
    snprintf(line, sizeof(line), "pos_pid=%.3f %.3f %.3f\r\n",
             cfg->position_kp, cfg->position_ki, cfg->position_kd);
    hal_uart_write(line);
    snprintf(line, sizeof(line), "iq_pid=%.3f %.3f id_pid=%.3f %.3f\r\n",
             cfg->current_q_kp, cfg->current_q_ki, cfg->current_d_kp, cfg->current_d_ki);
    hal_uart_write(line);
    snprintf(line, sizeof(line), "gear=%.1f enc_cpr=%lu zero=%ld\r\n",
             cfg->base.gearbox_ratio, (unsigned long)cfg->base.encoder_counts_per_rev,
             (long)cfg->base.joint_zero_offset);
    hal_uart_write(line);
}
