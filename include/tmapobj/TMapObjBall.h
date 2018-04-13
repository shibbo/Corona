#ifndef TMAPOBJBALL_H
#define TMAPOBJBALL_H

#include "tmapobj/TMapObjGeneral.h"

class TMapObjBall : public TMapObjGeneral
{
    public:
    TMapObjBall(char const *name);

    float _148;
    float _14C;
    float _150;
    float _154;
    float _158;
    float _15C;
    float _160;
    float _164;
    float _168;
    float _16C;
    float _170;
    float _174;
    float _178;
    float _17C;
    float _180;
    float _184;
    float _188;
    float depth;
    float _190;
    int _194;
};

#endif // TMAPOBJBALL_H