#include <kamek.h>

#include "types.h"
#include "os.h"
#include "actor/item/TCoin.h"
#include "actor/TMario.h"

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
		coin->position.x = mario->position.x;
		coin->position.y = mario->position.y + 200;
		coin->position.z = mario->position.z;
		
		// set our rotation to 0, 0, 0
		coin->rotation.x = 0;
		coin->rotation.y = 0;
		coin->rotation.z = 0;
		
		// set our scale to the normal 1, 1, 1
		coin->scale.x = 1;
		coin->scale.y = 1;
		coin->scale.z = 1;
		
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