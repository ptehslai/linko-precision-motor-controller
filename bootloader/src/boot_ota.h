#pragma once

#include <stdint.h>
#include "ota_layout.h"

uint32_t boot_ota_select_slot(void);
bool boot_ota_vector_valid(uint32_t vector_table_addr);
bool boot_ota_slot_crc_valid(uint32_t slot_base, uint32_t image_size, uint32_t expected_crc32);
