#ifndef TMAPOBJBASE_H
#define TMAPOBJBASE_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/MActor.h"
#include "actor/THitActor.h"
#include "actor/TLiveActor.h"

using namespace JDrama;
using namespace JGeometry;

struct ObjData
{
	char* objName; // _0
	float _4; // this might not even be a float
	char* _8; // manager?
	char* _C; // manager 2?
	int* animInfo; // _10
	int* hitInfo; // _14
	int* collisionInfo; // _18
	int* soundInfo; // _1C
	int unused[0x4]; // _20
	float _30;
	int flag; // _34
	int flag2; // _38
};

/* Size -- 0x138 */
class TMapObjBase : public TLiveActor
{
	public:
	TMapObjBase(char const *);
	~TMapObjBase();
	
	void load(JSUMemoryInputStream &);
	void loadAfter();
	void perform(unsigned long, TGraphics *);
	bool recieveMessage(THitActor *, unsigned long);
	int* getTakingMtx();
	void ensureTakeSituation();
	float getRadiusAtY() const;
	int* getRootJointMtx() const;
	void calcRootMatrix();
	void setGroundCollision();
	void control();
	int getShadowType();
	void kill();
	void appear();
	void makeObjAppeared();
	void makeObjDead();
	void changeObjSRT(TVec3<float> const &, TVec3<float> const &, TVec3<float> const &);
	void changeObjMtx(float* [4]);
	void updateObjMtx();
	void setUpCurrentMapColision();
	void setObjHitData(unsigned short);
	void setModelMtx(float* [4]);
	void initMapObj();
	void loadBeforeInit();
	void initMapCollisionData();
	void makeMActors();
	int getSDLModelFlag() const;
	void checkIllegalAttr() const;
	void calc();
	void draw() const;
	void dead();
	void touchActor(THitActor *);
	void touchPlayer(THitActor *);
	int touchWater(THitActor *);
	void touchEnemy(THitActor *);
	void touchBoss(THitActor *);
	void makeObjDefault();
	int getHitObjNumMax();
	float getDepthAtFloating();
	
	// non-vtable functions
	void startSound(unsigned short soundID);
	bool hasModelOrAnimData() const;
	bool animIsFinished() const;
	bool hasAnim(unsigned short animID) const;
	void soundBas(unsigned long, float, float);
	void setUpMapCollision(unsigned short);
	void setUpCurrentMapCollision();
	void removeMapCollision();
	void sleep();
	void awake();
	void startAnim(unsigned short);
	static void startAllAnim(MActor *, char const *animName);
	void initAndRegister(char const *objName);
	
	bool marioHeadAttack() const;
	bool marioIsOn() const;
	bool marioIsOn(TLiveActor const *actor);
	void sendMsg(unsigned long, unsigned long);
	bool waterHitPlane(THitActor *);
	TVec3<float> getWaterPos(THitActor *waterActor);
	int getWaterSpeed(THitActor *waterActor);
	int getWaterPlane(THitActor *waterActor);
	int getWaterID(THitActor *waterActor);
	float getDistance(TVec3<float> const &) const;
	void startBck(char const *bckName);
	void startControlAnim(unsigned short);
	void initUnique();
	bool isFruit(THitActor *actor);
	bool isCoin(THitActor *actor);
	static void throwObjFromPointWithRot(TMapObjBase *, TVec3<float> const &throwFrom, TVec3<float> const &throwTo, float, float);
	void throwObjToFrontFromPoint(TMapObjBase *, TVec3<float> const &thrownPoint, float, float);
	void throwObjToFront(TMapObjBase *obj, float, float, float);
	void checkOnManhole();
	bool isDemo();
	bool isHideObj(THitActor *);
	void joinToGroup(char const *, THitActor *);

	void initModelData();
	void initObjCollisionData();
	
	char* objName; // _F4
	int _F8; // state related
	short _FC;
	short _FE;
	short _100;
	short _102;
	int _104;
	float _108;
	float _10C;
	float _110;
	float _114;
	float _118;
	float _11C;
	float _120;
	float _124;
	float _128;
	float _12C;
	ObjData* objData; // _130
	int eventID; // _134
};

#endif // TMAPOBJBASE_H