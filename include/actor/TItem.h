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
	virtual ~TItem();
	
	virtual void load(JSUMemoryInputStream &);
	virtual void perform(u32, JDrama::TGraphics *);
	virtual bool recieveMessage(THitActor *, u32);
	virtual void calcRootMatrix();
	virtual void appear();
	virtual void initMapObj();
	virtual void calc();
	virtual void touchPlayer(THitActor *);
	virtual void appearing();
	virtual void appeared();
	virtual void killByTimer(int);
	virtual void taken(THitActor *);
	
	u32* _148;
	s32 mKillTimer; // _14C
	u32 _150;

	static f32 mAppearedScaleSpeed;
};

#endif // TITEM_H