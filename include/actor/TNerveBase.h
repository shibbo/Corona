#ifndef TNERVEBASE_H
#define TNERVEBASE_H

#include "types.h"

// i've seen TLiveActor with this
template <typename T>
class TNerveBase
{
    public:
    TNerveBase();
    virtual ~TNerveBase();

    VTABLE; // _0
};

#endif // TNERVEBASE_H