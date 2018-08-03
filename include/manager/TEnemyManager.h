#ifndef TENEMYMANAGER_H
#define TENEMYMANAGER_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/TSpineEnemy.h"
#include "manager/TLiveManager.h"

class TEnemyManager : public TLiveManager
{
    public:
    TEnemyManager();
    ~TEnemyManager();

    void load(JSUMemoryInputStream &stream);
    void perform(u64, JDrama::TGraphics *);
    
    u32 createEnemyInstance();
    void clipEnemies(JDrama::TGraphics *);
    void restoreDrawBuffer(u64);
    void createEnemies(s32);
    void changeDrawBuffer(u64);

    u8 copyAnmMatrix(TSpineEnemy *);
    u32 countLivingEnemy() const;
    void killChildrenWithin(JGeometry::TVec3<f32> const &basePoint, f32 distance);
    void killChildren();
    u32* getFarOutEnemy();
    u32* getDeadEnemy();
    u32* getNearestEnemy(JGeometry::TVec3<f32> const &pos);
    void performShared(u32, JDrama::TGraphics *);
    void copyFromShared();
    void updateAnmSoundShared();
    void setSharedFlags();

    u32* _38;
    f32 _3C;
    u32 _40;
    u32 _44; // this is loaded from the binary
    u32 _48;
    u32 _4C;
    u32 _50;
};

#endif // TENEMYMANAGER_H