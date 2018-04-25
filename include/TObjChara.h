#ifndef TOBJCHARA_H
#define TOBJCHARA_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"

using namespace JDrama;

class TObjChara : public TCharacter
{
    public;
    ~TObjChara();

    void load(JSUMemoryInputStream &);
    u32* getGlbResource(char const *) const; // return type is probably JKRArchive*
};

#endif // TOBJCHARA_H