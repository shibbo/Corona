#ifndef JPARESOURCEMANAGER_H
#define JPARESOURCEMANAGER_H

#include "JKR.h"
#include "types.h"

class JPAResourceManager
{
    public:
    JPAResourceManager(u32, u32, JKRHeap *);

    void load(char const *,  u16);
    void load(void const *,  u16);
    
};

#endif // JPARESOURCEMANAGER_H