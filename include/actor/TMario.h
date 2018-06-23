#ifndef TMARIO_H
#define TMARIO_H

#include "J3D.h"
#include "JDrama.h"
#include "JGeometry.h"
#include "JUT.h"
#include "TParam.h"
#include "actor/TTakeActor.h"

// some states
#define MARIO_FLAG_NEUTRAL   0x00000001
#define MARIO_FLAG_THROWN 	 0x00000007

#define MARIO_STATE_HANGPOLE 0x10100341

using namespace JDrama;
using namespace JGeometry;

class TMarioCap;
class TYoshi;

/* Size -- 0x42C */
class TDeParams
{
	public:
	TDeParams();
	
	u32* marioParams; // _0 (pointer to /Mario/Mario.prm)
	u32 _4;
	TBaseParam baseParam_1; // _8
	u16 _18;
	u8 _1A[0x1C-0x1A];
	u32 _1C;
	u8 _20[0x2C-0x20];
	f32 _2C;
	u32 _30;
	u8 _34[0x40-0x34];
	f32 _40;
	u32 _44;
	u8 _48[0x58-0x48];
	u32 _58;
	u8 _60[0x68-0x60];
	f32 _68;
	u32 _6C;
	u8 _70[0x7C-0x70];
	u16 _7C;
	u16 _7E; // padding?
	u32 _80;
	u8 _84[0x90-0x84];
	u16 _90;
	u16 _92; // padding?
	u32 _94;
	u8 _98[0xA4-0x98];
	u16 _A4;
	u16 _A6; // padding?
	u32 _A8;
	u8 _AC[0xB8-0xAC];
	u16 _B8;
	u16 _BA; // padding?
	u32 _BC;
	u8 _C0[0xCC-0xC0];
	u16 _CC;
	u16 _CE; // padding?
	u32 _D0;
	u8 _D4[0xE0-0xD4];
	u16 _E0;
	u16 _E2; // padding?
	u32 _E4;
	u8 _E8[0xF4-0xE8];
	u16 _F4;
	u16 _F6; // padding?
	u32 _F8;
	u8 _FC[0x108-0xFC];
	u16 _108;
	u16 _10A; // padding?
	u32 _10C;
	u8 _110[0x11C-0x110];
	u16 _11C;
	u16 _11E; // padding?
	u32 _120;
	u8 _124[0x130-0x124];
	u8 _130;
	u8 _131; // padding?
	u8 _132; // ^^
	u8 _133; // ^^
	u32 _134;
	u8 _138[0x144-0x138];
	u8 _144;
	u8 _145; // padding?
	u8 _146; // ^^
	u8 _147; // ^^
	u32 _148;
	u8 _14C[0x158-0x14C];
	u8 _158;
	u8 _159; // padding?
	u8 _15A; // ^^
	u8 _15B; // ^^
	u32 _15C;
	u8 _160[0x16C-0x160];
	f32 _16C;
	u32 _170;
	u8 _174[0x180-0x174];
	f32 _180;
	u32 _184;
	u8 _188[0x194-0x188];
	f32 _194;
	u32 _198;
	u8 _19C[0x1A8-0x19C];
	f32 _1A8;
	u32 _1AC;
	u8 _1B0[0x1BC-0x1B0];
	f32 _1BC;
	u32 _1C0;
	u8 _1C4[0x1D0-0x1C4];
	f32 _1D0;
	u32 _1D4;
	u8 _1D8[0x1E4-0x1D8];
	f32 _1E4;
	u32 _1E8;
	u8 _1EC[0x1F8-0x1EC];
	f32 _1F8;
	u32 _1FC;
	u8 _200[0x210-0x200];
	u32 _210;
	u8 _214[0x220-0x214];
	f32 _220;
	u32 _224;
	u8 _228[0x234-0x228];
	f32 _234;
	u32 _238;
	u8 _23C[0x248-0x23C];
	f32 _248;
	u32 _24C;
	u8 _250[0x25C-0x250];
	f32 _25C;
	u32 _260;
	u8 _264[0x270-0x264];
	f32 _270;
	u32 _274;
	u8 _278[0x284-0x278];
	f32 _284;
	u32 _288;
	u8 _28C[0x298-0x28C];
	f32 _298;
	u32 _29C;
	u8 _2A0[0x2AC-0x2A0];
	f32 _2AC;
	u32 _2B0;
	u8 _2B4[0x2C4-0x2B4];
	u32 _2C4;
	u8 _2C8[0x2D4-0x2C8];
	f32 _2D4;
	u32 _2D8;
	u8 _2DC[0x2E8-0x2DC];
	f32 _2E8;
	u32 _2EC;
	u8 _2F0[0x300-0x2F0];
	u32 _300;
	u8 _304[0x310-0x304];
	u16 _310;
	u16 _312; // padding?
	u32 _314;
	u8 _318[0x324-0x314];
	u16 _324;
	u16 _326; // padding?
	u32 _328;
	u8 _32C[0x338-0x32C];
	f32 _338;
	u32 _33C;
	u8 _340[0x34C-0x340];
	f32 _34C;
	u32 _350;
	u8 _354[0x360-0x354];
	f32 _360;
	u32 _364;
	u8 _368[0x378-0x368];
	u32 _378;
	u8 _37C[0x388-0x37C];
	f32 _388;
	u32 _38C;
	u8 _390[0x39C-0x390];
	f32 _39C;
	u32 _3A0;
	u8 _3A4[0x3B0-0x3A4];
	u16 _3B0;
	u16 _3B2; // padding?
	u32 _3B4;
	u8 _3B8[0x3C4-0x3B8];
	u16 _3C4;
	u16 _3C6; // padding?
	u32 _3C8;
	u8 _3CC[0x3D8-0x3CC];
	u16 _3D8;
	u16 _3DA; // padding?
	u32 _3DC;
	u8 _3E0[0x3EC-0x3E0];
	f32 _3EC;
	u32 _3F0;
	u8 _3F4[0x400-0x3F4];
	f32 _400;
	u32 _404;
	u8 _408[0x414-0x408];
	u16 _414;
	u16 _416; // padding?
	u32 _418;
	u8 _41C[0x428-0x41C];
	u16 _428;
};

class TDrawSyncCallback
{
	public:
	VTABLE; // _0
};

class TMarioSoundValues
{
	public:
	TMarioSoundValues();
	
	u32 _0;
	u32 _4;
	u32 _8;
	u32 _C;
	u32 _10;
	u32 _14;
	u8 _18;
	u32 _1C;
	u8 _20;
	u16 _22;
	u8 _24;
	u16 _26;
	u8 _2A;
	u8 _2B;
	u8 _2C;
	u8 _2D; // padding?
	u8 _2E; // ^^
	u8 _2F; // ^^
};

struct TMarioControllerWork
{
	u32 _0; // unk
	u32 _4;
	u32 _8;
	u8 _C[0x1C-0xC]; // unk
	f32 _1C;
};

class TMarioGamePad : public JUTGamePad
{
	public:
	~TMarioGamePad();

	void read();
	void onNeutralMarioKey();
	void updateMeaning();
	void reset();

	f32 _A8;
	f32 _AC;
	f32 _B0;
	f32 _B4;
	f32 _B8;
	f32 _BC;
	f32 stickX; // _C0
	f32 stickY; // _C4
	f32 _C8;
	f32 _CC;
	u32 _D0;
	u32 _D4;
	u32 _D8;
	u16 _DC;
	u16 _DE;
	u16 _E0;
	u16 _E2;
	u16 _E4;
	u16 _E6; // padding?
	u32 _E8;
	u32 _EC; // padding?
};

/* Size -- 0x4310 */
class TMario : public TTakeActor, public TDrawSyncCallback
{
	public:
	TMario();
	~TMario();
	
	/* these are a part of the vtable */
	void load(JSUMemoryInputStream &);
	void loadAfter();
	void perform(u32, TGraphics *);
	bool recieveMessage(THitActor *, u32);
	u32* getTakingMtx();
	u32 moveRequest(TVec3<f32> const &);
	void initValues();
	void checkReturn();
	void checkController(TGraphics *);
	void playerControl(TGraphics *);
	void initModel();
	void drawSpecial(TGraphics *);
	void checkCollision();
	void damageExec(THitActor *, u32, u32, u32, f32, u32, f32, u16);
	u32 getVoiceStatus();
	void drawSyncCallBack(s16);
	
	/* the following are not */
	u32 checkStatusType(u32) const;
	u32 actnMain();
	u32 taking();
	u32 demoMain();
	u32 footDowning();
	u32 electricDamage();
	u32 warpOut();
	void toroccoStart();
	u32 waitingStart(TVec3<f32> const *, f32);
	u32 returnStart(TVec3<f32> const *, f32, bool, u32);
	u32 rollingStart(TVec3<f32> const *, f32);
	u32 isUnUsualStageStart();
	void warpIn();
	u32 jumpingDemoCommon(u32, u32, f32);
	u32 readBillboard();
	u32 winDemo();
	void emitGetEffect();
	void emitGetWaterEffect();
	void emitGetCoinEffect(TVec3<f32> *);
	void emitSweatSometimes();
	void emitSweat(u16);
	void emitSmoke(u16);
	void emitParticle(u32);
	bool emitParticle(u32, TVec3<f32> const *);
	bool emitParticle(u32, u16);
	void moveParticle();
	void initParticle();
	
	void startSoundActor(u32);
	void startVoice(u32);
	u32 startVoiceIfNoVoice(u32);
	void stopVoice();
	void soundTorocco();
	void animSound();
	void soundMovement();
	
	void loserExec();
	
	bool onYoshi() const;
	bool isInvincible() const;
	bool isUnderWater() const;
	bool isWallInFront() const;
	bool canSquat() const;
	bool isTakeSituation(THitActor *);
	bool canTake(THitActor *);
	
	u32 getWallAngle() const;
	u32 getAttackAngle(THitActor * const);
	
	void rumbleStart(u32, u32);
	void dropObject();
	void decHP(u32);
	void incHP(u32);
	bool changePlayerStatus(u32, u32, bool);
	void setStatusToJumping(u32, u32);
	void setPlayerVelocity(f32 velocity);
	void doJumping();
	void throwMario(TVec3<f32> const &throwTo, f32 velocity);
	void checkPlayerAround(u32, f32);
	
	void normalizeNozzle();
	
	void setAnimation(u32, f32); // this *might* return a f32
	bool isAnimeLoopOrStop();
	void isLast1AnimeFrame();
	void takeOffGlass();
	void wearGlass();
	bool isWearingHelm();
	bool isWearingCap();
	bool rocketing();
	void setDivHelm();
	
	bool swimMain();
	bool swimPaddle();
	void surfingEffect();
	bool checkSwimJump();
	void doSwimming();
	void inOutWaterEffect(f32);

	bool rocketCheck();
	bool boardJumping();
	bool thrownDowning();
	bool slipFalling();
	bool catchStop();

	bool isMario();

	void checkThrowObject();
	void checkEnforceJump();

	bool sleeping();
	void sleepingEffect();
	bool waiting();
	void waitProcess();
	bool waitingCommonEvents();
	bool canSleep();
	void changeMontemanWaitingAnim();
	void stopCommon(u32, u32);
	bool considerRotateStart();
	bool checkPumpEnable();

	void setGamePad(TMarioGamePad *gamePad);
	bool askJumpIntoWaterEffectExist() const;

	// _70 is the TDrawSyncCallback vtable
	u32 _74;
	u32 _78;
	u32 status; // _7C
	u32 lastStatus; // _80
	u16 statusTimer;
	u16 _86;
	u16 _88;
	u16 _8A; // padding?
	f32 _8C;
	u16 _90;
	u16 _92; // padding?
	u16 _94;
	u16 _96;
	u16 _98;
	u16 _9A;
	u16 _9C;
	u16 _9E;
	u16 _A0;
	u16 _A2; // padding?
	TVec3<f32> speed; // _A4
	f32 velocity; // _B0
	f32 _B4;
	f32 _B8;
	f32 _BC;
	f32 _C0;
	u16 _C4;
	u16 _C6; // padding?
	f32 _C8;
	f32 _CC;
	f32 _D0;
	u8 _D4;
	u8 _D5;
	u8 _D6; // padding?
	u8 _D7; // ^^
	u32 _D8;
	u32 _DC;
	u32* illegalCheckData; // _E0
	u32 _E4;
	f32 _E8;
	f32 _EC;
	f32 _F0;
	u16 _F4;
	u16 _F6;
	u16 _F8;
	u16 _FA;
	u16 _FC;
	u16 _FE;
	u16 _100;
	f32 _104;
	u32 _108;
	u32 _10C; // padding?
	u32 _110; // ^^
	u32 _114; // ^^
	u32 stateFlags; // _118
	u32 _11C;
	u16 health; // in terms of 10000 (80000 = full health) _120
	u16 _122;
	u16 _124;
	u16 _126;
	u16 _128;
	u16 _12A; // padding?
	f32 _12C;
	f32 _130;
	u32 _134; // padding?
	u32 _138; // ^^
	u32 _13C; // ^^
	u32 _140; // ^^
	u32 _144;
	u32 _148;
	u16 _14C;
	u16 _14E;
	u32 _150; // padding?
	u32 _154;
	u32 _158;
	f32 _15C;
	f32 _160;
	f32 _164;
	f32 _168;
	f32 _16C;
	f32 _170;
	f32 _174;
	f32 _178;
	f32 _17C;
	f32 _180;
	f32 _184;
	f32 _188;
	f32 _18C;
	f32 _190;
	f32 _194;
	f32 _198;
	f32 _19C;
	f32 _1A0;
	f32 _1A4;
	f32 _1A8;
	f32 _1AC;
	f32 _1B0;
	f32 _1B4;
	f32 _1B8;
	f32 _1BC;
	Mtx mtx1; // _1C0
	Mtx mtx2; // _1F0
	Mtx mtx3; // _220
	Mtx mtx4; // _250
	u32 _280;
	u32 _284;
	u32 _288;
	u32 _28C;
	u32 _290;
	u32 _294;
	u32 _298; // padding?
	u32 _29C;
	u32 _2A0;
	u32 _2A4;
	u32 _2A8;
	u32 _2AC;
	u32 _2B0;
	u32 _2B4;
	u16 _2B8;
	u16 _2BA;
	f32 _2BC;
	u32 _2C0;
	Mtx mtx5; // _2C4
	f32 _2F4;
	f32 _2F8;
	f32 _2FC;
	f32 _300;
	f32 _304;
	f32 _308;
	f32 _30C;
	f32 _310;
	f32 _314;
	Mtx mtx6; // _318
	f32 _348;
	u16 _34C;
	u16 _34E;
	u32 _350;
	f32 _354;
	f32 _358;
	f32 _35C;
	u16 _360;
	u16 _362;
	u16 _364;
	u16 _366;
	f32 _368;
	f32 _36C;
	f32 _370;
	f32 _374;
	f32 _378;
	u16 _37E;
	u32 _380;
	u32 _384;
	u8 _388;
	u8 _389; // padding?
	u8 _38A; // ^^
	u8 _38B; // ^^
	u32 _38C; // ^^
	u32 _390;
	u32 _394;
	u32 _398;
	u32 _39C;
	u32 _3A0;
	u32 _3A4; // padding?
	u32* _3A8;
	u32* _3AC;
	u32 _3B0;
	u32 _3B4;
	u32 _3B8;
	u32 _3BC;
	u32 _3C0; // padding?
	u8 _3C4; // ^^
	u8 _3C5;
	u8 _3C6;
	u8 _3C7;
	u8 _3C8;
	u8 _3C9;
	u8 _3CA;
	u8 _3CB;
	u8 _3CC;
	u8 _3CD;
	u8 _3CE;
	u8 _3CF;
	u8 _3D0;
	u8 _3D1; // padding?
	u8 _3D2; // ^^
	u8 _3D3; // ^^
	u16 _3D4;
	u16 _3D6;
	f32 _3D8;
	f32 _3DC;
	TMarioCap* marioCap; // _3E0
	u32* _3E4; // TWaterGun
	u32 _3E8;
	f32 _3EC;
	TYoshi* yoshi; // _3F0
	u32 _3F4;
	u32* _3F8;
	u32 _3FC;
	u32 _400;
	f32 _404;
	f32 _408;
	f32 _40C;
	u16 _410;
	u16 _412;
	f32 _414;
	f32 _418;
	f32 _41C;
	u32 _420;
	u32* _424; // TMarioEffect
	f32 _428;
	f32 _42C;
	f32 _430;
	f32 _434;
	f32 _438;
	f32 _43C;
	f32 _440;
	f32 _444;
	f32 _448;
	f32 _44C;
	f32 _450;
	f32 _454;
	f32 _458;
	u8 _45C[0x4DC-0x45C]; // something is here
	u32* _4DC; // MAnmSound
	u32 _4E0;
	u32 _4E4;
	u32 _4E8;
	u8 _4EC;
	u8 _4ED;
	u8 _4EE; // padding?
	u8 _4EF; // ^^
	f32 _4F0;
	f32 _4F4;
	f32 _4F8;
	TMarioGamePad* gamepad; // _4FC
	TMarioSoundValues soundValues; // _500
	u32 _530;
	u8 _534;
	u8 _535; // padding?
	u16 _536;
	u16 _538;
	u8 _53A;
	u8 _53B;
	u8 _53C;
	u8 _53D; // padding?
	u16 _53E; // padding?
	f32 _540;
	f32 _544;
	u32 _548;
	u8 _54C;
	u8 _54D;
	u16 _54E;
	u16 _550;
	u16 _552;
	u16 _554;
	u16 _556; // padding?
	u32 _558;
	f32 _55C;
	f32 _560;
	f32 _564;
	f32 _568;
	f32 _56C;
	f32 _570;
	TDeParams deParams; // _574
	u32 _9A0;
	u32 _9A4;
	u32* _9A8;
	u32 _9AC; // padding?
	u32 _9B0; // ^^
	u32 _9B4; // ^^
	f32 _9B8;
	u32 _9BC;
	u32 _9C0; // padding?
	u32 _9C4; // ^^
	u32 _9C8; // ^^
	f32 _9CC;
	u32 _9D0;
	u32 _9D4; // padding?
	u32 _9D8; // ^^
	u32 _9DC; // ^^
	f32 _9E0;
	u32 _9E4;
	u8 _9E8[0x4310 - 0x9E8]; // there's a lot of stuff here
};

class TMarioCap
{
	public:
	TMarioCap(TMario *);
	
	VTABLE; // _0
	u32 state;
	u32 _8;
	u32 _C;
	J3DModel* model; // _10
};

#endif // TMARIO_H