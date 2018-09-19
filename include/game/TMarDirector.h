#ifndef TMARDIRECTOR_H
#define TMARDIRECTOR_H

#include "actor/TYoshi.h"
#include "actor/item/TShine.h"
#include "actor/item/TCoin.h"
#include "JDrama.h"
#include "JGeometry.h"
#include "game/TGCConsole2.h"
#include "types.h"

class TMarDirector : public JDrama::TDirector
{
    public:
    TMarDirector();
    ~TMarDirector();

    virtual s32 direct();
    virtual void JSGFindObject(char const *, u32); // JStage::TEObject

    void moveStage();
    void updateGameMode();
    void nextStateInitialize(s8);
    void setMario();
    void currentStateFinalize(s8);
    void changeState();
    void fireStreamingMovie(s8);
    void fireEndDemoCamera();
    void fireStartDemoCamera(char const *, JGeometry::TVec3<f32> const *, u32, f32, bool, u32 (*)(u32, u32), u32, JDrama::TActor *, JDrama::TFlagT<s16>);
    void setNextStage(s16 stageID, JDrama::TActor *);
    void movement();
    void fireRideYoshi(TYoshi *);
    void fireGetStar(TShine *);
    void fireGetNozzle(u32 *); // TItemNozzle
    void fireGetBlueCoin(TCoin *);
    void movement_game();
    u32* findNearestTalkNPC();
    u32 createObjects(); // returns 0
    void setupObjects();
    bool thpInit();
    void loadParticleMario();
    void loadParticle();
    void initLoadParticle();
    void loadResource();

    u8 _28[0x24];
    u16 mState; // _4C
    u8 _4E[0x74-0x4E];
    TGCConsole2* mConsole; // _74
    u32 _78;
    u8 mCurStage; // _7C
    u8 mCurEpisode; // _7D
    u16 _7E;
    u8 _80[0x268-0x80];
};

u8[0x7] stages;

#endif // TMARDIRECTOR_H