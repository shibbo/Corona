#ifndef MSOUNDSESYSTEM_H
#define MSOUNDSESYSTEM_H

#include "JGeometry.h"
#include "sound/JAISound.h"

using namespace JGeometry;

namespace MSoundSESystem
{
    class MSoundSE
    {
        public:
        static void startSoundNpcActor(unsigned long, TVec3<float> const *, unsigned long, JAISound **, unsigned long, unsigned char);
        static bool checkSoundArea(unsigned long, TVec3<float> const &);
        static void startSoundActorWithInfo(unsigned long, TVec3<float> const *, TVec3<float> *, float, unsigned long, unsigned long, JAISound **, unsigned long, unsigned char); 
        static void startSoundSystemSE(unsigned long, unsigned long, JAISound **, unsigned long);
        static void startSoundActor(unsigned long, TVec3<float> const *, unsigned long, JAISound **, unsigned long, unsigned char);
        static int getRandomID(unsigned long);
        static void construct();
    };
};

#endif // MSOUNDSESYSTEM_H