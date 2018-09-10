#ifndef TMAPOBJGENERAL_H
#define TMAPOBJGENERAL_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/THitActor.h"
#include "tmapobj/TMapObjBase.h"

class TMapObjGeneral : public TMapObjBase
{
	public:
	TMapObjGeneral(char const *);
	virtual ~TMapObjGeneral();
	
	virtual void load(JSUMemoryInputStream &);
	virtual void loadAfter();
	virtual void perform(u32, JDrama::TGraphics *);
	virtual bool recieveMessage(THitActor *, u32);
	virtual void ensureTakeSituation();
	virtual void calcRootMatrix();
	virtual void control();
	virtual void bind();
	virtual void kill();
	virtual void appear();
	virtual void initMapObj();
	virtual void checkIllegalAttr() const;
	virtual void touchPlayer(THitActor *);
	virtual u32 touchWater(THitActor *);
	virtual u32 getLivingTime() const;
	virtual u32 getFlushTime() const;
	virtual bool isPollutedGround(JGeometry::TVec3<f32> const &);
	virtual void work();
	virtual void appearing();
	virtual void appeared();
	virtual void breaking();
	virtual void sinking();
	virtual void holding();
	virtual void waitingToRecover();
	virtual void recovering();
	virtual void waitingToAppear();
	virtual void touchingPlayer();
	virtual void touchingWater();
	virtual void hold(TTakeActor *);
	virtual void put();
	virtual void thrown();
	virtual void sink();
	virtual void recover();
	virtual void waitToAppear(s32 appearTime);
	virtual void makeObjBuried();
	virtual void makeObjRecovered();
	virtual void recieveMessageFromPlayer();
	virtual void calcVelocity();
	virtual void checkGroundCollision(JGeometry::TVec3<f32> *);
	virtual void touchGround(JGeometry::TVec3<f32> *);
	virtual void checkWallCollision(JGeometry::TVec3<f32> *);
	virtual void touch(JGeometry::TVec3<f32> *, u32 *); // TBGWallCheckRecord*
	virtual void checkRoofCollision(JGeometry::TVec3<f32> *);
	virtual void touchRoof(JGeometry::TVec3<f32> *);
	
	THitActor* _138;
	u32 _13C;
	f32 _140;
	f32 _144;

	static f32 mNormalLivingTime;
	static f32 mNormalFlushTime;
	static f32 mNormalFlushInterval;
	static f32 mNormalWaitToAppearTime;
	static f32 mNormalAppearingScaleUp;
	static f32 mNormalThrowSpeedRate;
};

#endif // TMAPOBJGENERAL_H