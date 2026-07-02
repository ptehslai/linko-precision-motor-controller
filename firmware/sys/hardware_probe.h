#pragma once
#include <stdbool.h>
typedef struct {
    bool ok;
    bool required_failed;
    bool encoder_ok;
    bool adc_ok;
    bool can_ok;
} hardware_probe_result_t;
hardware_probe_result_t hardware_probe_run(void);
