#ifndef TSPLINERAIL_H
#define TSPLINERAIL_H

#include "types.h"

#include "JGeometry.h"
#include "node/TGraphWeb.h"
#include "node/TSplinePath.h"

using namespace JGeometry;

class TSplineRail
{
    public:
    TSplineRail(TGraphWeb const *);

    void getPosAndRot(f32, TVec3<f32> *position, TVec3<f32> *rotation)

    TSplinePath* splinePath; // _0
    u32 _4;
};

#endif // TSPLINERAIL_H