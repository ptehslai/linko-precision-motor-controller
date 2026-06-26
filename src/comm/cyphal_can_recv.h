#pragma once

#include "cyphal_can.h"

#ifdef __cplusplus
extern "C" {
#endif

void cyphal_can_poll_rx(cyphal_can_t *ctx, CanardMicrosecond now_usec);
void cyphal_can_poll_tx(cyphal_can_t *ctx, CanardMicrosecond now_usec);

#ifdef __cplusplus
}
#endif
