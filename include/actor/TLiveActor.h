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
	void perform(u32, TGraphics *);
	bool recieveMessage(THitActor *, u32);
	u32* getTakingMtx();
	bool belongToGround() const;
	u32 getRootJointMtx() const;
	void init(TLiveManager *);
	void calcRootMatrix();
	void setGroundCollision();
	void control();
	void bind();
	void moveObject();
	void requestShadow();
	void drawObject(TGraphics *);
	void performOnlyDraw(u32, TGraphics *);
	u32 getShadowType();
	void kill();
	f32 getGravityY() const;
	bool hasMapCollision() const;
	void getFocalPoint() const;
	void updateAnmSound();
	u32 getBasNameTable() const;
	MActor* getMActor() const;
	void stopAnmSound();
	void setCurAnmSound();
	void setAnmSound(char const *);
	void initAnmSound();
	void getJointTransByIndex(u32, TVec3<f32> *) const;
	void calcVelocityToJumpToY(TVec3<f32> const &, f32, f32) const;
	void initLodAnm(u32 *, u32, f32); // TLodAnmIndex
	u32* getModel() const;
	void calcRideMomentum();
	void calcRidePos();
	
	u32* _70; // TMActorKeeper
	u32* _74; // model data related
	u32* _78; // TMActorKeeper
	u16 _7C;
	u16 _7E; // padding?
	u32 _80;
	u32 _84;
	u32 _88;
	u32* _8C;
	u32* _90;
	f32 _94;
	f32 _98;
	f32 _9C;
	f32 _A0;
	f32 _A4;
	f32 _A8;
	TVec3<f32> velocity; // _AC
	f32 _B8;
	f32 _BC;
	f32 _C0;
	u32* _C4; // TMapCollisionData::mIllegalCheckData
	f32 _C8;
	f32 _CC;
	u32 _D0;
	u32 _D4;
	f32 _D8;
	f32 _DC;
	f32 _E0;
	f32 _E4;
	u8 _E8;
	u8 _E9; // padding?
	u8 _EA; // ^^
	u8 _EB; // ^^
	u32 flags;
	u32 _F0;
};

#endif // TLIVEACTOR_H