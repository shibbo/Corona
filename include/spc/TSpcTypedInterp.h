#ifndef TSPCTYPEDINTERP_H
#define TSPCTYPEDINTERP_H

#include "types.h"
#include "spc/TSpcInterp.h"

template <typename T>
class TSpcTypedInterp : public TSpcInterp
{
    public:
    ~TSpcTypedInterp();

    void dispatchBuiltin(u32, u32);
};

#endif // TSPCTYPEDINTERP_H