#ifndef GX_H
#define GX_H

#include "types.h"

#ifdef __cplusplus
extern "C" 
{
	void GXSetNumChans(u32);
	void GXSetNumTevStages(u32);
	void GXSetNumTexGens(u32);
	void GXSetTevOrder(u32, u32, u32, u32);
	void GXSetTevOp(u32, u32);
	void GXSetBlendMode(u32, u32, u32, u32);
	void GXSetVtxAttrFmt(u32, u32, u32, u32, u32);
	void GXClearVtxDesc();
	void GXSetVtxDesc(u32, u32);
	void GXSetTevColorIn(u32, u32, u32, u32, u32);
	void GXSetTevAlphaIn(u32, u32, u32, u32, u32);
	void GXSetTevColorOp(u32, u32, u32, u32, u32, u32);
	void GXSetTevAlphaOp(u32, u32, u32, u32, u32, u32);
	void GXSetTevColor(u32, u32);
	void GXBegin(u32, u32, u32);
	void GXInitTexObjLOD(u32, u32, u32, u32, u32, u32, f32, f32, f32);
	void GXCallDisplayList(u32, u32);
	void GXSetNumIndStages(u32);
	void GXSetTevDirect(u32);
	void GXSetTexCoordGen2(u32, u32, u32, u32, u32, u32);
}
#endif

#endif // GX_H