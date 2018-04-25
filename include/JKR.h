#ifndef JKR_H
#define JKR_H

#include "JSUStream.h"

class JKRArchive;

class JKRDisposer
{
	public:
	JKRDisposer();
	~JKRDisposer();
	
	u32* vtable; // _0
	u32 _4;
	JSUPtrLink ptrLink; // _8
};

class JKRHeap : public JKRDisposer
{
	public:
	JKRHeap(void *, u32, JKRHeap *, bool);
	~JKRHeap();

	void freeAll();

	void becomeSystemHeap();
	void becomeCurrentHeap();
	bool initArena(u8 **, u32 *, u32);
	void alloc(u32, u32, JKRHeap *);
	void free(void *, JKRHeap *);
	u32* findFromRoot(void *);

	u8 _18[0x30-0x18];
	u32 _30;
	u32 _34;
	u32 _38;
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
	u32* getGlbResource(char const *);
	u32* getGlbResource(char const *, JKRFileLoader *);
	u32 getResSize(void *, JKRFileLoader *);
	u32* findVolume(char const **);
	JKRArchive* findFirstFile(char const *);
	u8* fetchVolumeName(u8 *, long, char const *);
	
	JSUPtrLink ptrLink2; // _18
	u32 _28;
	u32 _2C;
	u8 _30;
	u8 _31; // padding?
	u8 _32; // ^^
	u8 _33; // ^^
	u32 _34;
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
	
	u32* _38;
	u8 _3C;
	u8 _3D; // padding?
	u8 _3E; // ^^
	u8 _3F; // ^^
	
};

#endif // JKR_H