#ifndef TSMALLENEMY_H
#define TSMALLENEMY_H

#include "JDrama.h"
#include "types.h"
#include "actor/THitActor.h"
#include "actor/TSpineEnemy.h"
#include "actor/item/TCoin.h"
#include "manager/TLiveManager.h"

class TSmallEnemy : public TSpineEnemy
{
	public:
	TSmallEnemy(char const *);
	virtual ~TSmallEnemy();
	
	virtual void load(JSUMemoryInputStream &);
	virtual void loadAfter();
	virtual void perform(u32, JDrama::TGraphics *);
	virtual bool recieveMessage(THitActor *, u32);
	virtual void init(TLiveManager *);
	virtual void moveObject();
	virtual void kill();
	virtual void updateAnmSound();
	virtual void reset();
	virtual void genRandomItem();
	virtual void genEventCoin();
	virtual void generateItem();
	virtual bool isEatenByYosshi();
	virtual void setBehavior();
	virtual void jumpBehavior();
	virtual void behaveToWater(THitActor *);
	virtual bool changeByJuice();
	virtual bool changeMove();
	virtual u32* getChangeBlockTime();
	virtual void scalingChangeActor();
	virtual void changeOut();
	virtual void behaveToTaken(THitActor *);
	virtual void behaveToRelease();
	virtual void setGenerateAnm();
	virtual void setWalkAnm();
	virtual void setDeadAnm();
	virtual void setFreezeAnm();
	virtual void setMeltAnm();
	virtual void setWaitAnm();
	virtual void setRunAnm();
	virtual void attackToMario();
	virtual void forceKill();
	virtual void setMActorAndKeeper();
	virtual void initAttacker(THitActor *);
	virtual bool isHitValid(u32);
	virtual bool isCollidMove(THitActor *);
	virtual bool isInhibitedForceMove();
	virtual void endHitWaterJump();
	virtual void sendAttackMsgToMario();
	virtual void decHpByWater(THitActor *);
	virtual void setBckAnm(u32);
	virtual void setDeadEffect();
	virtual void setAfterDeadEffect();
	virtual u32 doKeepDistance();
	virtual void generateEffectColumWater();
	virtual bool isFindMario(f32);
	
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
	TCoin* spawnedCoin; // _180
	u8 _184; // set to 1 in initAttacker
	u8 _185;
	u8 _186; // padding?
	u8 _187; // ^^
	f32 _188;
	u32 _18C;
};

#endif // TSMALLENEMY_H