#ifndef JPAVORTEXFIELD_H
#define JPAVORTEXFIELD_H

#include "jpa/field/JPABaseField.h"

class JPAVortexField : public JPABaseField
{
    public:
    JPAVortexField();
    ~JPAVortexField();

    void set();
    void affect(JPAParticle *particle);
    bool checkMaxDistance(JGeometry::TVec3<f32> &, JGeometry::TVec3<f32> &);
};

#endif // JPAVORTEXFIELD_H