#ifndef TPATHNODE_H
#define TPATHNODE_H

#include "types.h"

class TPathNode
{
    public:
    TPathNode();
    ~TPathNode();
    
    u32 getPoint() const;

    u32 _0;
    f32 _4;
    f32 _8;
    f32 _C;
};