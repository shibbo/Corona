#ifndef TFLAGMANAGER_H
#define TFLAGMANAGER_H

#include "JKR.h"
#include "JSUStream.h"

class TFlagManager
{
	public:
	// doesn't have a ctor or dtor
	bool getBool(unsigned long) const;
	void setFlag(unsigned long, unsigned long);
	char getFlag(unsigned long) const;
	void setShineFlag(unsigned char stageID);
	bool getShineFlag(unsigned char stageID) const;
	void setBlueCoinFlag(unsigned char stageID, unsigned char);
	bool getBlueCoinFlag(unsigned char stageID, unsigned char) const;
	void incGoldCoinFlag(unsigned char stageNo, long howMany);
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
	void save(JSUMemoryOutputStream&);
	void firstStart();
	void restore();
	void load(JSUMemoryInputStream&);
	void setNozzleRight(unsigned char stageID, unsigned char);
	void getNozzleRight(unsigned char stageID, unsigned char) const;	

	char _0[0x78];
	int _78;
	int _7C;
	int _80;
	int _84;
	int _88;
	int _8C;
	int _90;
	int _94;
	int _98;
	int _9C;
	int _A0;
	int _A4;
	int _A8;
	int _AC;
	int _B0;
	int _B4;
	char _B8[0x37C-0xB8];
};

#endif // TFLAGMANAGER_H