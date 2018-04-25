#ifndef TPOLLUTIONOBJ_H
#define TPOLLUTIONOBJ_H

#include "types.h"
#include "j3d/TJoint.h"

class TPollutionObj : public TJointObj
{
	public:
	TPollutionObj();
	
	*TPollutionObj newJointObj() const;
	
	u32 _20;
	u32 _24;
	u32 _28;
	u32 _2C;
	u32 _30;
	u32 _34;
};

#endif // TPOLLUTIONOBJ_H