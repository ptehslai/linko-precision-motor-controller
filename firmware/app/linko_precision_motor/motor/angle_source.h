#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ANGLE_SRC_ENCODER = 0,
    ANGLE_SRC_HFI = 1,
    ANGLE_SRC_SMO = 2,
} angle_source_kind_t;

typedef struct {
    angle_source_kind_t active;
    bool enc_ok;
    float elec_angle_rad;
    float mech_angle_rad;
    float speed_erpm;
    uint8_t pole_pairs;
} angle_source_t;

void angle_source_init(angle_source_t *as, uint8_t pole_pairs);
void angle_source_set_encoder(angle_source_t *as, uint16_t raw_counts, uint32_t cpr, float speed_erpm);
void angle_source_set_enc_fault(angle_source_t *as, bool fault);
void angle_source_enable_sensorless(angle_source_t *as, bool enable);
float angle_source_get_elec(angle_source_t *as);
angle_source_kind_t angle_source_get_kind(const angle_source_t *as);

#ifdef __cplusplus
}
#endif
