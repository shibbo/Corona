#ifndef JMATH_H
#define JMATH_H

namespace JMath
{
    // not a typo :(
    class TRandom_fast_
    {
        public:
        TRandom_fast_(unsigned long);

        int get();
        float get_ufloat_1();
        
        int seed; // _0
    };

    class TRandom_enough_
    {
        public:
        void setSeed(unsigned long);

        int _0;
        int _4;
    };
};

#endif // JMATH_H