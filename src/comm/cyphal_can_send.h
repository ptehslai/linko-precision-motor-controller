#pragma once

#include "cyphal_can.h"
#include "canard.h"

#ifdef __cplusplus
extern "C" {
#endif

void cyphal_can_publish_periodic(cyphal_can_t *ctx, uint32_t now_ms);
void cyphal_send_get_info_response(cyphal_can_t *ctx, uint8_t remote_node_id, CanardTransferID transfer_id);
void cyphal_send_service_status(cyphal_can_t *ctx, uint32_t service_id, uint8_t remote_node_id,
                                CanardTransferID transfer_id, uint8_t status);

#ifdef __cplusplus
}
#endif
