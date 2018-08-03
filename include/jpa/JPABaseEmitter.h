#ifndef JPABASEEMITTER_H
#define JPABASEEMITTER_H

#include "jpa/JPADraw.h"
#include "JSUStream.h"

class JPABaseEmitter
{
    public:
    JPABaseEmitter();

    JSUPtrLink mBaseEmitterLink; // _0
    f32 _10;
    f32 _14;
    f32 _18;
    f32 _1C;
    u32 _20;
    u32 _24;
    u32 _28;
    u32 _2C;
    JPADraw; // _30
    JSUPtrList mPtrList1; // _F4
    JSUPtrList mPtrList2; // _100
    u8 _10C[0x124-0x10C];
    Mtx mMtx1; // _124
};

#endif // JPABASEEMITTER_H