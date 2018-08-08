#ifndef JAIBASIC_H
#define JAIBASIC_H

#include "types.h"
#include "sound/JAISound.h"

class JAIBasic
{
    public:
    JAIBasic();

    virtual void initStream();
    virtual void makeSound(u32);
    virtual bool getMapInfoFxline(u32);
    virtual bool getMapInfoGround(u32);
    virtual f32 getMapInfoFxParameter(u32);
    virtual void sendPlayingSeCommand();
    virtual void sendSeAllParameter(JAISound *);
    virtual void setSeExtParameter(JAISound *);
    virtual bool setRegisterTrackCallback();
    virtual void checkStream();
    virtual void checkNextFrameSe();
    virtual void loadGroupWave(int, int);

    u32 _0;
    VTABLE; // _4
    u8 _8[0x38-0x8];
    JAISound* sound; // _38
    u8 _3C[0x50-0x3C];
    char* paramWavePath; // _50
    u8 _54[0x64-0x54];
    char* paramSequenceArchivesPath; // _64
    u8 _64[0x74-0x64];
    char* paramStreamPath; // _74
    u32 _78;
};

#endif // JAIBASIC_H