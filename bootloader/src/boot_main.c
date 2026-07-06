#include "boot_jump.h"
#include "boot_ota.h"

#include "config_generated.h"

int main(void)
{
    uint32_t app_base = boot_ota_select_slot();

    if (!boot_ota_vector_valid(app_base)) {
        uint32_t fallback = (app_base == CFG_MEMORY_APP_SLOT_A_ADDR)
                                ? CFG_MEMORY_APP_SLOT_B_ADDR
                                : CFG_MEMORY_APP_SLOT_A_ADDR;
        if (boot_ota_vector_valid(fallback)) {
            app_base = fallback;
        } else {
            for (;;) {
            }
        }
    }

    boot_jump_to_app(app_base);
    for (;;) {
    }
}
