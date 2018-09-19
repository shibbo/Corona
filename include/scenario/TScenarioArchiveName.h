#ifndef TSCENARIOARCHIVENAME_H
#define TSCENARIOARCHIVENAME_H

#include "JDrama.h"

class TScenarioArchiveName : public JDrama::TNameRef
{
    public:
    TScenarioArchiveName(TScenarioArchiveName const &);
    virtual ~TScenarioArchiveName();

    void load(JSUMemoryInputStream &stream);

    char* mScenarioName; // _C
};

#endif // TSCENARIOARCHIVENAME_H