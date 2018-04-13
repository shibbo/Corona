#ifndef TMAPHIDEOBJ_H
#define TMAPHIDEOBJ_H

#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/THitActor.h"
#include "tmapobj/TMapObjBase.h"

using namespace JGeometry;

class TMapHideObj : public TMapObjBase
{
    public:
    TMapHideObj(char const *name);
    ~TMapHideObj();

    void load(JSUMemoryInputStream &);
    void loadAfter();
    int recieveMessage(THitActor *, unsigned long);
    void appearObj(float);
    void appearObjFromPoint(TVec3<float> const &);
    void emitEffect();

    float _138;
    float _13C;
    float _140;
    int _144;
    int _148;
    char _14C;
    char _14D; // padding?
    char _14E; // ^^
    char _14F; // ^^
};

#endif // TMAPHIDEOBJ_H