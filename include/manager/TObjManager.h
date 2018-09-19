#ifndef TOBJMANAGER_H
#define TOBJMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"
#include "obj/TObjChara.h"

/* Size -- 0x34 */
class TObjManager : public JDrama::TViewObj
{
	public:
	TObjManager(char const *);
	virtual ~TObjManager();
	
	virtual void load(JSUMemoryInputStream &);
	virtual TObjManager* searchF(s16, char const *);
	virtual void perform(JDrama::TGraphics *);
	virtual void createModelData();
	virtual void createAnmData();

	void manageObj(THitActor *);
	
	s32 mMaxObjs; // _10
	u32 _14; // I think this is obj number
	u32* _18;
	TObjChara* _1C;
	u32 _20;
	u32 _24;
	u32 _28;
	u32 _2C;
	u32 _30;
};

#endif // TOBJMANAGER_H