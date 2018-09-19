#ifndef TRAILNODE_H
#define TRAILNODE_H

#include "types.h"

struct TRailNode
{
    u8* mPathName; // _0
    u16 _4;
    u16 mCount; // _6
    u16 _8;
    u16 _A;
    u16 mPitch; // _C
    u16 mYaw; // _E
    u16 mRoll; // _10
    u16 mSpeed; // _12
    u16 mConnectionIndices[8]; // _14
    f32 mDistances[8]; 
};

#endif // TRAILNODE