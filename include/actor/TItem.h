#ifndef TITEM_H
#define TITEM_H

#include "JDrama.h"
#include "JSUStream.h"
#include "actor/THitActor.h"
#include "tmapobj/TMapObjGeneral.h"

using namespace JDrama;

class TItem : public TMapObjGeneral
{
	public:
	TItem(char const *);
	~TItem();
	
	void load(JSUMemoryInputStream &);
	void perform(unsigned long, TGraphics *);
	int recieveMessage(THitActor*, unsigned long);
	void calcRootMatrix();
	void appear();
	void initMapObj();
	void calc();
	void touchPlayer(THitActor *);
	void appearing();
	void appeared();
	void killByTimer(int);
	void taken(THitActor *);
	
	int _148;
	int _14C;
	int _150;
};

#endif // TITEM_H