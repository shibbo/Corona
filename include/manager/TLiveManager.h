#ifndef TLIVEMANAGER_H
#define TLIVEMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"
#include "manager/TObjManager.h"

using namespace JDrama;

class TLiveManager : public TObjManager
{
	public:
	TLiveManager(char const *);
	~TLiveManager();

	void load(JSUMemoryInputStream &);
	void perform(u32, TGraphics *);
	void clipActors(TGraphics *);
	void setFlagOutOfCube();
	void createSpcBinary();
	bool hasMapCollsion() const;
	
	u32 _34; // *TSpcBinary
};

#endif // TLIVEMANAGER_H