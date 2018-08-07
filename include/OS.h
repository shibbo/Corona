#ifndef OS_H
#define OS_H

#include "types.h"

typedef u32 OSHeapHandle;
typedef u32 OSTime;
typedef s32 OSPriority; // 0 is highest priority, 31 is lowest
typedef void* OSMessage;
extern volatile OSHeapHandle __OSCurrHeap;

#define OSAlloc(size)   OSAllocFromHeap(__OSCurrHeap, (size))

struct OSMutex;
struct OSThread;

struct OSCalendarTime
{
	u32 sec, min, hour, mday, mon, year, wday, yday, msec, usec;
};

struct OSThreadQueue
{
    OSThread* threadHead; // _0
    OSThread* threadTail; // _4
};

struct OSThreadLink
{
    OSThread* nextThread; // _0
    OSThread* prevThread; // _4
};

struct OSMutexQueue
{
    OSMutex* mutexHead; // _0
    OSMutex* mutexTail; // _4
};

struct OSMutexLink
{
    OSMutex* nextMutex; // _0
    OSMutex* prevMutex; // _4
};

struct OSMessageQueue
{
    OSThreadQueue sentQueue;
    OSThreadQueue recievedQueue;
    OSMessage* messageArray;
    s32 messageCount;
    s32 firstIndex;
    s32 usedCount;
};

struct OSContext
{
    u32 gpr[32]; // general purpose registers r0-r31
    u32 cr; // control register
    u32 lr; // link register
    u32 ctr; // counter register
    u32 xer; // condition indicator register
    f64 fpr[32]; // floating point registers f0-f31
    u32 fpscr_pad; // floating point status -- control
    u32 fpscr; // floating point status -- control
    u32 srr0; // save/store register 0
    u32 srr1; // save/store register 1
    u16 mode;
    u16 state;
    u32 gqr[8];
    f64 psf[32];
};

struct OSThread
{
    OSContext registerContext;
    u16 threadState;
    u16 threadAttribute;
    s32 willSuspend;
    OSPriority priority;
    OSPriority baseScheduler;
    void* exitVal;
    OSThreadQueue* threadQueue;
    OSThreadLink queueLink;
    OSThreadQueue queueJoin;
    OSMutex* mutex;
    OSMutexQueue ownedMutex;
    OSThreadLink linkActive;
    u8* stackBase;
    u32* stackEnd;
};

struct OSMutex
{
    OSThreadQueue queue;
    OSThread* thread;
    s32 lockCount;
    OSMutexLink link;
};

#ifdef __cplusplus
extern "C" {
#endif

// report / panic
void OSReport(const char *, ...);
void OSPanic(u8 *, u32, u8 *, ...);
void OSFatal(u32 *, u32 *, const u8 *);
void OSResetSystem(u32, u32, bool);
u32 OSGetResetCode();
u32 OSGetConsoleType();

// ticks
u32 OSGetTime();
u32 OSGetTick();
void OSTicksToCalendarTime(u32, OSCalendarTime *);

// allocation
void* OSAllocFromHeap(OSHeapHandle, u32);

// thread
void OSYeildThread();
bool OSCreateThread(OSThread *thread, void*(*funcToThread)(void*), void *parameter, void *stack, u32 stackSize, OSPriority priority, u16 attributes);
void OSExitThread(void *);
void OSCancelThread(OSThread *thread);
bool OSJoinThread(OSThread *thread, void **);
void OSDetachThread(OSThread *thread);
s32 OSResumeThread(OSThread *thread);
s32 OSSuspendThread(OSThread *thread);
void OSSleepThread(OSThreadQueue *queue);
void OSWakeupThread(OSThreadQueue *queue);
OSPriority OSGetThreadPriority(OSThread *thread);

// init
void OSInit();
void OSExceptionInit();

// alarm
void OSInitAlarm();

// DC ranges
void DCInvalidateRange(void *, u32);
void DCFlushRange(void *, u32);
void DCStoreRange(void *, u32);
void DCFlushRangeNoSync(void *, u32);
void DCZeroRange(void *, u32);

#ifdef __cplusplus
}
#endif

#endif // OS_H