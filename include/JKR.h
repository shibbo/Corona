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
	static void alloc(u32, u32, JKRHeap *);
	void free(void *, JKRHeap *);
	void freeAll();
	static u32* findFromRoot(void *);
	u32* find(void *) const;
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
	JKRThread(u32, u32, u32);
	~JKRThread();

	void start(void *);
	u32 run();

	JSUPtrLink threadPtrs; // _18
	JKRHeap* heap; // _28
	u32* osThread; // _2C (this is OSThread*)
	u32* messageQueue; // _30 (this is OSMessageQueue*)
	u8 _34[0x50-0x34];
	u32* osMessage; // _50 (this is OSMessage*)
	s32 messageCount; // _54
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
	u8* fetchVolumeName(u8 *, u32, char const *);
	
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
	JKRArchive(u32, EMountMode);
	~JKRArchive();
	
	u32* _38;
	u8 _3C;
	u8 _3D; // padding?
	u8 _3E; // ^^
	u8 _3F; // ^^
	
};

void JKRDefaultMemoryErrorRoutine(void *, u64, u32);

#endif // JKR_H