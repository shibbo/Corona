#ifndef TDOLPICEVENTBIANCOGATE_H
#define TDOLPICEVENTBIANCOGATE_H

#include "event/TMapEventSink.h"

class TDolpicEventBiancoGate : public TMapEventSink
{
    public:
    TDolpicEventBiancoGate(char const *);
    ~TDolpicEventBiancoGate();

    void loadAfter();
    bool isFinishedAll() const;
    s32 watch();
    void control();

    u32* _20;
    f32 _24;
};

#endif // TDOLPICEVENTBIANCOGATE_H