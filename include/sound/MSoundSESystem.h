#ifndef MSOUNDSESYSTEM_H
#define MSOUNDSESYSTEM_H

#include "JGeometry.h"
#include "types.h"
#include "sound/JAISound.h"

using namespace JGeometry;

namespace MSoundSESystem
{
    class MSoundSE
    {
        public:
        static void startSoundNpcActor(u32, TVec3<f32> const *, u32, JAISound **, u32,  u8);
        static bool checkSoundArea(u32, TVec3<f32> const &);
        static void startSoundActorWithInfo(u32, TVec3<f32> const *, TVec3<f32> *, f32, u32, u32, JAISound **, u32,  u8); 
        static void startSoundSystemSE(u32, u32, JAISound **, u32);
        static void startSoundActor(u32, TVec3<f32> const *, u32, JAISound **, u32,  u8);
        static u32 getRandomID(u32);
        static void construct();
    };
};

#endif // MSOUNDSESYSTEM_H