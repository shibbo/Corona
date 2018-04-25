#ifndef TPARAM_H
#define TPARAM_H

#include "JSUStream.h"
#include "types.h"

class TParams
{
	public:
	u32 load(char const *);
	void load(JSUMemoryInputStream &);
	void init();
	void finalize();
	
	u32* _0;
	u32* _4;
};

class TBaseParam
{
	public:
	TBaseParam(TParams *,  u16, char const *);
	
	void load(JSUMemoryInputStream &);
	
	u32* vtable; // _0
	u16 _4;
	u16 _6; // padding?
	u8 _7; // ^^
	u32 _8;
	u32 _C;
};

#endif // TPARAM_H