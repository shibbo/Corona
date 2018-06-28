#ifndef CPOLARSUBCAMERA_H
#define CPOLARSUBCAMERA_H

#include "JDrama.h"
#include "JGeometry.h"
#include "actor/TMario.h"
#include "camera/TCameraBck.h"
#include "camera/TCameraInbetween.h"
#include "camera/TCameraMarioData.h"

class CPolarSubCamera : public TLookAtCamera
{
    public:
    CPolarSubCamera(char const *);
    ~CPolarSubCamera();

    void loadAfter();
    void perform(u32, JDrama::TGraphics *);

    bool execGroundCheck_(Vec position);
    bool execRoofCheck_(Vec position);
    bool execWallCheck_(Vec *position);
    void ctrlMultiPlayerCamera_();
    bool removeMultiPlayer(JGeometry::TVec3<f32> const *);
    bool addMultiPlayer(JGeometry::TVec3<f32> const *, f32);
    void createMultiPlayer(u8 howMany);
    u8 isLButtonCameraSpecifyMode(u32) const;
    u8 isLButtonCameraInbetween() const;
    u8 isTalkCameraSpecifyMode(u32) const;

    u32 mode; // _50
    u32 _54;
    u32 _58;
    u32 _5C;
    u32 _60;
    u16 _64; // something relating to a state
    u16 _66; // padding?
    TCameraMarioData* cameraMarioData; // _68 
    TCameraInbetween* cameraInbetween; // _6C
    u32 _70;
    u32 _74;
    u32 _78;
    u32 _7C;
    u8 _80[0x11C-0x80];
    u32 _11C;
    TMarioGamePad* gamePad; // _120
    u8 _124[0x24C-0x124];
    f32 _24C;
    f32 _250;
    u16 _254;
    u16 _256; // padding?
    u8 _258[0x268-0x258];
    f32 _268;
    f32 _26C;
    u32 _270; // assumed
    u16 _274;
    u16 _276;
    u16 _278;
    u16 _27A;
    u16 _27C;
    u16 _27E;
    u16 _280;
    u16 _282;
    u32 _284;
    f32 _288;
    u16 _28C;
    u16 _28E;
    f32 _290;
    f32 _294;
    f32 _298;
    u32 _29C;
    u32 _2A0; // ??
    u32* _2A4;
    u32 _2A8; // ??
    u32 _2AC;
    TCameraBck* cameraBck; // _2B0
    u32 _2B4;
    u32* _2B8; // TCameraJetCoaster*
    u32 _2BC; // array of multi-player stuff
    f32 _2C0;
    f32 _2C4;
    u16 _2C8;
    u16 _2CA;
    u8 _2CC;
    u8 _2CD; // padding?
    u8 _2CE; // ^^
    u8 _2CF; // ^^
    u32* _2D0; // TCamSaveNotice*
    u32* _2D4; // TCamSaveEx*
    u8 _2D8[0x3FC-0x2D8];
};

#endif // CPOLARSUBCAMERA_H