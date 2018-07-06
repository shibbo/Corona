#ifndef JPARANDOMFIELD_H
#define JPARANDOMFIELD_H

#include "jpa/field/JPABaseField.h"

class JPARandomField : public JPABaseField
{
    public:
    JPARandomField();
    ~JPARandomField();

    void affect(JPAParticle *particle);
};

#endif // JPARANDOMFIELD_H