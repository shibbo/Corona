#ifndef TGCCONSOLE2_H
#define TGCCONSOLE2_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"

using namespace JDrama;

class TGCConsole2 : public TViewObj
{
    public:
    TGCConsole2(char const *);
    ~TGCConsole2();

    void load(JSUMemoryInputStream &);
    void loadAfter();
    void perform(u32, TGraphics *);

    // not all of them
    bool processDisappearBalloon();
    bool processAppearBalloon();
    bool processAppearTimer(u32);
    bool processAppearRed(u32);
    bool processAppearJet(u32);

    u32 getFinishedTime();
    void stopMoveTimer();
    void startMoveTimer(u32);
    void countBlueCoin();
    void countShine();
    void setTimer(u32);
    u32* checkDolpic8();

    void startAppearRedCoin();
    void startInsertJetBalloon();
    void startAppearJetBalloon(u32, u32);
    void startInsertTimer();
    void startAppearTimer(u32, u32 timeInSeconds);
    void startDisappearTimer();

    void startCameraDemo();

    u32 _10;
    u32 _14;
    u32 _18;
    u16 _1C;
    u16 _1E; // padding?
    u8 _20[0x4A-0x20];
    u8 isTimerMoving; // _4A
    u8 _4B[0x500-0x4B];
    u32 finishedTime; // _500
    u32 _504;
    u32 _508;
    u32 _50C;
    u32 _510;
    u32 _514;
    u32 _518;
    u32 timerRelated; // _51C
};

#endif // TGCCONSOLE2_h