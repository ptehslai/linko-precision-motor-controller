#include "board.h"
#include "version.h"
#include "config.h"
#include "can_lks.h"
#include "cyphal_can.h"
#include "encoder_kth7816.h"
#include "adc_current.h"
#include "mcpwm_motor.h"
#include "joint_axis.h"
#include "angle_source.h"
#include "foc.h"
#include "svpwm.h"
#include "trap_commutation.h"
#include "motor_fsm.h"
#include "fault.h"
#include "commissioning.h"
#include "protection.h"
#include "motor_status.h"
#include "lks_hal.h"
#include "config_generated.h"
#include "board_pins.h"
#include "observer/smo.h"

static runtime_config_t g_cfg;
static can_lks_t g_can;
static cyphal_can_t g_cyphal;
static encoder_kth7816_t g_enc;
static adc_current_t g_adc;
static joint_axis_t g_joint;
static angle_source_t g_angle;
static foc_state_t g_foc;
static trap_state_t g_trap;
static protection_state_t g_prot;
static uint8_t g_canard_mem[4096];

int main(void)
{
    board_init();
    hal_uart_init(115200U);
    hal_uart_write(CFG_META_FIRMWARE_BANNER " " FW_VERSION_STRING " " CFG_META_BOARD_ID "\r\n");

    config_init(&g_cfg);
    fault_init();
    protection_init(&g_prot);
    motor_fsm_init();
    commissioning_init();

    can_lks_init(&g_can, g_cfg.base.can_bitrate_kbps);
    cyphal_can_init(&g_cyphal, &g_can, &g_cfg, g_canard_mem, sizeof(g_canard_mem));

    encoder_kth7816_init(&g_enc, g_cfg.base.ssi_clock_hz);
    adc_current_init(&g_adc, CFG_HARDWARE_SHUNT_RESISTANCE_OHM, CFG_HARDWARE_SHUNT_AMP_GAIN);
    mcpwm_motor_init((uint32_t)g_cfg.base.foc_pwm_hz);
    joint_axis_init(&g_joint, &g_cfg);
    angle_source_init(&g_angle, g_cfg.base.pole_pairs);
    angle_source_enable_sensorless(&g_angle, g_cfg.base.sensorless_enabled != 0U);
    trap_commutation_init(&g_trap);
    commissioning_bind(&g_cfg, &g_joint);

    g_foc.pole_pairs = g_cfg.base.pole_pairs;
    g_foc.vbus = g_cfg.base.rated_voltage_v;

    config_print(&g_cfg);

    uint32_t last_ms = sys_get_ms();

    while (1) {
        uint32_t now = sys_get_ms();
        float dt = (float)(now - last_ms) * 0.001f;
        if (dt <= 0.0f) {
            continue;
        }
        last_ms = now;

        uint16_t enc_raw;
        if (encoder_kth7816_read(&g_enc, &enc_raw)) {
            joint_axis_update_encoder(&g_joint, enc_raw, dt);
            float erpm = joint_axis_get_output_rpm(&g_joint) * (float)g_cfg.base.pole_pairs * g_cfg.base.gearbox_ratio;
            angle_source_set_encoder(&g_angle, enc_raw, g_cfg.base.encoder_counts_per_rev, erpm);
            if (fault_get() == FAULT_ENCODER) {
                fault_clear();
            }
        } else {
            angle_source_set_enc_fault(&g_angle, true);
            fault_set(FAULT_ENCODER);
        }

        uint16_t raw_vbus = hal_adc_read(ADC_CH_VBUS);
        float vbus = ((float)raw_vbus / 4095.0f) * 3.3f * CFG_HARDWARE_VBUS_DIVIDER_RATIO;
        g_foc.vbus = vbus;

        adc_current_sample(&g_adc, hal_adc_read(ADC_CH_IA), hal_adc_read(ADC_CH_IB), hal_adc_read(ADC_CH_IC));
        protection_update(&g_prot, vbus, &g_adc, joint_axis_get_output_rpm(&g_joint), dt);

        g_foc.elec_angle_rad = angle_source_get_elec(&g_angle);
        float iq_ref = 0.0f;

        if (motor_fsm_is_enabled() && !fault_is_active()) {
            if (motor_fsm_get_state() == MOTOR_STATE_SPEED) {
                iq_ref = joint_axis_run_speed(&g_joint, motor_fsm_get_speed_rpm(),
                                              joint_axis_get_output_rpm(&g_joint), dt);
            } else if (motor_fsm_get_state() == MOTOR_STATE_POSITION) {
                float rpm = joint_axis_run_position(&g_joint, motor_fsm_get_position_counts(),
                                                    joint_axis_get_output_position(&g_joint), dt);
                iq_ref = joint_axis_run_speed(&g_joint, rpm, joint_axis_get_output_rpm(&g_joint), dt);
            }

            float torque_scale = (float)g_cfg.base.joint_max_torque_pct / 1000.0f;
            if (torque_scale > 0.0f && torque_scale < 1.0f) {
                iq_ref *= torque_scale;
            }

            if (motor_fsm_get_ctrl_mode() == MOTOR_CTRL_TRAP_BRINGUP) {
                trap_commutation_step(&g_trap, g_foc.elec_angle_rad, 0.15f);
                trap_commutation_apply(&g_trap, 0U, 1U, 2U);
            } else {
                foc_park(g_adc.ia, g_adc.ib, g_adc.ic, g_foc.elec_angle_rad, &g_foc.id, &g_foc.iq);
                if (angle_source_get_kind(&g_angle) == ANGLE_SRC_SMO) {
                    float valpha, vbeta;
                    foc_inv_park(g_foc.vd, g_foc.vq, g_foc.elec_angle_rad, &valpha, &vbeta);
                    smo_update(g_adc.ia, g_adc.ib, valpha, vbeta, dt);
                }
                foc_run_current_loop(&g_foc, 0.0f, iq_ref, g_cfg.current_q_kp, g_cfg.current_q_ki, dt);
                float va, vb;
                foc_inv_park(g_foc.vd, g_foc.vq, g_foc.elec_angle_rad, &va, &vb);
                svpwm_out_t pwm;
                svpwm_calc(va, vb, g_foc.vbus, &pwm);
                mcpwm_motor_set_svpwm(pwm.ua, pwm.ub, pwm.uc);
            }
        } else {
            mcpwm_motor_enable(false);
        }

        motor_status_set(g_foc.vbus, g_foc.iq, 25.0f, joint_axis_get_output_rpm(&g_joint),
                         joint_axis_get_output_position(&g_joint));
        motor_fsm_update(dt);
        commissioning_step(dt);
        cyphal_can_update(&g_cyphal, now);
    }

    return 0;
}
