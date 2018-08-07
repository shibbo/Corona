#ifndef JPA_H
#define JPA_H

#include "JGeometry.h"
#include "types.h"

void JPAVecToRotaMtx(MtxPtr, JGeometry::TVec3<f32>, JGeometry::TVec3<f32>);
f32 JPAConvertFixToFloat(u16);

#endif // JPA_H