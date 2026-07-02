#include "cyphal_can.h"
#include "cyphal_can_recv.h"
#include "cyphal_can_send.h"
#include "cyphal_can_msg_list.h"
#include "config_generated.h"
#include "o1heap.h"

static O1HeapInstance *s_heap;

static void *canard_alloc(void *user, size_t size)
{
    (void)user;
    return o1heapAllocate(s_heap, size);
}

static void canard_free(void *user, size_t size, void *ptr)
{
    (void)user;
    (void)size;
    o1heapFree(s_heap, ptr);
}

static void subscribe_request(cyphal_can_t *ctx, CanardPortID port, CanardRxSubscription *sub)
{
    (void)canardRxSubscribe(&ctx->canard, CanardTransferKindRequest, port, 64U,
                            CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC, sub);
}

bool cyphal_can_init(cyphal_can_t *ctx, can_lks_t *can, runtime_config_t *cfg, void *mem, size_t mem_size)
{
    if (ctx == NULL || can == NULL || cfg == NULL || mem == NULL) {
        return false;
    }

    s_heap = o1heapInit(mem, mem_size);
    if (s_heap == NULL) {
        return false;
    }

    struct CanardMemoryResource memory = {
        .user_reference = NULL,
        .allocate = canard_alloc,
        .deallocate = canard_free,
    };

    ctx->can = can;
    ctx->cfg = cfg;
    ctx->canard = canardInit(memory);
    ctx->canard.node_id = cfg->base.can_node_id;
    ctx->tx_queue = canardTxInit(64U, CANARD_MTU_CAN_CLASSIC, memory);

    ctx->feedback_period_pkt1_ms = (uint8_t)CFG_CAN_FEEDBACK_PERIOD_MS_PKT96;
    ctx->feedback_period_pkt2_ms = (uint8_t)CFG_CAN_FEEDBACK_PERIOD_MS_PKT97;
    ctx->feedback_period_pkt3_ms = (uint8_t)CFG_CAN_FEEDBACK_PERIOD_MS_PKT98;

    subscribe_request(ctx, HUAYI_SVC_SET_DRIVER, &ctx->sub_set_driver);
    subscribe_request(ctx, HUAYI_SVC_CLEAR_ERRORS, &ctx->sub_clear_errors);
    subscribe_request(ctx, HUAYI_SVC_CONFIG_FEEDBACK, &ctx->sub_config_feedback);
    subscribe_request(ctx, HUAYI_SVC_SET_MODE_SETPOINT, &ctx->sub_set_speed);
    subscribe_request(ctx, HUAYI_SVC_SET_SPEED_PID, &ctx->sub_set_pid);
    subscribe_request(ctx, HUAYI_SVC_SET_ACCEL_DECEL, &ctx->sub_set_accel);
    subscribe_request(ctx, HUAYI_SVC_SET_CONTOUR_SPEED, &ctx->sub_contour_speed);
    subscribe_request(ctx, HUAYI_SVC_SET_MAX_TORQUE, &ctx->sub_max_torque);
    subscribe_request(ctx, HUAYI_SVC_SET_CONTROLLER_GAIN, &ctx->sub_controller_gain);
    subscribe_request(ctx, HUAYI_SVC_ENGINEERING_TEST, &ctx->sub_eng_test);
    subscribe_request(ctx, HUAYI_SVC_SET_COMM_PARAMS, &ctx->sub_comm_params);
    subscribe_request(ctx, CYPHAL_SVC_GET_INFO, &ctx->sub_get_info);
    subscribe_request(ctx, CYPHAL_SVC_EXECUTE_COMMAND, &ctx->sub_exec_cmd);
    subscribe_request(ctx, CYPHAL_MSG_MOTOR_COMMAND, &ctx->sub_motor_cmd);
    return true;
}

void cyphal_can_update(cyphal_can_t *ctx, uint32_t now_ms)
{
    if (ctx == NULL) {
        return;
    }
    CanardMicrosecond now_usec = (CanardMicrosecond)now_ms * 1000ULL;
    cyphal_can_poll_rx(ctx, now_usec);
    cyphal_can_publish_periodic(ctx, now_ms);
    cyphal_can_poll_tx(ctx, now_usec);
}
