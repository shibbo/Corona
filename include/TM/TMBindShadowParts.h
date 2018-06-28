#ifndef TMBINDSHADOWPARTS_H
#define TMBINDSHADOWPARTS_H

#include "J3D.h"
#include "actor/THitActor.h"

class TMBindShadowBody;

class TMBindShadowParts
{
    public:
    TMBindShadowParts(J3DModel *model, u8, TMBindShadowBody *shadowBody, f32);

    void calc(f32);

    f32 _0;
    u32 _4;
    u32 _8;
    u32 _C;
    u32 _10;
    u8 _14;
    u8 _15;
    u8 _16;
    u8 _17; // assumed padding for 0x18
};

#endif // TMBINDSHADOWPARTS_H