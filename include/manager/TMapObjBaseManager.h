#ifndef TMAPOBJBASEMANAGER_H
#define TMAPOBJBASEMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
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
	TMapObjBase* makeObjAppeared(unsigned long);
	TMapObjBase* makeObjAppear(unsigned long);
	TMapObjBase* makeObjAppear(float, float, float, unsigned long, bool);

	static TMapObjBase* newAndRegisterObjByEventID(unsigned long, char const *);
	
	float _38; // clip actor related
	float _3C; // ^^
};

#endif // TMAPOBJBASEMANAGER_H