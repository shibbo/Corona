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
    bool recieveMessage(THitActor * hitActor, unsigned long);
    void control();
    
    int _138;
    int _13C;
    int _140;
    int _144;
    short _148;
    short _14A;
    short _14C;
    short _14E;
};

#endif // TMAPOBJSWITCH_H