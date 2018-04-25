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
    void moveTo(u32);
    void setTo(u32);

    u32* _0; // not sure WHAT graph yet
    u32 graphIndex;
    u32 _8;
    f32 _C;
    f32 _10;
    f32 _14;
};

#endif // TGRAPHTRACER_H