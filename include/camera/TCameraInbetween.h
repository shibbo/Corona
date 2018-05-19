#ifndef TCAMERAINBETWEEN_H
#define TCAMERAINBETWEEN_H

#include "JGeometry.h"

using namespace JGeometry;

class TCameraInbetween
{
    public:
    TCameraInbetween();

    void execCameraInbetween(TVec3<f32> const &, TVec3<f32> const &, TVec3<f32> const &);
    void initCameraInbetween(TVec3<f32> const &, TVec3<f32> const &, TVec3<f32> const &);
    void startCameraInbetween(u32);
    void addMoveCameraAndMario(Vec const &);
    void warpPosAndAt(Vec const &, Vec const &);

    u32 _0;
    u32 _4;
    f32 _8;
    u16 _C;
    u16 _E;
    f32 _10;
    u16 _14;
    u16 _16;
    TVec3<f32> _18;
    TVec3<f32> _24;
    TVec3<f32> _30;
    u32 _3C;
    u32 _40;
    f32 _44;
};

#endif // TCAMERAINBETWEEN_H