#include <assert.h>
#include "ota_manager.h"

int main(void)
{
    ota_manager_boot_notify(true);
    ota_manager_runtime_tick(true, 0U);
    ota_manager_runtime_tick(true, 5000U);
    return 0;
}
