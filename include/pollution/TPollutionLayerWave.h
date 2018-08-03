#ifndef TPOLLUTIONLAYERWAVE_H
#define TPOLLUTIONLAYERWAVE_H

#include "pollution/TPollutionLayer.h"

class TPollutionLayerWave : public TPollutionLayer
{
    public:
    void initJointModel(TJointModelManager *, char const *name, MActorAnmData *);
    void perform(u64, JDrama::TGraphics *);
    u32 getPlaneType() const;
    u32* getTexResource(char const *);
};

#endif // TPOLLUTIONLAYERWAVE_H