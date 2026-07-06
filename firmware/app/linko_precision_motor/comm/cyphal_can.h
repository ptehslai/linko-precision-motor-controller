#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "canard.h"
#include "can_lks.h"
#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    CanardInstance canard;
    CanardTxQueue tx_queue;
    can_lks_t *can;
    runtime_config_t *cfg;
    CanardRxSubscription sub_set_driver;
    CanardRxSubscription sub_clear_errors;
    CanardRxSubscription sub_config_feedback;
    CanardRxSubscription sub_set_speed;
    CanardRxSubscription sub_set_pid;
    CanardRxSubscription sub_set_accel;
    CanardRxSubscription sub_contour_speed;
    CanardRxSubscription sub_max_torque;
    CanardRxSubscription sub_controller_gain;
    CanardRxSubscription sub_eng_test;
    CanardRxSubscription sub_comm_params;
    CanardRxSubscription sub_get_info;
    CanardRxSubscription sub_exec_cmd;
    CanardRxSubscription sub_motor_cmd;
    uint8_t feedback_period_pkt1_ms;
    uint8_t feedback_period_pkt2_ms;
    uint8_t feedback_period_pkt3_ms;
    uint32_t last_pkt1_ms;
    uint32_t last_pkt2_ms;
    uint32_t last_pkt3_ms;
} cyphal_can_t;

bool cyphal_can_init(cyphal_can_t *ctx, can_lks_t *can, runtime_config_t *cfg, void *mem, size_t mem_size);
void cyphal_can_update(cyphal_can_t *ctx, uint32_t now_ms);

#ifdef __cplusplus
}
#endif
