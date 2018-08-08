#ifndef JKR_H
#define JKR_H

#include "JSUStream.h"
#include "OS.h"

class JKRArchive;
class JKRArcFinder;

class JKRDisposer
{
	public:
	JKRDisposer();
	virtual ~JKRDisposer();
	
	VTABLE; // _0
	u32 _4;
	JSUPtrLink mPtrLink; // _8
};

class JKRHeap : public JKRDisposer
{
	public:
	JKRHeap(void *, u32, JKRHeap *, bool);
	virtual ~JKRHeap();
	
	virtual void freeAll();

	void becomeSystemHeap();
	void becomeCurrentHeap();
	bool initArena(u8 **, u32 *, int);
	static void alloc(u32, int, JKRHeap *);
	void free(void *, JKRHeap *);
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
	JKRThread(u32 stackSize, int messageCount, int);
	virtual ~JKRThread();

	virtual u32 run();

	static void* start(void *src);

	JSUPtrLink mThreadPtrs; // _18
	JKRHeap* mHeap; // _28
	OSThread* mThread; // _2C
	OSMessageQueue mMessageQueue; // _30
	OSMessage* mMessage; // _50
	int mMessageCount; // _54
	void* mStackPtr; // _58
	u32 mStackSize; // _5C
};

class JKRFileLoader : public JKRDisposer
{
	public:
	JKRFileLoader();
	virtual ~JKRFileLoader();
	
	virtual void unmount();

	JKRFileLoader* getVolume(char const *);
	void changeDirectory(char const *dirName);
	u32* getGlbResource(char const *);
	u32* getGlbResource(char const *, JKRFileLoader *);
	u32 getResSize(void *resource, JKRFileLoader *);
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
	virtual ~JKRArchive();

	virtual s32 becomeCurrent(char const *);
	virtual s32 getResource(char const *);
	virtual s32 getResource(u32, char const *);
	virtual u32* readResource(void *, u32, char const *);
	virtual u32* readResource(void *, u32, u32, char const *);
	virtual void removeResourceAll();
	virtual void removeResource(void *);
	virtual void detachResource(void *);
	virtual s32 getResSize(void const *) const;
	virtual s16 countFile(char const *);
	virtual JKRArcFinder* getFirstFile(char const *) const;
	
	u32* _38;
	u8 _3C;
	u8 _3D; // padding?
	u8 _3E; // ^^
	u8 _3F; // ^^
	
};

class JKRFileFinder
{
	public:
	virtual ~JKRFileFinder();

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
	virtual ~JKRArcFinder();

	virtual bool findNextFile();

	u8 _10;
	u8 _11;
	u8 _12; // padding?
	u8 _13; // ^^
	JKRArchive* mArchive; // _14
	u32 _18;
	u32 _1C;
	u32 _20;
};

void JKRDefaultMemoryErrorRoutine(void *, u32, u32);

#endif // JKR_H