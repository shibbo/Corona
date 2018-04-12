#ifndef TCOIN_H
#define TCOIN_H

#include "actor/TItem.h"
#include "actor/THitActor.h"
#include "JDrama.h"

using namespace JDrama;

class TCoin : public TItem
{
	public:
	TCoin(char const *);
	~TCoin();
	
	void loadAfter();
	void perform(unsigned long, TGraphics*);
	void appear();
	void makeObjAppeared();
	void makeObjDead();
	void initMapObj();
	void taken(THitActor*);
	
	int _154;
};

#endif // TCOIN_H