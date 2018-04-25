#ifndef JPA_H
#define JPA_H

#include "JGeometry.h"
#include "types.h"

using namespace JGeometry;

void JPAVecToRotaMtx(f32 *[4], TVec3<f32>, TVec3<f32>);
f32 JPAConvertFixToFloat(u16);

#endif // JPA_H