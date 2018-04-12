#ifndef JPA_H
#define JPA_H

#include "JGeometry.h"

using namespace JGeometry;

void JPAVecToRotaMtx(float *[4], TVec3<float>, TVec3<float>);
float JPAConvertFixToFloat(short);

#endif // JPA_H