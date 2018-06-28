#ifndef SPC_H
#define SPC_H

#include "JDrama.h"
#include "spc/TSpcTypedInterp.h"
#include "TEventWatcher.h"

void SpcTrace(char const *, ...);

void evStartMontemanFanfare(TSpcTypedInterp<TEventWatcher> *, u32);
void evStartMontemanBGM(TSpcTypedInterp<TEventWatcher> *, u32);
void evIsWaterMelonIsReached(TSpcTypedInterp<TEventWatcher> *, u32);
void evInvalidatePad(TSpcTypedInterp<TEventWatcher> *, u32);
void evOnNeutralMarioKey(TSpcTypedInterp<TEventWatcher> *, u32);
void evWarpFrontToMario(TSpcTypedInterp<TEventWatcher> *, u32);
void evAppear8RedCoinsAndTimer(TSpcTypedInterp<TEventWatcher> *, u32);
void evAppearReadyGo(TSpcTypedInterp<TEventWatcher> *, u32);
void evSetEventForWaterMelon(TSpcTypedInterp<TEventWatcher> *, u32);

#endif // SPC_H