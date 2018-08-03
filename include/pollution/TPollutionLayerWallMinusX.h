#ifndef TPOLLUTIONLAYERWALLMINUSX_H
#define TPOLLUTIONLAYERWALLMINUSX_H

#include "pollution/TPollutionLayerWallPlusX.h"

class TPollutionLayerWallMinusX : public TPollutionLayerWallPlusX
{
    public:
    u32 getPlaneType() const;
    u32 getTexPosS(f32) const;
};

#endif // TPOLLUTIONLAYERWALLMINUSX_H