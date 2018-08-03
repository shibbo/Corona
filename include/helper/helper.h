#ifndef HELPER_H
#define HELPER_H

#include "common.h"
#include "globals.h"
#include "types.h"

void makeShineAppear(u32 type, f32 xPos, f32 yPos, f32 zPos);
void incCoins(u32 howMany);
void incLives(u32 howMany);
void changeYoshiColor(u8 r, u8 g, u8 b);

enum ShineSpawnType
{
    SHINE_BOSS,
    SHINE_100_COIN,
    SHINE_NPC,
    SHINE_SIRENA_SINK,
    SHINE_CORK_REMOVE,
    SHINE_BELL_DOLPIC,
    SHINE_MONUMENT,
    SHINE_REVIVE_SUNFLOWER,
    SHINE_WOODBOX_WIN,
};

#endif // HELPER_H