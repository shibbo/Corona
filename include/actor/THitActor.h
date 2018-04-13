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
	
	bool recieveMessage(THitActor *, unsigned long);
	void initHitActor(unsigned long, unsigned short, int, float, float, float, float);
	void perform(unsigned long, TGraphics *);
	void calcEntryRadius();
	
	int _44;
    short _48;
    short _4A;
    int _4C;
	float _50;
    float _54;
    float radiusAtY; // _58
    float _5C;
    float _60;
    int collisionFlags; // _64
};

#endif // THITACTOR_H