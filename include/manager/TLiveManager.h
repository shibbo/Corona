#ifndef TLIVEMANAGER_H
#define TLIVEMANAGER_H

#include "manager/TObjManager.h"
#include "spc/TSpcBinary.h"

class TLiveManager : public TObjManager
{
	public:
	TLiveManager(char const *);
	virtual ~TLiveManager();

	virtual void load(JSUMemoryInputStream &);
	virtual void perform(u32, JDrama::TGraphics *);
	virtual void clipActors(JDrama::TGraphics *);
	virtual void setFlagOutOfCube();
	virtual void createSpcBinary();
	virtual bool hasMapCollsion() const;
	
	TSpcBinary* mSpcBinary; // _34 
};

#endif // TLIVEMANAGER_H