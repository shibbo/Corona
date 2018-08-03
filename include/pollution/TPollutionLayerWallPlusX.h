#ifndef TPOLLUTIONLAYERWALLPLUSX_H
#define TPOLLUTIONLAYERWALLPLUSX_H

#include "pollution/TPollutionLayerWallBase.h"

class TPollutionLayerWallPlusX
{
    public:
    u32 getPlaneType() const;
    u32 getTexPosS(f32) const;
    void initLayerInfo(TPollutionLayerInfo const *);
    void stamp(u16, f32, f32, f32, f32);
    bool isInArea(f32, f32, f32) const;
    bool isInAreaSize(f32, f32, f32, f32) const;
};

#endif // TPOLLUTIONLAYERWALLPLUS_X