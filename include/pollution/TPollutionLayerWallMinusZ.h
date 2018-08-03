#ifndef TPOLLUTIONLAYERWALLMINUSZ_H
#define TPOLLUTIONLAYERWALLMINUSZ_H

#include "pollution/TPollutionLayerWallPlusZ.h"

class TPollutionLayerWallMinusZ : public TPollutionLayerWallPlusZ
{
    public:
    u32 getPlaneType() const;
    u32 getTexPosT(f32) const;
};

#endif // TPOLLUTIONLAYERWALLMINUSZ_H