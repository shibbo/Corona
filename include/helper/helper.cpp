#include "helper.h"
#include "os.h"

void makeShineAppear(ShineSpawnType type, f32 xPos, f32 yPos, f32 zPos)
{
    switch (type)
    {
        case SHINE_BOSS:
            itemManager->makeShineAppearWithDemo("シャイン（ボス用）", "ボスシャインカメラ", xPos, yPos, zPos);
            break;
        case SHINE_100_COIN:
            itemManager->makeShineAppearWithDemo("シャイン（１００枚コイン用）", "シャイン（１００枚コイン用）カメラ", xPos, yPos, zPos);
            break;
        default:
            OSReport("Spawn type not supported / not found.\n");
            break;
    }
}

// notice: this introduces a bug with the 100 coin shine
void incCoins(u32 howMany)
{
    flagManager->incGoldCoinFlag(SMS_getShineStage((u8)0x803E970E), howMany);
}

void incLives(u32 howMany)
{
    // get the flag that has our lives
    s32 curLives = flagManger->getFlag(0x20001);

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
    flagManager->incMario(howMany);

    // pretty effect
    mario->emitGetEffect();
}

void killMario()
{
    mario->loserExec();
}

void changeYoshiColor(u8 r, u8 g, u8 b)
{
    if (mario->yoshi == nullptr)
    {
        OSReport("Can't get a Yoshi that doesn't exist, now can we?\n");
        return;
    }

    mario->yoshi->colorR = r;
    mario->yoshi->colorG = g;
    mario->yoshi->colorB = b;
}

void changeYoshiFruit(Fruits fruit)
{
    if (mario->yoshi == nullptr)
    {
        OSReport("Can't get a Yoshi that doesn't exist, now can we?\n");
        return;
    }

    mario->yoshi->wantedFruit = fruit;
}