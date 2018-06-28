#ifndef TCONDUCTOR_H
#define TCONDUCTOR_H

#include "JDrama.h"
#include "JGeometry.h"
#include "actor/TLiveActor.h"
#include "actor/TSmallEnemy.h"
#include "node/TGraphGroup.h"
#include "manager/TEnemyManager.h"
#include "manager/TLiveManager.h"

class TConductor : public JDrama::TViewObj
{
    public:
    TConductor(char const *);
    ~TConductor();

    TNameRef* searchF(u16, char const *);
    void perform(u32, JDrama::TGraphics *);

    void genEnemyFromPollution();
    void killEnemiesWithin(JGeometry::TVec3<f32> const &position, f32 distance);
    TSmallEnemy* makeOneEnemyAppear(JGeometry::TVec3<f32> const &position, char const *name, u32);
    TSmallEnemy* makeEnemyAppear(JGeometry::TVec3<f32> const &position, char const *name, u32, u32);
    bool isBossDefeated();
    TLiveManager* getManagerByName(char const *managerName);
    TGraphGroup* getGraphByName(char const *graphName);
    void init();
    void registerEnemyInfoTable(u32 *); // TStageEnemyInfoTable
    void registerSDLModelData(u32 *); // SDLModelData
    void registerAreaCylinderManager(u32 *); // AreaCylinderManager
    void registerGenerator(u32 *); // TGenerator
    void registerOtherObj(TViewObj *obj);
    void registerAloneActor(TLiveActor *actor);
    void registerEnemyManager(TEnemyManager *manager);
    void registerLiveManager(TLiveManager *manager);
    void initGraphGroup();
    void makeGraphGroup(void *);
};

#endif // TCONDUCTOR_H