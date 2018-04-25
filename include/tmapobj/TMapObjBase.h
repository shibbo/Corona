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
	u8* objName; // _0
	f32 _4; // this might not even be a f32
	u8* _8; // manager?
	u8* _C; // manager 2?
	u32* animInfo; // _10
	u32* hitInfo; // _14
	u32* collisionInfo; // _18
	u32* soundInfo; // _1C
	u32 unused[0x4]; // _20
	f32 _30;
	u32 flag; // _34
	u32 flag2; // _38
};

/* Size -- 0x138 */
class TMapObjBase : public TLiveActor
{
	public:
	TMapObjBase(char const *);
	~TMapObjBase();
	
	void load(JSUMemoryInputStream &);
	void loadAfter();
	void perform(u32, TGraphics *);
	bool recieveMessage(THitActor *, u32);
	u32* getTakingMtx();
	void ensureTakeSituation();
	f32 getRadiusAtY() const;
	u32* getRootJointMtx() const;
	void calcRootMatrix();
	void setGroundCollision();
	void control();
	u32 getShadowType();
	void kill();
	void appear();
	void makeObjAppeared();
	void makeObjDead();
	void changeObjSRT(TVec3<f32> const &, TVec3<f32> const &, TVec3<f32> const &);
	void changeObjMtx(f32* [4]);
	void updateObjMtx();
	void setUpCurrentMapColision();
	void setObjHitData( u16);
	void setModelMtx(f32* [4]);
	void initMapObj();
	void loadBeforeInit();
	void initMapCollisionData();
	void makeMActors();
	u32 getSDLModelFlag() const;
	void checkIllegalAttr() const;
	void calc();
	void draw() const;
	void dead();
	void touchActor(THitActor *);
	void touchPlayer(THitActor *);
	u32 touchWater(THitActor *);
	void touchEnemy(THitActor *);
	void touchBoss(THitActor *);
	void makeObjDefault();
	u32 getHitObjNumMax();
	f32 getDepthAtFloating();
	
	// non-vtable functions
	void startSound( u16 soundID);
	bool hasModelOrAnimData() const;
	bool animIsFinished() const;
	bool hasAnim( u16 animID) const;
	void soundBas(u32, f32, f32);
	void setUpMapCollision( u16);
	void setUpCurrentMapCollision();
	void removeMapCollision();
	void sleep();
	void awake();
	void startAnim( u16);
	static void startAllAnim(MActor *, char const *animName);
	void initAndRegister(char const *objName);
	
	bool marioHeadAttack() const;
	bool marioIsOn() const;
	bool marioIsOn(TLiveActor const *actor);
	void sendMsg(u32, u32);
	bool waterHitPlane(THitActor *);
	TVec3<f32> getWaterPos(THitActor *waterActor);
	u32 getWaterSpeed(THitActor *waterActor);
	u32 getWaterPlane(THitActor *waterActor);
	u32 getWaterID(THitActor *waterActor);
	f32 getDistance(TVec3<f32> const &) const;
	void startBck(char const *bckName);
	void startControlAnim( u16);
	void initUnique();
	bool isFruit(THitActor *actor);
	bool isCoin(THitActor *actor);
	static void throwObjFromPointWithRot(TMapObjBase *, TVec3<f32> const &throwFrom, TVec3<f32> const &throwTo, f32, f32);
	void throwObjToFrontFromPoint(TMapObjBase *, TVec3<f32> const &thrownPoint, f32, f32);
	void throwObjToFront(TMapObjBase *obj, f32, f32, f32);
	void checkOnManhole();
	bool isDemo();
	bool isHideObj(THitActor *);
	void joinToGroup(char const *, THitActor *);

	void initModelData();
	void initObjCollisionData();
	
	u8* objName; // _F4
	u32 _F8; // state related
	u16 _FC;
	u16 _FE;
	u16 _100;
	u16 _102;
	u32 _104;
	f32 _108;
	f32 _10C;
	f32 _110;
	f32 _114;
	f32 _118;
	f32 _11C;
	f32 _120;
	f32 _124;
	f32 _128;
	f32 _12C;
	ObjData* objData; // _130
	u32 eventID; // _134
};

#endif // TMAPOBJBASE_H