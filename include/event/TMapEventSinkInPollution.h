#ifndef TMAPEVENTSINKINPOLLUTION_H
#define TMAPEVENTSINKINPOLLUTION_H

#include "event/TMapEventSink.h"

class TMapEventSinkInPollution : public TMapEventSinkInPollution
{
    public:
    ~TMapEventSinkInPollution();

    void loadAfter();
    s32 watch();
};

#endif // TMAPEVENTSINKINPOLLUTION_H