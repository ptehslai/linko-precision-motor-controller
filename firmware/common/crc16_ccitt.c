#include "crc16_ccitt.h"

static uint16_t crc16_ccitt_byte(uint16_t crc, uint8_t data)
{
    crc ^= (uint16_t)data << 8;
    for (uint8_t i = 0; i < 8U; i++) {
        if ((crc & 0x8000U) != 0U) {
            crc = (uint16_t)((crc << 1) ^ 0x1021U);
        } else {
            crc <<= 1;
        }
    }
    return crc;
}

uint16_t crc16_ccitt(const uint8_t *data, uint32_t len, uint16_t seed)
{
    uint16_t crc = seed;
    if (data == NULL) {
        return crc;
    }
    for (uint32_t i = 0; i < len; i++) {
        crc = crc16_ccitt_byte(crc, data[i]);
    }
    return crc;
}
