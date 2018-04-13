#ifndef TSPINEENEMY_H
#define TSPINEENEMY_H

#include "JDrama.h"
#include "JGeometry.h"
#include "JSUStream.h"
#include "actor/TLiveActor.h"

using namespace JDrama;
using namespace JGeometry;

/* Size -- 0x150 */
class TSpineEnemy : public TLiveActor
{
	public:
	TSpineEnemy(char const *);
	~TSpineEnemy();
	
	void load(JSUMemoryInputStream &);
	void perform(unsigned long, TGraphics *);
	bool recieveMessage(THitActor *, unsigned long);
	void init(TLiveManager *);
	void calcRootMatrix();
	void reset();
	void resetToPosition(TVec3<float> const &);
	void resetSRTV(TVec3<float> const &, TVec3<float> const &, TVec3<float> const &, TVec3<float> const &);
	int getSaveParam() const;
	float getPhaseShift() const;
	bool isReachedToGoal() const;
	
	int _F4;
	float _F8;
	float _FC;
	float _100;
	int _104;
	float _108;
	float _10C;
	float _110;
	int _114;
	int _118;
	int* _11C; // array
	int _120;
	int _124; // padding?
	short _128;
	short _12A; // padding?
	float _12C;
	char _130;
	char _131; // padding?
	char _132; // ^^
	char _133; // ^^
	float _134;
	int _138;
	char _13C;
	char _13D; // padding?
	char _13E; // ^^
	char _13F; // ^^
	float _140;
	float _144;
	float _148;
	float _14C;
};

#endif // TSPINEENEMY_H