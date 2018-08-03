#ifndef JKR_H
#define JKR_H

#include "JSUStream.h"
#include "OS.h"

class JKRArchive;

class JKRDisposer
{
	public:
	JKRDisposer();
	~JKRDisposer();
	
	VTABLE; // _0
	u32 _4;
	JSUPtrLink mPtrLink; // _8
};

class JKRHeap : public JKRDisposer
{
	public:
	JKRHeap(void *, u32, JKRHeap *, bool);
	~JKRHeap();

	void becomeSystemHeap();
	void becomeCurrentHeap();
	bool initArena(u8 **, u32 *, u32);
	static void alloc(u32, u32, JKRHeap *);
	void free(void *, JKRHeap *);
	void freeAll();
	static JKRHeap* findFromRoot(void *);
	JKRHeap* find(void *) const;
	void dispose_subroutine(u32, u32);
	void dispose(void *, u32);
	void dispose(void *, void *);
	void dispose();
	static u32* copyMemory(void *, void *, u32);
	u32 dump_sort();
	u32 changeGroupID(u8 newID);
	u32 getCurrentGroupId();

	u8 _18[0x30-0x18];
	u32 _30;
	u32 _34;
	u32 _38;
	JSUPtrList ptrList; // _3C
};

class JKRThread : public JKRDisposer
{
	public:
	JKRThread(u32 stackSize, s32 messageCount, u32);
	~JKRThread();

	static void* start(void *src);
	u32 run();

	JSUPtrLink mThreadPtrs; // _18
	JKRHeap* mHeap; // _28
	OSThread* mThread; // _2C
	OSMessageQueue mMessageQueue; // _30
	OSMessage* mMessage; // _50
	s32 mMessageCount; // _54
	void* mStackPtr; // _58
	u32 mStackSize; // _5C
};

class JKRFileLoader : public JKRDisposer
{
	public:
	JKRFileLoader();
	~JKRFileLoader();
	
	void unmount();
	JKRFileLoader* getVolume(char const *);
	void changeDirectory(char const *);
	u32* getGlbResource(char const *);
	u32* getGlbResource(char const *, JKRFileLoader *);
	u32 getResSize(void *, JKRFileLoader *);
	u32* findVolume(char const **);
	JKRArchive* findFirstFile(char const *);
	u8* fetchVolumeName(u8 *, u32, char const *);
	
	JSUPtrLink mPtrLink2; // _18
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
	JKRArchive(u32, EMountMode);
	~JKRArchive();
	
	u32* _38;
	u8 _3C;
	u8 _3D; // padding?
	u8 _3E; // ^^
	u8 _3F; // ^^
	
};

class JKRFileFinder
{
	public:
	~JKRFileFinder();

	u32 _0;
	u32 _4;
	u16 _8;
	u16 _A;
	VTABLE; // _C
};

class JKRArcFinder : public JKRFileFinder
{
	public:
	JKRArcFinder(JKRArchive *, u32, u32);
	~JKRArcFinder();

	bool findNextFile();

	u8 _10;
	u8 _11;
	u8 _12; // padding?
	u8 _13; // ^^
	JKRArchive* mArchive; // _14
	u32 _18;
	u32 _1C;
	u32 _20;
};

void JKRDefaultMemoryErrorRoutine(void *, u64, u32);

#endif // JKR_H