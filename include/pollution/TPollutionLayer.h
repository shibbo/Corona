#ifndef TPOLLUTIONLAYER_H
#define TPOLLUTIONLAYER_H

#include "j3d/TJoint.h"
#include "pollution/TPollutionObj.h"
#include "pollution/TPollutionPos.h"

struct TPollutionLayerInfo
{
    u16 _0;
    u16 _2;
    u8 _4[0x10-0x04];
    f32 _10;
    f32 _14;
    f32 _18;
    f32 _1C;

};

class TPollutionLayer : public TJointModel
{
    public:
    TPollutionLayer();

    TPollutionObj* newJointObj() const;
    void initJointModel(TJointModelManager *, char const *name, MActorAnmData *);
    void perform(u64, JDrama::TGraphics *);
    u32 getJ3DModelDataFlag() const;
    u32 getPlaneType() const;
    u32 getTexPosT(f32) const;
    void initLayerInfo(TPollutionLayerInfo const *);
    u32* getTexResource(char const *);
    void stamp(u16, f32, f32, f32, f32);
    void stampModel(J3DModel *);
    bool isPolluted(f32 x, f32 y, f32 z) const;
    bool isInArea(f32 x, f32 y, f32 z) const;
    bool isInAreaSize(f32 x, f32 y, f32 w, f32 h);

    void cleaned(f32, f32, f32, f32);
    void appearItem(f32, f32, f32); // nullsub

    u16 _30;
    u16 _32;
    u32 _34;
    f32 _38;
    f32 _3C;
    f32 _40;
    f32 _44;
    u32 _48;
    u32 _4C;
    u8 _50;
    u8 _51; // padding?
    u8 _52; // ^^
    u8 _53; // ^^
    u32 _54;
    u32 _58;
    TPollutionPos pollutionPos; // _5C
    u32 _80;
    u8 _84;
    u8 _85;
    u8 _86; // padding?
    u8 _87; // ^^
    u32 _88;
    u32 _8C;
    u32 _90;
    s32 arrayCount; // _94
    TVec3<f32>* someArray; // _98 (count is defined by 0x94)
    u32 _9C;
    u32 _A0;
    u32 _A4;
    u32 _A8;
};

void initGXforStamp(u8 const *, u16, u16, s32);
void initGXforPollutionLayer(s16, u32, u8, u8);
void drawTex(u16, u16);
void initDrawObjGX();

#endif // TPOLLUTIONLAYER_H