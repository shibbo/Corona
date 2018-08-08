#ifndef JPAPARTICLE_H
#define JPAPARTICLE_H

#include "JGeometry.h"
#include "jpa/JPABaseParticle.h"

class JPAParticle : public JPABaseParticle
{
    public:
    JPAParticle();

    void init();
    bool checkCreateChildParticle();

    f32 getDynamicsWeight() const;
    f32 getAirResistance() const;
    f32 getCurrentDragForce() const;
    JGeometry::TVec3<f32>& accessBaseVelVec() const;
    JGeometry::TVec3<f32>& accessFAccVec() const;
    JGeometry::TVec3<f32>& accessFVelVec() const;

    f32 getWidth();
    f32 getHeight();

    void setVelocity();
    void calcVelocity();

    JGeometry::TVec3<f32> mBaseVelocity; // _5C
    u8 _68[0x74-0x68];
    f32 mDymanicsWeight; // _74
    f32 mAirResistance; // _7C
    f32 mDragForce; // _80
    f32 mCurrentDragForce; // _84
    JGeometry::TVec3<f32> mFowardVelocity; // _88
    JGeometry::TVec3<f32> mFowardAcceleration; // _94
    u8 _A0[0xB0-0xA0];
    f32 mWidthRelated; // _B0
    f32 mHeightRelated; // _B4
    u8 _B8[0xD4-0xB8];
};

#endif // JPAPARTICLE_H