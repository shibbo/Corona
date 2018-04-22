#ifndef MS_H
#define MS_H

#include "JGeometry.h"

using namespace JGeometry;

// a bunch of functions starting with "Ms" that I feel are important to document
float MsVECMag2(Vec *);
void MsVECNormalize(Vec *, Vec *);
bool MsIsInSight(TVec3<float> const &, float, TVec3<float> const &, float, float, float);
void MsMtxSetTRS(float *[4], float, float, float, float, float, float, float, float, float);
void MsMtxSetXYZRPH(float *[4], float, float, float, short, short, short);
void MsMtxSetRotRPH(float *[4], float, float, float);
void MsGetRotFromZaxis(TVec3<float> const &);

#endif // MS_H