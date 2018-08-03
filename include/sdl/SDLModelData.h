#ifndef SDLMODELDATA_H
#define SDLMODELDATA_H

#include "J3D.h"

typedef u32 SDLDrawBufToken;

class SDLModelData
{
    public:
    SDLModelData(J3DModelData *modelData);

    void recursiveEntry(J3DNode *, SDLDrawBufToken *);
    void entryNode(J3DNode *, SDLDrawBufToken *);
    void entrySameMat(J3DMaterial *, SDLDrawBufToken *);

    J3DModelData* modelData; // _0
    u32 _4;
    u8 _8;
    u8 _9; // padding?
    u8 _A; // ^^
    u8 _B; // ^^
    u32 _C;
    u32 _10;
    u32 _14;
    u32 _18;
    
};

#endif // SDAMODELDATA_H