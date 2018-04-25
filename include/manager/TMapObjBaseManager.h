#ifndef TMAPOBJBASEMANAGER_H
#define TMAPOBJBASEMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"
#include "tmapobj/TMapObjBase.h"
#include "manager/TLiveManager.h"

using namespace JDrama;

class TMapObjBaseManager : public TLiveManager
{
	public:
	TMapObjBaseManager(char const *);
	~TMapObjBaseManager();
	
	void load(JSUMemoryInputStream &);
	void createModelData();
	void clipActors(TGraphics *);
	TMapObjBase* makeObjAppeared(u32);
	TMapObjBase* makeObjAppear(u32);
	TMapObjBase* makeObjAppear(f32, f32, f32, u32, bool);

	static TMapObjBase* newAndRegisterObjByEventID(u32, char const *);
	
	f32 _38; // clip actor related
	f32 _3C; // ^^
};

#endif // TMAPOBJBASEMANAGER_H