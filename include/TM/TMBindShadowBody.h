#ifndef TMBINDSHADOWBODY_H
#define TMBINDSHADOWBODY_H

#include "J3D.h"
#include "actor/THitActor.h"
#include "TM/TMBindShadowParts.h"

class TBindShadowBody
{
    public:
    TBindShadowBody(THitActor *, J3DModel, f32);

    void entryDrawShadow();

    TMBindShadowParts* shadowParts; // _0
    THitActor* hitActor; // _4
    u32 _8;
    f32 _10;
    f32 _14;
    f32 _18;

};

#endif // TMBINDSHADOWBODY_H