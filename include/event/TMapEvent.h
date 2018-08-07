#ifndef TMAPEVENT_H
#define TMAPEVENT_H

#include "event/TEventWatcher.h"

class TMapEvent : public TEventWatcher
{
    public:
    TMapEvent(char const *);
    ~TMapEvent();

    void load(JSUMemoryInputStream &stream);
    void perform(u32, JDrama::TGraphics *);
    bool isFinishedAll() const;
    void startControl();
    void finishControl();
    u32* getBuilding(int) const;

    u32 mEventState; // _18
    u32* _1C;
};

#endif // TMAPEVENT_H