#ifndef THITACTOR_H
#define THITACTOR_H

#include "JDrama.h"

class THitActor : public JDrama::TActor
{
	public:
	THitActor(char const *name);
	virtual ~THitActor();
	
	virtual void perform(u32, JDrama::TGraphics *);
	virtual bool recieveMessage(THitActor *reciever, u32 message);

	void initHitActor(u32, u16 collisionArrayCap, s32 collisionFlags, f32 attackRadius, f32 attackHeight, f32 recieveRadius, f32 recieveHeight);
	void calcEntryRadius();
	
	THitActor** mCollisionArray; // _44
    u16 mCollisionArrayCount; // _48
    u16 mCollisionArrayCap; // _4A
    u32 mShadowRelated; // _4C
	f32 mAttackRadius; // _50
    f32 mAttackHeight; // _54
    f32 mRecieveRadius; // _58
    f32 mRecieveHeight; // _5C
    f32 mEntryRadius; // _60
    u32 mCollisionFlags; // _64
};

#endif // THITACTOR_H