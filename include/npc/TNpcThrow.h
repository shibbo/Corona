#ifndef TNPCTHROW_H
#define TNPCTHROW_H

#include "types.h"
#include "actor/THitActor.h"

class TNpcThrow
{
    public:
    void throwMario(THitActor *marioActor);

    f32 velocity; // _0
    f32 _4;
};

#endif // TNPCTHROW_H