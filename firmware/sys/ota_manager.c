#include "ota_manager.h"
#include "nvs.h"

typedef struct {
    uint32_t slot;
    uint32_t pending;
    uint32_t confirmed;
    uint32_t crc;
} ota_state_t;

static ota_state_t s_state;

void ota_manager_boot_notify(bool startup_ok)
{
    if (!startup_ok && s_state.pending) {
        s_state.slot = 0U;
        s_state.pending = 0U;
    }
}

bool ota_confirm_running_image(void)
{
    s_state.confirmed = 1U;
    s_state.pending = 0U;
    return true;
}
