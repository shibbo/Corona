#ifndef TMARIO_H
#define TMARIO_H

#include "JDrama.h"
#include "JGeometry.h"
#include "TParam.h"
#include "actor/TTakeActor.h"

// some states
#define MARIO_FLAG_NEUTRAL   0x00000001
#define MARIO_FLAG_THROWN 	 0x00000007

#define MARIO_STATE_HANGPOLE 0x10100341

typedef float Mtx[3][4];

using namespace JDrama;
using namespace JGeometry;

class TMarioCap;

/* Size -- 0x42C */
class TDeParams
{
	public:
	TDeParams();
	
	int* marioParams; // _0 (pointer to /Mario/Mario.prm)
	int _4;
	TBaseParam baseParam_1; // _8
	short _18;
	char _1A[0x1C-0x1A];
	int _1C;
	char _20[0x2C-0x20];
	float _2C;
	int _30;
	char _34[0x40-0x34];
	float _40;
	int _44;
	char _48[0x58-0x48];
	int _58;
	char _60[0x68-0x60];
	float _68;
	int _6C;
	char _70[0x7C-0x70];
	short _7C;
	short _7E; // padding?
	int _80;
	char _84[0x90-0x84];
	short _90;
	short _92; // padding?
	int _94;
	char _98[0xA4-0x98];
	short _A4;
	short _A6; // padding?
	int _A8;
	char _AC[0xB8-0xAC];
	short _B8;
	short _BA; // padding?
	int _BC;
	char _C0[0xCC-0xC0];
	short _CC;
	short _CE; // padding?
	int _D0;
	char _D4[0xE0-0xD4];
	short _E0;
	short _E2; // padding?
	int _E4;
	char _E8[0xF4-0xE8];
	short _F4;
	short _F6; // padding?
	int _F8;
	char _FC[0x108-0xFC];
	short _108;
	short _10A; // padding?
	int _10C;
	char _110[0x11C-0x110];
	short _11C;
	short _11E; // padding?
	int _120;
	char _124[0x130-0x124];
	char _130;
	char _131; // padding?
	char _132; // ^^
	char _133; // ^^
	int _134;
	char _138[0x144-0x138];
	char _144;
	char _145; // padding?
	char _146; // ^^
	char _147; // ^^
	int _148;
	char _14C[0x158-0x14C];
	char _158;
	char _159; // padding?
	char _15A; // ^^
	char _15B; // ^^
	int _15C;
	char _160[0x16C-0x160];
	float _16C;
	int _170;
	char _174[0x180-0x174];
	float _180;
	int _184;
	char _188[0x194-0x188];
	float _194;
	int _198;
	char _19C[0x1A8-0x19C];
	float _1A8;
	int _1AC;
	char _1B0[0x1BC-0x1B0];
	float _1BC;
	int _1C0;
	char _1C4[0x1D0-0x1C4];
	float _1D0;
	int _1D4;
	char _1D8[0x1E4-0x1D8];
	float _1E4;
	int _1E8;
	char _1EC[0x1F8-0x1EC];
	float _1F8;
	int _1FC;
	char _200[0x210-0x200];
	int _210;
	char _214[0x220-0x214];
	float _220;
	int _224;
	char _228[0x234-0x228];
	float _234;
	int _238;
	char _23C[0x248-0x23C];
	float _248;
	int _24C;
	char _250[0x25C-0x250];
	float _25C;
	int _260;
	char _264[0x270-0x264];
	float _270;
	int _274;
	char _278[0x284-0x278];
	float _284;
	int _288;
	char _28C[0x298-0x28C];
	float _298;
	int _29C;
	char _2A0[0x2AC-0x2A0];
	float _2AC;
	int _2B0;
	char _2B4[0x2C4-0x2B4];
	int _2C4;
	char _2C8[0x2D4-0x2C8];
	float _2D4;
	int _2D8;
	char _2DC[0x2E8-0x2DC];
	float _2E8;
	int _2EC;
	char _2F0[0x300-0x2F0];
	int _300;
	char _304[0x310-0x304];
	short _310;
	short _312; // padding?
	int _314;
	char _318[0x324-0x314];
	short _324;
	short _326; // padding?
	int _328;
	char _32C[0x338-0x32C];
	float _338;
	int _33C;
	char _340[0x34C-0x340];
	float _34C;
	int _350;
	char _354[0x360-0x354];
	float _360;
	int _364;
	char _368[0x378-0x368];
	int _378;
	char _37C[0x388-0x37C];
	float _388;
	int _38C;
	char _390[0x39C-0x390];
	float _39C;
	int _3A0;
	char _3A4[0x3B0-0x3A4];
	short _3B0;
	short _3B2; // padding?
	int _3B4;
	char _3B8[0x3C4-0x3B8];
	short _3C4;
	short _3C6; // padding?
	int _3C8;
	char _3CC[0x3D8-0x3CC];
	short _3D8;
	short _3DA; // padding?
	int _3DC;
	char _3E0[0x3EC-0x3E0];
	float _3EC;
	int _3F0;
	char _3F4[0x400-0x3F4];
	float _400;
	int _404;
	char _408[0x414-0x408];
	short _414;
	short _416; // padding?
	int _418;
	char _41C[0x428-0x41C];
	short _428;
};

class TDrawSyncCallback
{
	public:
	int* vtable; // _0
};

class TMarioSoundValues
{
	public:
	TMarioSoundValues();
	
	int _0;
	int _4;
	int _8;
	int _C;
	int _10;
	int _14;
	char _18;
	int _1C;
	char _20;
	short _22;
	char _24;
	short _26;
	char _2A;
	char _2B;
	char _2C;
	char _2D; // padding?
	char _2E; // ^^
	char _2F; // ^^
};

struct TMarioControllerWork
{
	int _0; // unk
	int _4;
	int _8;
	char _C[0x1C-0xC]; // unk
	float _1C;
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
	void perform(unsigned long, TGraphics *);
	bool recieveMessage(THitActor *, unsigned long);
	int* getTakingMtx();
	int moveRequest(TVec3<float> const &);
	void initValues();
	void checkReturn();
	void checkController(TGraphics *);
	void playerControl(TGraphics *);
	void initModel();
	void drawSpecial(TGraphics *);
	void checkCollision();
	void damageExec(THitActor *, int, int, int, float, int, float, short);
	int getVoiceStatus();
	void drawSyncCallBack(unsigned short);
	
	/* the following are not */
	int checkStatusType(long) const;
	int actnMain();
	int taking();
	int demoMain();
	int footDowning();
	int electricDamage();
	int warpOut();
	void toroccoStart();
	int waitingStart(TVec3<float> const *, float);
	int returnStart(TVec3<float> const *, float, bool, int);
	int rollingStart(TVec3<float> const *, float);
	int isUnUsualStageStart();
	void warpIn();
	int jumpingDemoCommon(unsigned long, int, float);
	int readBillboard();
	int winDemo();
	void emitGetEffect();
	void emitGetWaterEffect();
	void emitGetCoinEffect(TVec3<float> *);
	void emitSweatSometimes();
	void emitSweat(short);
	void emitSmoke(short);
	void emitParticle(int);
	bool emitParticle(int, TVec3<float> const *);
	bool emitParticle(int, short);
	void moveParticle();
	void initParticle();
	
	void startSoundActor(unsigned long);
	void startVoice(unsigned long);
	int startVoiceIfNoVoice(unsigned long);
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
	
	int getWallAngle() const;
	int getAttackAngle(THitActor * const);
	
	void rumbleStart(int, int);
	void dropObject();
	void decHP(int);
	void incHP(int);
	bool changePlayerStatus(unsigned long, unsigned long, bool);
	void setStatusToJumping(unsigned long, unsigned long);
	void setPlayerVelocity(float velocity);
	void doJumping();
	void throwMario(TVec3<float> const &throwTo, float velocity);
	void checkPlayerAround(int, float);
	
	void normalizeNozzle();
	
	void setAnimation(int, float); // this *might* return a float
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
	void inOutWaterEffect(float);

	bool rocketCheck();
	bool boardJumping();
	bool thrownDowning();
	bool slipFalling();
	bool catchStop();

	bool isMario();

	void checkThrowObject();
	void checkEnforceJump();

	// _70 is the TDrawSyncCallback vtable
	int _74;
	int _78;
	int status; // _7C
	int lastStatus; // _80
	short statusTimer;
	short _86;
	short _88;
	short _8A; // padding?
	float _8C;
	short _90;
	short _92; // padding?
	short _94;
	short _96;
	short _98;
	short _9A;
	short _9C;
	short _9E;
	short _A0;
	short _A2; // padding?
	TVec3<float> speed; // _A4
	float velocity; // _B0
	float _B4;
	float _B8;
	float _BC;
	float _C0;
	short _C4;
	short _C6; // padding?
	float _C8;
	float _CC;
	float _D0;
	char _D4;
	char _D5;
	char _D6; // padding?
	char _D7; // ^^
	int _D8;
	int _DC;
	int* illegalCheckData; // _E0
	int _E4;
	float _E8;
	float _EC;
	float _F0;
	short _F4;
	short _F6;
	short _F8;
	short _FA;
	short _FC;
	short _FE;
	short _100;
	float _104;
	int _108;
	int _10C; // padding?
	int _110; // ^^
	int _114; // ^^
	int stateFlags; // _118
	int _11C;
	short health; // in terms of 10000 (80000 = full health) _120
	short _122;
	short _124;
	short _126;
	short _128;
	short _12A; // padding?
	float _12C;
	float _130;
	int _134; // padding?
	int _138; // ^^
	int _13C; // ^^
	int _140; // ^^
	int _144;
	int _148;
	short _14C;
	short _14E;
	int _150; // padding?
	int _154;
	int _158;
	float _15C;
	float _160;
	float _164;
	float _168;
	float _16C;
	float _170;
	float _174;
	float _178;
	float _17C;
	float _180;
	float _184;
	float _188;
	float _18C;
	float _190;
	float _194;
	float _198;
	float _19C;
	float _1A0;
	float _1A4;
	float _1A8;
	float _1AC;
	float _1B0;
	float _1B4;
	float _1B8;
	float _1BC;
	Mtx mtx1; // _1C0
	Mtx mtx2; // _1F0
	Mtx mtx3; // _220
	Mtx mtx4; // _250
	int _280;
	int _284;
	int _288;
	int _28C;
	int _290;
	int _294;
	int _298; // padding?
	int _29C;
	int _2A0;
	int _2A4;
	int _2A8;
	int _2AC;
	int _2B0;
	int _2B4;
	short _2B8;
	short _2BA;
	float _2BC;
	int _2C0;
	Mtx mtx5; // _2C4
	float _2F4;
	float _2F8;
	float _2FC;
	float _300;
	float _304;
	float _308;
	float _30C;
	float _310;
	float _314;
	Mtx mtx6; // _318
	float _348;
	short _34C;
	short _34E;
	int _350;
	float _354;
	float _358;
	float _35C;
	short _360;
	short _362;
	short _364;
	short _366;
	float _368;
	float _36C;
	float _370;
	float _374;
	float _378;
	short _37E;
	int _380;
	int _384;
	char _388;
	char _389; // padding?
	char _38A; // ^^
	char _38B; // ^^
	int _38C; // ^^
	int _390;
	int _394;
	int _398;
	int _39C;
	int _3A0;
	int _3A4; // padding?
	int* _3A8;
	int* _3AC;
	int _3B0;
	int _3B4;
	int _3B8;
	int _3BC;
	int _3C0; // padding?
	char _3C4; // ^^
	char _3C5;
	char _3C6;
	char _3C7;
	char _3C8;
	char _3C9;
	char _3CA;
	char _3CB;
	char _3CC;
	char _3CD;
	char _3CE;
	char _3CF;
	char _3D0;
	char _3D1; // padding?
	char _3D2; // ^^
	char _3D3; // ^^
	short _3D4;
	short _3D6;
	float _3D8;
	float _3DC;
	TMarioCap* marioCap; // _3E0
	int* _3E4; // TWaterGun
	int _3E8;
	float _3EC;
	int* _3F0; // TYoshi
	int _3F4;
	int* _3F8;
	int _3FC;
	int _400;
	float _404;
	float _408;
	float _40C;
	short _410;
	short _412;
	float _414;
	float _418;
	float _41C;
	int _420;
	int* _424; // TMarioEffect
	float _428;
	float _42C;
	float _430;
	float _434;
	float _438;
	float _43C;
	float _440;
	float _444;
	float _448;
	float _44C;
	float _450;
	float _454;
	float _458;
	char _45C[0x4DC-0x45C]; // something is here
	int* _4DC; // MAnmSound
	int _4E0;
	int _4E4;
	int _4E8;
	char _4EC;
	char _4ED;
	char _4EE; // padding?
	char _4EF; // ^^
	float _4F0;
	float _4F4;
	float _4F8;
	int* _4FC; // TMarioGamePad
	TMarioSoundValues soundValues; // _500
	int _530;
	char _534;
	char _535; // padding?
	short _536;
	short _538;
	char _53A;
	char _53B;
	char _53C;
	char _53D; // padding?
	short _53E; // padding?
	float _540;
	float _544;
	int _548;
	char _54C;
	char _54D;
	short _54E;
	short _550;
	short _552;
	short _554;
	short _556; // padding?
	int _558;
	float _55C;
	float _560;
	float _564;
	float _568;
	float _56C;
	float _570;
	TDeParams deParams; // _574
	int _9A0;
	int _9A4;
	int* _9A8;
	int _9AC; // padding?
	int _9B0; // ^^
	int _9B4; // ^^
	float _9B8;
	int _9BC;
	int _9C0; // padding?
	int _9C4; // ^^
	int _9C8; // ^^
	float _9CC;
	int _9D0;
	int _9D4; // padding?
	int _9D8; // ^^
	int _9DC; // ^^
	float _9E0;
	int _9E4;
	char _9E8[0x4310 - 0x9E8]; // there's a lot of stuff here
};

class TMarioCap
{
	public:
	TMarioCap(TMario*);
	
	int* vtable; // _0
	int state;
	int _8;
	int* _10; // J3DModel
	
};

#endif // TMARIO_H