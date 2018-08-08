#ifndef TAIRPORTEVENTSINK_H
#define TAIRPORTEVENTSINK_H

#include "event/TMapEventSinkInPollutionReset.h"

class TAirportEventSink : public TMapEventSinkInPollutionReset
{
    public:
    TAirportEventSink(char const *);
    virtual ~TAirportEventSink();

    virtual void loadAfter();
    virtual s32 watch();
    virtual s32 control();
    virtual void finishControl();

    u32 _64;
    u32 _68;
};

#endif // TAIRPORTEVENTSINK_H