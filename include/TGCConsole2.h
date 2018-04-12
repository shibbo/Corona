#ifndef TGCCONSOLE2_H
#define TGCCONSOLE2_H

#include "JDrama.h"
#include "JSUStream.h"

using namespace JDrama;

class TGCConsole2 : public TViewObj
{
    public:
    TGCConsole2(char const *);
    ~TGCConsole2();

    void load(JSUMemoryInputStream &);
    void loadAfter();
    void perform(unsigned long, TGraphics *);

    // not all of them
    bool processDisappearBalloon();
    bool processAppearBalloon();
    bool processAppearTimer(int);
    bool processAppearRed(int);
    bool processAppearJet(int);

    int getFinishedTime();
    void stopMoveTimer();
    void startMoveTimer(int);
    void countBlueCoin();
    void countShine();
    void setTimer(long);
    int* checkDolpic8();

    void startAppearRedCoin();
    void startInsertJetBalloon();
    void startAppearJetBalloon(int, int);
    void startInsertTimer();
    void startAppearTimer(int, long timeInSeconds);
    void startDisappearTimer();

    void startCameraDemo();

    int _10;
    int _14;
    int _18;
    short _1C;
    short _1E; // padding?
    char _20[0x4A-0x20];
    char isTimerMoving; // _4A
    char _4B[0x500-0x4B];
    int finishedTime; // _500
    int _504;
    int _508;
    int _50C;
    int _510;
    int _514;
    int _518;
    int timerRelated; // _51C
};

#endif // TGCCONSOLE2_h