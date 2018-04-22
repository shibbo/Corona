#ifndef TSPLINERAIL_H
#define TSPLINERAIL_H

#include "JGeometry.h"
#include "node/TGraphWeb.h"
#include "node/TSplinePath.h"

using namespace JGeometry;

class TSplineRail
{
    public:
    TSplineRail(TGraphWeb const *);

    void getPosAndRot(float, TVec3<float> *position, TVec3<float> *rotation)

    TSplinePath* splinePath; // _0
    int _4;
};

#endif // TSPLINERAIL_H