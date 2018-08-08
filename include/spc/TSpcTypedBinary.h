#ifndef TSPCTYPEDBINARY_H
#define TSPCTYPEDBINARY_H

#include "actor/TLiveActor.h"
#include "spc/TSpcBinary.h"
#include "spc/TSpcTypedInterp.h"

template<typename T>
class TSpcTypedBinary : public TSpcBinary
{
    public:
    virtual ~TSpcTypedBinary();

    virtual void initUserBuiltin();
};

void linPushNerve(TSpcTypedInterp<TLiveActor> *, u32);
void linSetBck(TSpcTypedInterp<TLiveActor> *, u32);
void linSetBpk(TSpcTypedInterp<TLiveActor> *, u32);
void linSetBtp(TSpcTypedInterp<TLiveActor> *, u32);
void linSetBtk(TSpcTypedInterp<TLiveActor> *, u32);
void linSetBlk(TSpcTypedInterp<TLiveActor> *, u32);
void linSetBls(TSpcTypedInterp<TLiveActor> *, u32);
void linSetSRT(TSpcTypedInterp<TLiveActor> *, u32);
void linGetSRT(TSpcTypedInterp<TLiveActor> *, u32);
void linSetAnmRate(TSpcTypedInterp<TLiveActor> *, u32);


#endif // TSPCTYPEDBINARY_H