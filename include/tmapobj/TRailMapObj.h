#ifndef TRAILMAPOBJ_H
#define TRAILMAPOBJ_H

#include "JDrama.h"
#include "JSUStream.h"
#include "node/TGraphTracer.h"
#include "node/TGraphWeb.h"
#include "tmapobj/TMapObjBase.h"

class TRailMapObj : public TMapObjBase
{
    public:
    TRailMapObj(char const *);
    virtual ~TRailMapObj();

    virtual void load(JSUMemoryInputStream &);
    virtual void perform(u32, JDrama::TGraphics *);
    virtual void setGroundCollision();
    virtual void control();
    virtual u32 getShadowType();
    virtual void initMapObj();
    virtual bool calcRecycle();
    virtual void resetPosition();

    bool checkMarioRiding();
    void moveToNextNode(f32);
    void resetStep(f32);
    void initGraphTracer(TGraphWeb *);

    TGraphTracer* tracer; // _138
    u32 _13C;
    u32 _140; // is mario riding?
    f32 _144;
    u8 _148;
    u8 _149; // padding?
    u16 _14A;
    u8 _14C;
    u8 _14D; // padding?
    u8 _14E; // ^^
    u8 _14F; // ^^
};

#endif // TRAILMAPOBJ_H