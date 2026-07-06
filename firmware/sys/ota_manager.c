#include "ota_manager.h"

#include "config_generated.h"
#include "crc32_mpeg2.h"
#include "lks_hal.h"
#include "ota_layout.h"

#include <string.h>

#ifndef BUILD_HOST_TEST
#define OTA_META_ADDR ((uintptr_t)CFG_MEMORY_OTA_META_ADDR)
#else
static ota_boot_meta_t s_host_meta;
#define OTA_META_ADDR ((uintptr_t)&s_host_meta)
#endif

static uint32_t ota_meta_crc(const ota_boot_meta_t *meta)
{
    ota_boot_meta_t tmp;
    memcpy(&tmp, meta, sizeof(tmp));
    tmp.crc32 = 0U;
    return crc32_mpeg2((const uint8_t *)&tmp, sizeof(tmp), 0U);
}

static bool ota_meta_load(ota_boot_meta_t *out)
{
    if (out == NULL) {
        return false;
    }
    memcpy(out, (const void *)OTA_META_ADDR, sizeof(*out));
    if (out->magic != OTA_META_MAGIC) {
        return false;
    }
    return out->crc32 == ota_meta_crc(out);
}

static bool ota_meta_save(const ota_boot_meta_t *in)
{
    if (in == NULL) {
        return false;
    }
    ota_boot_meta_t tmp;
    memcpy(&tmp, in, sizeof(tmp));
    tmp.magic = OTA_META_MAGIC;
    tmp.crc32 = ota_meta_crc(&tmp);
#ifdef BUILD_HOST_TEST
    memcpy((void *)OTA_META_ADDR, &tmp, sizeof(tmp));
    return true;
#else
    return hal_flash_write((uint32_t)OTA_META_ADDR, &tmp, sizeof(tmp));
#endif
}

void ota_manager_boot_notify(bool startup_ok)
{
    ota_boot_meta_t meta;
    if (!ota_meta_load(&meta)) {
        memset(&meta, 0, sizeof(meta));
        meta.magic = OTA_META_MAGIC;
        meta.active_slot = OTA_SLOT_A;
        meta.pending_slot = OTA_SLOT_A;
        meta.confirmed = 1U;
        ota_meta_save(&meta);
        return;
    }

    if (!startup_ok && CFG_OTA_ROLLBACK_ON_PROBE_FAIL && meta.confirmed == 0U) {
        meta.pending_slot = meta.active_slot;
        meta.confirmed = 1U;
        ota_meta_save(&meta);
    }
}

void ota_manager_runtime_tick(bool healthy, uint32_t now_ms)
{
    static uint32_t healthy_since_ms;
    static bool done;

    if (done) {
        return;
    }

    ota_boot_meta_t meta;
    if (!ota_meta_load(&meta)) {
        return;
    }
    if (meta.confirmed != 0U || meta.active_slot == meta.pending_slot) {
        done = true;
        return;
    }

    if (!healthy) {
        healthy_since_ms = 0U;
        return;
    }

    if (healthy_since_ms == 0U) {
        healthy_since_ms = now_ms;
    }

    if ((now_ms - healthy_since_ms) >= (uint32_t)CFG_OTA_CONFIRM_TIMEOUT_MS) {
        if (ota_confirm_running_image()) {
            done = true;
        }
    }
}

bool ota_confirm_running_image(void)
{
    ota_boot_meta_t meta;
    if (!ota_meta_load(&meta)) {
        return false;
    }
    meta.active_slot = meta.pending_slot;
    meta.confirmed = 1U;
    return ota_meta_save(&meta);
}
