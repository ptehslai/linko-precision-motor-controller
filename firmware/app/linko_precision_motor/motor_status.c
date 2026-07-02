#include "motor_status.h"

static float s_v;
static float s_i;
static float s_t;
static float s_rpm;
static int32_t s_pos;

void motor_status_set(float voltage_v, float current_a, float temp_c, float speed_rpm, int32_t position)
{
    s_v = voltage_v;
    s_i = current_a;
    s_t = temp_c;
    s_rpm = speed_rpm;
    s_pos = position;
}

uint8_t motor_status_pack(uint8_t *buf, uint8_t buflen)
{
    if (buf == NULL || buflen < 8U) {
        return 0U;
    }
    int16_t rpm10 = (int16_t)(s_rpm * 10.0f);
    buf[0] = (uint8_t)((uint16_t)rpm10 & 0xFFU);
    buf[1] = (uint8_t)(((uint16_t)rpm10 >> 8) & 0xFFU);
    buf[2] = (uint8_t)((uint32_t)s_pos & 0xFFU);
    buf[3] = (uint8_t)(((uint32_t)s_pos >> 8) & 0xFFU);
    buf[4] = (uint8_t)(((uint32_t)s_pos >> 16) & 0xFFU);
    buf[5] = (uint8_t)(((uint32_t)s_pos >> 24) & 0xFFU);
    buf[6] = (uint8_t)((int16_t)(s_i * 100.0f) & 0xFFU);
    buf[7] = (uint8_t)((uint16_t)(s_v * 10.0f) & 0xFFU);
    return 8U;
}

float motor_status_get_voltage_v(void) { return s_v; }
float motor_status_get_current_a(void) { return s_i; }
float motor_status_get_temp_c(void) { return s_t; }
float motor_status_get_speed_rpm(void) { return s_rpm; }
int32_t motor_status_get_position(void) { return s_pos; }
