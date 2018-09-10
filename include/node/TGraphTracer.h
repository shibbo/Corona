#ifndef TGRAPHTRACER_H
#define TGRAPHTRACER_H

#include "types.h"

#include "node/TGraphWeb.h"

class TGraphTracer
{
    public:
    TGraphTracer();

    u32 getCurGraphIndex() const;
    u32* getGraph() const;
    u32 traceSpline(f32);
    f32 calcSplineSpeed(f32);
    s32 moveTo(s32 index);
    void setTo(s32 index);

    TGraphWeb* graphWeb; // _0
    s32 mGraphIndex;
    u32 _8;
    f32 _C;
    f32 _10;
    f32 _14;
};

#endif // TGRAPHTRACER_H