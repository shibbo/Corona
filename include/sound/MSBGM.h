#ifndef MSBGM_H
#define MSBGM_H

#include "types.h"

class MSBgm
{
    public:
    static void setStageBgmYoshiPercussion(bool);
    static void setDolby( u8, f32, u32,  u8);
    static void setPan( u8, f32, u32,  u8);
    static void setVolume(u32, f32, u32,  u8);
    static void setTrackVolume( u8, f32, u32,  u8);
    static void stopTrackBGMs( u8, u32);
    static void stopTrackBGM( u8, u32);
    static void stopBGM(u32, u32);
    static u32* getHandle( u8);
    static u32* startBGM(u32);
    static u32 getSceneNo(u32);
    static void init();
};
#endif // MSBGM_H