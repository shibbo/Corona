#ifndef TLIGHTCOMMON_H
#define TLIGHTCOMMON_H

#include "JDrama.h"
#include "JUT.h"

class TLightCommon : public JDrama::TViewObj
{
    public:
    TLightCommon(char const *);
    virtual ~TLightCommon();

    virtual void loadAfter();
    virtual void perform(JDrama::TGraphics const *, int);
    virtual JUtility::TColor* getLightColor(int index) const;
    virtual JUtility::TColor* getAmbColor(int index) const;
    virtual TVec3<f32>* getLightPosition(int index) const;
    virtual void setLight(JDrama::TGraphics const *, int);

    f32 _10;
    f32 _14;
    f32 _18;
    f32 _1C;
    u32 _20;
    u32 _24;
    u8 _28;
    u8 _29; // padding?
    u8 _2A; // ^^
    u8 _2B; // ^^
    u8 _2C[0x40-0x2C];
    u8 _40;
    u8 _41;
    u8 _42; // padding?
    u8 _43; // ^^
    TVec3<f32> _44[0x4]; // array of vectors, each with a different purpose
};

#endif // TLIGHTCOMMON