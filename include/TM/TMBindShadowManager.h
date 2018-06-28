#ifndef TMBINDSHADOWMANAGER_H
#define TMBINDSHADOWMANAGER_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"

class TMBindShadowManager : public JDrama::TViewObj
{
    public:
    TMBindShadowManager(char const *);
    ~TMBindShadowManager();

    void load(JSUMemoryInputStream &stream);
    void perform(u32, JDrama::TGraphics *);

    void calcVtx();
    void drawShadowGD(u32, JDrama::TGraphics *);
    void drawShadow(u32, JDrama::TGraphics *);

    u32 _10; // assumed
    u32 _14;
    u32 _18; // unused?
    u32 _1C: // ^^
    u32 _20;
    u32 _24; // unused?
    u32 _28; // ^^
    u32 _2C;
    Vec* lightPos; // _30
    u32* _3C;
    u16 _40;
    u16 _42;
    u32 _44;
    u8 _48;
    u8 _49;
    u8 _4A; // padding?
    u8 _4B; // ^^
    u8 _4C;
    u32 _54;
    u32 _58;
    u8 _5C;
    u8 _5D;
    u8 _5E;
    u8 _5F;
    f32 _60;
    u8 _64;
    u8 _65;
    u8 _66; // padding?
    u8 _67; // ^^
    f32 _68;
    f32 _6C;
    u32 _70; // void* array
};

#endif // TMBINSHADOWMANAGER_H