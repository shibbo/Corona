#ifndef TMAPHIDEOBJ_H
#define TMAPHIDEOBJ_H

#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/THitActor.h"
#include "tmapobj/TMapObjBase.h"

class TMapHideObj : public TMapObjBase
{
    public:
    TMapHideObj(char const *name);
    virtual ~TMapHideObj();

    virtual void load(JSUMemoryInputStream &);
    virtual void loadAfter();
    virtual bool recieveMessage(THitActor *, u32);
    virtual void appearObj(f32);
    virtual void appearObjFromPoint(JGeometry::TVec3<f32> const &);
    virtual void emitEffect();

    f32 _138;
    f32 _13C;
    f32 _140;
    u32 _144;
    u32 _148;
    u8 _14C;
    u8 _14D; // padding?
    u8 _14E; // ^^
    u8 _14F; // ^^
};

#endif // TMAPHIDEOBJ_H