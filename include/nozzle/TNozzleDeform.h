#ifndef TNOZZLEDEFORM_H
#define TNOZZLEDEFORM_H

#include "nozzle/TNozzleBase.h"

class TNozzleDeform : public TNozzleBase
{
    public:
    
    u32 getNozzleKind() const; // 3
    void movement(TMarioControllerWork const &);
    void emit(u32);
    void animation(u32);
};

#endif // TNOZZLEDEFORM_H