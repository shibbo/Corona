#ifndef TDOLPICEVENTRICCOMAMMAGATE_H
#define TDOLPICEVENTRICCOMAMMAGATE_H

#include "J3D.h"
#include "event/TMapEvent.h"

class TDolpicEventRiccoMammaGate : public TMapEvent
{
    public:
    TDolpicEventRiccoMammaGate(char const *);
    ~TDolpicEventRiccoMammaGate();

    void loadAfter();
    bool isFinished() const;
    u32 watch();
    void control();

    J3DJoint* mJoint; // _20
    u32 _24;
    u32 _28;
    u32 mSomeFlag; // seems to be a boolean flag in TFlagManager
    u8 _30;
    u8 _31;
    u8 _32;
    u8 _33;
    f32 _34;
    u32 _38;
    u32 _3C;
    u32 _40;
    u32 _44;
    JGeometry::TVec3<f32> mEventPosition; // _48
    JGeometry::TVec3<f32> _54;
    f32 _60;
};

#endif // TDOLPICEVENTRICCOMAMMAGATE_H