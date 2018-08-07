#ifndef TGRAPHWEB_H
#define TGRAPHWEB_H

#include "JGeometry.h"
#include "types.h"
#include "node/TGraphNode.h"
#include "node/TRailNode.h"
#include "node/TSplineRail.h"

class TGraphWeb
{
    public:
    TGraphWeb(TRailNode *, char const *railName, int nodeCount);
    ~TGraphWeb();

    u32 getNeighborNodeIndexByFlag(int, int, u32) const;
    JGeometry::TVec3<f32> getNearestPosOnGraphLink(JGeometry::TVec3<f32> const &) const;
    bool isDummy() const;
    Vec* indexToPoint(int) const;
    bool startIsEnd() const;
    void initGoalIndex(Vec const &);
    void calcGraphDirection(int);
    s32 findNearestVisibleIndex(JGeometry::TVec3<f32> const &, f32, f32, f32, u32) const;
    s32 findNearestNodeIndex(JGeometry::TVec3<f32> const &, u32) const;
    s16 getEscapeDirLimited(int, int, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, f32, u32) const;
    s16 getEscapeFromMarioIndex(int, int, JGeometry::TVec3<f32> const &, u32) const;
    s16 getRandomNextIndex(int, int, u32) const;
    s16 getShortestNextIndex(int, int, u32) const;
    void translateNodes(TRailNode *);
    s16 filterRailNode(u32, TRailNode const *, TRailNode const *, TRailNode *) const;
    s32 getRandomButDirLimited(int, int, JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &, f32, u32) const;
    s32 getAimToDirNextIndex(int, int, JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &, u32) const;

    TGraphNode* mNodes; // _0 (array of nodes)
    TRailNode* mRailNode; // _4
    s32 mNodeCount; //  _8
    u8* mRailName; // _C
    s32 mNearestNodeIndex; // _10
    TSplineRail* mSplineRail; // _14
    VTABLE; // _18
};

#endif // TGRAPHWEB_H