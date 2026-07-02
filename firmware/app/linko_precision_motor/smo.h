#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void smo_init(float pll_kp, float pll_ki);
void smo_update(float ialpha, float ibeta, float valpha, float vbeta, float dt_s);
float smo_get_angle(void);

#ifdef __cplusplus
}
#endif
