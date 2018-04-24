#ifndef OS_H
#define OS_H

typedef int OSHeapHandle;
extern volatile OSHeapHandle __OSCurrHeap;
#define OSAlloc(size)   OSAllocFromHeap(__OSCurrHeap, (size))
typedef long OSTime;

#ifdef __cplusplus
extern "C" {
#endif

void OSReport(const char *, ...);
void OSPanic (char *, int, char *, ...);
unsigned long OSGetTime();
unsigned int OSGetTick();
void OSFatal(unsigned int*, unsigned int *, const char *);
void* OSAllocFromHeap(OSHeapHandle, unsigned int);

typedef struct 
{
	int sec, min, hour, mday, mon, year, wday, yday, msec, usec;
} OSCalendarTime;

void OSTicksToCalendarTime(unsigned long, OSCalendarTime *);

int OSGetConsoleType();
void OSInit();
void OSExceptionInit();

void OSInitAlarm();

void DCInvalidateRange(void *, int);
void DCFlushRange(void *, int);
void DCStoreRange(void *, int);
void DCFlushRangeNoSync(void *, int);
void DCZeroRange(void *, int);

void OSResetSystem(int, int, bool);
int OSGetResetCode();

#ifdef __cplusplus
}
#endif

#endif // OS_H