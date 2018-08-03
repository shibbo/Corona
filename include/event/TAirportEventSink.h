#ifndef TAIRPORTEVENTSINK_H
#define TAIRPORTEVENTSINK_H

#include "event/TMapEventSinkInPollutionReset.h"

class TAirportEventSink : public TMapEventSinkInPollutionReset
{
    public:
    TAirportEventSink(char const *);
    ~TAirportEventSink();

    void loadAfter();
    s32 watch();
    s32 control();
    void finishControl();

    u32 _64;
    u32 _68;
};

#endif // TAIRPORTEVENTSINK_H