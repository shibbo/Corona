#ifndef TMAPEVENTSINKINPOLLUTIONRESET_H
#define TMAPEVENTSINKINPOLLUTIONRESET_H

#include "event/TMapEventSinkInPollution.h"

class TMapEventSinkInPollutionReset : public TMapEventSinkInPollution
{
    public:
    virtual ~TMapEventSinkInPollutionReset();

    virtual void loadAfter();
    virtual void makeBuildingRecovered(int);
};

#endif // TMAPEVENTSINKINPOLLUTIONRESET_H