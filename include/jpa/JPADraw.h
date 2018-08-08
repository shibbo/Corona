#ifndef JPADRAW_H
#define JPADRAW_H

#include "types.h"

/* Size -- 0xC4 */
class JPADraw
{
    public:
    void setParticleClipBoard();
    void setChildClipBoard();
    void drawParticle();
    void drawChild();
    void zDraw();
    void zDrawParticle();
    void zDrawChild();
    u8 getMainTextureID(u8);

    u8 _0[0x89];
    u8 _89;
    u8 _8A;
    u8 _8B;
    u8 _8C;
    u8 _8D;
    u8 _8E;
    u8 _8F; // padding?
    u32 _90;
    u32* _94;
    u32 _9C;
    u32 _A0;
    u32 _A4;
    u32 _A8;
    u32 _AC;
    u32 _B0;
    u8 _B4[0xC2-0xB4];
    u8 _C2;
    u8 _C3;
};

#endif // JPADRAW_H