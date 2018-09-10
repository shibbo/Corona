#ifndef THITACTOR_H
#define THITACTOR_H

#include "JDrama.h"

enum CollisionFlags
{
	None 			= 0x00000000,
	PlayerRelated  	= 0x40000000,
	Water			= 0x5C000000,
	Unknown1        = 0x68000000, // used by pondskaters
	Unknown2     	= 0x70000000, // used by yoshi and other generators
	ThrowActor 		= 0x7F000000,
	KnockbackActor 	= 0x80000000
};

// as much as I would love to add this to JDrama, but it's not a part of that namespace
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
    u32 _4C;
	f32 mAttackRadius; // _50
    f32 mAttackHeight; // _54
    f32 mRecieveRadius; // _58
    f32 mRecieveHeight; // _5C
    f32 mEntryRadius; // _60
    u32 mCollisionFlags; // _64
};

#endif // THITACTOR_H