#ifndef JPANEWTONFIELD_H
#define JPANEWTONFIELD_H

#include "jpa/field/JPABaseField.h"

class JPANewtonField : public JPABaseField
{
    public:
    JPANewtonField();
    ~JPANewtonField();

    void set();
    void affect(JPAParticle *particle);  
};

#endif // JPANEWTONFIELD_H