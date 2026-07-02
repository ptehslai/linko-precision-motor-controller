#include "angle_source.h"
#include "hfi.h"
#include "smo.h"
#include "config_generated.h"

#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void angle_source_init(angle_source_t *as, uint8_t pole_pairs)
{
    if (as == NULL) {
        return;
    }
    as->active = ANGLE_SRC_ENCODER;
    as->enc_ok = true;
    as->elec_angle_rad = 0.0f;
    as->mech_angle_rad = 0.0f;
    as->speed_erpm = 0.0f;
    as->pole_pairs = pole_pairs;
}

void angle_source_set_encoder(angle_source_t *as, uint16_t raw_counts, uint32_t cpr, float speed_erpm)
{
    if (as == NULL || cpr == 0U) {
        return;
    }
    as->mech_angle_rad = (2.0f * (float)M_PI * (float)raw_counts) / (float)cpr;
    as->elec_angle_rad = as->mech_angle_rad * (float)as->pole_pairs;
    as->speed_erpm = speed_erpm;
    if (as->enc_ok) {
        as->active = ANGLE_SRC_ENCODER;
    }
}

void angle_source_set_enc_fault(angle_source_t *as, bool fault)
{
    if (as == NULL) {
        return;
    }
    as->enc_ok = !fault;
    if (fault && CFG_SENSORLESS_FALLBACK_ON_ENC_FAULT) {
        as->active = ANGLE_SRC_SMO;
    }
}

void angle_source_enable_sensorless(angle_source_t *as, bool enable)
{
    if (as == NULL) {
        return;
    }
    if (enable && CFG_SENSORLESS_ENABLED) {
        hfi_init((float)CFG_SENSORLESS_HFI_CARRIER_HZ, CFG_SENSORLESS_HFI_VOLTAGE_START_V);
        smo_init(CFG_SENSORLESS_SMO_PLL_KP, CFG_SENSORLESS_SMO_PLL_KI);
        as->active = ANGLE_SRC_HFI;
    } else if (!as->enc_ok && CFG_SENSORLESS_FALLBACK_ON_ENC_FAULT) {
        as->active = ANGLE_SRC_SMO;
    } else {
        as->active = ANGLE_SRC_ENCODER;
    }
}

float angle_source_get_elec(angle_source_t *as)
{
    if (as == NULL) {
        return 0.0f;
    }
    if (as->active == ANGLE_SRC_HFI) {
        return hfi_get_angle();
    }
    if (as->active == ANGLE_SRC_SMO) {
        return smo_get_angle();
    }
    return as->elec_angle_rad;
}

angle_source_kind_t angle_source_get_kind(const angle_source_t *as)
{
    return (as != NULL) ? as->active : ANGLE_SRC_ENCODER;
}
