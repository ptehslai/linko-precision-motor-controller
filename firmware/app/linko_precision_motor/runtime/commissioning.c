#include "commissioning.h"
#include "config.h"
#include "joint_axis.h"
#include "motor_fsm.h"
#include "config_generated.h"

static comm_step_t s_step = COMM_STEP_IDLE;
static float s_timer;
static runtime_config_t *s_cfg;
static joint_axis_t *s_joint;
static int32_t s_repeat_start_pos;
static int32_t s_repeat_max_err;

void commissioning_init(void)
{
    s_step = COMM_STEP_IDLE;
    s_timer = 0.0f;
    s_cfg = NULL;
    s_joint = NULL;
    s_repeat_max_err = 0;
}

void commissioning_bind(runtime_config_t *cfg, joint_axis_t *joint)
{
    s_cfg = cfg;
    s_joint = joint;
}

void commissioning_start_rl_id(void)
{
    s_step = COMM_STEP_RL_ID;
    s_timer = 0.0f;
    motor_fsm_set_ctrl_mode(MOTOR_CTRL_TRAP_BRINGUP);
    motor_fsm_set_speed_rpm(30.0f);
    motor_fsm_set_enabled(true);
}

void commissioning_start_enc_align(void)
{
    s_step = COMM_STEP_ENC_ALIGN;
    s_timer = 0.0f;
    motor_fsm_set_ctrl_mode(MOTOR_CTRL_TRAP_BRINGUP);
    motor_fsm_set_speed_rpm(5.0f);
    motor_fsm_set_enabled(true);
}

void commissioning_start_repeatability(void)
{
    s_step = COMM_STEP_REPEATABILITY;
    s_timer = 0.0f;
    s_repeat_max_err = 0;
    if (s_joint != NULL) {
        s_repeat_start_pos = joint_axis_get_output_position(s_joint);
    }
    motor_fsm_set_ctrl_mode(MOTOR_CTRL_FOC_POSITION);
    motor_fsm_set_position_counts(s_repeat_start_pos + 10000);
    motor_fsm_set_enabled(true);
}

comm_step_t commissioning_get_step(void)
{
    return s_step;
}

bool commissioning_step(float dt_s)
{
    s_timer += dt_s;
    switch (s_step) {
    case COMM_STEP_RL_ID:
        if (s_timer > 2.0f) {
            if (s_cfg != NULL) {
                s_cfg->base.phase_resistance_ohm = CFG_MOTOR_PHASE_RESISTANCE_OHM;
                s_cfg->base.phase_inductance_mh = CFG_MOTOR_PHASE_INDUCTANCE_MH;
            }
            motor_fsm_set_ctrl_mode(MOTOR_CTRL_FOC_SPEED);
            motor_fsm_set_enabled(false);
            s_step = COMM_STEP_IDLE;
            return true;
        }
        break;
    case COMM_STEP_ENC_ALIGN:
        if (s_timer > 1.0f && s_cfg != NULL && s_joint != NULL) {
            s_cfg->base.joint_zero_offset = s_joint->motor_position_counts;
            s_joint->zero_offset_counts = s_cfg->base.joint_zero_offset;
            motor_fsm_set_ctrl_mode(MOTOR_CTRL_FOC_SPEED);
            motor_fsm_set_enabled(false);
            s_step = COMM_STEP_IDLE;
            return true;
        }
        break;
    case COMM_STEP_REPEATABILITY:
        if (s_joint != NULL) {
            int32_t err = joint_axis_get_output_position(s_joint) - s_repeat_start_pos;
            if (err < 0) {
                err = -err;
            }
            if (err > s_repeat_max_err) {
                s_repeat_max_err = err;
            }
        }
        if (s_timer > 3.0f) {
            motor_fsm_set_position_counts(s_repeat_start_pos);
            if (s_timer > 6.0f) {
                motor_fsm_set_enabled(false);
                s_step = COMM_STEP_IDLE;
                return true;
            }
        }
        break;
    default:
        break;
    }
    return false;
}
