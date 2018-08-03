#ifndef TMAPEVENTSINKINPOLLUTIONRESET_H
#define TMAPEVENTSINKINPOLLUTIONRESET_H

#include "event/TMapEventSinkInPollution.h"

class TMapEventSinkInPollutionReset : public TMapEventSinkInPollution
{
    public:
    ~TMapEventSinkInPollutionReset();

    void loadAfter();
    void makeBuildingRecovered(s32);
};

#endif // TMAPEVENTSINKINPOLLUTIONRESET_H