#ifndef TMAPOBJBASE_H
#define TMAPOBJBASE_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/MActor.h"
#include "actor/THitActor.h"
#include "actor/TLiveActor.h"

struct AnimationData
{
	char* modelKey; // _0
	int unk[0x9]; // _4
	char* model; // _28
	char* animKey; // _2C
	int _30;
	int _34;
	int _38;
};

struct AnimationInfo
{
	int _0;
	AnimationData* data; // _4
};

struct CollisionData
{
	char* collisionKey; // _0
	int _4;
};

struct CollisionInfo 
{
	int _0;
	CollisionData* collisionData; // _4
};

struct HitTable
{
	f32 _0;
	f32 _4;
	f32 _8;
	f32 _C;
 };

struct HitInfo
{
	int _0;
	int _4;
	int _8;
	HitTable* hitData; // _C
};

struct NormalSoundData 
{
	int _0[0xA];
};

struct SoundInfo 
{
	int _0;
	NormalSoundData* normalSoundData; // _4
};

struct ObjData
{
	u8* objName; // _0
	f32 _4; // this might not even be a f32
	u8* _8; // manager?
	u8* _C; // manager 2?
	AnimationInfo* animInfo; // _10
	HitInfo* hitInfo; // _14
	CollisionInfo* collisionInfo; // _18
	SoundInfo* soundInfo; // _1C
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
	virtual ~TMapObjBase();
	
	virtual void load(JSUMemoryInputStream &);
	virtual void loadAfter();
	virtual void perform(u32, JDrama::TGraphics *);
	virtual bool recieveMessage(THitActor *, u32);
	virtual Mtx* getTakingMtx();
	virtual void ensureTakeSituation();
	virtual f32 getRadiusAtY() const;
	virtual Mtx* getRootJointMtx() const;
	virtual void calcRootMatrix();
	virtual void setGroundCollision();
	virtual void control();
	virtual u32 getShadowType();
	virtual void kill();
	virtual void appear();
	virtual void makeObjAppeared();
	virtual void makeObjDead();
	virtual void changeObjSRT(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &);
	virtual void changeObjMtx(f32* [4]);
	virtual void updateObjMtx();
	virtual void setUpCurrentMapColision();
	virtual void setObjHitData(s16);
	virtual void setModelMtx(f32* [4]);
	virtual void initMapObj();
	virtual void loadBeforeInit();
	virtual void initMapCollisionData();
	virtual u32* makeMActors();
	virtual u32 getSDLModelFlag() const;
	virtual void checkIllegalAttr() const;
	virtual void calc();
	virtual void draw() const;
	virtual void dead();
	virtual void touchActor(THitActor *);
	virtual void touchPlayer(THitActor *);
	virtual u32 touchWater(THitActor *);
	virtual void touchEnemy(THitActor *);
	virtual void touchBoss(THitActor *);
	virtual void makeObjDefault();
	virtual u32 getHitObjNumMax();
	virtual f32 getDepthAtFloating();

	void startSound(s16 soundID);
	bool hasModelOrAnimData() const;
	bool animIsFinished() const;
	bool hasAnim(s16 animID) const;
	void soundBas(u32, f32, f32);
	void setUpMapCollision(s16);
	void setUpCurrentMapCollision();
	void removeMapCollision();
	void sleep();
	void awake();
	void startAnim(s16);
	static void startAllAnim(MActor *, char const *animName);
	void initAndRegister(char const *objName);
	
	bool marioHeadAttack() const;
	bool marioIsOn() const;
	bool marioIsOn(TLiveActor const *actor);
	void sendMsg(u32, u32);
	bool waterHitPlane(THitActor *);
	JGeometry::TVec3<f32> getWaterPos(THitActor *waterActor);
	u32 getWaterSpeed(THitActor *waterActor);
	u32 getWaterPlane(THitActor *waterActor);
	u32 getWaterID(THitActor *waterActor);
	f32 getDistance(JGeometry::TVec3<f32> const &) const;
	void startBck(char const *bckName);
	void startControlAnim(s16);
	void initUnique();
	bool isFruit(THitActor *actor);
	bool isCoin(THitActor *actor);
	static void throwObjFromPointWithRot(TMapObjBase *, JGeometry::TVec3<f32> const &throwFrom, JGeometry::TVec3<f32> const &throwTo, f32, f32);
	void throwObjToFrontFromPoint(TMapObjBase *, JGeometry::TVec3<f32> const &thrownPoint, f32, f32);
	void throwObjToFront(TMapObjBase *obj, f32, f32, f32);
	void checkOnManhole();
	bool isDemo();
	bool isHideObj(THitActor *);
	static void joinToGroup(char const *, THitActor *);

	void initModelData();
	void initObjCollisionData();

	static void makeLowerStr(char const *, char const *);
	MActor* initMActor(char const *, char const *, u32);
	void setJointScaleY(J3DJoint *joint, f32 scale);
	static f32 getJointScaleY(J3DJoint *);
	static void setJointTransY(J3DJoint *, f32);
	void newAndInitBuildingCollisionMove(int, TLiveActor *);
	void newAndInitBuildingCollisionWarp(int,TLiveActor *);
	
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