#ifndef TWATEREMITINFO_H
#define TWATEREMITINFO_H

#include "TParam.h"

class TWaterEmitInfo
{
	public:
	TWaterEmitInfo(char const *);
	
	char* _0;
	int _4;
	TBaseParam param1; // _8
	int _18;
	TBaseParam param2; // _1C
	short _2C;
	short _2E; // padding
	TBaseParam param3; // _30
	short _40;
	short _42; // padding
	TBaseParam param4; // _44
	int _54;
	int _58;
	int _5C;
	TBaseParam param5; // _60
	int _70; // not sure why this wasn't declared in the ctor
	int _74;
	int _78;
	TBaseParam param6; // _7C
	int _8C;
	int _90;
	int _94;
	TBaseParam param7; // _98
	float _A8;
	TBaseParam param8; // _AC
	float _BC;
	TBaseParam param9; // _C0
	float _D0;
	TBaseParam param10; // _D4
	float _E4;
	TBaseParam param11; // _E8
	float _F8;
	TBaseParam param12; // _FC
	float _10C;
	TBaseParam param13; // _110
	float _120;
	TBaseParam param14; // _124
	int _134;
	TBaseParam param15; // _138
	short _148;
	short _14A; // padding
	TBaseParam param16; // _14C
	short _15C;
	short _15E; // padding
};

#endif // TWATEREMITINFO_H