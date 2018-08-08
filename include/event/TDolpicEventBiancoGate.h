#ifndef TDOLPICEVENTBIANCOGATE_H
#define TDOLPICEVENTBIANCOGATE_H

#include "event/TMapEventSink.h"

class TDolpicEventBiancoGate : public TMapEventSink
{
    public:
    TDolpicEventBiancoGate(char const *);
    virtual ~TDolpicEventBiancoGate();

    virtual void loadAfter();
    virtual bool isFinishedAll() const;
    virtual s32 watch();
    virtual s32 control();

    u32* _20;
    f32 _24;
};

#endif // TDOLPICEVENTBIANCOGATE_H