#ifndef TGRAPHNODE_H
#define TGRAPHNODE_H

#include "JGeometry.h"
#include "types.h"

class TGraphNode
{
    public:
    TGraphNode();

    void getPoint(Vec const *);

    u32* _0;
    u32 _4;
    f32 _8;
    s16 _C;
    s16 _E;
};

#endif // TGRAPHNODE_H