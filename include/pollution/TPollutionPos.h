#ifndef TPOLLUTIONPOS_H
#define TPOLLUTIONPOS_H

#include "pollution/TPollutionLayer.h"

class TPollutionPos
{
    public:
    TPollutionPos();

    void init(TPollutionLayer *, f32, f32, u8 *, s32, s32);
    u32 worldToTexSize(f32) const;
    u32 worldToDepth(f32) const;
    bool isProhibit(s32, s32) const;
    bool isSame(s32, s32, f32) const;
    f32 getDepthWorld(s32, s32) const;
    s32 getEdgeDegree(s32, s32) const;

    u32 _0;
    u32 _4;
    u32 _8;
    u32 _C;
    f32 _10;
    f32 _14;
    f32 _18;
    u32 _1C;
    TPollutionLayer* pollutionLayer; // _20
};

#endif // TPOLLUTIONPOS_H