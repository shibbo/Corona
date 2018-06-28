#ifndef TSPINEBASE_H
#define TSPINEBASE_H

#include "actor/TLiveActor.h"
#include "actor/TNerveBase.h"

template <typename T>
class TSpineBase
{
    public:
    ~TSpineBase();

    void update();
    void pushNerve(TNerveBase<TLiveActor> const *);
    u32* getLatestNerve() const;

    VTABLE; // _0
    u8 _4[0x14-0x4];
    TNerveBase* nerveBase; // _14
    
};

#endif // TSPINEBASE_H