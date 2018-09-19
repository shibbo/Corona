#ifndef TMAPSTATICOBJ_H
#define TMAPSTATICOBJ_H

#include "JDrama.h"
#include "JSUStream.h"
#include "actor/MActor.h"
#include "actor/THitActor.h"
#include "collision/TMapCollisionManager.h"

/* Size -- 0x80 */
class TMapStaticObj : public THitActor
{
	public:
	TMapStaticObj(char const *);
	virtual ~TMapStaticObj();
	
	virtual void load(JSUMemoryInputStream &);
	virtual void loadAfter();
	virtual void perform(u32, JDrama::TGraphics *);
	
	void init(char const *);
	void initUnique();
	void initModel(char const *);
	u32* getModelData() const;
	
	u8* mActorName; // _68
	u8* mModelName; // _6C
	MActor* mActor; // _70
	TMapCollisionManager* mColMgr; // _74
	s32 mSoundID; // _78
	s32 mSoundID2; // _7C

	static f32** mEffectCoronaScale;
};

#endif // TMAPSTATICOBJ_H