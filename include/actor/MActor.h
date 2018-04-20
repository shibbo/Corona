#ifndef MACTOR_H
#define MACTOR_H

#include "JDrama.h"

using namespace JDrama;

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

	void updateMatAnm();
	void entryOut();
	void entryIn();
	void updateOut();
	void updateIn();
	void setBrkFromIndex(int index);
	void setBrk(char const *brkName);
	void setBlk(char const *blkName);
	void setBtkFromIndex(int index);
	void setBtk(char const *btkName);
	void setBtpFromIndex(int index);
	void setBtp(char const *btpName);
	void setpBpkFromIndex(int index);
	void setBpk(char const *bpkName);
	void setBckFromIndex(int index);
	void setBck(char const *bckName);
	void setFrameRate(float, int);
	int getCurAnmIdx(int) const;
	bool checkBckPass(float);
	int getFrameCtrl(int);
	bool checkAnmFileExist(char const *fileName, int);

	void perform(unsigned long, TGraphics *);
	void matAnmFrameUpdate();
	void frameUpdate();
	void entry();

	void setLightType(int lightType);
	void setLightID(short lightID);
	void viewCalc();
	void calc();
	void calcAnim();

	void resetDL();
	
	int _0;
	int _4;
	int _8;
	int _C;
	int _10;
	int _14;
	int _18;
	int _1C;
	int _20;
	int _24;
	int* _28;
	int _2C;
	int _30;
	int _34;
	char _38;
	char _39;
	char _3A; // padding?
	char _3B; // ^^
	int lightID; // _3C
	char _40;
	char _41; // padding?
	char _42; // ^^
	char _43; // ^^
	int lightType; // _44
};

#endif // MACTOR_H