#ifndef TEVENTWATCHER_H
#define TEVENTWATCHER_H

#include "JDrama.h"

using namespace JDrama;

class TEventWatcher : public TViewObj
{
    public:
    TEventWatcher(char const *, char const *);
    ~TEventWatcher();

    void perform(unsigned long, TGraphics *);
    void launchScript(char const *);

    int _10;
    int _14;
};

#endif // TEVENTWATCHER_H