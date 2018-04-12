#ifndef JPARESOURCEMANAGER_H
#define JPARESOURCEMANAGER_H

#include "JKR.h"

class JPAResourceManager
{
    public:
    JPAResourceManager(unsigned long, unsigned long, JKRHeap *);

    void load(char const *, unsigned short);
    void load(void const *, unsigned short);
    
};

#endif // JPARESOURCEMANAGER_H