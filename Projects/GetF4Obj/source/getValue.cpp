#include <kamek.h>

#include "tmapobj/TMapObjGeneral.h"
#include "os.h"

TMapObjGeneral* GetValue(TMapObjGeneral *obj)
{
	// gets 0xF4 from objects and prints them to the console
	OSReport("0xF4: %s\n", obj->_F4);
	
	return obj;
}

// patches our function so that when we exit, we go to 0x801B4020
kmPatchExitPoint(GetValue, 0x801B4020);
kmBranch(0x801B401C, GetValue);