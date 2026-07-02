#pragma once

#include <stdint.h>

/* Standard Cyphal services / messages */
#define CYPHAL_SVC_GET_INFO             430U
#define CYPHAL_SVC_EXECUTE_COMMAND      435U
#define CYPHAL_MSG_HEARTBEAT            7509U
#define CYPHAL_MSG_MOTOR_COMMAND        145U
#define CYPHAL_MSG_MOTOR_STATUS         5001U

/* Huayi motor services */
#define HUAYI_SVC_SET_DRIVER            80U
#define HUAYI_SVC_CLEAR_ERRORS          81U
#define HUAYI_SVC_CONFIG_FEEDBACK       82U
#define HUAYI_SVC_SET_MODE_SETPOINT     83U
#define HUAYI_SVC_SET_ACCEL_DECEL       84U
#define HUAYI_SVC_SET_CONTOUR_SPEED     85U
#define HUAYI_SVC_SET_MAX_TORQUE        86U
#define HUAYI_SVC_SET_CONTROLLER_GAIN   87U
#define HUAYI_SVC_SET_SPEED_PID         88U
#define HUAYI_SVC_ENGINEERING_TEST      94U
#define HUAYI_SVC_SET_COMM_PARAMS       95U

/* Huayi feedback subjects */
#define HUAYI_MSG_STATUS_PKT1           96U
#define HUAYI_MSG_STATUS_PKT2           97U
#define HUAYI_MSG_STATUS_PKT3           98U

#pragma pack(push, 1)

typedef struct {
    uint32_t uptime;
    uint8_t  health;
    uint8_t  mode;
    uint8_t  vendor_specific_code;
} cyphal_heartbeat_t;

typedef struct {
    uint8_t status;
    uint16_t error_status;
} huayi_status_pkt1_t;

typedef struct {
    int32_t real_position;
    int32_t real_speed; /* 0.1 RPM */
} huayi_status_pkt2_t;

typedef struct {
    int32_t real_torque_current_ma;
    int16_t drive_temperature_c;
    int16_t motor_temperature_c;
} huayi_status_pkt3_t;

typedef struct {
    uint8_t mode;
    int16_t setpoint;
} cyphal_motor_command_req_t;

#pragma pack(pop)
