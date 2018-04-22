#ifndef TGRAPHNODE_H
#define TGRAPHNODE_H

#include "JGeometry.h"

class TGraphNode
{
    public:
    TGraphNode();

    void getPoint(Vec const *);

    int*  _0;
    int _4
    float _8;
    short _C;
    short _E; // assumed padding
};

#endif // TGRAPHNODE_H