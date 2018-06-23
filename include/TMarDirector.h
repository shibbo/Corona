#ifndef TMARDIRECTOR_H
#define TMARDIRECTOR_H

#include "actor/TYoshi.h"
#include "actor/item/TShine.h"
#include "actor/item/TCoin.h"
#include "JDrama.h"
#include "JGeometry.h"
#include "TGCConsole2.h"
#include "types.h"

using namespace JDrama;
using namespace JGeometry;

class TMarDirector : public TDirector
{
    public:
    TMarDirector();
    ~TMarDirector();

    void direct();
    void moveStage();
    void updateGameMode();
    void nextStateInitialize( u8);
    void setMario();
    void currentStateFinalize( u8);
    void changeState();
    void fireStreamingMovie( u8);
    void fireEndDemoCamera();
    void fireStartDemoCamera(char const *, TVec3<f32> const *, u32, f32, bool, u32 (*)(u32, u32), u32, TActor *, TFlagT< u16>);
    void setNextStage( u16 stageID, TActor *);
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
    u16 state; // _4C
    u8 _4E[0x74-0x4E];
    TGCConsole2* gccConsole; // _74
};

#endif // TMARDIRECTOR_H