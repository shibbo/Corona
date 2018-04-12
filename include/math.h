#ifndef MATH_H
#define MATH_H

//float fabs(double);
float fabsf(float);
float atan(float);
float cos(float);
float sin(float);

#ifdef __cplusplus
extern "C" {
#endif

//float frexp(float);
//float atan2(float, float);
float atanf(float, float);
float _inv_sqrtf(float);
float acosf(float);
float atan2f(float, float);
float tanf(float);
float cosf(float);
float sinf(float);
float powf(float);
float expf(float);

int rand();

#ifdef __cplusplus
}
#endif

#endif // MATH_H