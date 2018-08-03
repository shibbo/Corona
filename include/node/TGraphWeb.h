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
    TGraphWeb(TRailNode *, char const *railName, s32 nodeCount);
    ~TGraphWeb();

    u32 getNeighborNodeIndexByFlag(s32, s32, u64) const;
    JGeometry::TVec3<f32> getNearestPosOnGraphLink(JGeometry::TVec3<f32> const &) const;
    bool isDummy() const;
    Vec* indexToPoint(s32) const;
    bool startIsEnd() const;
    void initGoalIndex(Vec const &);
    void calcGraphDirection(s32);
    s32 findNearestVisibleIndex(JGeometry::TVec3<f32> const &, f32, f32, f32, u64) const;
    s32 findNearestNodeIndex(JGeometry::TVec3<f32> const &, u64) const;
    s16 getEscapeDirLimited(s32, s32, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, f32, u64) const;
    s16 getEscapeFromMarioIndex(u32, u32, JGeometry::TVec3<f32> const &, u64) const;
    s16 getRandomNextIndex(s32, s32, u64) const;
    s16 getShortestNextIndex(s32, s32, u64) const;
    void translateNodes(TRailNode *);
    s16 filterRailNode(u64, TRailNode const *, TRailNode const *, TRailNode *) const;
    s32 getRandomButDirLimited(s32, s32, JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &, f32, u64) const;
    s32 getAimToDirNextIndex(s32, s32, JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &, u64) const;

    TGraphNode* mNodes; // _0 (array of nodes)
    TRailNode* mRailNode; // _4
    s32 mNodeCount; //  _8
    u8* mRailName; // _C
    s32 mNearestNodeIndex; // _10
    TSplineRail* mSplineRail; // _14
    VTABLE; // _18
};

#endif // TGRAPHWEB_H