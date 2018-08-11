#include <kamek.h>

#include "types.h"
#include "actor/item/TCoin.h"
#include "actor/TMario.h"
#include "dolphin/OS.h"

// timer that we use to see if we can spawn a coin
u32 timeSinceLastCoin = 0;

TMario* SpawnObject(TMario* mario)
{
	// if we reach this point we create a new coin
	if (timeSinceLastCoin > 10)
	{
		// use the "new" keyword to create a new coin
		TCoin* coin = new TCoin("coin");

		// now we set our position based on mario's position
		coin->mPosition.x = mario->mPosition.x;
		coin->mPosition.y = mario->mPosition.y + 200;
		coin->mPosition.z = mario->mPosition.z;
		
		// set our rotation to 0, 0, 0
		coin->mRotation.x = 0;
		coin->mRotation.y = 0;
		coin->mRotation.z = 0;
		
		// set our scale to the normal 1, 1, 1
		coin->mScale.x = 1;
		coin->mScale.y = 1;
		coin->mScale.z = 1;
		
		// we call this to register our coin to tell the system that we will spawn it soon
		coin->initAndRegister("coin");
		
		// now we make it appear
		coin->appear();
		
		// and reset our timer
		timeSinceLastCoin = 0;
	}
	else
		timeSinceLastCoin++;
	
	// we return TMario* to keep the flow of r3 going (as r3 is TMario* and we dont want to change that)
	return mario;
}

kmBranch(0x8024CAD8, SpawnObject);