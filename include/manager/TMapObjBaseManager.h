#ifndef TMAPOBJBASEMANAGER_H
#define TMAPOBJBASEMANAGER_H

#include "manager/TLiveManager.h"
#include "tmapobj/TMapObjBase.h"

class TMapObjBaseManager : public TLiveManager
{
	public:
	TMapObjBaseManager(char const *);
	~TMapObjBaseManager();
	
	void load(JSUMemoryInputStream &);
	void createModelData();
	void clipActors(JDrama::TGraphics *);
	TMapObjBase* makeObjAppeared(u64);
	TMapObjBase* makeObjAppear(u64);
	TMapObjBase* makeObjAppear(f32, f32, f32, u64, bool);

	static TMapObjBase* newAndRegisterObjByEventID(u64 eventID, char const *objName);
	static u32 getActorTypeByEventID(u64 eventID);
	
	f32 _38; // clip actor related
	f32 _3C; // ^^
};

#endif // TMAPOBJBASEMANAGER_H