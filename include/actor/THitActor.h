#ifndef THITACTOR_H
#define THITACTOR_H

#include "JDrama.h"

// as much as I would love to add this to JDrama, but it's not a part of that namespace
class THitActor : public JDrama::TActor
{
	public:
	THitActor(char const *);
	virtual ~THitActor();
	
	virtual void perform(u32, JDrama::TGraphics *);
	virtual bool recieveMessage(THitActor *, u32);

	void initHitActor(u32, u16, int, f32, f32, f32, f32);
	void calcEntryRadius();
	
	THitActor** mCollisionArray; // _44
    u16 mCollisionArrayCount; // _48
    u16 mCollisionArrayCap; // _4A
    u32 _4C;
	f32 mAttackRadius; // _50
    f32 mAttackHeight; // _54
    f32 mRecieveRadius; // _58
    f32 mRecieveHeight; // _5C
    f32 _60;
    u32 mCollisionFlags; // _64
};

#endif // THITACTOR_H