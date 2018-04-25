#ifndef SMS_H
#define SMS_H

#include "J3D.h"
#include "JGeometry.h"
#include "JKR.h"
#include "JUT.h"
#include "types.h"
#include "actor/THitActor.h"
#include "actor/TItem.h"
#include "actor/TLiveActor.h"
#include "actor/TMario.h"
#include "actor/TYoshi.h"

using namespace JGeometry;

void SMS_WindMoveMario(TVec3<f32> const &);
void SMS_FlowMoveMario(TVec3<f32> const &);
void SMS_MarioWarpRequest(TVec3<f32> const &, f32);
void SMS_MarioMoveRequest(TVec3<f32> const &);
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
void SMS_AskJumpIntoWaterEffectExist();
TYoshi* SMS_GetYoshi();
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
void SMS_ThrowMario(TVec3<f32> const & ,f32);
bool SMS_SendMessageToMario(THitActor *, u32);
u8 SMS_getShineStage(s8);
TMario* SMS_GetMarioHitActor();
//TWaterGun* SMS_GetMarioWaterGun();

TItem* newItemByName(char const *);
TItem* newUniqueObjByName(char const *);

J3DModel SMS_CreatePartsModel(u8 *, u32);
J3DModel* SMS_CreateMinimumSDLModel(char const *);

void SMS_UnifyMaterial(J3DModel *);
void SMS_CalcMatAnmAndMakeDL(J3DModel *, s16);
void SMS_ResetTexCacheRegion();
void SMS_DrawInit();
void SMS_MakeDLAndLock(J3DModel *);
f32 SMS_GetSandRiseUpRatio(TLiveActor const *);
u32 SMS_GetMonteVillageAreaInMario();

JUTRect SMSGetRederRect_Game();

u32* SMSLoadArchive(char const *, void *, u32, JKRHeap *); // returns JKRMemArchive

void SMSCalcJumpVelocityXZ(TVec3<f32> const &, TVec3<f32> const &, f32, f32, TVec3<f32> *)

#endif // SMS_H