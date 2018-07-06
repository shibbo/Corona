#ifndef JPAMAGNETFIELD_H
#define JPAMAGNETFIELD_H

#include "jpa/field/JPABaseField.h"

class JPAMagnetField : public JPABaseField
{
    public:
    JPAMagnetField();
    ~JPAMagnetField();

    void set();
    void affect(JPAParticle *particle);  
};

#endif // JPAMAGNETFIELD_H