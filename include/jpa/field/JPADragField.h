#ifndef JPADRAGFIELD_H
#define JPADRAGFIELD_H

#include "jpa/field/JPABaseField.h"

class JPADragField : public JPABaseField
{
    public:
    JPADragField();
    ~JPADragField();

    void affect(JPAParticle *particle);
};

#endif // JPADRAGFIELD_H