#ifndef TYOSHI_H
#define TYOSHI_H

#include "actor/TMario.h"
#include "actor/THitActor.h"
#include "J3D.h"
#include "JDrama.h"
#include "JGeometry.h"
#include "tmapobj/TMapObjGeneral.h"

using namespace JDrama;
using namespace JGeometry;

class TEggYoshi : public TMapObjGeneral
{
    public:
    TEggYoshi(char const *);
    ~TEggYoshi();

    void load(JSUMemoryInputStream &);
    void peform(unsigned long, TGraphics *);
    bool recieveMessage(THitActor *, unsigned long);
    void control();
    void touchActor(THitActor *);
    int getHitObjNumMax();

    void startFruit();
    void touchFruit(THitActor *);
    void decideRandomLoveFruit();

    int _148;
    int _14C;
    int _150;
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
    void doEat(unsigned long);
    void doSearch();
    void thinkUpper();
    void thinkAnimation();
    void getOff(bool);
    void ride();
    void kill();
    bool disappear();
    void appearFromEgg(TVec3<float> const &, float, TEggYoshi*);
    void setEggYoshiPtr(TEggYoshi *);
    void getEmitPosDir(TVec3<float> *, TVec3<float> *);
    void changeAnimation(int);
    void thinkBtp(int);
    void initInLoadAfter();
    void init(TMario*);

    char _0;
    char _1;
    short _2;
    short _4;
    short _6;
    int _8;
    int _C;
    TMario* mario; // _10
    char _14[0x20-0x14];
    float _20;
    float _24;
    float _28;
    float _2C;
    int* _30; // MActorAnmData
    J3DModel* model; // _34
    int _38;
    short _3C;
    short _3E;
    short _40;
    short _42;
    short _44;
    short _46; // padding?
    int _48;
    int _4C;
    int _50;
    int _54;
    int _58;
    int _5C; // padding?
    char _60;
    char _61; // padding?
    short _62;
    int _64; // padding?
    float _68;
    float _6C;
    short _70;
    short _72;
    char _74[0x80-0x74];
    float _80;
    float _84;
    float _88;
    float _8C;
    float _90;
    int _94;
    float _98;
    float _9C;
    float _A0;
    float _A4;
    int _A8;
    int _AC;
    int _B0;
    int _B4;
    char _B8;
    char _B9; // padding?
    char _BA; // ^^
    char _BB; // ^^
    short _BC;
    short _BE; // padding?
    float _C0;
    float _C4;
    char _D0;
    char _D1; // padding?
    char _D2; // ^^
    char _D3; // ^^
    int _D4;
    int _D8;
    char _DC;
    char _DD; // padding?
    short _DE;
    short _E0;
    float _E4;
    short _E8;
    short _EA;
    float _EC;
    TEggYoshi* _F0;
    short _F4;
    short _F6;
    short _F8;
    short _FA; // padding?
    int _FC; // ^^
    float _100;
    float _104;
    float _108;
    float _10C;
    float _110;
    float _114;
    int _118;
    int _11C;
    int _120;
};

#endif // TYOSHI_H