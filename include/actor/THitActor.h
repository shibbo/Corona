#ifndef THITACTOR_H
#define THITACTOR_H

#include "JDrama.h"

// as much as I would love to add this to JDrama, but it's not a part of that namespace
class THitActor : public JDrama::TActor
{
	public:
	THitActor(char const *);
	~THitActor();
	
	bool recieveMessage(THitActor *, u32);
	void initHitActor(u32,  u16, u32, f32, f32, f32, f32);
	void perform(u32, JDrama::TGraphics *);
	void calcEntryRadius();
	
	THitActor** collisionArray; // _44
    u16 collisionArrayCount; // _48
    u16 collisionArrayCap; // _4A
    u32 _4C;
	f32 attackRadius; // _50
    f32 attackHeight; // _54
    f32 recieveRadius; // _58
    f32 recieveHeight; // _5C
    f32 _60;
    u32 collisionFlags; // _64
};

#endif // THITACTOR_H