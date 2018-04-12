#ifndef TMAPSTATICOBJ_H
#define TMAPSTATICOBJ_H

#include "JDrama.h"
#include "JSUStream.h"
#include "MActor.h"
#include "THitActor.h"

using namespace JDrama;

/* Size -- 0x80 */
class TMapStaticObj : public THitActor
{
	public:
	TMapStaticObj(char const *);
	~TMapStaticObj();
	
	void load(JSUMemoryStream &);
	void loadAfter();
	void perform(unsigned long, TGraphics *);
	void init(char const *);
	void initUnique();
	void initModel(char const *);
	int* getModelData() const;
	
	char* actorName; // _68
	char* modelName; // _6C
	MActor* actor; // _70
	int _74;
	int _78;
	int _7C;
};

#endif // TMAPSTATICOBJ_H