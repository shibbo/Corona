#ifndef TSPCSLICE_H
#define TSPCSLICE_H

#include "types.h"

class TSpcSlice
{
    public:
    TSpcSlice();

    u32 getDataInt() const;
    f32 getDataFloat() const;
    
    bool operator !=(TSpcSlice const &) const;
    bool operator ==(TSpcSlice const &) const;

    u32 _0;
    u32 _4;
};

#endif // TSPCSLICE_H