#ifndef TGRAPHWEB_H
#define TGRAPHWEB_H

#include "JGeometry.h"
#include "node/TRailNode.h"
#include "node/TSplineRail.h"

using namespace JGeometry;

class TGraphWeb
{
    public:
    TGraphWeb(TRailNode *, char const *railName, int nodeCount);
    ~TGraphWeb();

    int getNeighborNodeIndexByFlag(int, int, unsigned long) const;
    TVec3<float> getNearestPosOnGraphLink(TVec3<float> const &) const;
    bool isDummy() const;
    int indexToPoint(int) const;
    bool startIsEnd() const;
    void initGoalIndex(Vec const &);
    void calcGraphDirection(int);
    int findNearestVisibleIndex(TVec3<float> const &, float, float, float, unsigned long) const;
    int findNearestNodeInde(TVec3<float> const &, unsigned long) const;
    short getEscapeDirLimited(int, int, TVec3<float> const &, TVec3<float> const &, float, unsigned long) const;
    short getEscapeFromMarioIndex(int, int, TVec3<float> const &, unsigned long) const;
    short getRandomNextIndex(int, int, unsigned long) const;
    short getShortestNextIndex(int, int, unsigned long) const;
    void translateNodes(TRailNode *);
    short filterRailNode(unsigned long, TRailNode const *, TRailNode const *, TRailNode *) const;

    int* _0; // some array
    TRailNode* railNode; // _4
    int nodeCount; //  _8
    char* railName; // _C
    int nearestNodeIndex; // _10
    TSplineRail* splineRail; // _14
    int* vtable; // _18
};

#endif // TGRAPHWEB_H