#ifndef TPATHNODE_H
#define TPATHNODE_H

#include "JGeometry.h"

using namespace JGeometry;

class TPathNode
{
    public:
    TPathNode();
    ~TPathNode();

    float getPoint() const;

    int _0;
    TVec3<float> position; // _4
};

#endif // TPATHNODE_H