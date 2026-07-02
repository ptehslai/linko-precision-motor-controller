#include "startup_protection.h"
#include "lks_hal.h"
#include "fault.h"

void startup_protection_init(void)
{
    hal_mcpwm_enable(false);
    fault_clear_all();
}

bool startup_protection_run(void)
{
    return fault_get() == FAULT_NONE;
}
