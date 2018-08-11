#ifndef TMAPOBJMANAGER_H
#define TMAPOBJMANAGER_H

#include "J3D.h"
#include "actor/MActor.h"
#include "dolphin/GX.h"
#include "manager/TMapObjBaseManager.h"

class TMapObjManager : public TMapObjBaseManager
{
    public:
    TMapObjManager();
    virtual ~TMapObjManager();

    virtual void load(JSUMemoryInputStream &stream);
    virtual void loadAfter();
    virtual bool hasMapCollision() const;

    void initKeyCode(); // can't tell if this is static or not, overwritten instantly
    void entryStaticDrawBufferSun(J3DModel *);
    void entryStaticDrawBufferShadow(J3DModel *);
    void initPacketMatColor(J3DModel *,_GXTevRegID,_GXColorS10 const *);

    MActorAnmData* mAnmData; // _40
    u8 _44[0x98-0x44];
    SDLModelData* mModelData; // _98
    MActor* mActor; // _9C
    MActor* mActor1; // _A0
    MActor* mActor2; // _A4
};

#endif // TMAPOBJMANAGER_H