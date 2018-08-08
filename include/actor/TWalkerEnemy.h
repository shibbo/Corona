#ifndef TWALKERENEMY_H
#define TWALKERENEMY_H

#include "types.h"
#include "actor/THitActor.h"
#include "actor/TSmallEnemy.h"
#include "manager/TLiveManager.h"

class TWalkerEnemy : public TSmallEnemy
{
    public:
    TWalkerEnemy(char const *);
    virtual ~TWalkerEnemy();

    virtual void init(TLiveManager *);
    virtual void moveObject();
    virtual void reset();
    virtual void attackToMario();
    virtual void initAttacker(THitActor *);
    virtual void behaveToFindMario();
    virtual void walkBehavior(u32, f32);
    virtual bool isResignationAttack();
    virtual void initialGraphNode();
};

#endif // TWALKERENEMY_H