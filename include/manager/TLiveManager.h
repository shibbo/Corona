#ifndef TLIVEMANAGER_H
#define TLIVEMANAGER_H

#include "manager/TObjManager.h"
#include "spc/TSpcBinary.h"

class TLiveManager : public TObjManager
{
	public:
	TLiveManager(char const *);
	~TLiveManager();

	void load(JSUMemoryInputStream &);
	void perform(u32, JDrama::TGraphics *);
	void clipActors(JDrama::TGraphics *);
	void setFlagOutOfCube();
	void createSpcBinary();
	bool hasMapCollsion() const;
	
	TSpcBinary* spc; // _34 
};

#endif // TLIVEMANAGER_H