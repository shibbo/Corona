#ifndef TSPCINTERP_H
#define TSPCINTERP_H

#include "types.h"
#include "spc/TSpcBinary.h"
#include "spc/TSpcSlice.h"

class TSpcInterp
{
    public:
    TSpcInterp(TSpcBinary *, void *, int, int, int, int);
    ~TSpcInterp();

    void update();
    void verifyArgNum(u32, u32 *);
    void dump();
    void dispatchBuiltin(u32, u32);
    void dispatchBuiltinDefault(u32, u32);

    /* SPC EXECUTE FUNCTIONS */
    void execend();
    void execint1();
    void execint0();
    void execpop();
    void execjmp();
    void execjne();
    void execret0();

    TSpcBinary* spcBin; // _0
    u32 _4;
    u32 _8;
    u32 _C;
    u32 _10;
    u32 _14;
    u32 mNumSplices; // _18
    u32 _1C;
    TSpcSlice* mSlices; // _20 (array of TSpcSlice*)
    u32 _24;
    u32 _28;
    u32 _2C;
    u32 _30;
    u32 _34;
    u32 _38;
    u32 _3C;
    u32 _40;
    VTABLE; // _44 -- TSpcStack vtable
    u32 _48;
    u32 _4C;
    u32 _50;
    u32 _54;
    u32 _58;
    u32 _5C;
};

#endif // TSPCINTERP_H