#ifndef TMAPSTATICOBJ_H
#define TMAPSTATICOBJ_H

#include "JDrama.h"
#include "JSUStream.h"
#include "MActor.h"
#include "THitActor.h"

/* Size -- 0x80 */
class TMapStaticObj : public THitActor
{
	public:
	TMapStaticObj(char const *);
	~TMapStaticObj();
	
	void load(JSUMemoryStream &);
	void loadAfter();
	void perform(u32, JDrama::TGraphics *);
	void init(char const *);
	void initUnique();
	void initModel(char const *);
	u32* getModelData() const;
	
	u8* actorName; // _68
	u8* modelName; // _6C
	MActor* actor; // _70
	u32 _74;
	u32 _78;
	u32 _7C;
};

#endif // TMAPSTATICOBJ_H