#ifndef TSPLINEPATH_H
#define TSPLINEPATH_H

#include "types.h"

class TSplinePath
{
    public:
    TSplinePath(int); // this integer is nodeCount + 3

    f32 calcSpline(f32, f32 *, f32 *, f32 *);
    void calcTable();
    void makeTable(f32 *, f32 *, f32 *);
    void getFloat(f32);

    u32 _0; // said nodeCount + 3 is stored here
    f32* _4;
    f32* _8;
    f32* _C;
    f32* _10;
    f32* _14;
    f32* _18;
    f32* _1C;
    f32* _20;
    f32* _24;
};

#endif // TSPLINEPATH_H