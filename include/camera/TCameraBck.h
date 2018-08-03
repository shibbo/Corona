#ifndef TCAMERABCK_H
#define TCAMERABCK_H

#include "JGeometry.h"
#include "actor/MActor.h"

class TCameraBck
{
    public:
    TCameraBck();

    void setFrame(f32);
    bool updateDemo(JGeometry::TVec3<f32> *, JGeometry::TVec3<f32> *, JGeometry::TVec3<f32> *, f32 *);
    void endDemo();
    u32 getTotalDemoFrames() const;
    void startDemo(char const *, JGeometry::TVec3<f32> const *);
    bool isFileExist(char const *) const;

    MActor* mActor; // _0
    MActorAnmData* mAnmData; // _4
    u32 mNameTabIndex; // _8
    u32 mPositionJointMtxOffset; // _C
    u32 mInterestJointMtxOffset; // _10
    JGeometry::TVec3<f32>* mUnkVector; // _14
};

#endif // TCAMERABCK_H