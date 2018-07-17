#ifndef TMAPCOLLISIONWARP_H
#define TMAPCOLLISIONWARP_H

#include "collision/TMapCollisionBase.h"

class TMapCollisionWarp : public TMapCollisionBase
{
    public:
    TMapCollisionWarp();

    void init(char const *, u16, TLiveActor *actor);
    void setUp();
    void setUpTrans(JGeometry::TVec3<f32> const &);
    void remove();
};

#endif // TMAPCOLLISIONWARP_H