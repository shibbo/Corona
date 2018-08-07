#ifndef TGRAPHTRACER_H
#define TGRAPHTRACER_H

#include "types.h"

class TGraphTracer
{
    public:
    TGraphTracer();

    u32 getCurGraphIndex() const;
    u32* getGraph() const;
    u32 traceSpline(f32);
    f32 calcSplineSpeed(f32);
    void moveTo(int);
    void setTo(int);

    u32* _0; // not sure WHAT graph yet
    u32 mGraphIndex;
    u32 _8;
    f32 _C;
    f32 _10;
    f32 _14;
};

#endif // TGRAPHTRACER_H