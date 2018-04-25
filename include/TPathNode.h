#ifndef TPATHNODE_H
#define TPATHNODE_H

#include "JGeometry.h"

using namespace JGeometry;

class TPathNode
{
    public:
    TPathNode();
    ~TPathNode();

    f32 getPoint() const;

    u32 _0;
    TVec3<f32> position; // _4
};

#endif // TPATHNODE_H