#ifndef TRIDINGINFO_H
#define TRIDINGINFO_H

#include "JGeometry.h"
#include "types.h"
#include "actor/THItActor.h"

using namespace JGeometry;

struct TRidingInfo
{
    THitActor *hitActor; // _0
    TVec3<f32> unkVector; // _4
};

#endif // TRIDINGINFO_H