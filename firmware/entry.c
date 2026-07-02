#include "startup_protection.h"
#include "hardware_probe.h"
#include "ota_manager.h"

int app_run_main(void);

int main(void)
{
    startup_protection_init();
    if (!startup_protection_run()) {
        for(;;){}
    }
    hardware_probe_result_t probe = hardware_probe_run();
    if (!probe.ok && probe.required_failed) {
        for(;;){}
    }
    ota_manager_boot_notify(probe.ok);
    return app_run_main();
}
