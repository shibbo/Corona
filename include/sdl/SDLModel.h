#ifndef SDLMODEL_H
#define SDLMODEL_H

#include "J3D.h"
#include "sdl/SDLModelData.h"

class SDLModel : public J3DModel
{
    public:
    SDLModel(SDLModelData *, u32, u32);

    void entryModelDataSDL(SDLModelData *, u32, u32);

};

#endif // SDLMODEL_H