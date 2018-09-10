#ifndef RUMBLEMANAGER_H
#define RUMBLEMANAGER_H

#include "JGeometry.h"
#include "types.h"

class RumbleMgr
{
    public:
    RumbleMgr(bool, bool, bool, bool);

    void startPause();
    void finishPause();
    void setActive(bool);
    void update();
    void stop(u32);
    void stop();
    void start(int, int, JGeometry::TVec3<f32> *);
    void start(int, int, f32 *);
    void start(int, JGeometry::TVec3<f32> *);
    void start(int, f32 *);
    void reset();
    void init();

    f32 _0;
    f32 _4;
    u8 _8;
    u8 _9;
    u8 _A;
    u8 _B;
    u8 _C[0x1C-0xC];
    u32 _1C;
    u32 _20;
    u32 _24;
    u32 _28;
    u32* _2C;

    static s32 mMotorCountLimit;
    static s16 mMotorTimerPeriod;
    static f32 mPowerThreshold;
};

#endif // RUMBLEMANAGER_H