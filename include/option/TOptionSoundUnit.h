#ifndef TOPTIONSOUNDUNIT_H
#define TOPTIONSOUNDUNIT_H

#include "J2D.h"

class TOptionSoundUnit
{
    public:
    TOptionSoundUnit(J2DScreen *);

    void setInfluencedAlphaRecursive(J2DScreen *, bool);

    void setState(u32); // TOptionSoundUnit::State
    void adjustView();
    void update();
    void initSurroundAnm();
    void initSteleoAnm();
    static s32 typeToFlag(u32); // TOptionSoundUnit::SoundType
    static u32 flagToType(int);

    J2DScreen* screen; // _0
    // todo -- finish
};

#endif // TOPTIONSOUNDUNIT_H