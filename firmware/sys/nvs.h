#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "config_generated.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t node_id;
    float speed_kp;
    float speed_ki;
    float speed_kd;
    float position_kp;
    float position_ki;
    float position_kd;
    int32_t joint_zero_offset;
    uint32_t magic;
    uint32_t crc32;
} nvs_data_t;

#define NVS_MAGIC 0x4C504D43U /* "LPMC" */

bool nvs_load(nvs_data_t *out);
bool nvs_save(const nvs_data_t *in);
void nvs_fill_from_config(nvs_data_t *nvs, const app_config_t *cfg);

#ifdef __cplusplus
}
#endif
