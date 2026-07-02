#pragma once
#include <stdbool.h>
void ota_manager_boot_notify(bool startup_ok);
bool ota_confirm_running_image(void);
