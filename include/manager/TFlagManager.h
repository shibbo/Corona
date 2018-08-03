#ifndef TFLAGMANAGER_H
#define TFLAGMANAGER_H

#include "JKR.h"
#include "JSUStream.h"
#include "types.h"

#define FLAG_SHINES		0x00004
#define FLAG_REDCOIN 	0x00006
#define FLAG_LIVES 		0x20001
#define FLAG_BLUECOINS	0x40001
#define FLAG_COINS		0x40002

class TFlagManager
{
	public:
	// doesn't have a ctor or dtor
	bool getBool(u64) const;
	void setFlag(u64, s64);
	s8 getFlag(u64) const;
	void setShineFlag(s8 stageID);
	bool getShineFlag(s8 stageID) const;
	void setBlueCoinFlag(s8 stageID, s8);
	bool getBlueCoinFlag(s8 stageID, s8) const;
	void incGoldCoinFlag(s8 stageNo, s64 howMany);
	void incMario(u32 howMany);
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
	void setNozzleRight(s8 stageID, s8 whatNozzle);
	void getNozzleRight(s8 stageID, s8) const;	

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