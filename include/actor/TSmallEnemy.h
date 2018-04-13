#ifndef TSMALLENEMY_H
#define TSMALLENEMY_H

#include "JDrama.h"
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
	void perform(unsigned long, TGraphics *);
	bool recieveMessage(THitActor *, unsigned long);
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
	int* getChangeBlockTime();
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
	bool isHitValid(unsigned long);
	bool isCollidMove(THitActor *);
	bool isInhibitedForceMove();
	void endHitWaterJump();
	void sendAttackMsgToMario();
	void decHpByWater(THitActor *);
	void setBckAnm(int);
	void setDeadEffect();
	void setAfterDeadEffect();
	int doKeepDistance();
	void generateEffectColumWater();
	bool isFindMario(float);
	
	bool isFindMarioFromParam(float) const;
	
	int _150;
	float _154;
	float _158;
	int _15C;
	int _160;
	char _164;
	char _165;
	char _166; // padding?
	char _167; // ^^
	int _168;  // ^^
	int _16C;  // ^^
	int _170;  // ^^
	int _174;
	int _178;
	int _17C; // 
	int _180;
	char _184; // set to 1 in initAttacker
	char _185;
	char _186; // padding?
	char _187; // ^^
	float _188;
	int _18C;
};

#endif // TSMALLENEMY_H