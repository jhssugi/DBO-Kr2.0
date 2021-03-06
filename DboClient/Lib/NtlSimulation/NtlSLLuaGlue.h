/*****************************************************************************
 *
 * File			: NtlSLLuaGlue.h
 * Author		: HyungSuk, Jang
 * Copyright	: (??)NTL
 * Date			: 2006. 2. 20	
 * Abstract		: simulation lua glue function
 *****************************************************************************
 * Desc         : 
 *
 *****************************************************************************/

#ifndef __NTL_SLLUA_GLUE_H__
#define __NTL_SLLUA_GLUE_H__

struct lua_State;
struct SHitStuff;

class CNtlFSMStateBase;
class CNtlBehaviorBase;
class CNtlSob;

class CNtlLuaState;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CNtlLuaState* GetLuaState(void);

void	SLLua_CreateState(void);
void	SLLua_Compile(void);

void	SLLua_Setup(void);
void	SLLua_Release(void);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LuaExec_SLSetupData(void);
void LuaExec_SobCreate(CNtlSob *pSobObj);
void LuaExec_SobDestroy(CNtlSob *pSobObj);
void LuaExec_CharStateEnter(unsigned int uiSerialId, CNtlFSMStateBase *pState);
void LuaExec_CharStateExit(unsigned int uiSerialId, CNtlFSMStateBase *pState);
void LuaExec_CharBehaviorEnter(unsigned int uiSerialId, CNtlBehaviorBase *pBehavior);
void LuaExec_CharBehaviorExit(unsigned int uiSerialId, CNtlBehaviorBase *pBehavior);
void LuaExec_Attack(unsigned int uiAttackerSerialId, unsigned int uiDefenderSerialId, const SHitStuff *pHit);
void LuaExec_Hurt(unsigned int uiAttackerSerialId, unsigned int uiDefenderSerialId, const SHitStuff *pHit);
void LuaExec_SkillCastingEnter(unsigned int uiSerialId, unsigned int uiSkillId);
void LuaExec_SkillCastingExit(unsigned int uiSerialId, unsigned int uiSkillId, unsigned int uiSkillSuccess);
void LuaExec_SkillActionEnter(unsigned int uiSerialId, unsigned int uiSkillId);
void LuaExec_SkillActionExit(unsigned int uiSerialId, unsigned int uiSkillId);
void LuaExec_HTBSkillStepEnter(unsigned int uiSerialId, unsigned int uiHtbTblId, unsigned int uiSkillTblId, unsigned int uiStepId);
void LuaExec_HTBSkillStepExit(unsigned int uiSerialId, unsigned int uiHtbTblId, unsigned int uiSkillTblId, unsigned int uiStepId);
void LuaExec_HTBCameraStart(unsigned int  uiAttackSerialId, unsigned int uiTargetSerialId, unsigned int uiHtbTblId);
void LuaExec_DragonDNEnter();
void LuaExec_ExplosionCamera(unsigned int uiExplosionId);
void LuaExec_ObserverCamera(unsigned int uiIndex);
void LuaExec_DirectionStep(const char* pcStepName);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


extern "C" {

	////////////////////////////////////////////////////////////////////////////
	// lua run script
	////////////////////////////////////////////////////////////////////////////

	int LuaGlue_RunScript(lua_State *L);
	
	////////////////////////////////////////////////////////////////////////////
	// lua register function
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : 
	int LuaGlue_RegisterSLSetupData(lua_State *L);

	// lua ???? : serial id, sob key name
	int LuaGlue_RegisterSobCreate(lua_State *L);

	// lua ???? : serial id, sob key name
	int LuaGlue_RegisterSobDestroy(lua_State *L);

	// lua ???? : serial id, state key name
	int LuaGlue_RegisterCharStateEnter(lua_State *L);

	// lua ???? : serial id, state key name
	int LuaGlue_RegisterCharStateExit(lua_State *L);

	// lua ???? : serial id, behavior key name
	int LuaGlue_RegisterCharBehaviorEnter(lua_State *L);

	// lua ???? : serial id, behavior key name
	int LuaGlue_RegisterCharBehaviorExit(lua_State *L);

	// lua ???? : attack serial id, target serial id
	int LuaGlue_RegisterAttack(lua_State *L);

	// lua ???? : attack serial id, target serial id
	int LuaGlue_RegisterHurt(lua_State *L);

	// lua ???? : attack serial id, target serial id, skill key name
	int LuaGlue_RegisterSkillCastingEnter(lua_State *L);

	// lua ???? : attack serial id, target serial id, skill key name
	int LuaGlue_RegisterSkillCastingExit(lua_State *L);

	// lua ???? : attack serial id, target serial id, skill key name
	int LuaGlue_RegisterSkillActionEnter(lua_State *L);

	// lua ???? : attack serial id, target serial id, skill key name
	int LuaGlue_RegisterSkillActionExit(lua_State *L);

	// lua ???? : htb attack serial id, htb skill table id, set skill table id, current step id
	int LuaGlue_RegisterHTBSkillStepEnter(lua_State *L);

	// lua ???? : htb attack serial id, htb skill table id, set skill table id, current step id
	int LuaGlue_RegisterHTBSkillStepExit(lua_State *L);

	// lua ???? : htb table id
	int LuaGlue_RegisterHTBCameraStart(lua_State *L);

	// lua ???? : 
	int LuaGlue_RegisterDragonDNEnter(lua_State* L);

	// lua ???? : explosion id
	int LuaGlue_RegisterExplosionCamera(lua_State* L);

    // lua ???? : camera index
    int LuaGlue_RegisterObserverCamera(lua_State* L);

	////////////////////////////////////////////////////////////////////////////
	// lua : ??????/?????? ??ü ???? ?Լ?
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : key name, add object flag
	int LuaGlue_CreateEffect(lua_State *L);
	
	// lua ???? : filename, add object flag
	int LuaGlue_CreateSound(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : Data?? ?????? actor ??ü ????
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : serial id
	int LuaGlue_ActiveActor(lua_State *L);

	// lua ???? : serial id
	int LuaGlue_ActiveObject(lua_State *L);

	// lua ???? : ????.
	int LuaGlue_ActiveActorEdit(lua_State *L);

	// lua ???? : ????.
	int LuaGlue_ActiveObjectEdit(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : transform position?? ???õ? ?Լ?.
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : ????.
	int LuaGlue_BeginTransform(lua_State *L);

	// lua ???? : ????.
	int LuaGlue_EndTransform(lua_State *L);

	// lua ???? : offset x, offset y, offset z
	int LuaGlue_SetPosition(lua_State *L);

	// lua ???? : bone name, offset x, offset y, offset z
	int LuaGlue_SetBonePosition(lua_State *L);

	// lua ???? : offset x, offset y, offset z
	int LuaGlue_AddPosition(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : transform direction?? ???õ? ?Լ?.
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : ????.
	int LuaGlue_SetDirection(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : transform scale?? ???õ? ?Լ?.
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : scale x, scale y, scale z
	int LuaGlue_SetScale(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : attach?? ???õ? ?Լ?.
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : offset x, offset y, offset z
	int LuaGlue_AttachWorld(lua_State *L);

	// lua ???? : bone name
	int LuaGlue_AttachBone(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : actor ?????? ???õ? ?Լ?.
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : actor serial id, actor height offset rate
	int LuaGlue_GetActorPosition(lua_State *L);

	// lua ???? : actor serial id, actor height offset rate, front distance
	int LuaGlue_GetActorFrontPosition(lua_State *L);

	// lua ???? : actor serial id, actor height offset rate, back distance
	int LuaGlue_GetActorBackPosition(lua_State *L);

	// lua ???? : actor serial id, actor height offset rate, left distance
	int LuaGlue_GetActorLeftPosition(lua_State *L);

	// lua ???? : actor serial id, actor height offset rate, right distance
	int LuaGlue_GetActorRightPosition(lua_State *L);
	
	////////////////////////////////////////////////////////////////////////////
	// lua : camera?? ???õ? ?Լ?.
	////////////////////////////////////////////////////////////////////////////

	int LuaGlue_CameraShake(lua_State *L);

	// lua ???? : shake weight, shake height
	int LuaGlue_SetCameraShakeFactor(lua_State *L);

	// lua ???? : ????.
	int LuaGlue_ResetCameraShakeFactor(lua_State *L);

	// lua ???? : fov value
	int LuaGlue_SetCameraFov(lua_State *L);

	// lua ???? : camera direction node previous node?? attach ??Ű?? flag?? enable ?Ѵ?.
	int LuaGlue_CameraDirectChildBegin(lua_State *L);

	// lua ???? : camera direction node previous node?? attach ??Ű?? flag?? disable ?Ѵ?.
	int LuaGlue_CameraDirectChildEnd(lua_State *L);
	
	// lua ???? : camera direction node clear
	int LuaGlue_CameraDirectClear(lua_State *L);

	// lua ???? : keep time(?????ð?)
	int LuaGlue_AddCameraPauseNode(lua_State *L);

	// lua ???? : start position x, start position y, start position z, direct property key name
	int LuaGlue_AddSplineCameraSelfNode(lua_State *L);

	int LuaGlue_AddSkillSplineDynamicActorSelfNode(lua_State *L);

	// lua ???? : actor height offset, property key
	int LuaGlue_AddSkillSplineDynamicLookAtNode(lua_State *L);

	// lua ???? : actor height offset, property key
	int LuaGlue_AddSkillSplineDynamicLookAtCenterNode(lua_State *L);

	int LuaGlue_AddSkillSplineStaticPosDynamicLookAtNode(lua_State *L);

	// lua ???? : direct property key name
	int LuaGlue_AddSkillAttackerSplineCameraSelfNode(lua_State *L);

	// lua ???? : direct property key name
	int LuaGlue_AddSkillTargetSplineCameraSelfNode(lua_State *L);

	// lua ???? : actor serial id, direct property key name
	int LuaGlue_AddSkillSplineActorRefSelfNode(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : Logic => actor
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : serial id
	int LuaGlue_GetOwnerSerialId(lua_State *L);

	// lua ???? : serial id
	int LuaGlue_GetActorType(lua_State *L);
	
	// lua ???? : serial id
	int LuaGlue_IsAvatarActor(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : Logic => HTB camera control ?Ӽ??? ???õ? ?Լ?.
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : ????.
	int LuaGlue_GetSkillAttackSerialId(lua_State *L);

	// lua ???? : ????.
	int LuaGlue_GetSkillTargetSerialId(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : Presentation => day and night
	////////////////////////////////////////////////////////////////////////////

	// lua ???? : delay time, duration time, start value, finish value, blend factor
	int LuaGlue_AddDNNode(lua_State *L);

	// lua ???? : delay time, duration time, finish value, blend factor
	int LuaGlue_AddDNNodeCurrentStart(lua_State *L);


	////////////////////////////////////////////////////////////////////////////
	// lua : Logic => cinematic ???⿡ ???õ? ?Լ?.
	////////////////////////////////////////////////////////////////////////////

	int LuaGlue_BeginCinematic(lua_State *L);

	int LuaGlue_EndCinematic(lua_State *L);

	int LuaGlue_BeignCinematicLayer(lua_State *L);

	int LuaGlue_EndCinematicLayer(lua_State *L);

	int LuaGlue_BeignCinematicGroup(lua_State *L);

	int LuaGlue_EndCinematicGroup(lua_State *L);

	int LuaGlue_BeginCinematicSibling(lua_State *L);

	int LuaGlue_EndCinematicSibling(lua_State *L);

	int LuaGlue_BeginCinematicCameraAsync(lua_State *L);

	int LuaGlue_EndCinematicCameraAsync(lua_State *L);

	int LuaGlue_BeginCinematicCameraLock(lua_State *L);

	int LuaGlue_EndCinematicCameraLock(lua_State *L);

	int LuaGlue_CNViewShow(lua_State *L);

	int LuaGlue_CNViewHide(lua_State *L);

	int LuaGlue_CNBalloon(lua_State *L);

	int LuaGlue_CNBalloonBegin(lua_State *L);

	int LuaGlue_CNBalloonProgress(lua_State *L);

	int LuaGlue_CNBalloonEnd(lua_State *L);

	int LuaGlue_CNBalloonSingle(lua_State *L);

	int LuaGlue_CNFlash(lua_State *L);

	int LuaGlue_AddCNMobCreate(lua_State *L);

	int LuaGlue_AddCNNpcCreate(lua_State *L);

	int LuaGlue_AddCNSobDelete(lua_State *L);

	int LuaGlue_AddCNSobMove(lua_State *L);

	int LuaGlue_AddCNSobSplineMove(lua_State *L);

	int LuaGlue_AddCNSobSplineWalkMove(lua_State *L);

	int LuaGlue_AddCNSobSplineFlyMove(lua_State *L);

	int LuaGlue_AddCNSobTriggerObjectState(lua_State *L);

	int LuaGlue_AddCNSobDirectPlay(lua_State *L);

	int LuaGlue_AddCNSobAnimPlay(lua_State *L);

	int LuaGlue_AddCNSobAnimPlayPositionSetting(lua_State *L);

	int LuaGlue_AddCNSobPositionSetting(lua_State *L);

	int LuaGlue_AddCNSobDirectSetting(lua_State *L);

	int LuaGlue_AddCNSobRotateY(lua_State *L);

	int LuaGlue_AddCNPause(lua_State *L);

	int LuaGlue_AddCNEffectActorBone(lua_State *L);

	int LuaGlue_AddCNEffectActorOffset(lua_State *L);

	int LuaGlue_AddCNEffectWorld(lua_State *L);

	int LuaGlue_AddCNEffectDelete(lua_State *L);

	int LuaGlue_AddCNCameraSoftActorDist(lua_State *L);

	int LuaGlue_AddCNCameraSoftActorDyncLookAtDist(lua_State *L);

	int LuaGlue_AddCNCameraSoftCurrRotX(lua_State *L);

	int LuaGlue_AddCNCameraSoftCurrRotY(lua_State *L);

	int LuaGlue_AddCNCameraSoftCurrRotZ(lua_State *L);

	int LuaGlue_AddCNCameraSoftCurrFov(lua_State *L);

	int LuaGlue_AddCNCameraSoftPause(lua_State *L);

	int LuaGlue_AddCNCameraSplineSelf(lua_State *L);

	int LuaGlue_AddCNCameraSplineSelfActor(lua_State *L);

	int LuaGlue_AddCNCameraSplineCurrDyncLookAt(lua_State *L);

	int LuaGlue_AddCNCameraShake(lua_State *L);

	int LuaGlue_AddCNCameraShakeFactor(lua_State *L);

	int LuaGlue_AddCNCameraShakeFactorReset(lua_State *L);

	int LuaGlue_AddCNFadeIn(lua_State *L);

	int LuaGlue_AddCNFadeOut(lua_State *L);

	int LuaGlue_AddCNFadeInTVH(lua_State *L);

	int LuaGlue_AddCNFadeOutTVH(lua_State *L);

	int LuaGlue_AddCNSound2D(lua_State *L);

	int LuaGlue_AddCNSound3D(lua_State *L);

	int LuaGlue_AddCNSoundBGM(lua_State *L);

	int LuaGlue_AddCNSoundBGMStop(lua_State *L);

	int LuaGlue_AddCNCharacterShadowOnOff(lua_State *L);

	int LuaGlue_AddCNCharacterVisibleOnOff(lua_State *L);

	int LuaGlue_AddCNSceneMoonVisibleOnOff(lua_State *L);

	int LuaGlue_AddCNSceneRainBloomLight(lua_State *L);

	int LuaGlue_AddCNSceneRainSkyLight(lua_State *L);

	int LuaGlue_AddCNGuiCommand(lua_State *L);

	int LuaGlue_AddCNCinematicServerAck(lua_State *L);

	////////////////////////////////////////////////////////////////////////////
	// lua : Logic => Explosion camera ???⿡ ???õ? ?Լ?.
	////////////////////////////////////////////////////////////////////////////

	int LuaGlue_AddSinExplosionAlgorithm_XAxis(lua_State *L);

	int LuaGlue_AddSinExplosionAlgorithm_YAxis(lua_State *L);

	int LuaGlue_AddSinExplosionAlgorithm_ZAxis(lua_State *L);



	///////////////////////////////////////////////////////////////////////////

	int LuaGlue_AddCNCinematicScale(lua_State *L);


	////////////////////////////////////////////////////////////////////////////
	// õ?????? ????ȸ ???? ????
	////////////////////////////////////////////////////////////////////////////

	int LuaGlue_DTAddController(lua_State *L);

	int LuaGlue_DTRemoveController(lua_State *L);    

    int LuaGlue_GetRefreePos(lua_State* L);
}



#endif
