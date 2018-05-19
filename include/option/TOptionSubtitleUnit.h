#ifndef TOPTIONSUBTITLEUNIT_H
#define TOPTIONSUBTITLEUNIT_H

#include "J2D.h"

class TOptionSubtitleUnit
{
    public:
    TOptionSubtitleUnit(J2DScreen *);

    void setInfluencedAlphaRecursive(J2DPane *, bool);
    void setState(u32); // TOptionSubtitleUnit::State

    J2DScreen* screen; // _0
    u32* _4;
    u8 _8;
    u8 _9; // padding?
    u8 _A; // ^^
    u8 _B; // ^^
    u32* _C;
    u32 _10;
};

#endif // TOPTIONSUBTITLEUNIT_H