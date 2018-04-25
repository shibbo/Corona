#ifndef JMATH_H
#define JMATH_H

#include "types.h"

namespace JMath
{
    // not a typo :(
    class TRandom_fast_
    {
        public:
        TRandom_fast_(u32);

        u32 get();
        f32 get_ufloat_1();
        
        u32 seed; // _0
    };

    class TRandom_enough_
    {
        public:
        void setSeed(u32);

        u32 _0;
        u32 _4;
    };
};

#endif // JMATH_H