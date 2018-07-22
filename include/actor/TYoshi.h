#ifndef TYOSHI_H
#define TYOSHI_H

#include "J3D.h"
#include "JDrama.h"
#include "JGeometry.h"
#include "actor/THitActor.h"
#include "actor/TTakeActor.h"
#include "tmapobj/TMapObjGeneral.h"

class TMario;
class TYoshi;

class TEggYoshi : public TMapObjGeneral
{
    public:
    TEggYoshi(char const *);
    ~TEggYoshi();

    void load(JSUMemoryInputStream &);
    void peform(u32, JDrama::TGraphics *);
    bool recieveMessage(THitActor *, u32);
    void control();
    void touchActor(THitActor *);
    u32 getHitObjNumMax();

    void startFruit();
    void touchFruit(THitActor *);
    void decideRandomLoveFruit();

    u32 _148;
    u32 wantedFruit;
    u32 _150;
};

class TYoshiTongue : public TTakeActor
{
    public:
    ~TYoshiTongue();

    Mtx* getTakingMtx();
    void init(TYoshi *yoshi);
    void movement();
    void checkTaking();
    void checkTaken();

    void entry();
    void viewCalc();
    void calcAnim(f32 *[4]);
    u32 findTarget(bool, bool);
    bool canGo();
    void emit(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &);
    void initInLoadAfter();

    TYoshi* yoshi; // _70
    J3DModel* tongueModel; // _74
    J3DModel* tongueTipModel; // _78
    u16 _7C;
    u16 _7E;
    u16 _80;
    u16 _82;
    f32 _84;
    f32 _88;
    f32 _8C;
    f32 _90;
    f32 _94;
    f32 _98;
    f32 _9C;
    f32 _A0;
    f32 _A4;
    f32 _A8;
    f32 _AC;
    f32 _B0;
    f32 _B4;
    f32 _B8;
    f32 _BC;
    f32 _C0;
    f32 _C4;
    f32 _C8;
    f32 _CC;
    f32 _D0;
    f32 _D4;
};

class TYoshi
{
    public:
    bool onYoshi();
    void entry();
    void viewCalc();
    void calcAnim();
    void movement();
    void thinkHoldOut();
    void doEat(u32);
    void doSearch();
    void thinkUpper();
    void thinkAnimation();
    void getOff(bool);
    void ride();
    void kill();
    bool disappear();
    void appearFromEgg(JGeometry::TVec3<f32> const &, f32, TEggYoshi *);
    void setEggYoshiPtr(TEggYoshi *);
    void getEmitPosDir(JGeometry::TVec3<f32> *, JGeometry::TVec3<f32> *);
    void changeAnimation(u32);
    void thinkBtp(u32);
    void initInLoadAfter();
    void init(TMario *mario);

    u8 _0;
    u8 _1;
    u16 _2;
    u16 _4;
    u16 _6;
    u32 _8;
    u32 _C;
    TMario* mario; // _10
    u8 _14[0x20-0x14];
    f32 _20;
    f32 _24;
    f32 _28;
    f32 _2C;
    u32* _30; // MActorAnmData
    J3DModel* model; // _34
    TYoshiTongue* tongue; // _38
    u16 _3C;
    u16 _3E;
    u16 _40;
    u16 _42;
    u16 _44;
    u16 _46; // padding?
    u32 _48;
    u32 _4C;
    u32 _50;
    u32 _54;
    u32 _58;
    u32 _5C; // padding?
    u8 _60;
    u8 _61; // padding?
    u16 _62;
    u32 _64; // padding?
    f32 _68;
    f32 _6C;
    u16 _70;
    u16 _72;
    u8 _74[0x80-0x74];
    f32 _80;
    f32 colorR; // _84
    f32 colorG; // _88
    f32 colorB; // _8C
    f32 _90;
    u32 _94;
    f32 _98;
    f32 _9C;
    f32 _A0;
    f32 _A4;
    u32 _A8;
    J3DDrawBuffer* drawBuffer; // _AC
    u32 _B0;
    u32 _B4;
    u8 _B8;
    u8 _B9; // padding?
    u8 _BA; // ^^
    u8 _BB; // ^^
    u16 _BC;
    u16 _BE; // padding?
    f32 _C0;
    f32 _C4;
    u8 _D0;
    u8 _D1; // padding?
    u8 _D2; // ^^
    u8 _D3; // ^^
    u32 _D4;
    u32 _D8;
    u8 _DC;
    u8 _DD; // padding?
    u16 _DE;
    u16 _E0;
    f32 _E4;
    u16 _E8;
    u16 _EA;
    f32 _EC;
    TEggYoshi* _F0;
    u16 _F4;
    u16 _F6;
    u16 _F8;
    u16 _FA; // padding?
    u32 _FC; // ^^
    f32 _100;
    f32 _104;
    f32 _108;
    f32 _10C;
    f32 _110;
    f32 _114;
    u32 _118;
    u32 _11C;
    u32 _120;
};

bool YoshiHeadCtrl(J3DNode* node, u32);

#endif // TYOSHI_H