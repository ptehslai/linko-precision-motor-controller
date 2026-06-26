#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t bitrate_kbps;
} can_lks_t;

void can_lks_init(can_lks_t *can, uint32_t bitrate_kbps);
bool can_lks_send(can_lks_t *can, uint32_t id, const uint8_t *data, uint8_t len);
bool can_lks_recv(can_lks_t *can, uint32_t *id, uint8_t *data, uint8_t *len);
void can_lks_poll(can_lks_t *can);

#ifdef __cplusplus
}
#endif
