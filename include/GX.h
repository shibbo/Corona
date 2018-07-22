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

struct _GXColor
{
    u8 r;
	u8 g;
	u8 b;
	u8 a;
};

struct _GXColorS10
{
    s16 r;
	s16 g;
	s16 b;
	s16 a;
};

enum _GXTevRegID
{
    GX_TEV_PREV = 0,
    GX_TEV_REG0,
    GX_TEV_REG1,
    GX_TEV_REG2,
    GX_MAX_TEV_REG
};

enum _GXTevKColorID
{
    GX_KCOLOR0 = 0,
    GX_KCOLOR1,
    GX_KCOLOR2,
    GX_KCOLOR3,
    GX_MAX_KCOLOR
};

enum _GXChannelID
{
    GX_COLOR0,
    GX_COLOR1,
    GX_ALPHA0,
    GX_ALPHA1,
    GX_COLOR0A0,
    GX_COLOR1A1,
	GX_COLOR_ZERO,
	GX_ALPHA_BUMP,
	GX_ALPHA_BUMPN,
    GX_COLOR_NULL = 0xFF

};

#endif // GX_H