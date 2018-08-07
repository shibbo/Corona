#ifndef MSOUND_H
#define MSOUND_H

#include "JKR.h"
#include "sound/JAIBasic.h"

class MSound : public JAIBasic
{
    public:
    MSound(JKRHeap *, JKRHeap *, u32, u8 *, u8 *, u32);

    f32 getDistPowFromCamera(Vec const &);
    f32 getDistFromCamera(Vec *);
    void setPlayerInfo(Vec *, Vec *, MtxPtr, bool);
    bool cameraLooksAtMario();
    void startSoundActorSpecial(u32, Vec const *, f32, f32, u32, JAISound **, u32, u8);
    void startBeeSe(Vec *, u32);
    u32 getWallSound(u32, f32);
    bool checkMarioVoicePlaying(u8);
    void stopMarioVoice(u8, u8);
    u32 getMarioVoiceID(u8);
    u32 startMarioVoice(u8, u8);
    void playTimer(u32);

    void stopAllSound();
    
    // todo -- members
};

#endif // MSOUND_H