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

struct _GXRenderModeObj
{
    u32 tvMode;
    u16 fbWidth;
    u16 efbHeight;
    u16 externFBHeight;
    u16 viOrigX;
    u16 viOrigY;
    u16 viWidth;
    u16 viHeight;
    u32 externalFrameBufferMode;
    u8 isFieldRendering;
    u8 isAntiAliasing;
    u8 sample_pattern[12][2];
    u8 vfilter[7];
};

#endif // GX_H