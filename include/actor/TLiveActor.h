#ifndef TLIVEACTOR_H
#define TLIVEACTOR_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/MActor.h"
#include "actor/TRidingInfo.h"
#include "actor/TSpineBase.h"
#include "actor/TTakeActor.h"
#include "manager/TLiveManager.h"
#include "sound/MAnmSound.h"

/* Size -- 0xF4 */
class TLiveActor : public TTakeActor
{
	public:
	TLiveActor(char const *);
	virtual ~TLiveActor();
	
	virtual void load(JSUMemoryInputStream &);
	virtual void perform(u32, JDrama::TGraphics *);
	virtual bool recieveMessage(THitActor *, u32);
	virtual Mtx* getTakingMtx();
	virtual bool belongToGround() const;
	virtual Mtx* getRootJointMtx() const;
	virtual void init(TLiveManager *);
	virtual void calcRootMatrix();
	virtual void setGroundCollision();
	virtual void control();
	virtual void bind();
	virtual void moveObject();
	virtual void requestShadow();
	virtual void drawObject(JDrama::TGraphics *);
	virtual void performOnlyDraw(u32, JDrama::TGraphics *);
	virtual u32 getShadowType();
	virtual void kill();
	virtual f32 getGravityY() const;
	virtual bool hasMapCollision() const;
	virtual void getFocalPoint() const;
	virtual void updateAnmSound();
	virtual u32 getBasNameTable() const;
	
	MActor* getMActor() const;
	void stopAnmSound();
	void setCurAnmSound();
	void setAnmSound(char const *);
	void initAnmSound();
	void getJointTransByIndex(int, JGeometry::TVec3<f32> *) const;
	void calcVelocityToJumpToY(JGeometry::TVec3<f32> const &, f32, f32) const;
	void initLodAnm(u32 *, int, f32); // TLodAnmIndex
	u32* getModel() const;
	void calcRideMomentum();
	void calcRidePos();
	
	TLiveManager* mLiveManager; // _70
	MActor* mActor; // _74
	u32* _78; // TMActorKeeper
	u16 _7C;
	u16 _7E; // padding?
	MAnmSound* mAnmSound; // _80
	u32 _84;
	u32* _88;
	TSpineBase<TLiveActor>* mObjAI; // _8C
	u32* _90;
	JGeometry::TVec3<f32> mObjMovement; // _94
	JGeometry::TVec3<f32> mCurRotation; // _A0
	JGeometry::TVec3<f32> mVelocity; // _AC
	f32 _B8;
	f32 mActorBodyRadius; // _BC
	f32 _C0;
	u32* _C4; // TMapCollisionData::mIllegalCheckData
	f32 _C8; // gravity X?
	f32 mGravityY; // _CC
	u32 _D0;
	TRidingInfo mRidingInfo; // _D4
	f32 _E4;
	u8 _E8;
	u8 _E9; // padding?
	u8 _EA; // ^^
	u8 _EB; // ^^
	u32* _EC; // TMapCollisionBase*
	u32 mFlags; // _F0
};

#endif // TLIVEACTOR_H