#ifndef GLOBALS_H
#define GLOBALS_H

#include "JGeometry.h"

#include "camera/CPolarSubCamera.h"
#include "camera/TCameraShake.h"
#include "game/TConductor.h"
#include "game/TMarDirector.h"
#include "manager/TMapObjManager.h"
#include "manager/TItemManager.h"
#include "sound/MSound.h"

/* camera */
#define gpCamera (*((CPolarSubCamera **)0x8040D0A8))
#define gpCameraShake (*((TCameraShake **)0x8040D0B8))

/* game process stuff */
#define gpConductor (*((TConductor **)0x8040D110))
#define gpMarDirector (*((TMarDirector **)0x8040E178))

/* managers */
#define gpMapObjManager (*((TMapObjManager **)0x8040DF08))
#define gpItemManager (*((TItemManager **)0x8040DF10))

/* mario */
#define gpMarioPos (*((JGeometry::TVec3<f32> **) 0x8040E10C))

/* sound */
#define gpMSound (*((MSound **)0x8040E17C))

#endif // GLOBALS_H