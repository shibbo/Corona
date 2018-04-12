#ifndef TSPCTYPEDINTERP_H
#define TSPCTYPEDINTERP_H

#include "spc/TSpcInterp.h"

template <typename T>
class TSpcTypedInterp : public TSpcInterp
{
    public:
    ~TSpcTypedInterp();

    void dispatchBuiltin(unsigned long, unsigned long);
};

#endif // TSPCTYPEDINTERP_H