#ifndef TCAMCONNECTOR_H
#define TCAMCONNECTOR_H

#include "JDrama.h"

class TCamConnector : public JDrama::TViewConnector
{
    public:
    virtual ~TCamConnector();

    virtual void perform(u32, JDrama::TGraphics *);
};

#endif // TCAMCONNECTOR_H