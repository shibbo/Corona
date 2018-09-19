#ifndef GLOBALS_H
#define GLOBALS_H

#include "JGeometry.h"

#include "actor/THitActor.h"
#include "camera/CPolarSubCamera.h"
#include "camera/TCameraShake.h"
#include "game/TConductor.h"
#include "game/TGCConsole2.h"
#include "game/TMarDirector.h"
#include "game/TMarNameRefGen.h"
#include "manager/RumbleManager.h"
#include "manager/TMapObjManager.h"
#include "manager/TItemManager.h"
#include "map/map.h"
#include "message/TTalk2D2.h"
#include "npc/TBaseNPC.h"
#include "sound/MSound.h"

/* camera */
#define gpCamera (*((CPolarSubCamera **) 0x8040D0A8))
#define gpCameraShake (*((TCameraShake **) 0x8040D0B8))

/* game process stuff */
#define gpConductor (*((TConductor **) 0x8040D110))
#define gpMarDirector (*((TMarDirector **) 0x8040E178))
#define gpMarNameRefGen (*((TMarNameRefGen **) 0x8040E408))
#define gpGCConsole (*(TGCConsole2 **) 0x80902AB4)

/* managers */
#define gpMapObjManager (*((TMapObjManager **) 0x8040DF08))
#define gpItemManager (*((TItemManager **) 0x8040DF10))

/* map */
#define gpMap (*((TMap **) 0x8040DE98))
#define gpMapCollisionData (* ((TMapCollisionData **) 0x8040DEA0))

/* mario */
#define gpMarioOriginal (*((THitActor **) 0x8040E0E8))
#define gpMarioPos (*((JGeometry::TVec3<f32> **) 0x8040E10C))
#define gpMarioSpeedX (*((f32 **) 0x8040E11C))
#define gpMarioSpeedY (*((f32 **) 0x8040E120))
#define gpMarioSpeedZ (*((f32 **) 0x8040E124))
#define gpMarioFlag (*((s32 **) 0x8040E12C))

/* message */
#define gpTalk2D (* ((TTalk2D2 **) 0x8040DDD8))

/* npc */
#define gpCurrentNpc (*((TBaseNPC **) 0x8040DFA8))

/* rumble */
#define SMSRumbleMgr (*((RumbleManager **) 0x8040E0D0))

/* sound */
#define gpMSound (*((MSound **) 0x8040E17C))

#endif // GLOBALS_H