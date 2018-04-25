#ifndef TWATEREMITINFO_H
#define TWATEREMITINFO_H

#include "TParam.h"
#include "types.h"

class TWaterEmitInfo
{
	public:
	TWaterEmitInfo(char const *);
	
	u8* _0;
	u32 _4;
	TBaseParam param1; // _8
	u32 _18;
	TBaseParam param2; // _1C
	u16 _2C;
	u16 _2E; // padding
	TBaseParam param3; // _30
	u16 _40;
	u16 _42; // padding
	TBaseParam param4; // _44
	u32 _54;
	u32 _58;
	u32 _5C;
	TBaseParam param5; // _60
	u32 _70; // not sure why this wasn't declared in the ctor
	u32 _74;
	u32 _78;
	TBaseParam param6; // _7C
	u32 _8C;
	u32 _90;
	u32 _94;
	TBaseParam param7; // _98
	f32 _A8;
	TBaseParam param8; // _AC
	f32 _BC;
	TBaseParam param9; // _C0
	f32 _D0;
	TBaseParam param10; // _D4
	f32 _E4;
	TBaseParam param11; // _E8
	f32 _F8;
	TBaseParam param12; // _FC
	f32 _10C;
	TBaseParam param13; // _110
	f32 _120;
	TBaseParam param14; // _124
	u32 _134;
	TBaseParam param15; // _138
	u16 _148;
	u16 _14A; // padding
	TBaseParam param16; // _14C
	u16 _15C;
	u16 _15E; // padding
};

#endif // TWATEREMITINFO_H