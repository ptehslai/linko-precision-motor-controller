#include "observer/smo.h"

#include <math.h>

static float s_theta;
static float s_pll_int;

void smo_init(float pll_kp, float pll_ki)
{
    (void)pll_kp;
    (void)pll_ki;
    s_theta = 0.0f;
    s_pll_int = 0.0f;
}

void smo_update(float ialpha, float ibeta, float valpha, float vbeta, float dt_s)
{
    float est_alpha = valpha - 0.5f * ialpha;
    float est_beta = vbeta - 0.5f * ibeta;
    float err = est_alpha * sinf(s_theta) - est_beta * cosf(s_theta);
    s_pll_int += err * dt_s;
    s_theta += (err + s_pll_int) * dt_s;
}

float smo_get_angle(void)
{
    return s_theta;
}
