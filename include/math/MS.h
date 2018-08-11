#ifndef MS_H
#define MS_H

#include "JGeometry.h"
#include "types.h"

// a bunch of functions starting with "Ms" that I feel are important to document
f32 MsVECMag2(Vec *);
f32 MsSqrtf(f32 val);
void MsVECNormalize(Vec *, Vec *);
bool MsIsInSight(JGeometry::TVec3<f32> const &, f32, JGeometry::TVec3<f32> const &, f32, f32, f32);
void MsMtxSetTRS(MtxPtr, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void MsMtxSetXYZRPH(MtxPtr, f32, f32, f32, u16, u16, u16);
void MsMtxSetRotRPH(MtxPtr, f32, f32, f32);
void MsGetRotFromZaxis(JGeometry::TVec3<f32> const &);

f32 FConverge(f32, f32, f32, f32);
int IConverge(int, int, int, int);

template<typename T>
T MsWrap(T, T, T);

#endif // MS_H