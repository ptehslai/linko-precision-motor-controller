#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void hfi_init(float carrier_hz, float inj_v);
void hfi_inject(float *vd, float *vq);
float hfi_get_angle(void);

#ifdef __cplusplus
}
#endif
