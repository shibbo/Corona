#ifndef JKR_H
#define JKR_H

#include "JSUStream.h"

class JKRArchive;

class JKRDisposer
{
	public:
	JKRDisposer();
	~JKRDisposer();
	
	int* vtable; // _0
	int _4;
	JSUPtrLink ptrLink; // _8
};

class JKRHeap : public JKRDisposer
{
	public:
	JKRHeap(void *, unsigned long, JKRHeap *, bool);
	~JKRHeap();

	void freeAll();

	void becomeSystemHeap();
	void becomeCurrentHeap();
	bool initArena(char **, unsigned long *, int);
	void alloc(unsigned long, int, JKRHeap *);
	void free(void *, JKRHeap *);
	int* findFromRoot(void *);

	char _18[0x30-0x18];
	int _30;
	int _34;
	int _38;
	JSUPtrList ptrList; // _3C
};

class JKRFileLoader : public JKRDisposer
{
	public:
	JKRFileLoader();
	~JKRFileLoader();
	
	void unmount();
	JKRArchive* getVolume(char const *);
	void changeDirectory(char const *);
	int* getGlbResource(char const *);
	int* getGlbResource(char const *, JKRFileLoader *);
	int getResSize(void *, JKRFileLoader *);
	int* findVolume(char const **);
	JKRArchive* findFirstFile(char const *);
	char* fetchVolumeName(char *, long, char const *);
	
	JSUPtrLink ptrLink2; // _18
	int _28;
	int _2C;
	char _30;
	char _31; // padding?
	char _32; // ^^
	char _33; // ^^
	int _34;
};

enum EMountMode
{
	
};

class JKRArchive : public JKRFileLoader
{
	public:
	JKRArchive();
	JKRArchive(long, EMountMode);
	~JKRArchive();
	
	int* _38;
	char _3C;
	char _3D; // padding?
	char _3E; // ^^
	char _3F; // ^^
	
};

#endif // JKR_H