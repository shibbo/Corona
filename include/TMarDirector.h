#ifndef TMARDIRECTOR_H
#define TMARDIRECTOR_H

#include "actor/TYoshi.h"
#include "actor/item/TCoin.h"
#include "JDrama.h"
#include "JGeometry.h"
#include "TGCConsole2.h"

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
    void nextStateInitialize(unsigned char);
    void setMario();
    void currentStateFinalize(unsigned char);
    void changeState();
    void fireStreamingMovie(unsigned char);
    void fireEndDemoCamera();
    void fireStartDemoCamera(char const *, TVec3<float> const *, long, float, bool, long (*)(unsigned long, unsigned long), unsigned long, TActor *, TFlagT<unsigned short>);
    void setNextStage(unsigned short, TActor *);
    void movement();
    void fireRideYoshi(TYoshi *);
    void fireGetStar(int *); // TShine
    void fireGetNozzle(int *); // TItemNozzle
    void fireGetBlueCoin(TCoin *);
    void movement_game();
    int* findNearestTalkNPC();
    int createObjects(); // returns 0
    void setupObjects();

    char _28[0x24];
    short state; // _4C
    char _4E[0x74-0x4E];
    TGCConsole2* gccConsole; // _74
};

#endif // TMARDIRECTOR_H