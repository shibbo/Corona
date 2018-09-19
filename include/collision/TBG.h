#ifndef TBG_H
#define TBG_H

#include "types.h"

class TLiveActor;

class TBGCheckData
{
    public:
    TBGCheckData();

    u16 typeBitfield; // _0
    u16 _2;
    u16 _4;
    u8 terrainType; // _6
    u8 _7; // padding?
    f32 minY; // _8
    f32 maxY; // _C
    JGeometry::TVec3<f32> vert1; // _10
    JGeometry::TVec3<f32> vert2; // _1C
    JGeometry::TVec3<f32> vert3; // _28
    JGeometry::TVec3<f32> normal; // _34
    TLiveActor* owner; // _44

    u32 getPlaneType();
    f32 getJumpPower() const;
    bool isMarioThrough() const;
    bool isWaterSlip() const;
    bool isWaterSurface() const;
    bool isIllegalData() const;
    JGeometry::TVec3<f32> getNormal() const;
    void setVertex(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &);
};

class TBGCheckList
{
    public:
    TBGCheckList();

    void setPreNode(TBGCheckList *);

    VTABLE;
    u32 _4;
    u32 _8;
};

class TBGCheckListRoot
{
    public:
    TBGCheckListRoot();

    TBGCheckList mCheckLists[3]; // _0
};

class TBGCheckListWarp : public TBGCheckList
{
    public:
    TBGCheckListWarp();

    void setPreNode(TBGCheckList *);

    TBGCheckList* mPreNode; // _C
    u16 _10;
    u16 _12;
};

#endif // TBG_H