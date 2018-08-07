#ifndef TTALK2D2_H
#define TTALK2D2_H

#include "J2D.h"
#include "JDrama.h"
#include "message/TMessageLoader.h"

class TTalk2D2 : public JDrama::TViewObj
{
    public:
    TTalk2D2(char const *);
    ~TTalk2D2();

    void load(JSUMemoryInputStream &stream);
    void loadAfter();
    void perform(u32, JDrama::TGraphics *);

    void openWindow(s8, f32);
    void setTagParam(JSUMemoryInputStream &stream, J2DTextBox &textbox, int *, int *);
    void setupTextBox(void const *, JMSMesgEntry *);
    void setupBoardTextBox(void const *, JMSMesgEntry *);

    J2DScreen* _10;
    u32* _14; // TBoundPane*
    J2DTextBox* _18;
    u32 _1C;
    u32 _20;
    u32 _24;
    u8 _28;
    u8 _29;
    u8 _2A;
    u8 _2B;
    J2DSetScreen* _2C;
    u8 _30[0x48-0x30];
    u32* _48;
    u32* _4C;
    u32* _50;
    u32* _54;
    u32* _58;
    u32* _5C;
    u32* _60;
    u32* _64;
    u32* _68;
    u32* _6C;
    u32* _70;
    u32* _74;
    u8 _78[0x90-0x78];
    u32* _90;
    f32 _94;
    u8 _98[0x204-0x98];
    u32* _204;
    J2DTextBox* _208;
    u32 _20C;
    u32 _210;
    u32 _214;
    s8 _214;
    u8 _215;
    u8 _216;
    u8 _217;
    u32 _218;
    u32 _21C;
    u16 _220;
    u8 _222[0x234-0x222];
    f32 _234;
    f32 _238; // guess?
    f32 _23C;
    u32 _240;
    u32* _244; // JUTTexture*
    u32 _248;
    u32 _24C;
    u16 _250;
    u8 _252;
    u8 _253;
    u32* _254;
    TMessageLoader* _258;
    TMessageLoader* _25C;
    u32 _260;
    u32 _264;
    u16 _268;
    u8 _26A;
    u8 _26B;
    u8 _26C;
    u8 _26D;
    u8 _26E;
    u8 _26F;
    u32 _270;
    u32 _274;
    u32 _278;
    s32 _27C;
    u8 _280;
    u8 _281;
    u8 _282;
    u8 _283;
    u8 _284[0x2DC-0x284];
    u16 _2DC;
    u8 _2DE[0x330-0x2DE];
    u16 _330;
    u16 _332;
    u16 _334;
    u16 _336;
    u32 _338;
    u32 _33C;
    u32 _340;
};

#endif // TTALK2D2_H