#ifndef TMAPEVENTSINKINPOLLUTIONRESET_H
#define TMAPEVENTSINKINPOLLUTIONRESET_H

#include "event/TMapEventSinkInPollution.h"

class TMapEventSinkInPollutionReset : public TMapEventSinkInPollution
{
    public:
    ~TMapEventSinkInPollutionReset();

    void loadAfter();
    void makeBuildingRecovered(int);
};

#endif // TMAPEVENTSINKINPOLLUTIONRESET_H