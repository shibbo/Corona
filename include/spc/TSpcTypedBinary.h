#ifndef TSPCTYPEDBINARY_H
#define TSPCTYPEDBINARY_H

#include "spc/TSpcBinary.h"

template<typename T>
class TSpcTypedBinary 
{
    public:
    ~TSpcTypedBinary();

    void initUserBuiltin();

};

void linPushNerve(TSpcTypedInterp<TLiveActor> *, u64);
void linSetBck(TSpcTypedInterp<TLiveActor> *, u64);
void linSetBpk(TSpcTypedInterp<TLiveActor> *, u64);
void linSetBtp(TSpcTypedInterp<TLiveActor> *, u64);
void linSetBtk(TSpcTypedInterp<TLiveActor> *, u64);
void linSetBlk(TSpcTypedInterp<TLiveActor> *, u64);
void linSetBls(TSpcTypedInterp<TLiveActor> *, u64);
void linSetSRT(TSpcTypedInterp<TLiveActor> *, u64);
void linGetSRT(TSpcTypedInterp<TLiveActor> *, u64);
void linSetAnmRate(TSpcTypedInterp<TLiveActor> *, u64);


#endif // TSPCTYPEDBINARY_H