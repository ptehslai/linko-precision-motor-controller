#include "foc.h"

#include <math.h>

static const float k_sqrt3_2 = 0.8660254f;
static const float k_two_thirds = 0.6666667f;

void foc_park(float ia, float ib, float ic, float theta, float *id, float *iq)
{
    float i_alpha = k_two_thirds * (ia - 0.5f * ib - 0.5f * ic);
    float i_beta = k_two_thirds * (k_sqrt3_2 * ib - k_sqrt3_2 * ic);
    float c = cosf(theta);
    float s = sinf(theta);
    if (id != NULL) {
        *id = i_alpha * c + i_beta * s;
    }
    if (iq != NULL) {
        *iq = -i_alpha * s + i_beta * c;
    }
}

void foc_inv_park(float vd, float vq, float theta, float *valpha, float *vbeta)
{
    float c = cosf(theta);
    float s = sinf(theta);
    if (valpha != NULL) {
        *valpha = vd * c - vq * s;
    }
    if (vbeta != NULL) {
        *vbeta = vd * s + vq * c;
    }
}

void foc_run_current_loop(foc_state_t *st, float id_ref, float iq_ref, float kp, float ki, float dt_s)
{
    if (st == NULL || dt_s <= 0.0f) {
        return;
    }
    static float id_i;
    static float iq_i;

    float id_err = id_ref - st->id;
    float iq_err = iq_ref - st->iq;
    id_i += ki * id_err * dt_s;
    iq_i += ki * iq_err * dt_s;

    st->vd = kp * id_err + id_i;
    st->vq = kp * iq_err + iq_i;
}
