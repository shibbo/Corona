#ifndef TSMALLENEMY_H
#define TSMALLENEMY_H

#include "JDrama.h"
#include "types.h"
#include "actor/THitActor.h"
#include "manager/TLiveManager.h"
#include "actor/TSpineEnemy.h"

using namespace JDrama;

class TSmallEnemy : public TSpineEnemy
{
	public:
	TSmallEnemy(char const *);
	~TSmallEnemy();
	
	void load(JSUMemoryInputStream &);
	void loadAfter();
	void perform(u32, TGraphics *);
	bool recieveMessage(THitActor *, u32);
	void init(TLiveManager *);
	void moveObject();
	void kill();
	void updateAnmSound();
	void reset();
	void genRandomItem();
	void genEventCoin();
	void generateItem();
	bool isEatenByYosshi();
	void setBehavior();
	void jumpBehavior();
	void behaveToWater(THitActor *);
	bool changeByJuice();
	bool changeMove();
	u32* getChangeBlockTime();
	void scalingChangeActor();
	void changeOut();
	void behaveToTaken(THitActor *);
	void behaveToRelease();
	void setGenerateAnm();
	void setWalkAnm();
	void setDeadAnm();
	void setFreezeAnm();
	void setMeltAnm();
	void setWaitAnm();
	void setRunAnm();
	void attackToMario();
	void forceKill();
	void setMActorAndKeeper();
	void initAttacker(THitActor *);
	bool isHitValid(u32);
	bool isCollidMove(THitActor *);
	bool isInhibitedForceMove();
	void endHitWaterJump();
	void sendAttackMsgToMario();
	void decHpByWater(THitActor *);
	void setBckAnm(u32);
	void setDeadEffect();
	void setAfterDeadEffect();
	u32 doKeepDistance();
	void generateEffectColumWater();
	bool isFindMario(f32);
	
	bool isFindMarioFromParam(f32) const;
	
	u32 _150;
	f32 _154;
	f32 _158;
	u32 _15C;
	u32 _160;
	u8 _164;
	u8 _165;
	u8 _166; // padding?
	u8 _167; // ^^
	u32 _168;  // ^^
	u32 _16C;  // ^^
	u32 _170;  // ^^
	u32 _174;
	u32 _178;
	u32 _17C; // 
	u32 _180;
	u8 _184; // set to 1 in initAttacker
	u8 _185;
	u8 _186; // padding?
	u8 _187; // ^^
	f32 _188;
	u32 _18C;
};

#endif // TSMALLENEMY_H