#ifndef SPC_H
#define SPC_H

#include "JDrama.h"
#include "spc/TSpcTypedInterp.h"
#include "TEventWatcher.h"

using namespace JDrama;

void SpcTrace(char const *, ...);

void evStartMontemanFanfare(TSpcTypedInterp<TEventWatcher> *, unsigned long);
void evStartMontemanBGM(TSpcTypedInterp<TEventWatcher> *, unsigned long);
void evIsWaterMelonIsReached(TSpcTypedInterp<TEventWatcher> *, unsigned long);
void evInvalidatePad(TSpcTypedInterp<TEventWatcher> *, unsigned long);
void evOnNeutralMarioKey(TSpcTypedInterp<TEventWatcher> *, unsigned long);
void evWarpFrontToMario(TSpcTypedInterp<TEventWatcher> *, unsigned long);
void evAppear8RedCoinsAndTimer(TSpcTypedInterp<TEventWatcher> *, unsigned long);
void evAppearReadyGo(TSpcTypedInterp<TEventWatcher> *, unsigned long);
void evSetEventForWaterMelon(TSpcTypedInterp<TEventWatcher> *, unsigned long);

#endif // SPC_H