#ifndef TLIVEMANAGER_H
#define TLIVEMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
#include "manager/TObjManager.h"

using namespace JDrama;

class TLiveManager : public TObjManager
{
	public:
	TLiveManager(char const *);
	~TLiveManager();

	void load(JSUMemoryInputStream &);
	void perform(unsigned long, TGraphics *);
	void clipActors(TGraphics *);
	void setFlagOutOfCube();
	void createSpcBinary();
	bool hasMapCollsion() const;
	
	int _34; // *TSpcBinary
};

#endif // TLIVEMANAGER_H