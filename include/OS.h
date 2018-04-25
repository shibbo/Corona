#ifndef OS_H
#define OS_H

#include "types.h"

typedef u32 OSHeapHandle;
extern volatile OSHeapHandle __OSCurrHeap;
#define OSAlloc(size)   OSAllocFromHeap(__OSCurrHeap, (size))
typedef u64 OSTime;

#ifdef __cplusplus
extern "C" {
#endif

void OSReport(const u8 *, ...);
void OSPanic (u8 *, u32, u8 *, ...);
u32 OSGetTime();
u32 OSGetTick();
void OSFatal(u32*, u32 *, const u8 *);
void* OSAllocFromHeap(OSHeapHandle, u32);

typedef struct 
{
	u32 sec, min, hour, mday, mon, year, wday, yday, msec, usec;
} OSCalendarTime;

void OSTicksToCalendarTime(u32, OSCalendarTime *);

u32 OSGetConsoleType();
void OSInit();
void OSExceptionInit();

void OSInitAlarm();

void DCInvalidateRange(void *, u32);
void DCFlushRange(void *, u32);
void DCStoreRange(void *, u32);
void DCFlushRangeNoSync(void *, u32);
void DCZeroRange(void *, u32);

void OSResetSystem(u32, u32, bool);
u32 OSGetResetCode();

#ifdef __cplusplus
}
#endif

#endif // OS_H