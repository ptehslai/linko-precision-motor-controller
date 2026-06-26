#include "cyphal_can_send.h"
#include "motor_status.h"
#include "cyphal_can_msg_list.h"
#include "version.h"
#include "config_generated.h"
#include "board.h"
#include "fault.h"
#include "motor_fsm.h"
#include <string.h>

static uint32_t s_last_hb;
static uint32_t s_last_status;
static CanardTransferID s_tid_hb;
static CanardTransferID s_tid_status;
static CanardTransferID s_tid_pkt1;
static CanardTransferID s_tid_pkt2;
static CanardTransferID s_tid_pkt3;

static bool publish_message(cyphal_can_t *ctx, enum CanardPriority priority, uint32_t subject_id,
                            const uint8_t *payload, uint8_t len, CanardTransferID *tid,
                            CanardMicrosecond now_usec)
{
    struct CanardTransferMetadata meta = {
        .priority = priority,
        .transfer_kind = CanardTransferKindMessage,
        .port_id = subject_id,
        .remote_node_id = CANARD_NODE_ID_UNSET,
        .transfer_id = *tid,
    };

    struct CanardPayload pl = {.size = len, .data = payload};
    int32_t pushed = canardTxPush(&ctx->tx_queue, &ctx->canard, 0, &meta, pl, now_usec, NULL);
    if (pushed > 0) {
        *tid = (CanardTransferID)((*tid + 1U) & CANARD_TRANSFER_ID_MAX);
        return true;
    }
    return false;
}

static bool publish_response(cyphal_can_t *ctx, uint32_t service_id, uint8_t remote_node_id,
                             CanardTransferID transfer_id, const uint8_t *payload, uint8_t len,
                             CanardMicrosecond now_usec)
{
    struct CanardTransferMetadata meta = {
        .priority = CanardPriorityNominal,
        .transfer_kind = CanardTransferKindResponse,
        .port_id = service_id,
        .remote_node_id = remote_node_id,
        .transfer_id = transfer_id,
    };
    struct CanardPayload pl = {.size = len, .data = payload};
    return canardTxPush(&ctx->tx_queue, &ctx->canard, 0, &meta, pl, now_usec, NULL) > 0;
}

void cyphal_send_service_status(cyphal_can_t *ctx, uint32_t service_id, uint8_t remote_node_id,
                                CanardTransferID transfer_id, uint8_t status)
{
    if (ctx == NULL) {
        return;
    }
    publish_response(ctx, service_id, remote_node_id, transfer_id, &status, 1U,
                     (CanardMicrosecond)sys_get_ms() * 1000ULL);
}

void cyphal_send_get_info_response(cyphal_can_t *ctx, uint8_t remote_node_id, CanardTransferID transfer_id)
{
    if (ctx == NULL) {
        return;
    }

    uint8_t buf[64];
    memset(buf, 0, sizeof(buf));
    buf[0] = 0U;
    buf[1] = 5U; /* protocol minor */
    buf[2] = 1U;
    buf[3] = 0U;
    buf[4] = FW_VERSION_MAJOR;
    buf[5] = FW_VERSION_MINOR;
    memcpy(&buf[12], CFG_META_BOARD_ID, strlen(CFG_META_BOARD_ID));

    publish_response(ctx, CYPHAL_SVC_GET_INFO, remote_node_id, transfer_id, buf, sizeof(buf),
                     (CanardMicrosecond)sys_get_ms() * 1000ULL);
}

void cyphal_can_publish_periodic(cyphal_can_t *ctx, uint32_t now_ms)
{
    if (ctx == NULL) {
        return;
    }

    CanardMicrosecond now_usec = (CanardMicrosecond)now_ms * 1000ULL;

    if ((now_ms - s_last_hb) >= 1000U) {
        cyphal_heartbeat_t hb = {
            .uptime = now_ms / 1000U,
            .health = 0U,
            .mode = 0U,
            .vendor_specific_code = 0U,
        };
        publish_message(ctx, CanardPriorityHigh, CYPHAL_MSG_HEARTBEAT, (const uint8_t *)&hb,
                        (uint8_t)sizeof(hb), &s_tid_hb, now_usec);
        s_last_hb = now_ms;
    }

    if ((now_ms - s_last_status) >= 10U) {
        uint8_t buf[16];
        uint8_t len = motor_status_pack(buf, sizeof(buf));
        publish_message(ctx, CanardPriorityNominal, CYPHAL_MSG_MOTOR_STATUS, buf, len, &s_tid_status,
                        now_usec);
        s_last_status = now_ms;
    }

    if (ctx->feedback_period_pkt1_ms > 0U
        && (now_ms - ctx->last_pkt1_ms) >= (uint32_t)ctx->feedback_period_pkt1_ms) {
        uint8_t mode = 0x31U;
        if (motor_fsm_get_state() == MOTOR_STATE_POSITION) {
            mode = 0x30U;
        } else if (!motor_fsm_is_enabled()) {
            mode = 0x00U;
        }
        huayi_status_pkt1_t p1 = {
            .status = mode,
            .error_status = (uint16_t)fault_get(),
        };
        publish_message(ctx, CanardPriorityNominal, HUAYI_MSG_STATUS_PKT1, (const uint8_t *)&p1,
                        (uint8_t)sizeof(p1), &s_tid_pkt1, now_usec);
        ctx->last_pkt1_ms = now_ms;
    }

    if (ctx->feedback_period_pkt2_ms > 0U
        && (now_ms - ctx->last_pkt2_ms) >= (uint32_t)ctx->feedback_period_pkt2_ms) {
        huayi_status_pkt2_t p2 = {
            .real_position = motor_status_get_position(),
            .real_speed = (int32_t)(motor_status_get_speed_rpm() * 10.0f),
        };
        publish_message(ctx, CanardPriorityNominal, HUAYI_MSG_STATUS_PKT2, (const uint8_t *)&p2,
                        (uint8_t)sizeof(p2), &s_tid_pkt2, now_usec);
        ctx->last_pkt2_ms = now_ms;
    }

    if (ctx->feedback_period_pkt3_ms > 0U
        && (now_ms - ctx->last_pkt3_ms) >= (uint32_t)ctx->feedback_period_pkt3_ms) {
        huayi_status_pkt3_t p3 = {
            .real_torque_current_ma = (int32_t)(motor_status_get_current_a() * 1000.0f),
            .drive_temperature_c = (int16_t)motor_status_get_temp_c(),
            .motor_temperature_c = (int16_t)motor_status_get_temp_c(),
        };
        publish_message(ctx, CanardPriorityNominal, HUAYI_MSG_STATUS_PKT3, (const uint8_t *)&p3,
                        (uint8_t)sizeof(p3), &s_tid_pkt3, now_usec);
        ctx->last_pkt3_ms = now_ms;
    }
}
