#ifndef TJOINT_H
#define TJOINT_H

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
	
	int* vtable; // _0
	int _4;
	int _8;
	int* _C; // J3DJoint *
	int _10;
	int _14;
	int _18;
	int _1C;
};

#endif // TJOINT_H