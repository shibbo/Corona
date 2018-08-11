#ifndef TMARNAMEREFGEN_H
#define TMARNAMEREFGEN_H

#include "JDrama.h"
#include "JSUStream.h"
#include "types.h"

// not completed
template <class T, class T2>
class TNameRefAryT : public JDrama::TNameRef
{
    public:
    virtual ~TNameRefAryT();

    virtual void load(JSUMemoryInputStream&);
    virtual void loadAfter();
    virtual TNameRefAryT* searchF(s16, char const *);
};

class TMarNameRefGen : public JDrama::TNameRefGen
{
	public:
	virtual u32* getNameRef(char const *) const;
	u32* getNameRef_BossEnemy(char const *) const;
	u32* getNameRef_Enemy(char const *) const;
	u32* getNameRef_NPC(char const *) const;
	u32* getNameRef_Map(char const *) const;
	u32* getNameRef_MapObj(char const *) const;	
};

#endif // TMARNAMEREFGEN_H