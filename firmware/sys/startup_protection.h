#pragma once

#include <stdbool.h>

void startup_protection_init(void);
bool startup_protection_run(void);
void startup_protection_release_can(void);
bool startup_protection_can_allowed(void);
