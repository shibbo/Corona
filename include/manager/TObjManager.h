#ifndef TOBJMANAGER_H
#define TOBJMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"

/* Size -- 0x34 */
class TObjManager : public JDrama::TViewObj
{
	public:
	TObjManager(char const *);
	~TObjManager();
	
	void load(JSUMemoryInputStream &);
	TObjManager* searchF(s16, char const *);
	void perform(JDrama::TGraphics *);
	void createModelData();
	void createAnmData();
	
	u32 _10;
	u32 _14; // I think this is obj number
	u32* _18;
	u32* _1C; // TObjChara*
	u32 _20;
	u32 _24;
	u32 _28;
	u32 _2C;
	u32 _30;
};

#endif // TOBJMANAGER_H