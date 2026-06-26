#include "can_lks.h"
#include "lks_hal.h"

void can_lks_init(can_lks_t *can, uint32_t bitrate_kbps)
{
    if (can == NULL) {
        return;
    }
    can->bitrate_kbps = bitrate_kbps;
    hal_can_init(bitrate_kbps);
}

bool can_lks_send(can_lks_t *can, uint32_t id, const uint8_t *data, uint8_t len)
{
    (void)can;
    return hal_can_send(id, data, len);
}

bool can_lks_recv(can_lks_t *can, uint32_t *id, uint8_t *data, uint8_t *len)
{
    (void)can;
    return hal_can_recv(id, data, len);
}

void can_lks_poll(can_lks_t *can)
{
    (void)can;
}
