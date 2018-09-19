#include "helper.h"
#include "SMS.h"
#include "dolphin/OS.h"

TItemManager* gpItemManager = *itemManager;
TFlagManager* gpFlagManager = *flagManager;
TMario* gpMario = *mario;

void makeShineAppear(ShineSpawnType type, f32 xPos, f32 yPos, f32 zPos)
{
    switch (type)
    {
        case SHINE_BOSS:
            gpItemManager->makeShineAppearWithDemo("シャイン（ボス用）", "ボスシャインカメラ", xPos, yPos, zPos);
            break;
        case SHINE_100_COIN:
            gpItemManager->makeShineAppearWithDemo("シャイン（１００枚コイン用）", "シャイン（１００枚コイン用）カメラ", xPos, yPos, zPos);
            break;
        default:
            OSReport("Spawn type not supported / not found.\n");
            break;
    }
}

// notice: this introduces a bug with the 100 coin shine
void incCoins(u32 howMany)
{
    gpFlagManager->incGoldCoinFlag(SMS_getShineStage((u8)0x803E970E), howMany);
}

void incLives(u32 howMany)
{
    // get the flag that has our lives
    s32 curLives = gpFlagManager->getFlag(0x20001);

    // can't add anymore lives!
    if (curLives == 99)
        return;

    // if we add our howMany and it's above 99, wat do?
    if (curLives + howMany > 99)
    {
        // how many do we need for 99?
        // we get that and use that for howMany
        howMany = 99 - curLives;
    }

    // now we actually increment his lives
    gpFlagManager->incMario(howMany);

    // pretty effect
    gpMario->emitGetEffect();
}

void killMario()
{
    gpMario->loserExec();
}

void changeYoshiColor(u8 r, u8 g, u8 b)
{
    if (gpMario->yoshi == nullptr)
    {
        OSReport("Can't get a Yoshi that doesn't exist, now can we?\n");
        return;
    }

    gpMario->yoshi->colorR = r;
    gpMario->yoshi->colorG = g;
    gpMario->yoshi->colorB = b;
}

void changeYoshiFruit(Fruits fruit)
{
    if (gpMario->yoshi == nullptr)
    {
        OSReport("Can't get a Yoshi that doesn't exist, now can we?\n");
        return;
    }

    gpMario->yoshi->mYoshiEgg->mWantedFruit = fruit;
}

JKRMemArchive* openArchive(char *path)
{
    JKRMemArchive* ret;

    void* src = SMSLoadArchive(path, 0, 0, 0);
    bool isMounted = ret->mountFixed(src, 0);

    if (!isMounted)
        return 0;
    
    return ret;
}