#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    MOTOR_STATE_IDLE = 0,
    MOTOR_STATE_SPEED,
    MOTOR_STATE_POSITION,
    MOTOR_STATE_FAULT,
} motor_state_t;

typedef enum {
    MOTOR_CTRL_TRAP_BRINGUP = 0,
    MOTOR_CTRL_FOC_SPEED,
    MOTOR_CTRL_FOC_POSITION,
} motor_control_mode_t;

void motor_fsm_init(void);
void motor_fsm_set_enabled(bool en);
void motor_fsm_set_speed_rpm(float rpm);
void motor_fsm_set_position_counts(int32_t counts);
void motor_fsm_set_ctrl_mode(motor_control_mode_t mode);
bool motor_fsm_is_enabled(void);
float motor_fsm_get_speed_rpm(void);
int32_t motor_fsm_get_position_counts(void);
motor_control_mode_t motor_fsm_get_ctrl_mode(void);
motor_state_t motor_fsm_get_state(void);
void motor_fsm_update(float dt_s);

#ifdef __cplusplus
}
#endif
