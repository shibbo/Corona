#ifndef TLIVEACTOR_H
#define TLIVEACTOR_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/MActor.h"
#include "actor/TTakeActor.h"
#include "manager/TLiveManager.h"

using namespace JDrama;
using namespace JGeometry;

/* Size -- 0xF4 */
class TLiveActor : public TTakeActor
{
	public:
	TLiveActor(char const *);
	~TLiveActor();
	
	void load(JSUMemoryInputStream &);
	void perform(unsigned long, TGraphics *);
	bool recieveMessage(THitActor *, unsigned long);
	int* getTakingMtx();
	bool belongToGround() const;
	int getRootJointMtx() const;
	void init(TLiveManager *);
	void calcRootMatrix();
	void setGroundCollision();
	void control();
	void bind();
	void moveObject();
	void requestShadow();
	void drawObject(TGraphics *);
	void performOnlyDraw(unsigned long, TGraphics *);
	int getShadowType();
	void kill();
	float getGravityY() const;
	bool hasMapCollision() const;
	void getFocalPoint() const;
	void updateAnmSound();
	int getBasNameTable() const;
	MActor* getMActor() const;
	void stopAnmSound();
	void setCurAnmSound();
	void setAnmSound(char const *);
	void initAnmSound();
	void getJointTransByIndex(int, TVec3<float> *) const;
	void calcVelocityToJumpToY(TVec3<float> const &, float, float) const;
	void initLodAnm(int *, int, float); // TLodAnmIndex
	int* getModel() const;
	void calcRideMomentum();
	void calcRidePos();
	
	int* _70; // TMActorKeeper
	int* _74; // model data related
	int* _78; // TMActorKeeper
	short _7C;
	short _7E; // padding?
	int _80;
	int _84;
	int _88;
	int* _8C;
	int* _90;
	float _94;
	float _98;
	float _9C;
	float _A0;
	float _A4;
	float _A8;
	TVec3<float> velocity; // _AC
	float _B8;
	float _BC;
	float _C0;
	int* _C4; // TMapCollisionData::mIllegalCheckData
	float _C8;
	float _CC;
	int _D0;
	int _D4;
	float _D8;
	float _DC;
	float _E0;
	float _E4;
	char _E8;
	char _E9; // padding?
	char _EA; // ^^
	char _EB; // ^^
	int flags;
	int _F0;
};

#endif // TLIVEACTOR_H