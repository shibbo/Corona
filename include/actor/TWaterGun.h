#ifndef TWATERGUN_H
#define TWATERGUN_H

#include "types.h"
#include "actor/TMario.h"
#include "actor/TNozzleBase.h"

class TWaterGun
{
	public:
	TWaterGun(TMario *);
	
	u32* vtable; // _0
	u32 _4;
	TMario* mario; // _8
	TNozzleBase nozzleBase1; // _C
	
};

#endif // TWATERGUN_H