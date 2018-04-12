#ifndef TNOZZLEBASE_H
#define TNOZZLEBASE_H

#include "actor/TMario.h"
#include "TParam.h"
#include "actor/TWaterEmitInfo.h"
#include "actor/TWaterGun.h"

class TNozzleBase
{
	public:
	TNozzleBase(char const *, char const *, TWaterGun *);
	
	void init();
	int getNozzleKind() const;
	short getGunAngle();
	short getWaistAngle();
	void movement(TMarioControllerWork const &);
	void emitCommon(int, TWaterEmitInfo *);
	void emit(int);
	void animation(int);
	
	char* _0;
	int _4;
	TBaseParam param1; // _8
	char _18;
	char _19; // padding
	char _1A; // ^^
	char _1B; // ^^
	TBaseParam param2; // _1C
	float _2C;
	TBaseParam param3; // _30
	short _40;
	short _42; // padding
	TBaseParam param4; // _44
	float _54;
	TBaseParam param5; // _58
	float _68;
	TBaseParam param6; // _6C
	float _7C;
	TBaseParam param7; // _80
	float _90;
	TBaseParam param8; // _94
	float _A4;
	TBaseParam param9; // _A8
	float _B8;
	TBaseParam param10; // _BC
	int _CC;
	TBaseParam param11; // _D0
	float _E0;
	TBaseParam param12; // _E4
	float _F4;
	TBaseParam param13; // _F8
	short _108;
	short _10A; // padding
	TBaseParam param14; // _10C
	short _11C;
	short _11E; // padding
	TBaseParam param15; // _120
	int _130;
	TBaseParam param16; // _134
	float _144;
	TBaseParam param17; // _148
	float _158;
	TBaseParam param18; // _15C
	float _16C;
	TBaseParam param19; // _170
	short _180;
	short _182; // padding
	TBaseParam param20; // _184
	short _194;
	short _196; // padding
	TBaseParam param21; // _198
	short _1A8;
	short _1AA; // padding
	TBaseParam param22; // _1AC
	short _1BC;
	short _1BE; // padding
	TBaseParam param23; // _1C0
	short _1D0;
	short _1D2; // padding
	TBaseParam param24; // _1D4
	float _1E4;
	TBaseParam param25; // _1E8
	float _1F8;
	TBaseParam param26; // _1FC
	float _20C;
	TBaseParam param27; // _210
	float _220;
	TBaseParam param28; // _224
	short _234;
	short _236; // padding
	TBaseParam param29; // _238
	float _248;
	TBaseParam param30; // _24C
	float _25C;
	TBaseParam param31; // _260
	float _270;
	TBaseParam param32; // _274
	float _284;
	TBaseParam param33; // _288
	float _298;
	TBaseParam param34; // _29C
	float _2AC;
	TBaseParam param35; // _2B0
	float _2C0;
	TBaseParam param36; // _2C4
	float _2D4;
	TBaseParam param37; // _2D8
	short _2E8;
	short _2EA; // padding
	TBaseParam param38; // _2EC
	short _2FC;
	short _2FE; // padding
	TBaseParam param39; // _300
	short _310;
	short _312; // padding
	TBaseParam param40; // _314
	short _324;
	short _326; // padding
	TBaseParam param41; // _328
	short _338;
	short _33A; // padding
	TBaseParam param42; // _33C
	float _34C;
	TBaseParam param43; // _350
	float _360;
	int* vtable; // _364
	int* TWaterGun; // _368
	short _36C;
	short gunAngle; // _36E
	short waistAngle; // _370
	short _372;
	short _374; // padding?
	float _378;
	float _37C;
};

#endif // TNOZZLE_H