#ifndef RUMBLEMANAGER_H
#define RUMBLEMANAGER_H

#include "JGeometry.h"

using namespace JGeometry;

class RumbleMgr
{
    public:
    RumbleMgr(bool, bool, bool, bool);

    void startPause();
    void finishPause();
    void setActive(bool);
    void update();
    void stop(int);
    void stop();
    void start(int, int, TVec3<float> *);
    void start(int, int, float *);
    void start(int, TVec3<float> *);
    void start(int, float *);
    void reset();
    void init();


    float _0;
    float _4;
    char _8;
    char _9;
    char _A;
    char _B;
    char _C[0x1C-0xC];
    int _1C;
    int _20;
    int _24;
    int _28;
    int* _2C;
};

#endif // RUMBLEMANAGER_H