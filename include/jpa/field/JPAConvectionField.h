#ifndef JPACONVECTIONFIELD_H
#define JPACONVECTIONFIELD_H

#include "jpa/field/JPABaseField.h"

class JPAConvectionField : public JPABaseField
{
    public:
    JPAConvectionField();
    ~JPAConvectionField();

    void set();
    void affect(JPAParticle *particle);
	bool checkMaxDistance(JGeometry::TVec3<f32> &, JGeometry::TVec3<f32> &);
};

#endif // JPACONVECTIONFIELD_H