#ifndef TTAKEACTOR_H
#define TTAKEACTOR_H

#include "JGeometry.h"
#include "actor/THitActor.h"

using namespace JGeometry;

/* Size -- 0x70 */
class TTakeActor : public THitActor
{
	public:
	~TTakeActor();
	
	void ensureTakeSituation();
	int moveRequest(TVec3<float> const &);
	float getRadiusAtY(float) const;
	bool isTaken() const;
	
	TTakeActor* takenActor; // _68
	THitActor* hitActor; // _6C
};

#endif // TTAKEACTOR_H