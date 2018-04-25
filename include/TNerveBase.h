#ifndef TNERVEBASE_H
#define TNERVEBASE_H

#include "types.h"

// i've seen TLiveActor with this
template <typename T>
class TNerveBase
{
    public:
    TNerveBase();
    ~TNerveBase();

    u32* vtable; // _0
};

#endif // TNERVEBASE_H