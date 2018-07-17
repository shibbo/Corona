#ifndef TMAPCOLLISIONSTATIC_H
#define TMAPCOLLISIONSTATIC_H

#include "collision/TMapCollisionBase.h"

class TMapCollisionStatic : public TMapCollisionBase
{
    public:
    TMapCollisionStatic();

    void init(char const *, u16, TLiveActor *actor);
    void setUp();
    void remove();

    TLiveActor* actor; // _60
};

#endif // TMAPCOLLISIONSTATIC_H