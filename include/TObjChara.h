#ifndef TOBJCHARA_H
#define TOBJCHARA_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"

class TObjChara : public JDrama::TCharacter
{
    public:
    ~TObjChara();

    void load(JSUMemoryInputStream &);
    u32* getGlbResource(char const *) const; // return type is probably JKRArchive*
};

#endif // TOBJCHARA_H