#ifndef THIDEOBJBASE_H
#define THIDEOBJBASE_H

#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/THitActor.h"
#include "tmapobj/TMapObjBase.h"

class THideObjBase : public TMapObjBase
{
    public:
    THideObjBase(char const *name);
    virtual ~THideObjBase();

    virtual void load(JSUMemoryInputStream &);
    virtual void loadAfter();
    virtual bool recieveMessage(THitActor *, u32 message);
    virtual void appearObj(f32 spawnHeight);
    virtual void appearObjFromPoint(JGeometry::TVec3<f32> const &pos);
    virtual void emitEffect();

    f32 _138;
    f32 mThrowVelocityY; // _13C
    f32 mThrowVelocityZ; // _140
    char* mShineDemoName; // _144
    u32 _148;
    u8 _14C;
    u8 _14D; // padding?
    u8 _14E; // ^^
    u8 _14F; // ^^
};

#endif // THIDEOBJBASE_H