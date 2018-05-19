#ifndef TNOZZLEBASE_H
#define TNOZZLEBASE_H

#include "MActor.h"
#include "TParam.h"
#include "types.h"
#include "actor/TMario.h"
#include "actor/TWaterEmitInfo.h"
#include "nozzle/TWaterGun.h"

class TNozzleBase
{
	public:
	TNozzleBase(char const *, char const *, TWaterGun *);
	
	void init();
	u32 getNozzleKind() const;
	u16 getGunAngle();
	u16 getWaistAngle();
	void movement(TMarioControllerWork const &);
	void emitCommon(u32, TWaterEmitInfo *);
	void emit(u32);
	void animation(u32);
	
	u8* _0;
	u32 _4;
	TBaseParam param1; // _8
	u8 _18;
	u8 _19; // padding
	u8 _1A; // ^^
	u8 _1B; // ^^
	TBaseParam param2; // _1C
	f32 _2C;
	TBaseParam param3; // _30
	u16 _40;
	u16 _42; // padding
	TBaseParam param4; // _44
	f32 _54;
	TBaseParam param5; // _58
	f32 _68;
	TBaseParam param6; // _6C
	f32 _7C;
	TBaseParam param7; // _80
	f32 _90;
	TBaseParam param8; // _94
	f32 _A4;
	TBaseParam param9; // _A8
	f32 _B8;
	TBaseParam param10; // _BC
	u32 _CC;
	TBaseParam param11; // _D0
	f32 _E0;
	TBaseParam param12; // _E4
	f32 _F4;
	TBaseParam param13; // _F8
	u16 _108;
	u16 _10A; // padding
	TBaseParam param14; // _10C
	u16 _11C;
	u16 _11E; // padding
	TBaseParam param15; // _120
	u32 _130;
	TBaseParam param16; // _134
	f32 _144;
	TBaseParam param17; // _148
	f32 _158;
	TBaseParam param18; // _15C
	f32 _16C;
	TBaseParam param19; // _170
	u16 _180;
	u16 _182; // padding
	TBaseParam param20; // _184
	u16 _194;
	u16 _196; // padding
	TBaseParam param21; // _198
	u16 _1A8;
	u16 _1AA; // padding
	TBaseParam param22; // _1AC
	u16 _1BC;
	u16 _1BE; // padding
	TBaseParam param23; // _1C0
	u16 _1D0;
	u16 _1D2; // padding
	TBaseParam param24; // _1D4
	f32 _1E4;
	TBaseParam param25; // _1E8
	f32 _1F8;
	TBaseParam param26; // _1FC
	f32 _20C;
	TBaseParam param27; // _210
	f32 _220;
	TBaseParam param28; // _224
	u16 _234;
	u16 _236; // padding
	TBaseParam param29; // _238
	f32 _248;
	TBaseParam param30; // _24C
	f32 _25C;
	TBaseParam param31; // _260
	f32 _270;
	TBaseParam param32; // _274
	f32 _284;
	TBaseParam param33; // _288
	f32 _298;
	TBaseParam param34; // _29C
	f32 _2AC;
	TBaseParam param35; // _2B0
	f32 _2C0;
	TBaseParam param36; // _2C4
	f32 _2D4;
	TBaseParam param37; // _2D8
	u16 _2E8;
	u16 _2EA; // padding
	TBaseParam param38; // _2EC
	u16 _2FC;
	u16 _2FE; // padding
	TBaseParam param39; // _300
	u16 _310;
	u16 _312; // padding
	TBaseParam param40; // _314
	u16 _324;
	u16 _326; // padding
	TBaseParam param41; // _328
	u16 _338;
	u16 _33A; // padding
	TBaseParam param42; // _33C
	f32 _34C;
	TBaseParam param43; // _350
	f32 _360;
	u32* vtable; // _364
	TWaterGun* waterGun; // _368
	u16 _36C;
	u16 gunAngle; // _36E
	u16 waistAngle; // _370
	u16 _372;
	u16 _374; // padding?
	u16 _376; // ^^
	f32 _378;
	f32 _37C;
	MActor* mActor; // _380
};

#endif // TNOZZLE_H