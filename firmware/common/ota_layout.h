#pragma once

#include <stdint.h>

/* Shared OTA boot metadata — flash addresses come from generated config. */
#include "config_generated.h"

#define OTA_META_MAGIC 0x4F544142U /* "OTAB" */

typedef enum {
    OTA_SLOT_A = 0U,
    OTA_SLOT_B = 1U,
} ota_slot_t;

typedef struct {
    uint32_t magic;
    uint32_t active_slot;
    uint32_t pending_slot;
    uint32_t confirmed;
    uint32_t slot_a_crc32;
    uint32_t slot_b_crc32;
    uint32_t slot_a_size;
    uint32_t slot_b_size;
    uint32_t crc32;
} ota_boot_meta_t;

static inline uint32_t ota_slot_base(ota_slot_t slot)
{
    return (slot == OTA_SLOT_B) ? CFG_MEMORY_APP_SLOT_B_ADDR : CFG_MEMORY_APP_SLOT_A_ADDR;
}
