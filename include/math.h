#ifndef MATH_H
#define MATH_H

#include "types.h"

//f32 fabs(double);
f32 fabsf(f32);
f32 atan(f32);
f32 cos(f32);
f32 sin(f32);

#ifdef __cplusplus
extern "C" {
#endif

//f32 frexp(f32);
//f32 atan2(f32, f32);
f32 atanf(f32, f32);
f32 _inv_sqrtf(f32);
f32 acosf(f32);
f32 atan2f(f32, f32);
f32 tanf(f32);
f32 cosf(f32);
f32 sinf(f32);
f32 powf(f32);
f32 expf(f32);

u32 rand();

#ifdef __cplusplus
}
#endif

#endif // MATH_H