#include "boot_ota.h"

#include "config_generated.h"
#include "crc32_mpeg2.h"

#include <string.h>

#ifndef BUILD_HOST_TEST
#define OTA_META_FLASH_ADDR CFG_MEMORY_OTA_META_ADDR
#else
static ota_boot_meta_t s_host_meta;
#define OTA_META_FLASH_ADDR ((uintptr_t)&s_host_meta)
#endif

static uint32_t meta_crc(const ota_boot_meta_t *meta)
{
    ota_boot_meta_t tmp;
    tmp = *meta;
    tmp.crc32 = 0U;
    return crc32_mpeg2((const uint8_t *)&tmp, sizeof(tmp), 0U);
}

static bool boot_ota_meta_load(ota_boot_meta_t *out)
{
    if (out == NULL) {
        return false;
    }
    const ota_boot_meta_t *flash = (const ota_boot_meta_t *)(uintptr_t)OTA_META_FLASH_ADDR;
    *out = *flash;
    if (out->magic != OTA_META_MAGIC) {
        return false;
    }
    return out->crc32 == meta_crc(out);
}

bool boot_ota_vector_valid(uint32_t vector_table_addr)
{
    uint32_t sp = *(volatile uint32_t *)vector_table_addr;
    uint32_t pc = *(volatile uint32_t *)(vector_table_addr + 4U);

    if (sp < 0x20000000U || sp > 0x2000A000U) {
        return false;
    }
    if (pc < CFG_MEMORY_APP_SLOT_A_ADDR || pc >= (CFG_MEMORY_APP_SLOT_B_ADDR + CFG_MEMORY_APP_SLOT_SIZE)) {
        return false;
    }
    return true;
}

bool boot_ota_slot_crc_valid(uint32_t slot_base, uint32_t image_size, uint32_t expected_crc32)
{
    if (image_size == 0U || expected_crc32 == 0U) {
        return true;
    }
    if (slot_base < CFG_MEMORY_APP_SLOT_A_ADDR
        || (slot_base + image_size) > (CFG_MEMORY_APP_SLOT_B_ADDR + CFG_MEMORY_APP_SLOT_SIZE)) {
        return false;
    }
    uint32_t crc = crc32_mpeg2((const uint8_t *)(uintptr_t)slot_base, image_size, 0U);
    return crc == expected_crc32;
}

static bool boot_slot_ok(uint32_t slot_base, const ota_boot_meta_t *meta, ota_slot_t slot)
{
    if (!boot_ota_vector_valid(slot_base)) {
        return false;
    }
    if (strcmp(CFG_OTA_VERIFY_HASH, "crc32") != 0) {
        return true;
    }
    uint32_t size = (slot == OTA_SLOT_B) ? meta->slot_b_size : meta->slot_a_size;
    uint32_t crc = (slot == OTA_SLOT_B) ? meta->slot_b_crc32 : meta->slot_a_crc32;
    return boot_ota_slot_crc_valid(slot_base, size, crc);
}

uint32_t boot_ota_select_slot(void)
{
    ota_boot_meta_t meta;
    uint32_t slot_a = CFG_MEMORY_APP_SLOT_A_ADDR;
    uint32_t slot_b = CFG_MEMORY_APP_SLOT_B_ADDR;

    if (!boot_ota_meta_load(&meta)) {
        if (boot_ota_vector_valid(slot_a)) {
            return slot_a;
        }
        if (boot_ota_vector_valid(slot_b)) {
            return slot_b;
        }
        return slot_a;
    }

    uint32_t active = (meta.active_slot == OTA_SLOT_B) ? slot_b : slot_a;
    uint32_t pending = (meta.pending_slot == OTA_SLOT_B) ? slot_b : slot_a;

    if (meta.pending_slot <= OTA_SLOT_B && meta.confirmed == 0U) {
        if (boot_slot_ok(pending, &meta, meta.pending_slot)) {
            return pending;
        }
    }

    if (boot_slot_ok(active, &meta, meta.active_slot)) {
        return active;
    }
    if (boot_slot_ok(pending, &meta, meta.pending_slot)) {
        return pending;
    }
    if (boot_ota_vector_valid(slot_a)) {
        return slot_a;
    }
    return slot_b;
}
