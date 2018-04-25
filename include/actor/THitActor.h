#ifndef THITACTOR_H
#define THITACTOR_H

#include "JDrama.h"

using namespace JDrama;

// as much as I would love to add this to JDrama, but it's not a part of that namespace
class THitActor : public TActor
{
	public:
	THitActor(char const *);
	~THitActor();
	
	bool recieveMessage(THitActor *, u32);
	void initHitActor(u32,  u16, u32, f32, f32, f32, f32);
	void perform(u32, TGraphics *);
	void calcEntryRadius();
	
	u32 _44;
    u16 _48;
    u16 _4A;
    u32 _4C;
	f32 _50;
    f32 _54;
    f32 radiusAtY; // _58
    f32 _5C;
    f32 _60;
    u32 collisionFlags; // _64
};

#endif // THITACTOR_H