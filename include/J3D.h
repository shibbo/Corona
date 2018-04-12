#ifndef J3D_H
#define J3D_H

// declaration for J3DSkinDeform to use J3DModel
class J3DModel;
class J3DShape;
class J3DDisplayListObj;

class J3DVertexData
{
	public:
	J3DVertexData();
	~J3DVertexData();
	
	int _0;
	int _4;
	int _8;
	int _C;
	int _10;
	int _14;
	int _18;
	int _1C;
	int _20;
	int _24;
	int _28;
	int _2C;
	int _30;
	int _34;
	int _38;
	int _3C;
	int _40;
};

class J3DVertexBuffer
{
	public:
	J3DVertexBuffer(J3DVertexData *);
	~J3DVertexBuffer();
	
	void copyTransformedVtxArray();
	
	J3DVertexData* vtxData; // _0
	int _4;
	int _8;
	int _C;
	int _10;
	int _14;
	int _18;
	int _1C;
	int _20;
	int _24;
	int _28;
	int _2C;
	int _30;
	int _34;
	int* vtable; // _38
};

class J3DDrawMtxData
{
	public:
	J3DDrawMtxData();
	~J3DDrawMtxData();
	
	short _0;
	short _2; // padding?
	int _4;
	int _8;
};

class J3DModelData
{
	public:
	J3DModelData();
	~J3DModelData();
	
	void clear();
	bool isDeformableVertexFormat() const;
	
	int* vtable; // _0
	int _4;
	int _8;
	int _C;
	int _10;
	int _14;
	short _18;
	short _1A;
	short _1C;
	int _20;
	short _24;
	short _26; // padding?
	int _28;
	short _2C;
	short _2E; // padding?
	int _30;
	short _34;
	short _36; // padding?
	int _38;
	J3DVertexData vertexData; // _3C
	int _80;
	short _84;
	short _86; // padding?
	int _88;
	int _8C;
	int _90;
	int _94;
	J3DDrawMtxData drawMtxData; // _98
	int _A4;
	int _A8;
	int _AC;
	int _B0;
	int _B4;
	int _B8;
};

class J3DSkinDeform
{
	public:
	J3DSkinDeform();
	~J3DSkinDeform();
	
	void initMtxIndexArray(J3DModelData *);
	void calcNrmMtx(J3DModel *);
	void deform(J3DModel *);
	
	int* vtable; // _0
	int _4;
	int _8;
	int _C;
	int _10;
};

class J3DDisplayListObj
{
	public:
	void newDisplayList(unsigned long);
	void callDL();
	
	int _0;
	int _4;
	int _8;
	int _C;
};

class J3DMaterial
{
	public:
	J3DMaterial();
	~J3DMaterial();
	
	void initialize();
	void addShape(J3DShape *);
	void createColorBlock(int);
	void createTexGenBlock(int);
	void createTevBlock(int);
	void createIndBlock(int);
	void createPEBlock(int, unsigned long);
	int countDLSize();
	void makeDisplayList();
	void safeMakeDisplayList();
	void load();
	void calc(int *);
	void copy(J3DMaterial *);
	void change();
	void newSharedDisplayList(unsigned long);
	
	int* _0;
	J3DShape* shape; // _4
	int _8;
	short _C;
	short _E; //padding?
	int _10;
	int _14; // padding?
	int* _18;
	int _1C;
	int* _20; // *TItemManager
	int* _24; // *TItemManager
	int* _28;
	int _2C; // *TItemManager
	int _30;
	int* _34;
	int _38;
	J3DDisplayListObj dispListObj; // _3C
};

class J3DNode
{
	public:
	J3DNode();
	~J3DNode();
	
	void appendChild(J3DNode *);
	void init(J3DModelData *);
	void updateIn();
	void updateOut();
	void entryIn();
	void calcIn();
	void calcOut();
	int getType() const;
	
	int* vtable; // _0
	int _4;
	int _8;
	int _C; // padding?
	int* _10;
	J3DNode* childNode; // _14
};

class J3DJoint : public J3DNode
{
	public:
	~J3DJoint();
	
	void updateIn();
	void updateOut();
	void entryIn();
	void calcIn();
	void calcOut();
	int getType() const;
	void addMesh(J3DMaterial *);
	void initialize();
	
	short _18;
	char _1A;
	char _1B;
	float _1C;
	float _20;
	float _24;
	short _28;
	short _2A;
	short _2C;
	short _2E; // padding?
	float _30;
	float _34;
	float _38;
	float _3C;
	int _40;
	int _44;
	int _48;
	int _50;
	int _54;
	int _58;
	int _5C;
	J3DMaterial* material; // _60
};

class J3DModel
{
	public:
	J3DModel();
	J3DModel(J3DModelData *, unsigned long, unsigned long);
	~J3DModel();
	
	void update();
	void entry();
	void calc();
	void viewCalc();
	
	void initialize();
	void entryModelData(J3DModelData *, unsigned long, unsigned long);
	void lock();
	void unlock();
	void makeDL();
	void setSkinDeform(J3DSkinDeform *, int); // J3DDeformAttachFlag
	void calcNrmMtx();
	void calcBumpMtx();
	void calcBBoard();
	void prepareShapePackets();
	void calcWeightEnvelopeMtx();
	
	int* vtable; // _0
	J3DModelData* data; // _4
	int _8;
	int _C;
	float _14;
	float _18;
	float _1C;
	Mtx _20;
	int _50;
	int _54;
	int _58;
	int _5C;
	int _60;
	int _64;
	int _68;
	int _6C;
	int _70;
	int _74;
	int _7C;
	int _80;
	int _84;
	int _88;
	J3DSkinDeform* skinDeform; // _8C
	int _90;
	int _94;
	J3DVertexBuffer vtxBuffer; // _98
};

class J3DShape
{
	public:
	
	void initialize();
	int countBumpMtxNum() const;
	void makeVtxArrayCmd();
	void makeVcdVatCmd();
	int loadVtxArray() const;
	int draw() const;
	
	int _0;
	short _4;
	short _6;
	int _8;
	float _C;
	float _10;
	float _14;
	float _18;
	float _1C;
	float _20;
	float _24;
	int _2C;
	bool _30;
	char _31; // padding?
	char _32; // ^^
	char _33; // ^^
	int _34;
	int _38; // might be a class instance
	int _3C; // padding?
	int _40; // padding?
	int* _44;
	int _48;
	int _4C;
	int _50;
	int _54;
	int _58;
};

class J3DShapeMtx
{
	public:
	~J3DShapeMtx();
	
	void loadMtxIndx_PNGP(int, unsigned short) const;
	void loadMtxIndx_PCPU(int, unsigned short) const;
	void loadMtxIndx_NCPU(int, unsigned short) const;
	void loadMtxIndx_PNCPU(int, unsigned short) const;
	void load() const;
	int getType() const;
	int getUseMtxNum() const;
	short getUseMtxIndex(unsigned short) const;
	
	int* vtable; // _0
	short mtxIndex; // _4
	short _6; // padding?
};

#endif // J3D_H