#ifndef TJOINT_H
#define TJOINT_H

#include "J3D.h"
#include "JDrama.h"
#include "types.h"
#include "actor/MActor.h"

class TJointObj
{
	public:
	TJointObj();
	
	virtual void alive();
	virtual void awake();
	virtual void stand();
	virtual void kill();
	virtual void sit();
	virtual TJointObj* newJointObj() const;

	void initChildren();
	
	VTABLE; // _0
	u32 _4;
	u32 _8;
	J3DJoint* joint; // _C
	u32 numChildJoints; // _10
	TJointObj** childJoints; // _14 (array of child joints, non-fixed size)
	u32 _184;
	u32 _1C;
};

class TJointModelManager : public JDrama::TViewObj
{
	public:
	TJointModelManager(char const *name);
	virtual ~TJointModelManager();

	virtual void perform(JDrama::TGraphics *);
	TJointModel* newJointModel(int) const;

	u32 _10;
	u32 _14;
	u32 _18;
	char* modelName; // _1C
	MActorAnmData anmData; // _20
};

class TJointModel : public TJointObj
{
	public:
	TJointModel();

	void initJointModel(TJointModelManager *, char const *modelName, MActorAnmData *);
	virtual void perform(JDrama::TGraphics *);
	u32 getJ3DModelDataFlag() const;

	void initActor(char const *, MActorAnmData *);

	TJointModelManager* mModelManager; // _20
	J3DModelData* mModelData; // _24
	J3DModel* mModel; // _28
	MActor* mActor; // _2C
};

#endif // TJOINT_H