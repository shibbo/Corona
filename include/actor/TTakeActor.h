#ifndef TTAKEACTOR_H
#define TTAKEACTOR_H

#include "JGeometry.h"
#include "types.h"
#include "actor/THitActor.h"

/* Size -- 0x70 */
class TTakeActor : public THitActor
{
	public:
	virtual ~TTakeActor();
	
	virtual void ensureTakeSituation();
	virtual u32 moveRequest(JGeometry::TVec3<f32> const &destPosition);
	virtual f32 getRadiusAtY(f32) const;
	
	bool isTaken() const;
	
	TTakeActor* mHolder; // _68
	TTakeActor* mHeldActor; // _6C
};

#endif // TTAKEACTOR_H