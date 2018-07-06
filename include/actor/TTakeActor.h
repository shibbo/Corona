#ifndef TTAKEACTOR_H
#define TTAKEACTOR_H

#include "JGeometry.h"
#include "types.h"
#include "actor/THitActor.h"

/* Size -- 0x70 */
class TTakeActor : public THitActor
{
	public:
	~TTakeActor();
	
	void ensureTakeSituation();
	u32 moveRequest(JGeometry::TVec3<f32> const &);
	f32 getRadiusAtY(f32) const;
	bool isTaken() const;
	
	TTakeActor* holder; // _68
	TTakeActor* heldActor; // _6C
};

#endif // TTAKEACTOR_H