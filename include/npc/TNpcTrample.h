#ifndef TNPCTRAMPLE_H
#define TNPCTRAMPLE_H

#include "types.h"

class TNpcTrample
{
    public:
    bool updateTrample(f32, f32 *);
    void startTrample();

    f32 _0;
    u16 _4;
    u16 _6;
};

#endif // TNPCTRAMPLE_H