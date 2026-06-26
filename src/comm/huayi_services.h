#pragma once

#include "cyphal_can.h"

#ifdef __cplusplus
extern "C" {
#endif

void huayi_services_handle(cyphal_can_t *ctx, const CanardRxTransfer *transfer);

#ifdef __cplusplus
}
#endif
