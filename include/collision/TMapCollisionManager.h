#ifndef TMAPCOLLISIONMANAGER_H
#define TMAPCOLLISIONMANAGER_H

#include "actor/TLiveActor.h"

class TMapCollisionManager
{
    public:
    TMapCollisionManager(u16 colCount, char const *dirToManage, TLiveActor const *parentActor);

    void init(char const *, u16, char const *dirName);
    void createCollision(char const *, u8 collisionType);

    u32* _0;
    u16 mColCount; // _4
    u16 mColType; // _6
    u32* _8;
    char* mDirName; // _C
    TLiveActor* mParentActor; // _10
    u16 _14;
    u16 _16; // assumed padding
};

#endif // TMAPCOLLISIONMANAGER_H