#ifndef TMAPOBJGENERAL_H
#define TMAPOBJGENERAL_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/THitActor.h"
#include "tmapobj/TMapObjBase.h"

using namespace JDrama;
using namespace JGeometry;

class TMapObjGeneral : public TMapObjBase
{
	public:
	TMapObjGeneral(char const *);
	~TMapObjGeneral();
	
	void load(JSUMemoryInputStream &);
	void loadAfter();
	void perform(unsigned long, TGraphics *);
	bool recieveMessage(THitActor *, unsigned long);
	void ensureTakeSituation();
	void calcRootMatrix();
	void control();
	void bind();
	void kill();
	void appear();
	void initMapObj();
	void checkIllegalAttr() const;
	void touchPlayer(THitActor *);
	int touchWater(THitActor *);
	int getLivingTime() const;
	int getFlushTime() const;
	bool isPollutedGround(TVec3<float> const &);
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
	void hold(TTakeActor*);
	void put();
	void thrown();
	void sink();
	void recover();
	void waitToAppear(long);
	void makeObjBuried();
	void makeObjRecovered();
	void recieveMessageFromPlayer();
	void calcVelocity();
	void checkGroundCollision(TVec3<float> *);
	void touchGround(TVec3<float> *);
	void checkWallCollision(TVec3<float> *);
	void touch(TVec3<float> *, int *); // TBGWallCheckRecord*
	void checkRoofCollision(TVec3<float> *);
	void touchRoof(TVec3<float> *);
	
	THitActor* _138;
	int _13C;
	float _140;
	float _144;
};

#endif // TMAPOBJGENERAL_H