#ifndef TITEMMANAGER_H
#define TITEMMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"
#include "actor/item/TCoin.h"
#include "manager/TMapObjBaseManager.h"

/* Size -- 0x7C */
class TItemManager : public TMapObjBaseManager
{
	public:
	TItemManager(char const *);
	virtual ~TItemManager();
	
	virtual void load(JSUMemoryInputStream &);
	virtual void loadAfter();
	virtual void perform(u32, JDrama::TGraphics *);
	virtual bool hasMapCollision() const;

	TCoin* newAndRegisterCoinReal();
	static void newAndRegisterCoin(u32);
	void makeShineAppearWithDemoOffset(char const *, char const *, f32, f32, f32);
	void makeShineAppearWithDemo(char const *, char const *, f32, f32, f32);
	u32* makeShineAppearWithTime(char const *, int, f32, f32, float, int, int, int);
	void resetNozzleBoxesModel(int);
	
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
	u8 _7C[0x134-0x7C];
	u32 coinType; // _134
};

#endif // TITEMMANAGER_H