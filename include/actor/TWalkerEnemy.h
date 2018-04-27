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
    ~TWalkerEnemy();

    void init(TLiveManager *);
    void moveObject();
    void reset();
    void attackToMario();
    void initAttacker(THitActor *);
    void behaveToFindMario();
    void walkBehavior(u32, f32);
    bool isResignationAttack();
    void initialGraphNode();
};

#endif // TWALKERENEMY_H