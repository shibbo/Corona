#ifndef J3D_H
#define J3D_H

#include "types.h"
#include "JUT.h"

// declaration for J3DSkinDeform to use J3DModel
class J3DModel;
class J3DShape;
class J3DDisplayListObj;

class J3DVertexData
{
	public:
	J3DVertexData();
	~J3DVertexData();
	
	u32 _0;
	u32 _4;
	u32 _8;
	u32 _C;
	u32 _10;
	u32 _14;
	u32 _18;
	u32 _1C;
	u32 _20;
	u32 _24;
	u32 _28;
	u32 _2C;
	u32 _30;
	u32 _34;
	u32 _38;
	u32 _3C;
	u32 _40;
};

class J3DVertexBuffer
{
	public:
	J3DVertexBuffer(J3DVertexData *);
	~J3DVertexBuffer();
	
	void copyTransformedVtxArray();
	
	J3DVertexData* vtxData; // _0
	u32 _4;
	u32 _8;
	u32 _C;
	u32 _10;
	u32 _14;
	u32 _18;
	u32 _1C;
	u32 _20;
	u32 _24;
	u32 _28;
	u32 _2C;
	u32 _30;
	u32 _34;
	VTABLE; // _38
};

class J3DDrawMtxData
{
	public:
	J3DDrawMtxData();
	~J3DDrawMtxData();
	
	u16 _0;
	u16 _2; // padding?
	u32 _4;
	u32 _8;
};

class J3DModelData
{
	public:
	J3DModelData();
	~J3DModelData();
	
	void clear();
	bool isDeformableVertexFormat() const;
	
	VTABLE; // _0
	u32 _4;
	u32 _8;
	u32 _C;
	u32 _10;
	u32 _14;
	u16 _18;
	u16 _1A;
	u16 _1C;
	u32 _20;
	u16 _24;
	u16 _26; // padding?
	u32 _28;
	u16 _2C;
	u16 _2E; // padding?
	u32 _30; // JUTNameTab (joints)
	u16 _34;
	u16 _36; // padding?
	u32 _38;
	J3DVertexData vertexData; // _3C
	u32 _80;
	u16 _84;
	u16 _86; // padding?
	u32 _88;
	u32 _8C;
	u32 _90;
	u32 _94;
	J3DDrawMtxData drawMtxData; // _98
	u32 _A4;
	u32 _A8;
	u32 _AC;
	u32 _B0;
	u32 _B4;
	u32 _B8;
};

class J3DSkinDeform
{
	public:
	J3DSkinDeform();
	~J3DSkinDeform();
	
	void initMtxIndexArray(J3DModelData *);
	void calcNrmMtx(J3DModel *);
	void deform(J3DModel *);
	
	VTABLE; // _0
	u32 _4;
	u32 _8;
	u32 _C;
	u32 _10;
};

class J3DDisplayListObj
{
	public:
	void newDisplayList(u32 numLists);
	void callDL();
	
	u32 _0;
	u32 _4;
	u32 _8;
	u32 _C;
};

class J3DMaterial
{
	public:
	J3DMaterial();
	~J3DMaterial();
	
	void initialize();
	void addShape(J3DShape *);
	void createColorBlock(u32);
	void createTexGenBlock(u32);
	void createTevBlock(int);
	void createIndBlock(u32);
	void createPEBlock(int, u32);
	u32 countDLSize();
	void makeDisplayList();
	void safeMakeDisplayList();
	void load();
	void calc(u32 *);
	void copy(J3DMaterial *);
	void change();
	void newSharedDisplayList(u32);
	void calc(MtxPtr);
	void setCurrentMtx();
	
	u32* _0;
	J3DShape* shape; // _4
	u32 _8;
	u16 _C;
	u16 _E; //padding?
	u32 _10;
	u32 _14; // padding?
	u32* _18;
	u32 _1C;
	u32* _20; // *TItemManager
	u32* _24; // *TItemManager
	u32* _28;
	u32 _2C; // *TItemManager
	u32 _30;
	u32* _34;
	u32 _38;
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
	u32 getType() const;
	
	VTABLE; // _0
	u32 _4;
	u32 _8;
	u32 _C; // padding?
	u32* _10;
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
	u32 getType() const;
	void addMesh(J3DMaterial *);
	void initialize();
	
	u16 _18;
	u8 _1A;
	u8 _1B;
	f32 _1C;
	f32 _20;
	f32 _24;
	u16 _28;
	u16 _2A;
	u16 _2C;
	u16 _2E; // padding?
	f32 _30;
	f32 _34;
	f32 _38;
	f32 _3C;
	u32 _40;
	u32 _44;
	u32 _48;
	u32 _50;
	u32 _54;
	u32 _58;
	u32 _5C;
	J3DMaterial* material; // _60
};

class J3DModel
{
	public:
	J3DModel();
	J3DModel(J3DModelData *, u32, u32);
	~J3DModel();
	
	void update();
	void entry();
	void calc();
	void viewCalc();
	
	void initialize();
	void entryModelData(J3DModelData *, u32, u32);
	void lock();
	void unlock();
	void makeDL();
	void setSkinDeform(J3DSkinDeform *, u32); // J3DDeformAttachFlag
	void calcNrmMtx();
	void calcBumpMtx();
	void calcBBoard();
	void prepareShapePackets();
	void calcWeightEnvelopeMtx();
	
	VTABLE; // _0
	J3DModelData* data; // _4
	u32 _8;
	u32 _C;
	f32 _14;
	f32 _18;
	f32 _1C;
	Mtx _20;
	u32 _50;
	u32 _54;
	u32 _58;
	u32 _5C;
	u32 _60;
	u32 _64;
	u32 _68;
	u32 _6C;
	u32 _70;
	u32 _74;
	u32 _7C;
	u32 _80;
	u32 _84;
	u32 _88;
	J3DSkinDeform* skinDeform; // _8C
	u32 _90;
	u32 _94;
	J3DVertexBuffer vtxBuffer; // _98
};

class J3DShape
{
	public:
	
	void initialize();
	u32 countBumpMtxNum() const;
	void makeVtxArrayCmd();
	void makeVcdVatCmd();
	u32 loadVtxArray() const;
	u32 draw() const;
	
	u32 _0;
	u16 _4;
	u16 _6;
	u32 _8;
	f32 _C;
	f32 _10;
	f32 _14;
	f32 _18;
	f32 _1C;
	f32 _20;
	f32 _24;
	u32 _2C;
	bool _30;
	u8 _31; // padding?
	u8 _32; // ^^
	u8 _33; // ^^
	u32 _34;
	u32 _38; // might be a class instance
	u32 _3C; // padding?
	u32 _40; // padding?
	u32* _44;
	u32 _48;
	u32 _4C;
	u32 _50;
	u32 _54;
	u32 _58;
};

class J3DShapeMtx
{
	public:
	~J3DShapeMtx();
	
	void loadMtxIndx_PNGP(u32,  u16) const;
	void loadMtxIndx_PCPU(u32,  u16) const;
	void loadMtxIndx_NCPU(u32,  u16) const;
	void loadMtxIndx_PNCPU(u32,  u16) const;
	void load() const;
	u32 getType() const;
	u32 getUseMtxNum() const;
	u16 getUseMtxIndex(s16) const;
	
	VTABLE; // _0
	s16 mtxIndex; // _4
	u16 _6; // padding?
};

class J3DDrawBuffer
{
	public:
	J3DDrawBuffer(u32 size);

	void frameInit();
	void draw();

	u32* _0;
	u32 size; // _4
	u32 _8;
	u32 _C;
	f32 _10;
	f32 _14;
	f32 _18;
	u32 _1C;
	u32 _20;
};

class J3DColorChan
{
	public:
	J3DColorChan();

	u16 colorChanID; // _0
};

class J3DGXColor
{
	public:
	J3DGXColor();
};

class J3DColorBlock
{
	public:
	~J3DColorBlock();

	void reset(J3DColorBlock *);

	VTABLE; // _0
};

class J3DTexCoord
{
	public:
	J3DTexCoord();

	u8 _0;
	u8 _1;
	u8 _2;
};

class J3DTexture
{
	public:
	~J3DTexture();

	u16 _0;
	u16 _2;
	u32 _4;
	VTABLE; // _8
};

class J3DMaterialTable
{
	public:
	J3DMaterialTable();
	~J3DMaterialTable();

	void clear();

	VTABLE; // _0
	u16 _4;
	u16 _6;
	u32 _8;
	J3DTexture* texture; // _C
	u32 _10;
	u32 _14;
};

class J3DAnmBase
{
	public:
	J3DAnmBase();
	J3DAnmBase(u16);
	~J3DAnmBase();

	u16 _0;
	u16 _2;
	f32 _4;
	u32 _8; // guessed
	VTABLE; // _C
};

class J3DAnmTexPattern : public J3DAnmBase
{
	public:
	~J3DAnmTexPattern();
	
	void getTexNo(u16, u16 *texNo);
	void searchUpdateMaterialID(J3DModelData *);

	u32 _10;
	u32 _14;
	u16 _18;
	u16 _1A;
	u32 _1C;
	JUTNameTab* nameTab; // _20
};

class J3DTexNoAnm
{
	public:
	J3DTexNoAnm();
	~J3DTexNoAnm();

	VTABLE; // _0
	u16 _4;
	u16 _6; // padding?
};

class J3DPacket
{
	public:
	~J3DPacket();

	bool isSame() const;
	u32 entry(J3DDrawBuffer *);
	void draw();

	void addChildPacket(J3DPacket *parent);

	VTABLE;
	J3DPacket* parentPacket; // _4
	J3DPacket* childPacket; // _8
};

class J3DDrawPacket : public J3DPacket
{
	public:
	~J3DDrawPacket();

	void draw();

	void beginDL();
	void endDL();

	u8 _C[0x30-0xC];
	u32* _30;
};

class J3DCallbackPacket : public J3DPacket
{
	public:
	~J3DCallbackPacket();

	void draw();
};

class J3DShapePacket : public J3DCallbackPacket
{
	public:
	J3DShapePacket();
	~J3DShapePacket();

	void draw();
};

class J3DMatPacket : public J3DDrawPacket
{
	public:
	J3DMatPacket();

	bool isSame(J3DMatPacket *);
	void entry(J3DDrawBuffer *);
	void draw();

	void addShapePacket(J3DShapePacket *);

	J3DShapePacket* shapePacket; // _34
	u32 _38;
	u32 _3C;
	u32 _40;
	u32 _44;
};

u16 calcColorChanID(unsigned short, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

#endif // J3D_H