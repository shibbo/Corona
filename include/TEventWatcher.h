#ifndef TEVENTWATCHER_H
#define TEVENTWATCHER_H

#include "JDrama.h"
#include "types.h"

class TEventWatcher : public JDrama::TViewObj
{
    public:
    TEventWatcher(char const *, char const *);
    ~TEventWatcher();

    void perform(u32, JDrama::TGraphics *);
    void launchScript(char const *);

    u32 _10;
    u32 _14;
};

#endif // TEVENTWATCHER_H