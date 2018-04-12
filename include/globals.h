#ifndef GLOBALS_H
#define GLOBALS_H

// definitions for a lot of pointers in the game, especially classes
#include "common.h"
#include "actor/TMario.h"
#include "manager/RumbleManager.h"
#include "manager/TFlagManager.h"
#include "manager/TItemManager.h"
#include "TMarDirector.h"

static TMarDirector* marDirector = (TMarDirector*)(SDA_ADDR_NUS - 0x6048);
static TFlagManager* flagManager = (TFlagManager*)(SDA_ADDR_NUS - 0x6060);
static TMario* mario = (TMario*)(SDA_ADDR_NUS - 0x60D8);
static RumbleMgr* rumbleMgr = (RumbleMgr*)(SDA_ADDR_NUS - 0x60F0);
static TItemManager* itemManager = (TItemManager*)(SDA_ADDR_NUS - 0x62B0);


#endif // GLOBALS_H