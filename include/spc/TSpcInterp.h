#ifndef TSPCINTERP_H
#define TSPCINTERP_H

#include "spc/TSpcBinary.h"

class TSpcInterp
{
    public:
    TSpcInterp(TSpcBinary *, void *, int, int, int, int);
    ~TSpcInterp();

    void update();
    void verifyArgNum(unsigned long, unsigned long *);
    void dump();
    void dispatchBuiltin(unsigned long, unsigned long);
    void dispatchBuiltinDefault(unsigned long, unsigned long);

    /* SPC EXECUTE FUNCTIONS */
    void execend();
    void execint1();
    void execint0();
    void execpop();
    void execjmp();
    void execjne();
    void execret0();

    TSpcBinary* spcBin; // _0
    int _4;
    int _8;
    int _C;
    int _10;
    int _14;
    int _18;
    int _1C;
    int _20;
    int _24;
    int _28;
    int _2C;
    int _30;
    int _34;
    int _38;
    int _3C;
    int _40;
    int _44;
    int _48;
    int _4C;
    int _50;
    int _54;
    int _58;
    int _5C;
};

#endif // TSPCINTERP_H