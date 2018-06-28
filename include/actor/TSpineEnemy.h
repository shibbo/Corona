#ifndef TSPINEENEMY_H
#define TSPINEENEMY_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"
#include "types.h"
#include "actor/TLiveActor.h"

/* Size -- 0x150 */
class TSpineEnemy : public TLiveActor
{
	public:
	TSpineEnemy(char const *);
	~TSpineEnemy();
	
	void load(JSUMemoryInputStream &);
	void perform(u32, JDrama::TGraphics *);
	bool recieveMessage(THitActor *, u32);
	void init(TLiveManager *);
	void calcRootMatrix();
	void reset();
	void resetToPosition(JGeometry::TVec3<f32> const &);
	void resetSRTV(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &);
	u32 getSaveParam() const;
	f32 getPhaseShift() const;
	bool isReachedToGoal() const;

	void doShortCut();
	void walkToCurPathNode(f32, f32, f32);
	void turnToCurPathNode(f32);
	void zigzagToCurPathNode(f32, f32, f32, f32);
	
	u32 _F4;
	f32 _F8;
	f32 _FC;
	f32 _100;
	u32 _104;
	f32 _108;
	f32 _10C;
	f32 _110;
	u32 _114;
	u32 _118;
	u32* _11C; // array
	u32 _120;
	u32 _124; // padding?
	u16 _128;
	u16 _12A; // padding?
	f32 _12C;
	u8 _130;
	u8 _131; // padding?
	u8 _132; // ^^
	u8 _133; // ^^
	f32 _134;
	u32* _138;
	u8 health; // _13C
	u8 _13D; // padding?
	u8 _13E; // ^^
	u8 _13F; // ^^
	f32 _140;
	f32 _144;
	f32 _148;
	f32 _14C;
};

#endif // TSPINEENEMY_H