#include "startup_protection.h"

#include "board.h"
#include "board_pins.h"
#include "config_generated.h"
#include "fault.h"
#include "lks_hal.h"

#include <string.h>

static bool s_can_allowed;

static float startup_read_vbus_v(void)
{
    uint16_t raw = hal_adc_read(ADC_CH_VBUS);
    return ((float)raw / 4095.0f) * CFG_HARDWARE_ADC_REF_V * CFG_HARDWARE_VBUS_DIVIDER_RATIO;
}

void startup_protection_init(void)
{
    hal_mcpwm_enable(false);
    fault_clear_all();
    s_can_allowed = (CFG_STARTUP_PROTECTION_CAN_QUIET_MODE == 0);
}

bool startup_protection_run(void)
{
    if (CFG_STARTUP_PROTECTION_SAFE_OUTPUT_DEFAULT) {
        hal_mcpwm_enable(false);
    }

    if (CFG_STARTUP_PROTECTION_WATCHDOG_ENABLE) {
#ifdef LKS_SDK_LINK
        /* Watchdog policy placeholder — enable IWDG when board profile defines timeout. */
#endif
    }

    float vbus = startup_read_vbus_v();
    if (vbus > 0.1f && vbus < CFG_STARTUP_PROTECTION_BROWNOUT_GUARD_V) {
        fault_set(FAULT_UNDERVOLT);
        return false;
    }
    if (vbus > CFG_PROTECTION_OVERVOLTAGE_V) {
        fault_set(FAULT_OVERVOLT);
        return false;
    }

    return fault_get() == FAULT_NONE;
}

void startup_protection_release_can(void)
{
    s_can_allowed = true;
}

bool startup_protection_can_allowed(void)
{
    return s_can_allowed;
}
