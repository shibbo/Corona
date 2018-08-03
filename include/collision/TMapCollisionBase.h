#ifndef TMAPCOLLISIONBASE_H
#define TMAPCOLLISIONBASE_H

#include "actor/TLiveActor.h"

class TMapCollisionBase
{
    public:
    void init(char const *, u16, TLiveActor *actor);
    void moveSRT(JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &);
    void moveTrans(JGeometry::TVec3<f> const &);
    void moveMtx(f32 *[4]);
    void setUp();
    void setUpTrans(JGeometry::TVec3<f32> const &);
    void remove();

    void setAllActor(TLiveActor *);
    void setAllData(s16);
    void setAllBGType(u16);
    void setVertexData(u32, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &);

    void initAllCheckData(s16, f32 const *, u16, TLiveActor *);
    void update();
    void updateTrans(JGeometry::TVec3<f32> const &);

    VTABLE; // _0
    u32* _4;
    s32 _8;
    u32 mNumVerts; // _10
    u32 mVertOffset; // _14
    u32 mGroupCount; // _18
    u32* mGroups; // _1C
    Mtx _20;
    JGeometry::TVec3<f32> _50;
    u16 _5C;
    u16 _5E; // padding
};

#endif // TMAPCOLLISIONBASE_H