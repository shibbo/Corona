#ifndef TMAPCOLLISIONMOVE_H
#define TMAPCOLLISIONMOVE_H

#include "collision/TMapCollisionBase.h"

class TMapCollisionMove : public TMapCollisionBase
{
    public:
    TMapCollisionMove();

    void init(char const *, u16, TLiveActor *actor);
    void moveSRT(JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &);
    void moveTrans(JGeometry::TVec3<f> const &);
    void moveMtx(MtxPtr);

    void move();
    void setList();
};

#endif // TMAPCOLLISIONMOVE_H