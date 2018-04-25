#ifndef TJOINT_H
#define TJOINT_H

#include "types.h"

class TJointObj
{
	public:
	TJointObj();
	
	void alive();
	void awake();
	void stand();
	void kill();
	void sit();
	TJointObj* newJointObj() const;
	
	u32* vtable; // _0
	u32 _4;
	u32 _8;
	u32* _C; // J3DJoint *
	u32 _10;
	u32 _14;
	u32 _18;
	u32 _1C;
};

#endif // TJOINT_H