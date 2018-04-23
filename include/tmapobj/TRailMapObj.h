#ifndef TRAILMAPOBJ_H
#define TRAILMAPOBJ_H

#include "JDrama.h"
#include "JSUStream.h"
#include "node/TGraphTracer.h"
#include "node/TGraphWeb.h"
#include "tmapobj/TMapObjBase.h"

using namespace JDrama;

class TRailMapObj : public TMapObjBase
{
    public:
    TRailMapObj(char const *);
    ~TRailMapObj();

    void load(JSUMemoryInputStream &);
    void perform(unsigned long, TGraphcs *);
    void setGroundCollision();
    void control();
    int getShadowType();
    void initMapObj();
    bool calcRecycle();
    void resetPosition();

    bool checkMarioRiding();
    void moveToNextNode(float);
    void resetStep(float);
    void initGraphTracer(TGraphWeb *);

    TGraphTracer* tracer; // _138
    int _13C;
    int _140; // is mario riding?
    float _144;
    char _148;
    char _149; // padding?
    short _14A;
    char _14C;
    char _14D; // padding?
    char _14E; // ^^
    char _14F; // ^^
};

#endif // TRAILMAPOBJ_H