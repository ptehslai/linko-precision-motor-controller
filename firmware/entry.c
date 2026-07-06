#include "hardware_probe.h"
#include "ota_manager.h"
#include "startup_protection.h"
#include "sys_diag.h"

#include "board.h"

int app_run_main(void);

int main(void)
{
    board_init();
    startup_protection_init();
    if (!startup_protection_run()) {
        sys_fault_halt("startup_protection");
    }

    hardware_probe_result_t probe = hardware_probe_run();
    if (!probe.ok && probe.required_failed) {
        sys_fault_halt("hardware_probe");
    }

    ota_manager_boot_notify(probe.ok);
    return app_run_main();
}
