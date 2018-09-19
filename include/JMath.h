#ifndef JMATH_H
#define JMATH_H

#include "types.h"

void JMANewSinTable(u8);
void JMAEulerToQuat(s16, s16, s16, Quaternion *destQuat);
void JMAQuadLerp(Quaternion *, Quaternion *, f32, Quaternion *);
f32 JMAHermiteInterpolation(f32, f32, f32, f32, f32, f32, f32);

#endif // JMATH_H