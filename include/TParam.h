#ifndef TPARAM_H
#define TPARAM_H

#include "JSUStream.h"

class TParams
{
	public:
	int load(char const *);
	void load(JSUMemoryInputStream&);
	void init();
	void finalize();
	
	int* _0;
	int* _4;
};

class TBaseParam
{
	public:
	TBaseParam(TParams *, unsigned short, char const *);
	
	void load(JSUMemoryInputStream&);
	
	int* vtable; // _0
	short _4;
	short _6; // padding?
	char _7; // ^^
	int _8;
	int _C;
};

#endif // TPARAM_H