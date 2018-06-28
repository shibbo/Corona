#ifndef TITEM_H
#define TITEM_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"
#include "actor/THitActor.h"
#include "tmapobj/TMapObjGeneral.h"

class TItem : public TMapObjGeneral
{
	public:
	TItem(char const *);
	~TItem();
	
	void load(JSUMemoryInputStream &);
	void perform(u32, JDrama::TGraphics *);
	u32 recieveMessage(THitActor *, u32);
	void calcRootMatrix();
	void appear();
	void initMapObj();
	void calc();
	void touchPlayer(THitActor *);
	void appearing();
	void appeared();
	void killByTimer(u32);
	void taken(THitActor *);
	
	u32 _148;
	u32 _14C;
	u32 _150;
};

#endif // TITEM_H