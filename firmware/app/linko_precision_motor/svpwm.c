#include "svpwm.h"

#include <math.h>

float svpwm_clamp_mod(float m)
{
    if (m > 0.95f) {
        return 0.95f;
    }
    if (m < -0.95f) {
        return -0.95f;
    }
    return m;
}

void svpwm_calc(float valpha, float vbeta, float vbus, svpwm_out_t *out)
{
    if (out == NULL || vbus <= 0.0f) {
        return;
    }

    float va = valpha;
    float vb = (-0.5f * valpha + 0.8660254f * vbeta);
    float vc = (-0.5f * valpha - 0.8660254f * vbeta);

    float vmax = fmaxf(va, fmaxf(vb, vc));
    float vmin = fminf(va, fminf(vb, vc));
    float voffset = 0.5f * (vmax + vmin);

    out->ua = (va - voffset) / vbus + 0.5f;
    out->ub = (vb - voffset) / vbus + 0.5f;
    out->uc = (vc - voffset) / vbus + 0.5f;
}
