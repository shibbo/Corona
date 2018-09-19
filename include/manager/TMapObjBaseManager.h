#ifndef TMAPOBJBASEMANAGER_H
#define TMAPOBJBASEMANAGER_H

#include "manager/TLiveManager.h"
#include "tmapobj/TMapObjBase.h"

class TMapObjBaseManager : public TLiveManager
{
	public:
	TMapObjBaseManager(char const *);
	virtual ~TMapObjBaseManager();
	
	virtual void load(JSUMemoryInputStream &);
	virtual void createModelData();
	virtual void clipActors(JDrama::TGraphics *);
	TMapObjBase* makeObjAppeared(u32);
	TMapObjBase* makeObjAppear(u32);
	TMapObjBase* makeObjAppear(f32, f32, f32, u32, bool);

	static TMapObjBase* newAndRegisterObjByEventID(u32 eventID, char const *objName);
	static u32 getActorTypeByEventID(u32 eventID);
	
	f32 mClipRadius; // _38
	f32 mFarClip; // _3C
};

#endif // TMAPOBJBASEMANAGER_H