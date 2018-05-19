#ifndef TOPTIONRUMBLEUNIT_H
#define TOPTIONRUMBLEUNIT_H

#include "J2D.h"

class TOptionRumbleUnit
{
    public:
    TOptionRumbleUnit(J2DScreen *);
    
    void setInfluencedAlphaRecursive(J2DPane *, bool);
    void setState(u32); // TOptionRumbleUnit::State
    void adjustView();
    void update();

    J2DScreen* screen; // _0
    u32* _4; // TExPane*
    u8 _8;
    u8 _9;
    u8 _A; // padding?
    u8 _B; // ^^
    u32 _C;
    u32* _10; // TPatternAnmControl*
    u32* _14; // TPatternAnmControl*
    u32* _18; // some class
    u32 state; // _1C
    u32* _20; // copy of _18
    f32 _24;
};

#endif // TOPTIONRUMBLEUNIT_H