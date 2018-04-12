#ifndef GX_H
#define GX_H

#ifdef __cplusplus
extern "C" 
{
	void GXSetNumChans(int);
	void GXSetNumTevStages(int);
	void GXSetNumTexGens(int);
	void GXSetTevOrder(int, int, int, int);
	void GXSetTevOp(int, int);
	void GXSetBlendMode(int, int, int, int);
	void GXSetVtxAttrFmt(int, int, int, int, int);
	void GXClearVtxDesc();
	void GXSetVtxDesc(int, int);
	void GXSetTevColorIn(int, int, int, int, int);
	void GXSetTevAlphaIn(int, int, int, int, int);
	void GXSetTevColorOp(int, int, int, int, int, int);
	void GXSetTevAlphaOp(int, int, int, int, int, int);
	void GXSetTevColor(int, int);
	void GXBegin(int, int, int);
	void GXInitTexObjLOD(int, int, int, int, int, int, float, float, float);
	void GXCallDisplayList(int, int);
}
#endif

#endif // GX_H