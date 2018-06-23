#ifndef TSPCBINARY_H
#define TSPCBINARY_H

#include "types.h"

class TSpcBinary
{
    public:
    TSpcBinary(void *);
    ~TSpcBinary();

    void initUserBuiltin();
    void* getHeader() const;
    void bindSystemDataToSymbol(char const *, u32);
    u32* searchSymbol(char const *);
    void init();
    
    
    void* spcBinary; // _0
    VTABLE; // _4
};


#endif // TSPCBINARY_H