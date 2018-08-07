#ifndef TITEMMANAGER_H
#define TITEMMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"
#include "manager/TMapObjBaseManager.h"

/* Size -- 0x7C */
class TItemManager : public TMapObjBaseManager
{
	public:
	TItemManager(char const *);
	~TItemManager();
	
	void load(JSUMemoryInputStream &);
	void loadAfter();
	void perform(u32, JDrama::TGraphics *);
	bool hasMapCollision() const;
	void makeShineAppearWithDemoOffset(char const *, char const *, f32, f32, f32);
	void makeShineAppearWithDemo(char const *, char const *, f32, f32, f32);
	
	f32 _40;
	f32 _44;
	f32 _48;
	f32 _4C;
	f32 _50;
	f32 _54;
	f32 _58;
	f32 _5C;
	f32 _60;
	f32 _64;
	f32 _68; // padding? maybe.
	f32 _6C;
	f32 _70;
	f32 _74;
	u32 _78;
};

#endif // TITEMMANAGER_H