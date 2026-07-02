#include "nvs.h"
#include "crc32_mpeg2.h"
#include "lks_hal.h"
#include "config_generated.h"

#include <string.h>
#include <stdint.h>

#ifndef BUILD_HOST_TEST
#define NVS_FLASH_ADDR ((volatile uint32_t *)CFG_MEMORY_NVS_FLASH_ADDR)
#else
static uint32_t s_nvs_page[64];
#define NVS_FLASH_ADDR s_nvs_page
#endif

static uint32_t nvs_crc(const nvs_data_t *d)
{
    nvs_data_t tmp;
    memcpy(&tmp, d, sizeof(tmp));
    tmp.crc32 = 0U;
    return crc32_mpeg2((const uint8_t *)&tmp, sizeof(tmp), 0U);
}

bool nvs_load(nvs_data_t *out)
{
    if (out == NULL) {
        return false;
    }
    memcpy(out, (const void *)NVS_FLASH_ADDR, sizeof(*out));
    if (out->magic != NVS_MAGIC) {
        return false;
    }
    uint32_t crc = out->crc32;
    return crc == nvs_crc(out);
}

bool nvs_save(const nvs_data_t *in)
{
    if (in == NULL) {
        return false;
    }
    nvs_data_t tmp;
    memcpy(&tmp, in, sizeof(tmp));
    tmp.magic = NVS_MAGIC;
    tmp.crc32 = nvs_crc(&tmp);
#ifdef BUILD_HOST_TEST
    memcpy(s_nvs_page, &tmp, sizeof(tmp));
    return true;
#else
    return hal_flash_write((uint32_t)(uintptr_t)NVS_FLASH_ADDR, &tmp, sizeof(tmp));
#endif
}

void nvs_fill_from_config(nvs_data_t *nvs, const app_config_t *cfg)
{
    if (nvs == NULL || cfg == NULL) {
        return;
    }
    memset(nvs, 0, sizeof(*nvs));
    nvs->node_id = cfg->can_node_id;
    nvs->joint_zero_offset = cfg->joint_zero_offset;
    nvs->speed_kp = CFG_SPEED_LOOP_PID_KP;
    nvs->speed_ki = CFG_SPEED_LOOP_PID_KI;
    nvs->speed_kd = CFG_SPEED_LOOP_PID_KD;
    nvs->position_kp = CFG_POSITION_LOOP_PID_KP;
    nvs->position_ki = CFG_POSITION_LOOP_PID_KI;
    nvs->position_kd = CFG_POSITION_LOOP_PID_KD;
}
