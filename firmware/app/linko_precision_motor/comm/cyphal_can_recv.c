#include "cyphal_can_recv.h"
#include "huayi_services.h"

static void rx_free_payload(CanardInstance *ins, CanardRxTransfer *transfer)
{
    if (ins == NULL || transfer == NULL || transfer->payload.data == NULL) {
        return;
    }
    ins->memory.deallocate(ins->memory.user_reference, transfer->payload.allocated_size, transfer->payload.data);
    transfer->payload.data = NULL;
}

void cyphal_can_poll_rx(cyphal_can_t *ctx, CanardMicrosecond now_usec)
{
    if (ctx == NULL) {
        return;
    }

    uint32_t id;
    uint8_t data[8];
    uint8_t len;

    while (can_lks_recv(ctx->can, &id, data, &len)) {
        struct CanardFrame frame = {
            .extended_can_id = id & 0x1FFFFFFFU,
            .payload = {.size = len, .data = data},
        };

        struct CanardRxTransfer transfer;
        struct CanardRxSubscription *subscription = NULL;
        int8_t result = canardRxAccept(&ctx->canard, now_usec, &frame, 0U, &transfer, &subscription);
        if (result == 1) {
            huayi_services_handle(ctx, &transfer);
            rx_free_payload(&ctx->canard, &transfer);
        }
    }
}

static int8_t cyphal_tx_handler(void *user, CanardMicrosecond deadline, struct CanardMutableFrame *frame)
{
    (void)deadline;
    cyphal_can_t *ctx = (cyphal_can_t *)user;
    if (ctx == NULL || frame == NULL) {
        return -1;
    }
    return can_lks_send(ctx->can, frame->extended_can_id, frame->payload.data,
                        (uint8_t)frame->payload.size)
               ? 1
               : 0;
}

void cyphal_can_poll_tx(cyphal_can_t *ctx, CanardMicrosecond now_usec)
{
    if (ctx == NULL) {
        return;
    }
    (void)canardTxPoll(&ctx->tx_queue, &ctx->canard, now_usec, ctx, cyphal_tx_handler, NULL, NULL);
}
