#ifndef TCOIN_H
#define TCOIN_H

#include "JDrama.h"
#include "types.h"
#include "actor/TItem.h"
#include "actor/THitActor.h"

class TCoin : public TItem
{
	public:
	TCoin(char const *);
	virtual ~TCoin();
	
	virtual void loadAfter();
	virtual void perform(u32, JDrama::TGraphics *);
	virtual void appear();
	virtual void makeObjAppeared();
	virtual void makeObjDead();
	virtual void initMapObj();
	virtual void taken(THitActor *);
	
	u32 _154;
};

#endif // TCOIN_H