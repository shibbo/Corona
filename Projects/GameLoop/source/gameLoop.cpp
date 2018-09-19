#include <kamek.h>

#include "J2D.h"
#include "SMS.h"
#include "dolphin/OS.h"
#include "game/TMarDirector.h"

#include "globals.h"

// this is ran once
void OnSetup(TMarDirector* director)
{
	// run replaced call
	director->setupObjects();
}

// this is ran every frame
// though using this crashes
s32 OnUpdate(TMarDirector* director)
{
	return director->direct();
}

// this is ran when drawing is needed
void Draw2D(J2DOrthoGraph *graph)
{
	// run replaced call
	graph->setup2D();
}

kmPatchExitPoint(OnSetup, 0x802998BC);
kmBranch(0x802998B8, OnSetup);
//kmPatchExitPoint(OnUpdate, 0x802A6164);
//kmBranch(0x802A6160, OnUpdate);
kmPatchExitPoint(Draw2D, 0x80143F18);
kmBranch(0x80143F14, Draw2D);