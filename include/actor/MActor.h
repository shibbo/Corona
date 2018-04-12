#ifndef MACTOR_H
#define MACTOR_H

class MActorAnmData
{
	public:
	MActorAnmData();
	
	void init(char const *, char const **);
	int partsNameToIndx(char const *);
	
	int _0;
	int* _4; // _4->_4 = *J3DModelData
	int _8;
	int _C;
	int _10;
	int _14;
	int _18;
	int _1C;
	int _20;
	int _24;
	int _28;
	int _2C;
	int _30;
	int _34;
	int _38;
	int _3C;
	int _40;
	int _44;
	int _48;
};

class MActor
{
	public:
	MActor(MActorAnmData *);
	
	int _0;
	int _4;
	int _8;
	int _10;
	int _14;
	int _18;
	int _1C;
	int _20;
	int _24;
	int _28;
	int _2C;
	int _30;
	int _34;
	char _38;
	char _39;
	char _3A; // padding?
	char _3B; // ^^
	int _3C;
	char _40;
	char _41; // padding?
	char _42; // ^^
	char _43; // ^^
	int _44;
};

#endif // MACTOR_H