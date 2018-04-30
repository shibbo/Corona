#ifndef TLIVEMANAGER_H
#define TLIVEMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"
#include "manager/TObjManager.h"
#include "spc/TSpcBinary.h"

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
	
	TSpcBinary* spc; // _34 
};

#endif // TLIVEMANAGER_H