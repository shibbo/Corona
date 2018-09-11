#ifndef TCAMERASHAKE_H
#define TCAMERASHAKE_H

#include "JGeometry.h"

enum EnumCamShakeMode
{
    Unknown3 = 0x3,
    Unknown5 = 0x5,
    Unknown9 = 0x9,
    Unknown11 = 0x11,
    Unknown18 = 0x18
};

class TCameraShake
{
    public:
    TCameraShake();

    void execShake(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> *, JGeometry::TVec3<f32> *);
    void keepShake(EnumCamShakeMode, f32);
    u32* getUseShakeData_();
    void startShake(EnumCamShakeMode, f32);

    u16 _0;
    u16 _2;
    u32 _4;
    u8 _8;
    u8 _9;
    u16 _A;
    u16 _C;
    u16 _E; // padding?
    f32 _10;
    f32 _14;
    u16 _18;
    u16 _1A; // padding?
    f32 _1C;
    f32 _20;
    u16 _24;
    u16 _26; // padding?
    f32 _28;
    f32 _2C;
    u16 _30;
    u16 _32; // padding?
    u8 _34[0x0x6A8-0x34];
};

#endif // TCAMERASHAKE_H