#ifndef TWATERGUN_H
#define TWATERGUN_H

#include "actor/TMario.h"
#include "actor/TNozzleBase.h"

class TWaterGun
{
	public:
	TWaterGun(TMario *);
	
	int* vtable; // _0
	int _4;
	TMario* mario; // _8
	TNozzleBase nozzleBase1; // _C
	
};

#endif // TWATERGUN_H