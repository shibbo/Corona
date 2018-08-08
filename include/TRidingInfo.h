#ifndef TRIDINGINFO_H
#define TRIDINGINFO_H

#include "JGeometry.h"
#include "types.h"
#include "actor/THItActor.h"

struct TRidingInfo
{
    THitActor* mHitActor; // _0
    JGeometry::TVec3<f32> mUnkVector; // _4
};

#endif // TRIDINGINFO_H