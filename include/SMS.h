#ifndef SMS_H
#define SMS_H

#include "GX.h"
#include "J3D.h"
#include "JGeometry.h"
#include "JKR.h"
#include "JUT.h"
#include "TRidingInfo.h"
#include "types.h"
#include "actor/THitActor.h"
#include "actor/TItem.h"
#include "actor/TLiveActor.h"
#include "actor/TMario.h"
#include "actor/TYoshi.h"
#include "nozzle/TWaterGun.h"

void SMS_WindMoveMario(JGeometry::TVec3<f32> const &);
void SMS_FlowMoveMario(JGeometry::TVec3<f32> const &);
void SMS_MarioWarpRequest(JGeometry::TVec3<f32> const &, f32);
void SMS_MarioMoveRequest(JGeometry::TVec3<f32> const &);
bool SMS_IsMarioDashing();
bool SMS_IsMarioOnYoshi();
bool SMS_IsMarioOpeningDoor();
bool SMS_IsMarioOnWire();
bool SMS_IsMarioTouchGround4cm();
bool SMS_IsMarioStatusTypeJumping();
bool SMS_IsMarioStatusHipDrop();
bool SMS_IsMarioStatusTypeSwimming();
f32 SMS_GetMarioGravity();
f32 SMS_GetMarioGrLevel();
f32 SMS_GetMarioDamageRadius();
u16 SMS_GetMarioHP();
bool SMS_IsMarioHeadSlideAttack();
bool SMS_IsMarioStatusElecDamage();
bool SMS_IsMarioStatusThrownDown();
u32 SMS_GetMarioStatus();
u32 SMS_GetMarioStatus(THitActor *);
bool SMS_AskJumpIntoWaterEffectExist();
TYoshi* SMS_GetYoshi();
void SMS_SetMarioAccessParams();

u8 SMS_getShineIDofExStage(s8);
bool SMS_isOptionMap();
bool SMS_isDivingMap();
bool SMS_isMultiPlayerMap();
bool SMS_isExMap();
u32 SMSGetGCLogoVideoHeight();
u32 SMSGetGCLogoVideoWidth();
u32 SMSGetGCLogoRenderHeight();
u32 SMSGetGCLogoRenderWidth();
u32 SMSGetTitleRenderHeight();
u32 SMSGetTitleRenderWidth();
u32 SMSGetGameRenderHeight();
u32 SMSGetGameRenderWidth();
u32 SMSGetTitleVideoHeight();
u32 SMSGetTitleVideoWidth();
u32 SMSGetGameVideoHeight();
u32 SMSGetGameVideoWidth();
void SMS_ThrowMario(JGeometry::TVec3<f32> const & ,f32);
bool SMS_SendMessageToMario(THitActor *, u32);
u8 SMS_getShineStage(s8 shineID);
TMario* SMS_GetMarioHitActor();
TWaterGun* SMS_GetMarioWaterGun();

TItem* newItemByName(char const *);
TItem* newUniqueObjByName(char const *);

J3DModel SMS_CreatePartsModel(u8 *, u32);
J3DModel* SMS_CreateMinimumSDLModel(char const *);

void SMS_UnifyMaterial(J3DModel *);
void SMS_DrawShape(J3DModelData *, u16);
void SMS_SettingDrawShape(J3DModelData *, u16);
void SMS_DrawCube(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &);
u32 SMS_CountPolygonNumInShape(J3DShape *);
void SMS_ResetDamageFogEffect(J3DModelData *);
void SMS_AddDamageFogEffect(J3DModelData *, JGeometry::TVec3<f32> const &, JDrama::TGraphics *);
void SMS_CalcMatAnmAndMakeDL(J3DModel *, s16);
void SMS_ResetTexCacheRegion();
void SMS_DrawInit();
void SMS_MakeDLAndLock(J3DModel *);
f32 SMS_GetSandRiseUpRatio(TLiveActor const *);
u32 SMS_GetMonteVillageAreaInMario();
void SMS_MakeJointsToArc(J3DModel *,JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &,JGeometry::TVec3<f32> const &);

JUTRect SMSGetRenderRect_Game();

u32* SMSLoadArchive(char const *, void *, u32, JKRHeap *); // returns JKRMemArchive

void SMSCalcJumpVelocityXZ(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, f32, f32, JGeometry::TVec3<f32> *);

void SMS_EmitSinkInPollutionEffect(JGeometry::TVec3<f32> const &, JGeometry::TVec3<f32> const &, bool);
bool SMS_EmitRippleSea(f32 *[4], void *);
bool SMS_EmitRipplePool(f32 *[4],void *);
bool SMS_EmitRippleTiny(JGeometry::TVec3<f32> *);

void SMS_RideMoveCalcLocalPos(TRidingInfo *, JGeometry::TVec3<f32> const &);
void SMS_RideMoveByGroundActor(TRidingInfo *, JGeometry::TVec3<f32> *, float *);

void SMSSetupMovieRenderingInfo(JDrama::TDisplay *);
void SMSSetupGameRenderingInfo(JDrama::TDisplay *, bool);
void SMSSetupTitleRenderingInfo(JDrama::TDisplay *);
void SMSSetupTitleRenderMode(_GXRenderModeObj *);
void SMSSetupGCLogoRenderingInfo(JDrama::TDisplay *);
void SMSGetRederRect_Game();

#endif // SMS_H