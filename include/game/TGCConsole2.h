#ifndef TGCCONSOLE2_H
#define TGCCONSOLE2_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"

class TGCConsole2 : public JDrama::TViewObj
{
    public:
    TGCConsole2(char const *);
    virtual ~TGCConsole2();

    virtual void load(JSUMemoryInputStream &);
    virtual void loadAfter();
    virtual void perform(u32, JDrama::TGraphics *);

    // not all of them
    bool processDisappearBalloon();
    bool processAppearBalloon();
    bool processAppearTimer(int);
    bool processAppearRed(int);
    bool processAppearJet(int);

    u32 getFinishedTime();
    void stopMoveTimer();
    void startMoveTimer(int);
    void countBlueCoin();
    void countShine();
    void setTimer(u32);
    u32* checkDolpic8();

    void startAppearRedCoin();
    void startInsertJetBalloon();
    void startAppearJetBalloon(int, int);
    void startInsertTimer();
    void startAppearTimer(int, long timeInSeconds);
    void startDisappearTimer();

    void startCameraDemo();

    u32 _10;
    u32 _14;
    u32 _18;
    u16 _1C;
    u16 _1E; // padding?
    u8 _20[0x4A-0x20];
    u8 mIsTimerMoving; // _4A
    u8 _4B[0x500-0x4B];
    u32 mFinishedTime; // _500
    u32 _504;
    u32 _508;
    u32 _50C;
    u32 _510;
    u32 _514;
    u32 _518;
    u32 mTimerRelated; // _51C
};

#endif // TGCCONSOLE2_h