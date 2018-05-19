#ifndef TCAMERABCK_H
#define TCAMERABCK_H

#include "JGeometry.h"
#include "actor/MActor.h"

using namespace JGeometry;

class TCameraBck
{
    public:
    TCameraBck();

    void setFrame(f32);
    bool updateDemo(TVec3<f32> *, TVec3<f32> *, TVec3<f32> *, f32 *);
    void endDemo();
    u32 getTotalDemoFrames() const;
    void startDemo(char const *, TVec3<f32> const *);
    bool isFileExist(char const *) const;

    MActor* actor; // _0
    MActorAnmData* anmData; // _4
    u32 nameTabIndex; // _8
    u32 positionJointMtxOffset; // _C
    u32 interestJointMtxOffset; // _10
    TVec3<f32>* unkVector; // _14
};

#endif // TCAMERABCK_H