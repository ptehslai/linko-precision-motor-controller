#include "observer/hfi.h"

#include <math.h>

static float s_angle;
static float s_carrier;
static float s_inj;

void hfi_init(float carrier_hz, float inj_v)
{
    s_carrier = 2.0f * 3.1415926f * carrier_hz;
    s_inj = inj_v;
    s_angle = 0.0f;
}

void hfi_inject(float *vd, float *vq)
{
    static float t;
    t += 0.0001f;
    float inj = s_inj * sinf(s_carrier * t);
    if (vd != NULL) {
        *vd += inj;
    }
    (void)vq;
}

float hfi_get_angle(void)
{
    return s_angle;
}
