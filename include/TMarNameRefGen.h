#ifndef TMARNAMEREFGEN_H
#define TMARNAMEREFGEN_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"

using namespace JDrama;

// not completed
template <class T, class T2>
class TNameRefAryT : public TNameRef
{
    public:
    ~TNameRefAryT();

    void load(JSUMemoryInputStream&);
    void loadAfter();
    TNameRefAryT* searchF( u16, char const *);
};

class TMarNameRefGen : public TNameRefGen
{
	public:
	u32* getNameRef(char const *) const;
	u32* getNameRef_BossEnemy(char const *) const;
	u32* getNameRef_Enemy(char const *) const;
	u32* getNameRef_NPC(char const *) const;
	u32* getNameRef_Map(char const *) const;
	u32* getNameRef_MapObj(char const *) const;
};

#endif // TMARNAMEREFGEN_H