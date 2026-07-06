#pragma once

#include <stdbool.h>
#include <stdint.h>

void ota_manager_boot_notify(bool startup_ok);
void ota_manager_runtime_tick(bool healthy, uint32_t now_ms);
bool ota_confirm_running_image(void);
