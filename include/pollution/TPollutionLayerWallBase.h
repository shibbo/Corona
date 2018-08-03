#ifndef TPOLLUTIONLAYERWALLBASE_H
#define TPOLLUTIONLAYERWALLBASE_H

#include "pollution/TPollutionLayer.h"

class TPollutionLayerWallBase : public TPollutionLayer
{
    public:
    TPollutionLayerWallBase();

    u32 getTexPosT(f32) const;

    f32 _AC;
    f32 _B0; // texture position related
};

#endif // TPOLLUTIONLAYERWALLBASE_H