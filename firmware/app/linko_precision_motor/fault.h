#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    FAULT_NONE = 0,
    FAULT_UNDERVOLT = 1,
    FAULT_OVERVOLT = 2,
    FAULT_OVERCURRENT = 3,
    FAULT_ENCODER = 4,
    FAULT_STALL = 5,
    FAULT_EMERGENCY = 6,
} fault_code_t;

void fault_init(void);
void fault_set(fault_code_t code);
void fault_clear(void);
void fault_clear_all(void);
bool fault_is_active(void);
fault_code_t fault_get(void);

#ifdef __cplusplus
}
#endif
