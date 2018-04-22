#ifndef TSPLINERAIL_H
#define TSPLINERAIL_H

#include "JGeometry.h"
#include "node/TGraphWeb.h"

using namespace JGeometry;

class TSplineRail
{
    public:
    TSplineRail(TGraphWeb const *);

    void getPosAndRot(float, TVec3<float> *position, TVec3<float> *rotation)

    int _0; // TSplinePath*
    int _4;
};

#endif // TSPLINERAIL_H