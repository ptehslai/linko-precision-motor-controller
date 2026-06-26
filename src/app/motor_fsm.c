#include "motor_fsm.h"
#include "fault.h"

static motor_state_t s_state = MOTOR_STATE_IDLE;
static bool s_enabled;
static float s_speed_cmd;
static int32_t s_pos_cmd;
static motor_control_mode_t s_ctrl_mode = MOTOR_CTRL_FOC_SPEED;

void motor_fsm_init(void)
{
    s_state = MOTOR_STATE_IDLE;
    s_enabled = false;
    s_speed_cmd = 0.0f;
    s_pos_cmd = 0;
}

void motor_fsm_set_enabled(bool en)
{
    if (fault_is_active()) {
        s_enabled = false;
        s_state = MOTOR_STATE_FAULT;
        return;
    }
    s_enabled = en;
    s_state = en ? MOTOR_STATE_SPEED : MOTOR_STATE_IDLE;
}

void motor_fsm_set_speed_rpm(float rpm)
{
    s_speed_cmd = rpm;
    if (s_enabled) {
        s_state = MOTOR_STATE_SPEED;
    }
}

void motor_fsm_set_position_counts(int32_t counts)
{
    s_pos_cmd = counts;
    if (s_enabled) {
        s_state = MOTOR_STATE_POSITION;
    }
}

void motor_fsm_set_ctrl_mode(motor_control_mode_t mode)
{
    s_ctrl_mode = mode;
}

bool motor_fsm_is_enabled(void)
{
    return s_enabled;
}

float motor_fsm_get_speed_rpm(void)
{
    return s_speed_cmd;
}

int32_t motor_fsm_get_position_counts(void)
{
    return s_pos_cmd;
}

motor_control_mode_t motor_fsm_get_ctrl_mode(void)
{
    return s_ctrl_mode;
}

motor_state_t motor_fsm_get_state(void)
{
    return s_state;
}

void motor_fsm_update(float dt_s)
{
    (void)dt_s;
    if (fault_is_active()) {
        s_state = MOTOR_STATE_FAULT;
        s_enabled = false;
    }
}
