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
	~TMapObjGeneral();
	
	void load(JSUMemoryInputStream &);
	void loadAfter();
	void perform(u32, JDrama::TGraphics *);
	bool recieveMessage(THitActor *, u32);
	void ensureTakeSituation();
	void calcRootMatrix();
	void control();
	void bind();
	void kill();
	void appear();
	void initMapObj();
	void checkIllegalAttr() const;
	void touchPlayer(THitActor *);
	u32 touchWater(THitActor *);
	u32 getLivingTime() const;
	u32 getFlushTime() const;
	bool isPollutedGround(JGeometry::TVec3<f32> const &);
	void work();
	void appearing();
	void appeared();
	void breaking();
	void sinking();
	void holding();
	void waitingToRecover();
	void recovering();
	void waitingToAppear();
	void touchingPlayer();
	void touchingWater();
	void hold(TTakeActor *);
	void put();
	void thrown();
	void sink();
	void recover();
	void waitToAppear(int);
	void makeObjBuried();
	void makeObjRecovered();
	void recieveMessageFromPlayer();
	void calcVelocity();
	void checkGroundCollision(JGeometry::TVec3<f32> *);
	void touchGround(JGeometry::TVec3<f32> *);
	void checkWallCollision(JGeometry::TVec3<f32> *);
	void touch(JGeometry::TVec3<f32> *, u32 *); // TBGWallCheckRecord*
	void checkRoofCollision(JGeometry::TVec3<f32> *);
	void touchRoof(JGeometry::TVec3<f32> *);
	
	THitActor* _138;
	u32 _13C;
	f32 _140;
	f32 _144;
};

#endif // TMAPOBJGENERAL_H