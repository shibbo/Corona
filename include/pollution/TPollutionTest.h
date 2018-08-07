#ifndef TPOLLUTIONTEST_H
#define TPOLLUTIONTEST_H

#include "JDrama.h"

class TPollutionTest : public JDrama::TViewObj
{
    public:
    ~TPollutionTest();

    void loadAfter();
    void perform(u32, JDrama::TGraphics *);
};

#endif // TPOLLUTIONTEST_H