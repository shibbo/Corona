#ifndef GLOBALS_H
#define GLOBALS_H

// definitions for a lot of pointers in the game, especially classes
#include "common.h"
#include "JGeometry.h"
#include "JKR.h"
#include "TConductor.h"
#include "TMarDirector.h"
#include "TMarNameRefGen.h"
#include "types.h"
#include "actor/TMario.h"
#include "camera/CPolarSubCamera.h"
#include "camera/TCameraMarioData.h"
#include "jpa/JPAResourceManager.h"
#include "manager/RumbleManager.h"
#include "manager/TFlagManager.h"
#include "manager/TItemManager.h"
#include "manager/TMapObjManager.h"
#include "sound/MSound.h"

// globals are in their own category, ordered by lowest address to highest

/* OS Related globals */
static u32 aramSize = (u32)(SDA_ADDR_NUS - 0x5834);
static u32 arenaHi = (u32)(SDA_ADDR_NUS - 0x5A28);

/* JKR globals */
static JKRHeap** heap = (JKRHeap**)(SDA_ADDR_NUS - 0x5F28);
static JKRFileLoader** sceneVolume = (JKRFileLoader**)(SDA_ADDR_NUS - 0x604C);
static JKRFileLoader** paramsVolume = (JKRFileLoader**)(SDA_ADDR_NUS - 0x6050);

/* Mario globals */
static u32 marioStateFlags = (u32)(SDA_ADDR_NUS - 0x6094);
static f32* marioSpeedZ = (f32*)(SDA_ADDR_NUS - 0x609C);
static f32* marioSpeedY = (f32*)(SDA_ADDR_NUS - 0x60A0);
static f32* marioSpeedX = (f32*)(SDA_ADDR_NUS - 0x60A4);
static JGeometry::TVec3<f32>** marioPos = (JGeometry::TVec3<f32>**)(SDA_ADDR_NUS - 0x60B4);
static TMario** mario = (TMario**)(SDA_ADDR_NUS - 0x60D8);

/* Manager globals */
static JPAResourceManager** jpaRsrcMgr = (JPAResourceManager**)(SDA_ADDR_NUS - 0x5FE0);
static TFlagManager** flagManager = (TFlagManager**)(SDA_ADDR_NUS - 0x6060);
static RumbleMgr** rumbleMgr = (RumbleMgr**)(SDA_ADDR_NUS - 0x60F0);
static TItemManager** itemManager = (TItemManager**)(SDA_ADDR_NUS - 0x62B0);
static TMapObjManager** mapObjManager = (TMapObjManager**)(SDA_ADDR_NUS - 0x62B8);

/* Game process globals */
static TMarNameRefGen** nameRefGen = (TMarNameRefGen**)(SDA_ADDR_NUS - 0x5DB8);
static TMarDirector** marDirector = (TMarDirector**)(SDA_ADDR_NUS - 0x6048);
static TConductor** conductor = (TConductor**)(SDA_ADDR_NUS - 0x70B0);

/* Camera globals */
static CPolarSubCamera** subCamera = (CPolarSubCamera**)(SDA_ADDR_NUS - 0x7118);
static TCameraMarioData** marioCameraData = (TCameraMarioData**)(SDA_ADDR_NUS - 0x7150);

/* Sound globals */
static MSound** mSoundBoot = (MSound**)(SDA_ADDR_NUS - 0x6044); // used on afterBoot
static MSound** mSound = (MSound**)(SDA_ADDR_NUS - 0x7164); // used for mario, etc

#endif // GLOBALS_H