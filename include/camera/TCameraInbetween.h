#ifndef TCAMERAINBETWEEN_H
#define TCAMERAINBETWEEN_H

#include "JGeometry.h"

class TCameraInbetween
{
    public:
    TCameraInbetween();

    void execCameraInbetween(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &);
    void initCameraInbetween(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &);
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
    JGeometry::TVec3<f32> _18;
    JGeometry::TVec3<f32> _24;
    JGeometry::TVec3<f32> _30;
    u32 _3C;
    u32 _40;
    f32 _44;
};

#endif // TCAMERAINBETWEEN_H