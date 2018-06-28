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
    ~TRailMapObj();

    void load(JSUMemoryInputStream &);
    void perform(u32, JDrama::TGraphcs *);
    void setGroundCollision();
    void control();
    u32 getShadowType();
    void initMapObj();
    bool calcRecycle();
    void resetPosition();

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