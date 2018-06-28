#ifndef TRIDINGINFO_H
#define TRIDINGINFO_H

#include "JGeometry.h"
#include "types.h"
#include "actor/THItActor.h"

struct TRidingInfo
{
    THitActor *hitActor; // _0
    JGeometry::TVec3<f32> unkVector; // _4
};

#endif // TRIDINGINFO_H