#include "joint_axis.h"
#include "config_generated.h"
#include <stddef.h>

void joint_axis_init(joint_axis_t *axis, const runtime_config_t *cfg)
{
    if (axis == NULL || cfg == NULL) {
        return;
    }
    const app_config_t *b = config_get_base(cfg);
    speed_loop_init(&axis->speed, cfg->speed_kp, cfg->speed_ki, cfg->speed_kd,
                    b->rated_current_a, CFG_SPEED_LOOP_SPEED_FILTER_HZ, b->speed_loop_hz);
    position_loop_init(&axis->position, cfg->position_kp, cfg->position_ki, cfg->position_kd,
                       CFG_POSITION_LOOP_OUTPUT_RPM_MAX,
                       (float)CFG_POSITION_LOOP_PROFILE_ACCEL_RPM_S,
                       (float)CFG_POSITION_LOOP_PROFILE_DECEL_RPM_S);
    axis->zero_offset_counts = b->joint_zero_offset;
    axis->min_position = b->joint_min_position;
    axis->max_position = b->joint_max_position;
    axis->gearbox_ratio = b->gearbox_ratio;
    axis->encoder_cpr = b->encoder_counts_per_rev;
    axis->motor_position_counts = 0;
    axis->output_position_counts = 0;
    axis->output_rpm = 0.0f;
}

void joint_axis_update_encoder(joint_axis_t *axis, uint16_t raw_counts, float dt_s)
{
    if (axis == NULL || dt_s <= 0.0f) {
        return;
    }
    static int32_t prev_motor;
    static bool have_prev;

    int32_t motor = (int32_t)raw_counts;
    axis->motor_position_counts = motor;
    axis->output_position_counts = joint_axis_motor_to_output(axis, motor);

    if (have_prev) {
        int32_t delta = motor - prev_motor;
        if (delta > (int32_t)(axis->encoder_cpr / 2)) {
            delta -= (int32_t)axis->encoder_cpr;
        } else if (delta < -(int32_t)(axis->encoder_cpr / 2)) {
            delta += (int32_t)axis->encoder_cpr;
        }
        float motor_rpm = ((float)delta / (float)axis->encoder_cpr) * 60.0f / dt_s;
        axis->output_rpm = motor_rpm / axis->gearbox_ratio;
    }
    prev_motor = motor;
    have_prev = true;
}

int32_t joint_axis_motor_to_output(const joint_axis_t *axis, int32_t motor_counts)
{
    if (axis == NULL || axis->gearbox_ratio <= 0.0f) {
        return motor_counts;
    }
    return (int32_t)((float)motor_counts / axis->gearbox_ratio) - axis->zero_offset_counts;
}

int32_t joint_axis_output_to_motor(const joint_axis_t *axis, int32_t output_counts)
{
    if (axis == NULL) {
        return output_counts;
    }
    return (int32_t)((float)(output_counts + axis->zero_offset_counts) * axis->gearbox_ratio);
}

bool joint_axis_clamp_setpoint(joint_axis_t *axis, int32_t *output_counts)
{
    if (axis == NULL || output_counts == NULL) {
        return false;
    }
    bool clamped = false;
    if (axis->min_position != 0 && *output_counts < axis->min_position) {
        *output_counts = axis->min_position;
        clamped = true;
    }
    if (axis->max_position != 0 && *output_counts > axis->max_position) {
        *output_counts = axis->max_position;
        clamped = true;
    }
    return clamped;
}

float joint_axis_get_output_rpm(const joint_axis_t *axis)
{
    return (axis != NULL) ? axis->output_rpm : 0.0f;
}

int32_t joint_axis_get_output_position(const joint_axis_t *axis)
{
    return (axis != NULL) ? axis->output_position_counts : 0;
}

float joint_axis_run_speed(joint_axis_t *axis, float rpm_cmd, float rpm_meas, float dt_s)
{
    if (axis == NULL) {
        return 0.0f;
    }
    return speed_loop_update(&axis->speed, rpm_cmd, rpm_meas, dt_s);
}

float joint_axis_run_position(joint_axis_t *axis, int32_t pos_cmd, int32_t pos_meas, float dt_s)
{
    if (axis == NULL) {
        return 0.0f;
    }
    joint_axis_clamp_setpoint(axis, &pos_cmd);
    int32_t backlash = CFG_POSITION_LOOP_BACKLASH_COMP_COUNTS;
    if (backlash > 0) {
        int32_t err = pos_cmd - pos_meas;
        if (err > 0) {
            pos_cmd += backlash;
        } else if (err < 0) {
            pos_cmd -= backlash;
        }
    }
    return position_loop_update(&axis->position, (float)pos_cmd, (float)pos_meas, dt_s);
}
