#ifndef TPOLLUTIONLAYERWALLPLUSZ_H
#define TPOLLUTIONLAYERWALLPLUSZ_H

#include "pollution/TPollutionLayerWallBase.h"

class TPollutionLayerWallPlusZ : public TPollutionLayerWallBase
{
    public:
    u32 getPlaneType() const;
    void initLayerInfo(TPollutionLayerInfo const *);
    void stamp(u16, f32, f32, f32, f32);
    bool isInArea(f32, f32, f32) const;
    bool isInAreaSize(f32, f32, f32, f32) const;
};

#endif // TPOLLUTIONLAYERWALLPLUSZ_H