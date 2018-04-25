#ifndef TMAPOBJBALL_H
#define TMAPOBJBALL_H

#include "tmapobj/TMapObjGeneral.h"

class TMapObjBall : public TMapObjGeneral
{
    public:
    TMapObjBall(char const *name);

    f32 _148;
    f32 _14C;
    f32 _150;
    f32 _154;
    f32 _158;
    f32 _15C;
    f32 _160;
    f32 _164;
    f32 _168;
    f32 _16C;
    f32 _170;
    f32 _174;
    f32 _178;
    f32 _17C;
    f32 _180;
    f32 _184;
    f32 _188;
    f32 depth;
    f32 _190;
    u32 _194;
};

#endif // TMAPOBJBALL_H