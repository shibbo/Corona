#ifndef JPAAIRFIELD_H
#define JPAAIRFIELD_H

#include "jpa/field/JPABaseField.h"

class JPAAirField : public JPABaseField
{
    public:
    JPAAirField();
    ~JPAAirField();

    void set();
    void affect(JPAParticle *particle);  
};

#endif // JPAAIRFIELD_H