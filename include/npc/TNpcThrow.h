#ifndef TNPCTHROW_H
#define TNPCTHROW_H

#include "actor/THitActor.h"

class TNpcThrow
{
    public:
    void throwMario(THitActor *marioActor);

    float velocity; // _0
    float _4;
};

#endif // TNPCTHROW_H