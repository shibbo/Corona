#ifndef TOBJMANAGER_H
#define TOBJMANAGER_H

#include "JDrama.h"
#include "JSUStream.h"

using namespace JDrama;

/* Size -- 0x34 */
class TObjManager : public TViewObj
{
	public:
	TObjManager(char const *);
	~TObjManager();
	
	void load(JSUMemoryInputStream &);
	TObjManager* searchF(unsigned short, char const *);
	void perform(TGraphics *);
	void createModelData();
	void createAnmData();
	
	int _10;
	int _14;
	int _18;
	int* _1C; // TItemManager
	int _20;
	int _24;
	int _28;
	int _2C;
	int _30;
};

#endif // TOBJMANAGER_H