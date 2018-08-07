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