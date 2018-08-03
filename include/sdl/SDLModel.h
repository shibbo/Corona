#ifndef SDLMODEL_H
#define SDLMODEL_H

#include "J3D.h"
#include "sdl/SDLModelData.h"

class SDLModel : public J3DModel
{
    public:
    SDLModel(SDLModelData *, u64, u64);

    void entryModelDataSDL(SDLModelData *, u64, u64);

};

#endif // SDLMODEL_H