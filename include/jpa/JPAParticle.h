#ifndef JPAPARTICLE_H
#define JPAPARTICLE_H

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
    JGeometry:TVec3<f32>& accessFAccVec() const;
    JGeometry::TVec3<f32>& accessFVelVec() const;

    f32 getWidth();
    f32 getHeight();

    void setVelocity();
    void calcVelocity();

    JGeometry::TVec3<f32> baseVelocity; // _5C
    u8 _68[0x74-0x68];
    f32 dymanicsWeight; // _74
    f32 airResistance; // _7C
    f32 dragForce; // _80
    f32 currentDragForce; // _84
    JGeometry::TVec3<f32> fowardVelocity; // _88
    JGeoemtry::TVec3<f32> fowardAcceleration; // _94
    u8 _A0[0xB0-0xA0];
    f32 widthRelated; // _B0
    f32 heightRelated; // _B4
    u8 _B8[0xD4-0xB8];
};

#endif // JPAPARTICLE_H