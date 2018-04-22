#ifndef TGRAPHGROUP_H
#define TGRAPHGROUP_H

#include "JDrama.h"
#include "node/TGraphWeb.h"

using namespace JDrama;

class TGraphGroup
{
    public:
    TGraphGroup(void *);

    void perform(unsigned long, TGraphics *);
    TGraphWeb* getGraphByName(char const *graphName);
    void initGraphGroup();

    void* _0;
    int _4;
    int* _8;
    TGraphWeb* graphWeb; // _C
};

#endif // TGRAPHGROUP_H