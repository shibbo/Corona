#ifndef SMS_H
#define SMS_H

#include "JGeometry.h"
#include "JKR.h"
#include "actor/THitActor.h"
#include "actor/TItem.h"
#include "actor/TLiveActor.h"
#include "actor/TMario.h"

using namespace JGeometry;

void SMS_WindMoveMario(TVec3<float> const &);
void SMS_FlowMoveMario(TVec3<float> const &);
void SMS_MarioWarpRequest(TVec3<float> const &, float);
void SMS_MarioMoveRequest(TVec3<float> const &);
bool SMS_IsMarioDashing();
bool SMS_IsMarioOnYoshi();
bool SMS_IsMarioOpeningDoor();
bool SMS_IsMarioOnWire();
bool SMS_IsMarioTouchGround4cm();
bool SMS_IsMarioStatusTypeJumping();
bool SMS_IsMarioStatusHipDrop();
bool SMS_IsMarioStatusTypeSwimming();
float SMS_GetMarioGravity();
float SMS_GetMarioGrLevel();
float SMS_GetMarioDamageRadius();
short SMS_GetMarioHP();
bool SMS_IsMarioHeadSlideAttack();
bool SMS_IsMarioStatusElecDamage();
bool SMS_IsMarioStatusThrownDown();
int SMS_GetMarioStatus();
int SMS_GetMarioStatus(THitActor *);
void SMS_AskJumpIntoWaterEffectExist();
int* SMS_GetYoshi();
char SMS_getShineIDofExStage(unsigned char);
bool SMS_isOptionMap();
bool SMS_isDivingMap();
bool SMS_isMultiPlayerMap();
bool SMS_isExMap();
int SMSGetGCLogoVideoHeight();
int SMSGetGCLogoVideoWidth();
int SMSGetGCLogoRenderHeight();
int SMSGetGCLogoRenderWidth();
int SMSGetTitleRenderHeight();
int SMSGetTitleRenderWidth();
int SMSGetGameRenderHeight();
int SMSGetGameRenderWidth();
int SMSGetTitleVideoHeight();
int SMSGetTitleVideoWidth();
int SMSGetGameVideoHeight();
int SMSGetGameVideoWidth();
void SMS_ThrowMario(TVec3<float> const & ,float);
bool SMS_SendMessageToMario(THitActor *, unsigned long);
char SMS_getShineStage(unsigned char);
TMario* SMS_GetMarioHitActor();
//TWaterGun* SMS_GetMarioWaterGun();

TItem* newItemByName(char const *);
TItem* newUniqueObjByName(char const *);

J3DModel SMS_CreatePartsModel(char *, unsigned long);
void SMS_UnifyMaterial(J3DModel *);
void SMS_CalcMatAnmAndMakeDL(J3DModel *, unsigned short);
void SMS_ResetTexCacheRegion();
void SMS_DrawInit();
void SMS_MakeDLAndLock(J3DModel *);
float SMS_GetSandRiseUpRatio(TLiveActor const *);
int SMS_GetMonteVillageAreaInMario();

JUTRect SMSGetRederRect_Game();

int* SMSLoadArchive(char const *, void *, unsigned long, JKRHeap *); // returns JKRMemArchive

#endif // SMS_H