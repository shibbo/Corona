#ifndef TRAILNODE_H
#define TRAILNODE_H

#include "types.h"

struct TRailNode
{
    u8* pathName; // _0
    u16 _4;
    u16 count; // _6
    u16 _8;
    u16 _A;
    u16 pitch; // _C
    u16 yaw; // _E
    u16 roll; // _10
    u16 speed; // _12
    u16 cPoints[8]; // _14
    f32 pPoints[8]; 
};

#endif // TRAILNODE