#include <assert.h>
#include "ota_manager.h"
int main(void){ ota_manager_boot_notify(true); assert(ota_confirm_running_image()); return 0; }
