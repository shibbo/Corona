#ifndef TITEMMANAGER_H
#define TITEMMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
#include "manager/TMapObjBaseManager.h"

using namespace JDrama;

/* Size -- 0x7C */
class TItemManager : public TMapObjBaseManager
{
	public:
	TItemManager(char const *);
	~TItemManager();
	
	void load(JSUMemoryInputStream&);
	void loadAfter();
	void perform(unsigned long, TGraphics*);
	bool hasMapCollision() const;
	void makeShineAppearWithDemoOffset(char const *, char const *, float, float, float);
	void makeShineAppearWithDemo(char const *, char const *, float, float, float);
	
	float _40;
	float _44;
	float _48;
	float _4C;
	float _50;
	float _54;
	float _58;
	float _5C;
	float _60;
	float _64;
	float _68; // padding? maybe.
	float _6C;
	float _70;
	float _74;
	int _78;
};

#endif // TITEMMANAGER_H