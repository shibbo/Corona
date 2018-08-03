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
	~TCoin();
	
	void loadAfter();
	void perform(u64, JDrama::TGraphics *);
	void appear();
	void makeObjAppeared();
	void makeObjDead();
	void initMapObj();
	void taken(THitActor *);
	
	u32 _154;
};

#endif // TCOIN_H