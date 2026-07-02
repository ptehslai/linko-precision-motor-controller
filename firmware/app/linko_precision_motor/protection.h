#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "adc_current.h"
#include "fault.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float vbus_v;
    float oc_timer_s;
    float stall_timer_s;
} protection_state_t;

void protection_init(protection_state_t *ps);
void protection_update(protection_state_t *ps, float vbus_v, const adc_current_t *adc,
                       float speed_rpm, float dt_s);

#ifdef __cplusplus
}
#endif
