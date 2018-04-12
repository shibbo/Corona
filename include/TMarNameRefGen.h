#ifndef TMARNAMEREFGEN_H
#define TMARNAMEREFGEN_H

#include "JDrama.h"
#include "JSUStream.h"

using namespace JDrama;

// not completed
template <class T, class T2>
class TNameRefAryT : public TNameRef
{
    public:
    ~TNameRefAryT();

    void load(JSUMemoryInputStream&);
    void loadAfter();
    TNameRefAryT* searchF(unsigned short, char const *);
};

class TMarNameRefGen : public TNameRefGen
{
	public:
	int* getNameRef(char const *) const;
	int* getNameRef_BossEnemy(char const *) const;
	int* getNameRef_Enemy(char const *) const;
	int* getNameRef_NPC(char const *) const;
	int* getNameRef_Map(char const *) const;
	int* getNameRef_MapObj(char const *) const;
};

#endif // TMARNAMEREFGEN_H