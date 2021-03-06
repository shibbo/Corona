#ifndef MACTOR_H
#define MACTOR_H

#include "JDrama.h"
#include "types.h"

class MActorAnmData
{
	public:
	MActorAnmData();
	
	void init(char const *, char const **);
	u32 partsNameToIndx(char const *);
	
	u32 _0;
	u32* _4; // _4->_4 = *J3DModelData
	u32 _8;
	u32 _C;
	u32 _10;
	u32 _14;
	u32 _18;
	u32 _1C;
	u32 _20;
	u32 _24;
	u32 _28;
	u32 _2C;
	u32 _30;
	u32 _34;
	u32 _38;
	u32 _3C;
	u32 _40;
	u32 _44;
	u32 _48;
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
	void setFrameRate(f32, int);
	int getCurAnmIdx(int) const;
	bool checkBckPass(f32);
	int getFrameCtrl(int);
	bool checkAnmFileExist(char const *fileName, int);

	void perform(u32, JDrama::TGraphics *);
	void matAnmFrameUpdate();
	void frameUpdate();
	void entry();

	void setLightType(u32 lightType);
	void setLightID(u16 lightID);
	void viewCalc();
	void calc();
	void calcAnim();

	void resetDL();
	void setJointCallback(int, int (*)(J3DNode *, int));
	
	u32 _0;
	u32 _4;
	u32 _8;
	u32 _C;
	u32 _10;
	u32 _14;
	u32 _18;
	u32 _1C;
	u32 _20;
	u32 _24;
	u32* _28;
	u32 _2C;
	u32 _30;
	u32 _34;
	u8 _38;
	u8 _39;
	u8 _3A; // padding?
	u8 _3B; // ^^
	u32 mLightID; // _3C
	u8 _40;
	u8 _41; // padding?
	u8 _42; // ^^
	u8 _43; // ^^
	u32 mLightType; // _44
};

#endif // MACTOR_H