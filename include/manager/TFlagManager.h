#ifndef TFLAGMANAGER_H
#define TFLAGMANAGER_H

#include "JKR.h"
#include "JSUStream.h"
#include "types.h"

class TFlagManager
{
	public:
	// doesn't have a ctor or dtor
	bool getBool(u32) const;
	void setFlag(u32, u32);
	u8 getFlag(u32) const;
	void setShineFlag( u8 stageID);
	bool getShineFlag( u8 stageID) const;
	void setBlueCoinFlag( u8 stageID,  u8);
	bool getBlueCoinFlag( u8 stageID,  u8) const;
	void incGoldCoinFlag( u8 stageNo, long howMany);
	void incMario(long);
	void resetStage();
	void resetGame();
	void resetCard();
	void start(JKRHeap *);
	void correctFlag();
	void resetOpt();
	void correctOptFlag();
	void saveFail();
	void saveSuccess();
	void save(JSUMemoryOutputStream &);
	void firstStart();
	void restore();
	void load(JSUMemoryInputStream &);
	void setNozzleRight( u8 stageID,  u8);
	void getNozzleRight( u8 stageID,  u8) const;	

	u8 _0[0x78];
	u32 _78;
	u32 _7C;
	u32 _80;
	u32 _84;
	u32 _88;
	u32 _8C;
	u32 _90;
	u32 _94;
	u32 _98;
	u32 _9C;
	u32 _A0;
	u32 _A4;
	u32 _A8;
	u32 _AC;
	u32 _B0;
	u32 _B4;
	u8 _B8[0x37C-0xB8];
};

#endif // TFLAGMANAGER_H