#include "huayi_services.h"
#include "cyphal_can_send.h"
#include "cyphal_can_msg_list.h"
#include "motor_fsm.h"
#include "config.h"
#include "commissioning.h"
#include "fault.h"
#include "board.h"

static void handle_set_mode_setpoint(cyphal_can_t *ctx, const uint8_t *payload, size_t len)
{
    if (len < 6U) {
        return;
    }
    int32_t setpoint = (int32_t)((uint32_t)payload[0] | ((uint32_t)payload[1] << 8)
        | ((uint32_t)payload[2] << 16) | ((uint32_t)payload[3] << 24));
    uint8_t mode = payload[4];

    switch (mode) {
    case 0x31U:
        motor_fsm_set_ctrl_mode(MOTOR_CTRL_FOC_SPEED);
        motor_fsm_set_speed_rpm((float)setpoint * 0.1f);
        motor_fsm_set_enabled(true);
        break;
    case 0x30U:
        motor_fsm_set_ctrl_mode(MOTOR_CTRL_FOC_POSITION);
        motor_fsm_set_position_counts(setpoint);
        motor_fsm_set_enabled(true);
        break;
    case 0x22U:
        motor_fsm_set_ctrl_mode(MOTOR_CTRL_FOC_SPEED);
        motor_fsm_set_enabled(true);
        break;
    default:
        break;
    }
    (void)ctx;
}

static void handle_speed_pid(cyphal_can_t *ctx, const uint8_t *payload, size_t len)
{
    if (ctx == NULL || ctx->cfg == NULL || len < 6U) {
        return;
    }
    uint16_t p = (uint16_t)payload[0] | ((uint16_t)payload[1] << 8);
    uint16_t i = (uint16_t)payload[2] | ((uint16_t)payload[3] << 8);
    uint16_t d = (uint16_t)payload[4] | ((uint16_t)payload[5] << 8);
    config_apply_can_pid(ctx->cfg, (float)p * 0.01f, (float)i * 0.01f, (float)d * 0.01f, 0.0f, 0.0f, 0.0f);
}

static void handle_accel(cyphal_can_t *ctx, const uint8_t *payload, size_t len)
{
    (void)ctx;
    (void)payload;
    (void)len;
}

static void handle_contour_speed(cyphal_can_t *ctx, const uint8_t *payload, size_t len)
{
    if (ctx == NULL || len < 2U) {
        return;
    }
    int16_t rpm = (int16_t)((uint16_t)payload[0] | ((uint16_t)payload[1] << 8));
    motor_fsm_set_speed_rpm((float)rpm * 0.1f);
}

static void handle_max_torque(cyphal_can_t *ctx, const uint8_t *payload, size_t len)
{
    if (ctx == NULL || ctx->cfg == NULL || len < 2U) {
        return;
    }
    uint16_t pct = (uint16_t)payload[0] | ((uint16_t)payload[1] << 8);
    ctx->cfg->base.joint_max_torque_pct = pct;
    ctx->cfg->dirty = true;
}

static void handle_controller_gain(cyphal_can_t *ctx, const uint8_t *payload, size_t len)
{
    if (ctx == NULL || ctx->cfg == NULL || len < 6U) {
        return;
    }
    uint16_t p = (uint16_t)payload[0] | ((uint16_t)payload[1] << 8);
    uint16_t i = (uint16_t)payload[2] | ((uint16_t)payload[3] << 8);
    uint16_t d = (uint16_t)payload[4] | ((uint16_t)payload[5] << 8);
    config_apply_can_pid(ctx->cfg, 0.0f, 0.0f, 0.0f,
                         (float)p * 0.001f, (float)i * 0.001f, (float)d * 0.001f);
}

static void handle_eng_test(const uint8_t *payload, size_t len)
{
    if (len < 1U) {
        return;
    }
    switch (payload[0]) {
    case 0x09U:
        commissioning_start_rl_id();
        break;
    case 0x0CU:
    case 0x0EU:
        commissioning_start_enc_align();
        break;
    case 0x10U:
        commissioning_start_repeatability();
        break;
    default:
        break;
    }
}

static void handle_get_info(cyphal_can_t *ctx, const CanardRxTransfer *transfer)
{
    cyphal_send_get_info_response(ctx, transfer->metadata.remote_node_id, transfer->metadata.transfer_id);
}

static void handle_exec_cmd(cyphal_can_t *ctx, const CanardRxTransfer *transfer, const uint8_t *payload, size_t len)
{
    if (len < 2U) {
        return;
    }
    uint16_t cmd = (uint16_t)payload[0] | ((uint16_t)payload[1] << 8);
    switch (cmd) {
    case 65531U:
        motor_fsm_set_enabled(false);
        fault_set(FAULT_EMERGENCY);
        break;
    case 65530U:
        if (ctx->cfg != NULL) {
            config_persist(ctx->cfg);
        }
        break;
    case 65535U:
        board_reset();
        break;
    default:
        break;
    }

    cyphal_send_service_status(ctx, CYPHAL_SVC_EXECUTE_COMMAND, transfer->metadata.remote_node_id,
                               transfer->metadata.transfer_id, 0U);
}

void huayi_services_handle(cyphal_can_t *ctx, const CanardRxTransfer *transfer)
{
    if (ctx == NULL || transfer == NULL) {
        return;
    }

    const uint8_t *payload = (const uint8_t *)transfer->payload.data;
    size_t len = transfer->payload.size;

    if (transfer->metadata.transfer_kind == CanardTransferKindRequest) {
        switch (transfer->metadata.port_id) {
        case HUAYI_SVC_SET_DRIVER:
            if (len >= 1U) {
                motor_fsm_set_enabled(payload[0] == 0x01U);
            }
            break;
        case HUAYI_SVC_CLEAR_ERRORS:
            fault_clear_all();
            break;
        case HUAYI_SVC_CONFIG_FEEDBACK:
            if (len >= 3U) {
                ctx->feedback_period_pkt1_ms = payload[0];
                ctx->feedback_period_pkt2_ms = payload[1];
                ctx->feedback_period_pkt3_ms = payload[2];
            }
            break;
        case HUAYI_SVC_SET_MODE_SETPOINT:
            handle_set_mode_setpoint(ctx, payload, len);
            break;
        case HUAYI_SVC_SET_SPEED_PID:
            handle_speed_pid(ctx, payload, len);
            break;
        case HUAYI_SVC_SET_ACCEL_DECEL:
            handle_accel(ctx, payload, len);
            break;
        case HUAYI_SVC_SET_CONTOUR_SPEED:
            handle_contour_speed(ctx, payload, len);
            break;
        case HUAYI_SVC_SET_MAX_TORQUE:
            handle_max_torque(ctx, payload, len);
            break;
        case HUAYI_SVC_SET_CONTROLLER_GAIN:
            handle_controller_gain(ctx, payload, len);
            break;
        case HUAYI_SVC_ENGINEERING_TEST:
            handle_eng_test(payload, len);
            break;
        case HUAYI_SVC_SET_COMM_PARAMS:
            if (len >= 1U && ctx->cfg != NULL) {
                config_set_node_id(ctx->cfg, payload[0]);
                if (len >= 2U && payload[1] == 0x01U) {
                    config_persist(ctx->cfg);
                }
                ctx->canard.node_id = ctx->cfg->base.can_node_id;
            }
            break;
        case CYPHAL_SVC_GET_INFO:
            handle_get_info(ctx, transfer);
            break;
        case CYPHAL_SVC_EXECUTE_COMMAND:
            handle_exec_cmd(ctx, transfer, payload, len);
            break;
        case CYPHAL_MSG_MOTOR_COMMAND:
            if (len >= 3U) {
                uint8_t mode = payload[0];
                int16_t sp = (int16_t)((uint16_t)payload[1] | ((uint16_t)payload[2] << 8));
                if (mode == 0U) {
                    motor_fsm_set_enabled(false);
                } else if (mode == 2U) {
                    motor_fsm_set_ctrl_mode(MOTOR_CTRL_FOC_SPEED);
                    motor_fsm_set_speed_rpm((float)sp);
                    motor_fsm_set_enabled(true);
                } else if (mode == 3U) {
                    motor_fsm_set_ctrl_mode(MOTOR_CTRL_FOC_POSITION);
                    motor_fsm_set_position_counts((int32_t)sp);
                    motor_fsm_set_enabled(true);
                }
            }
            break;
        default:
            break;
        }
    }
}
