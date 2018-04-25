#ifndef TMAPOBJSWITCH_H
#define TMAPOBJSWITCH_H

#include "JSUStream.h"
#include "actor/THitActor.h"
#include "tmapobj/TMapObjBase.h"

class TMapObjSwitch : public TMapObjBase
{
    public:
    TMapObjSwitch(char const *);
    ~TMapObjSwitch();

    void load(JSUMemoryInputStream &);
    bool recieveMessage(THitActor * hitActor, u32);
    void control();
    
    u32 _138;
    u32 _13C;
    u32 _140;
    u32 _144;
    u16 _148;
    u16 _14A;
    u16 _14C;
    u16 _14E;
};

#endif // TMAPOBJSWITCH_H