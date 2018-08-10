#ifndef JKR_H
#define JKR_H

#include "JSUStream.h"
#include "OS.h"

class JKRArchive;
class JKRArcFinder;

enum JKRExpandSwitch
{
	NON_COMPRESSED = 0,
	COMPRESSED = 1
};

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

class JKRAram : public JKRThread
{
	public:
	JKRAram(u32, u32, s32);
	virtual ~JKRAram();

	virtual u32 run();

	static u32* create(u32, u32, s32, s32, s32);
	static s32 mainRamToAram(u8 *, u32, u32, JKRExpandSwitch, u32, JKRHeap *, int);
	static s32 aramToMainRam(u32, u8 *, u32, JKRExpandSwitch, u32, JKRHeap *, int, u32 *);

	u32 _60;
	u32 _64;
	u32 _68;
	u32 _70;
	u32 _74;
	u32 _78;
	u32 _7C;
	u32 _80;
	u32 _84;
};

class JKRDecompCommand
{
	public:
	JKRDecompCommand();
	~JKRDecompCommand();

	u32 _0;
	u8* _4;
	u8* _8;
	u32 _C;
	u32 _10;
	u32 _14;
	JKRDecompCommand* self; // _18
	u32 _1C;
	u32 _20;
	OSMessageQueue mMessageQueue; // _28
	OSMessage mMessage; // _48
};

enum CompressionType
{
	NONE = 0,
	SZP_COMPRESSED = 1,
	SZS_COMPRESSED = 2
};

class JKRDecomp : public JKRThread
{
	public:
	JKRDecomp(s32);
	virtual ~JKRDecomp();

	virtual u32 run();

	static void create(s32);
	static void sendCommand(JKRDecompCommand *);
	void orderSync(u8 *, u8 *, u32, u32);
	void decode(u8 *, u8 *, u32, u32);
	static void decodeSZP(u8 *src, u8 *dest, u32, u32);
	static void decodeSZS(u8 *src, u8 *dest, u32, u32);
	CompressionType checkCompressed(u8 *);
};

class JKRAramHeap : public JKRDisposer
{
	public:
	enum EAllocMode
	{
		ALLOC_FROM_HEAD = 0,
		ALLOC_FROM_TAIL = 1
	};

	JKRAramHeap(u32, u32);
	virtual ~JKRAramHeap();

	void* alloc(u32 size, EAllocMode allocMode);
	void* allocFromHead(u32 size);
	void* allocFromTail(u32 size);

	OSMutex mMutex; // _18
	s32 mSize; // _30
	u32 _34;
	u32 _38;
	u32 _3C;
	u8 _40;
	u8 _41;
	u8 _42;
	u8 _43;
	u8 _44;
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
	u32 _40;
	u32 _44;
	u32 _48;
	u32 _4C;
	u32 _50;
	u32 _54;
	u32 _58;
	int mountDirection; // _5C
};

/* 
 * ARAM
*/

class JKRAramArchive : public JKRFileLoader
{
	public:
	JKRAramArchive(s32, int);
	virtual ~JKRAramArchive();
	
	virtual int fetchResource(int *, u32 *);
	virtual int fetchResource(void *, u32, int *, u32 *);

	int fetchResource_subroutine(u32, u32, JKRHeap *, int, u8 **);
	int fetchResource_subroutine(u32, u32, u8 *, u32, int);
};

class JKRAramBlock
{
	public:
	JKRAramBlock(u32, u32, u32, u8, bool);
	virtual ~JKRAramBlock();

	JKRAramBlock* allocHead(u32, u8, JKRAramHeap *);
	JKRAramBlock* allocTail(u32, u8, JKRAramHeap *);

	VTABLE; // _0
	JSUPtrLink blockPtr; // _4
	u32 _14;
	u32 _18;
	u32 _1C;
	u8 _20;
	u8 _21;
	u8 _22; // padding?
	u8 _23; // ^^
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
void JKRDecompressFromAramToMainRam(u32, void *, u32, u32, u32);
s32 decompSZS_subroutine(u8 *src, u8 *dest);
u32* firstSrcData();
u32* nextSrcData(u8 *);

void* operator new(size_t, JKRHeap *, int);

#endif // JKR_H