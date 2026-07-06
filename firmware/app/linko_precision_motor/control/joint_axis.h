#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "config.h"
#include "speed_loop.h"
#include "position_loop.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    speed_loop_t speed;
    position_loop_t position;
    int32_t zero_offset_counts;
    int32_t min_position;
    int32_t max_position;
    float gearbox_ratio;
    uint32_t encoder_cpr;
    int32_t motor_position_counts;
    int32_t output_position_counts;
    float output_rpm;
} joint_axis_t;

void joint_axis_init(joint_axis_t *axis, const runtime_config_t *cfg);
void joint_axis_update_encoder(joint_axis_t *axis, uint16_t raw_counts, float dt_s);
int32_t joint_axis_motor_to_output(const joint_axis_t *axis, int32_t motor_counts);
int32_t joint_axis_output_to_motor(const joint_axis_t *axis, int32_t output_counts);
bool joint_axis_clamp_setpoint(joint_axis_t *axis, int32_t *output_counts);
float joint_axis_get_output_rpm(const joint_axis_t *axis);
int32_t joint_axis_get_output_position(const joint_axis_t *axis);
float joint_axis_run_speed(joint_axis_t *axis, float rpm_cmd, float rpm_meas, float dt_s);
float joint_axis_run_position(joint_axis_t *axis, int32_t pos_cmd, int32_t pos_meas, float dt_s);

#ifdef __cplusplus
}
#endif
