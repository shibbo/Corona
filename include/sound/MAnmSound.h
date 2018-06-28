#ifndef MANMSOUND_H
#define MANMSOUND_H

#include "sound/JAIAnimeSound.h"

class MAnmSound : public JAIAnimeSound
{
    public:
    MAnmSound(u32 *); // MSound *

    void startAnimSound(void *, u32, JAISound **, u32 *, u8); // JAIActor *
    void setSpeedModifySound(JAISound *, u32 *, f32); // JAIAnimeFrameSoundData *
};

#endif // MANMSOUND_H