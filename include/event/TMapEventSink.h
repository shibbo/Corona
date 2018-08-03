#ifndef TMAPEVENTSINK_H
#define TMAPEVENTSINK_H

#include "event/TMapEvent.h"

class TMapEventSink : public TMapEvent
{
    public:
    TMapEventSink(char const *);
    ~TMapEventSink();

    void load(JSUMemoryInputStream &stream);
    bool isFinishedAll() const;
    s32 watch();
    void startContorl();
    s32 control();
    void finishControl();
    u32* getBuilding(s32) const;
    void initBuilding(s32, JSUMemoryInputStream &);
    void initWithBuildingNum(JSUMemoryInputStream &);
    void rising();
    f32 getSinkOffsetY() const;
    void makeBuildingRecovered(s32);

    u32 _20; // defined in map binary
    u32 _24;
    s32 _28;
    u32 _2C;
    u32* _30;
    f32 _34;
    f32 _38;
    f32 _3C;
    u32 _40;
    u32 _44;
    u32 _48;
    u32 _4C;
    TVec3<f32>* _50; // array of something, count is this + 0x20
    void* _54;
    void* _58;
    void* _5C;
    void* _60;
};

#endif // TMAPEVENTSINK_H