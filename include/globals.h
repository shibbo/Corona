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
#include "include/camera/CPolarSubCamera.h"
#include "jpa/JPAResourceManager.h"
#include "manager/RumbleManager.h"
#include "manager/TFlagManager.h"
#include "manager/TItemManager.h"

/* OS Related globals */
static u32 arenaHi = (u32)(SDA_ADDR_NUS - 0x5A28);

/* other unrelated globals */
static TMarNameRefGen* nameRefGen = (TMarNameRefGen*)(SDA_ADDR_NUS - 0x5DB8);
static JKRHeap* heap = (JKRHeap*)(SDA_ADDR_NUS - 0x5F28);
static JPAResourceManager* jpaRsrcMgr = (JPAResourceManager*)(SDA_ADDR_NUS - 0x5FE0);
static TMarDirector* marDirector = (TMarDirector*)(SDA_ADDR_NUS - 0x6048);
static JKRFileLoader* sceneVolume = (JKRFileLoader*)(SDA_ADDR_NUS - 0x604C);
static JKRFileLoader* paramsVolume = (JKRFileLoader*)(SDA_ADDR_NUS - 0x6050);
static TFlagManager* flagManager = (TFlagManager*)(SDA_ADDR_NUS - 0x6060);
static u32 marioStateFlags = (u32)(SDA_ADDR_NUS - 0x6094);
static JGeometry::TVec3<f32>* marioPos = (JGeometry::TVec3<f32>*)(SDA_ADDR_NUS - 0x60B4);
static TMario* mario = (TMario*)(SDA_ADDR_NUS - 0x60D8);
static RumbleMgr* rumbleMgr = (RumbleMgr*)(SDA_ADDR_NUS - 0x60F0);
static TItemManager* itemManager = (TItemManager*)(SDA_ADDR_NUS - 0x62B0);
static TConductor* conductor = (TConductor*)(SDA_ADDR_NUS - 0x70B0);
static CPolarSubCamera* subCamera = (CPolarSubCamera*)(SDA_ADDR_NUS - 0x7118);

#endif // GLOBALS_H