#ifndef TPOLLUTIONOBJ_H
#define TPOLLUTIONOBJ_H

#include "j3d/TJoint.h"

class TPollutionObj : public TJointObj
{
	public:
	TPollutionObj();
	
	*TPollutionObj newJointObj() const;
	
	int _20;
	int _24;
	int _28;
	int _2C;
	int _30;
	int _34;
};

#endif // TPOLLUTIONOBJ_H