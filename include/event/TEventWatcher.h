#ifndef TEVENTWATCHER_H
#define TEVENTWATCHER_H

#include "JDrama.h"
#include "types.h"
#include "spc/TSpcTypedBinary.h"

class TEventWatcher : public JDrama::TViewObj
{
    public:
    TEventWatcher(char const *, char const *);
    TEventWatcher(char const *);
    virtual ~TEventWatcher();

    virtual void perform(u32, JDrama::TGraphics *);
    virtual void launchScript(char const *);

    TSpcTypedBinary<TEventWatcher>* _10;
    TSpcTypedBinary<TEventWatcher>* _14;
};

char* sShineViewObjName;

#endif // TEVENTWATCHER_H