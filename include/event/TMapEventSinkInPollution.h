#ifndef TMAPEVENTSINKINPOLLUTION_H
#define TMAPEVENTSINKINPOLLUTION_H

#include "event/TMapEventSink.h"

class TMapEventSinkInPollution : public TMapEventSink
{
    public:
    virtual ~TMapEventSinkInPollution();

    virtual void loadAfter();
    virtual s32 watch();
};

#endif // TMAPEVENTSINKINPOLLUTION_H