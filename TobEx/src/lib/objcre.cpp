#include "objcre.h"

//CProtectedSplList
void (CProtectedSplList::*CProtectedSplList_AddTail)(CEffect&, int, int, CCreatureObject&, BOOL, STRREF, BOOL, BOOL) =
	SetFP(static_cast<void (CProtectedSplList::*)(CEffect&, int, int, CCreatureObject&, BOOL, STRREF, BOOL, BOOL)>
																			(&CProtectedSplList::AddTail),				0x464A50);
void (CProtectedSplList::*CProtectedSplList_Update)(CCreatureObject&) =
	SetFP(static_cast<void (CProtectedSplList::*)(CCreatureObject&)>		(&CProtectedSplList::Update),				0x464BFB);

void CProtectedSplList::AddTail(CEffect& effect, int nPower, int nOpcode, CCreatureObject& cre, BOOL bCreateProj, STRREF strref, BOOL bDoNotUpdateEff, BOOL bRestoreLostSpls)
	{ return (this->*CProtectedSplList_AddTail)(effect, nPower, nOpcode, cre, bCreateProj, strref, bDoNotUpdateEff, bRestoreLostSpls); }
void CProtectedSplList::Update(CCreatureObject& cre) { return (this->*CProtectedSplList_Update)(cre); }

//CCreatureObject
CGameObject& (CCreatureObject::*CCreatureObject_SetTarget)(Object&, char) =
	SetFP(static_cast<CGameObject& (CCreatureObject::*)(Object&, char)>		(&CCreatureObject::SetTarget),				0x48D519);
void (CCreatureObject::*CCreatureObject_GetSpellIdsName)(int, IECString*) =
	SetFP(static_cast<void (CCreatureObject::*)(int, IECString*)>			(&CCreatureObject::GetSpellIdsName),		0x48FE60);
CDerivedStats& (CCreatureObject::*CCreatureObject_GetDerivedStats)() =
	SetFP(static_cast<CDerivedStats& (CCreatureObject::*)()>				(&CCreatureObject::GetDerivedStats),		0x495630);
ACTIONRESULT (CCreatureObject::*CCreatureObject_CastSpell)(ResRef&, CGameObject&, BOOL, STRREF, void*, BOOL, BOOL) =
	SetFP(static_cast<ACTIONRESULT (CCreatureObject::*)(ResRef&, CGameObject&, BOOL, STRREF, void*, BOOL, BOOL)>
																			(&CCreatureObject::CastSpell),				0x4AD88A);
void (*CCreatureObject_RemoveItem)(CCreatureObject&, int) =
	reinterpret_cast<void (*)(CCreatureObject&, int)>						(0x52033C);
CEffectList& (CCreatureObject::*CCreatureObject_GetEquippedEffectsList)() =
	SetFP(static_cast<CEffectList& (CCreatureObject::*)()>					(&CCreatureObject::GetEquippedEffectsList),	0x567540);
CEffectList& (CCreatureObject::*CCreatureObject_GetMainEffectsList)() =
	SetFP(static_cast<CEffectList& (CCreatureObject::*)()>					(&CCreatureObject::GetMainEffectsList),		0x567560);
CCreatureObject& (CCreatureObject::*CCreatureObject_Construct_10)(void*, unsigned int, BOOL, int, int, int, unsigned int, int, int, int) =
	SetFP(static_cast<CCreatureObject& (CCreatureObject::*)(void*, unsigned int, BOOL, int, int, int, unsigned int, int, int, int)>
																			(&CCreatureObject::Construct),				0x87FB08);
void (CCreatureObject::*CCreatureObject_CreateGore)(int, short, short) =
	SetFP(static_cast<void (CCreatureObject::*)(int, short, short)>			(&CCreatureObject::CreateGore),				0x8862FE);
void (CCreatureObject::*CCreatureObject_UpdateHPStatusTooltip)(CUIControl&) =
	SetFP(static_cast<void (CCreatureObject::*)(CUIControl&)>				(&CCreatureObject::UpdateHPStatusTooltip),	0x8AC3C5);
short (CCreatureObject::*CCreatureObject_GetOrientationTo)(POINT&) =
	SetFP(static_cast<short (CCreatureObject::*)(POINT&)>					(&CCreatureObject::GetOrientationTo),		0x8ACFC2);
short (*CCreatureObject_CalculateOrientation)(POINT&, POINT&) =
	reinterpret_cast<short (*)(POINT&, POINT&)>								(0x8AD080);
void (CCreatureObject::*CCreatureObject_SetAnimationSequence)(short) =
	SetFP(static_cast<void (CCreatureObject::*)(short)>						(&CCreatureObject::SetAnimationSequence),	0x8AD630);
void (CCreatureObject::*CCreatureObject_StartSpriteEffect)(char, char, int) =
	SetFP(static_cast<void (CCreatureObject::*)(char, char, int)>			(&CCreatureObject::StartSpriteEffect),		0x8B10DE);
CItem& (CCreatureObject::*CCreatureObject_GetFirstEquippedLauncherOfAbility)(ItmFileAbility& ability, int* pnSlot) =
	SetFP(static_cast<CItem& (CCreatureObject::*)(ItmFileAbility&, int*)>	(&CCreatureObject::GetFirstEquippedLauncherOfAbility),
																														0x8C5981);
int (CCreatureObject::*CCreatureObject_GetSlotOfEquippedLauncherOfAmmo)(short, short) =
	SetFP(static_cast<int (CCreatureObject::*)(short, short)>				(&CCreatureObject::GetSlotOfEquippedLauncherOfAmmo),
																														0x8C5B1E);
void (CCreatureObject::*CCreatureObject_UnequipAll)(BOOL) =
	SetFP(static_cast<void (CCreatureObject::*)(BOOL)>						(&CCreatureObject::UnequipAll),				0x8CA628);
void (CCreatureObject::*CCreatureObject_EquipAll)(BOOL) =
	SetFP(static_cast<void (CCreatureObject::*)(BOOL)>						(&CCreatureObject::EquipAll),				0x8CA88D);
void (CCreatureObject::*CCreatureObject_AddKnownSpell)(ResRef&, BOOL) =
	SetFP(static_cast<void (CCreatureObject::*)(ResRef&, BOOL)>				(&CCreatureObject::AddKnownSpell),			0x8CAFE4);
CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellPriest)(int, int) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(int, int)>	(&CCreatureObject::GetKnownSpellPriest),	0x8CB91F);
CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellMage)(int, int) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(int, int)>	(&CCreatureObject::GetKnownSpellMage),		0x8CB949);
CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellInnate)(int, int) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(int, int)>	(&CCreatureObject::GetKnownSpellInnate),	0x8CB973);
CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellPriest)(int, int) =
	SetFP(static_cast<CreFileMemSpell& (CCreatureObject::*)(int, int)>		(&CCreatureObject::GetMemSpellPriest),		0x8CB9D9);
CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellMage)(int, int) =
	SetFP(static_cast<CreFileMemSpell& (CCreatureObject::*)(int, int)>		(&CCreatureObject::GetMemSpellMage),		0x8CBA03);
CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellInnate)(int, int) =
	SetFP(static_cast<CreFileMemSpell& (CCreatureObject::*)(int, int)>		(&CCreatureObject::GetMemSpellInnate),		0x8CBA2D);
BOOL (CCreatureObject::*CCreatureObject_AddMemSpellPriest)(int, int, int*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(int, int, int*)>			(&CCreatureObject::AddMemSpellPriest),		0x8CBB64);
BOOL (CCreatureObject::*CCreatureObject_AddMemSpellMage)(int, int, int*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(int, int, int*)>			(&CCreatureObject::AddMemSpellMage),		0x8CBBEA);
BOOL (CCreatureObject::*CCreatureObject_AddMemSpellInnate)(int, int, int*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(int, int, int*)>			(&CCreatureObject::AddMemSpellInnate),		0x8CBC70);
BOOL (CCreatureObject::*CCreatureObject_AddKnownSpellPriest)(ResRef&, int) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(ResRef&, int)>				(&CCreatureObject::AddKnownSpellPriest),	0x8CC4F4);
BOOL (CCreatureObject::*CCreatureObject_AddKnownSpellMage)(ResRef&, int) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(ResRef&, int)>				(&CCreatureObject::AddKnownSpellMage),		0x8CC524);
BOOL (CCreatureObject::*CCreatureObject_AddKnownSpellInnate)(ResRef&, int) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(ResRef&, int)>				(&CCreatureObject::AddKnownSpellInnate),	0x8CC554);
void (CCreatureObject::*CCreatureObject_ApplyClassAbilities)(CDerivedStats&, BOOL) =
	SetFP(static_cast<void (CCreatureObject::*)(CDerivedStats&, BOOL)>		(&CCreatureObject::ApplyClassAbilities),	0x8D22D8);
void (CCreatureObject::*CCreatureObject_RemoveClassAbilities)(CDerivedStats&) =
	SetFP(static_cast<void (CCreatureObject::*)(CDerivedStats&)>			(&CCreatureObject::RemoveClassAbilities),	0x8D2E5F);
IECString& (CCreatureObject::*CCreatureObject_GetLongName)() =
	SetFP(static_cast<IECString& (CCreatureObject::*)()>					(&CCreatureObject::GetLongName),			0x8D49D9);
STRREF (CCreatureObject::*CCreatureObject_GetLongNameStrRef)() =
	SetFP(static_cast<STRREF (CCreatureObject::*)()>						(&CCreatureObject::GetLongNameStrRef),		0x8D4AAC);
void (CCreatureObject::*CCreatureObject_SetSpellMemorizedState)(ResSplContainer&, BOOL) =
	SetFP(static_cast<void (CCreatureObject::*)(ResSplContainer&, BOOL)>	(&CCreatureObject::SetSpellMemorizedState),	0x8D6202);
void (CCreatureObject::*CCreatureObject_ValidateAttackSequence)(char*) =
	SetFP(static_cast<void (CCreatureObject::*)(char*)>						(&CCreatureObject::ValidateAttackSequence),	0x8D6D78);
char (CCreatureObject::*CCreatureObject_GetNumUniqueMemSpellMage)(int, ResRef) =
	SetFP(static_cast<char (CCreatureObject::*)(int, ResRef)>				(&CCreatureObject::GetNumUniqueMemSpellMage),0x8DAE88);
BOOL (CCreatureObject::*CCreatureObject_InDialogAction)() =
	SetFP(static_cast<BOOL (CCreatureObject::*)()>							(&CCreatureObject::InDialogAction),			0x8DE5F5);
void (CCreatureObject::*CCreatureObject_SetSaveName)(ResRef&) =
	SetFP(static_cast<void (CCreatureObject::*)(ResRef&)>					(&CCreatureObject::SetSaveName),			0x8DF047);
unsigned int (CCreatureObject::*CCreatureObject_GetKitUnusableFlag)() =
	SetFP(static_cast<unsigned int (CCreatureObject::*)()>					(&CCreatureObject::GetKitUnusableFlag),		0x8E066B);
void (CCreatureObject::*CCreatureObject_PrintEventMessage)(short, int, int, int, STRREF, BOOL, IECString&) =
	SetFP(static_cast<void (CCreatureObject::*)(short, int, int, int, STRREF, BOOL, IECString&)>
																			(&CCreatureObject::PrintEventMessage),		0x8FAE5A);
short (CCreatureObject::*CCreatureObject_GetProficiencyInItem)(CItem&) =
	SetFP(static_cast<short (CCreatureObject::*)(CItem&)>					(&CCreatureObject::GetProficiencyInItem),	0x90C663);
ACTIONRESULT (CCreatureObject::*CCreatureObject_ActionMoveToObject)(CGameObject&) =
	SetFP(static_cast<ACTIONRESULT (CCreatureObject::*)(CGameObject&)>		(&CCreatureObject::ActionMoveToObject),		0x90EBCA);
ACTIONRESULT (CCreatureObject::*CCreatureObject_ActionPickPockets)(CCreatureObject&) =
	SetFP(static_cast<ACTIONRESULT (CCreatureObject::*)(CCreatureObject&)>	(&CCreatureObject::ActionPickPockets),		0x9431AE);
short (CCreatureObject::*CCreatureObject_GetProficiency)(int) =
	SetFP(static_cast<short (CCreatureObject::*)(int)>						(&CCreatureObject::GetProficiency),			0x950A4F);
short (CCreatureObject::*CCreatureObject_GetSpellCastingLevel)(ResSplContainer&, BOOL) =
	SetFP(static_cast<short (CCreatureObject::*)(ResSplContainer&, BOOL)>	(&CCreatureObject::GetSpellCastingLevel),	0x9514A1);
ACTIONRESULT (CCreatureObject::*CCreatureObject_ActionJumpToAreaEntranceMove)(IECString) =
	SetFP(static_cast<ACTIONRESULT (CCreatureObject::*)(IECString)>			(&CCreatureObject::ActionJumpToAreaEntranceMove), 0x953CE9);
void (CCreatureObject::*CCreatureObject_UpdateFaceTalkerTimer)() =
	SetFP(static_cast<void (CCreatureObject::*)()>							(&CCreatureObject::UpdateFaceTalkerTimer),	0x955CD7);


bool (CCreatureObject::*CCreatureObject_NeedsAIUpdate)(bool, int) =
	SetFP(static_cast<bool (CCreatureObject::*)(bool, int)>					(&CCreatureObject::NeedsAIUpdate),			0x8DE733);
BOOL (CCreatureObject::*CCreatureObject_EvaluateTrigger)(Trigger&) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(Trigger&)>					(&CCreatureObject::EvaluateTrigger),		0x8F6C0E);
ACTIONRESULT (CCreatureObject::*CCreatureObject_ExecuteAction)() =
	SetFP(static_cast<ACTIONRESULT (CCreatureObject::*)()>					(&CCreatureObject::ExecuteAction),			0x8E2276);
void (CCreatureObject::*CCreatureObject_SetCurrentAction)(Action&) =
	SetFP(static_cast<void (CCreatureObject::*)(Action&)>					(&CCreatureObject::SetCurrentAction),		0x8F97AA);

CGameObject& CCreatureObject::SetTarget(Object& o, char type)					{ return (this->*CCreatureObject_SetTarget)(o, type); }
void CCreatureObject::GetSpellIdsName(int nSpellIdx, IECString* ptr)			{ return (this->*CCreatureObject_GetSpellIdsName)(nSpellIdx, ptr); }
CDerivedStats& CCreatureObject::GetDerivedStats()								{ return (this->*CCreatureObject_GetDerivedStats)(); }
ACTIONRESULT CCreatureObject::CastSpell(ResRef& rResource, CGameObject& cgoTarget, BOOL bPrintStrref, STRREF strref, void* pMod, BOOL bPrintEventMsg, BOOL bDoNotApplySplAbil)
	{ return (this->*CCreatureObject_CastSpell)(rResource, cgoTarget, bPrintStrref, strref, pMod, bPrintEventMsg, bDoNotApplySplAbil); }
void CCreatureObject::RemoveItem(CCreatureObject& cre, int nSlot)				{ return (*CCreatureObject_RemoveItem)(cre, nSlot); }
CEffectList& CCreatureObject::GetEquippedEffectsList()							{ return (this->*CCreatureObject_GetEquippedEffectsList)(); }
CEffectList& CCreatureObject::GetMainEffectsList()								{ return (this->*CCreatureObject_GetMainEffectsList)(); }
CCreatureObject::CCreatureObject(void* pFile, unsigned int dwSize, BOOL bHasSpawned, int nTicksTillRemove, int nMaxMvtDistance, int nMaxMvtDistanceToObject, unsigned int nSchedule, int nDestX, int nDestY, int nFacing)
	{ (this->*CCreatureObject_Construct_10)(pFile, dwSize, bHasSpawned, nTicksTillRemove, nMaxMvtDistance, nMaxMvtDistanceToObject, nSchedule, nDestX, nDestY, nFacing); }
void CCreatureObject::CreateGore(int dwUnused, short wOrient, short wType)		{ return (this->*CCreatureObject_CreateGore)(dwUnused, wOrient, wType); }
void CCreatureObject::UpdateHPStatusTooltip(CUIControl& control)				{ return (this->*CCreatureObject_UpdateHPStatusTooltip)(control); }
short CCreatureObject::GetOrientationTo(POINT& pt)								{ return (this->*CCreatureObject_GetOrientationTo)(pt); }
short CCreatureObject::CalculateOrientation(POINT& pt1, POINT& pt2)				{ return (*CCreatureObject_CalculateOrientation)(pt1, pt2); }
void CCreatureObject::SetAnimationSequence(short wSeq)							{ return (this->*CCreatureObject_SetAnimationSequence)(wSeq); }
void CCreatureObject::StartSpriteEffect(char nEffectType, char nParticleType, int nParticles)
	{ return (this->*CCreatureObject_StartSpriteEffect)(nEffectType, nParticleType, nParticles); }
CItem& CCreatureObject::GetFirstEquippedLauncherOfAbility(ItmFileAbility& ability, int* pnSlot)
	{ return (this->*CCreatureObject_GetFirstEquippedLauncherOfAbility)(ability, pnSlot); }
int CCreatureObject::GetSlotOfEquippedLauncherOfAmmo(short wAmmoSlot, short wAbilityIdx)
	{ return (this->*CCreatureObject_GetSlotOfEquippedLauncherOfAmmo)(wAmmoSlot, wAbilityIdx); }
void CCreatureObject::UnequipAll(BOOL bKeepEffects)								{ return (this->*CCreatureObject_UnequipAll)(bKeepEffects); }
void CCreatureObject::EquipAll(BOOL bDoNotApplyEffects)							{ return (this->*CCreatureObject_EquipAll)(bDoNotApplyEffects); }
void CCreatureObject::AddKnownSpell(ResRef& name, BOOL bPrintEventMessage)		{ return (this->*CCreatureObject_AddKnownSpell)(name, bPrintEventMessage); }
CreFileKnownSpell& CCreatureObject::GetKnownSpellPriest(int nLevel, int nIndex)	{ return (this->*CCreatureObject_GetKnownSpellPriest)(nLevel, nIndex); }
CreFileKnownSpell& CCreatureObject::GetKnownSpellMage(int nLevel, int nIndex)	{ return (this->*CCreatureObject_GetKnownSpellMage)(nLevel, nIndex); }
CreFileKnownSpell& CCreatureObject::GetKnownSpellInnate(int nLevel, int nIndex)	{ return (this->*CCreatureObject_GetKnownSpellInnate)(nLevel, nIndex); }
CreFileMemSpell& CCreatureObject::GetMemSpellPriest(int nLevel, int nIndex)		{ return (this->*CCreatureObject_GetMemSpellPriest)(nLevel, nIndex); }
CreFileMemSpell& CCreatureObject::GetMemSpellMage(int nLevel, int nIndex)		{ return (this->*CCreatureObject_GetMemSpellMage)(nLevel, nIndex); }
CreFileMemSpell& CCreatureObject::GetMemSpellInnate(int nLevel, int nIndex)		{ return (this->*CCreatureObject_GetMemSpellInnate)(nLevel, nIndex); }
void CCreatureObject::ApplyClassAbilities(CDerivedStats& cdsOld, BOOL bPrintMsgForSpecAbil)
	{ return (this->*CCreatureObject_ApplyClassAbilities)(cdsOld, bPrintMsgForSpecAbil); }
void CCreatureObject::RemoveClassAbilities(CDerivedStats& cdsTarget)
	{ return (this->*CCreatureObject_RemoveClassAbilities)(cdsTarget); }
BOOL CCreatureObject::AddMemSpellPriest(int nLevel, int nIndex, int* pIndex)	{ return (this->*CCreatureObject_AddMemSpellPriest)(nLevel, nIndex, pIndex); }
BOOL CCreatureObject::AddMemSpellMage(int nLevel, int nIndex, int* pIndex)		{ return (this->*CCreatureObject_AddMemSpellMage)(nLevel, nIndex, pIndex); }
BOOL CCreatureObject::AddMemSpellInnate(int nLevel, int nIndex, int* pIndex)	{ return (this->*CCreatureObject_AddMemSpellInnate)(nLevel, nIndex, pIndex); }
BOOL CCreatureObject::AddKnownSpellPriest(ResRef& name, int nLevel)				{ return (this->*CCreatureObject_AddKnownSpellPriest)(name, nLevel); }
BOOL CCreatureObject::AddKnownSpellMage(ResRef& name, int nLevel)				{ return (this->*CCreatureObject_AddKnownSpellMage)(name, nLevel); }
BOOL CCreatureObject::AddKnownSpellInnate(ResRef& name, int nLevel)				{ return (this->*CCreatureObject_AddKnownSpellInnate)(name, nLevel); }
IECString& CCreatureObject::GetLongName()										{ return (this->*CCreatureObject_GetLongName)(); }
STRREF CCreatureObject::GetLongNameStrRef()										{ return (this->*CCreatureObject_GetLongNameStrRef)(); }
void CCreatureObject::SetSpellMemorizedState(ResSplContainer& resSpell, BOOL bState)
	{ return (this->*CCreatureObject_SetSpellMemorizedState)(resSpell, bState); }
void CCreatureObject::ValidateAttackSequence(char* pSeq)						{ return (this->*CCreatureObject_ValidateAttackSequence)(pSeq); }
char CCreatureObject::GetNumUniqueMemSpellMage(int nLevel, ResRef rTemp)		{ return (this->*CCreatureObject_GetNumUniqueMemSpellMage)(nLevel, rTemp); }
BOOL CCreatureObject::InDialogAction()											{ return (this->*CCreatureObject_InDialogAction)(); }
void CCreatureObject::SetSaveName(ResRef& rName)								{ return (this->*CCreatureObject_SetSaveName)(rName); }
unsigned int CCreatureObject::GetKitUnusableFlag()								{ return (this->*CCreatureObject_GetKitUnusableFlag)(); }
void CCreatureObject::PrintEventMessage(short wEventId, int nParam1, int nParam2, int nParam3, STRREF strrefParam4, BOOL bParam5, IECString& sParam6) {
	return (this->*CCreatureObject_PrintEventMessage)(wEventId, nParam1, nParam2, nParam3, strrefParam4, bParam5, sParam6);
}
short CCreatureObject::GetProficiencyInItem(CItem& itm)							{ return (this->*CCreatureObject_GetProficiencyInItem)(itm); }
ACTIONRESULT CCreatureObject::ActionMoveToObject(CGameObject& cgoTarget)		{ return (this->*CCreatureObject_ActionMoveToObject)(cgoTarget); }
ACTIONRESULT CCreatureObject::ActionPickPockets(CCreatureObject& creTarget)		{ return (this->*CCreatureObject_ActionPickPockets)(creTarget); }
short CCreatureObject::GetProficiency(int nWeapProfId)							{ return (this->*CCreatureObject_GetProficiency)(nWeapProfId); }
short CCreatureObject::GetSpellCastingLevel(ResSplContainer& resSpell, BOOL bUseWildMagicMod)
	{ return (this->*CCreatureObject_GetSpellCastingLevel)(resSpell, bUseWildMagicMod); }
ACTIONRESULT CCreatureObject::ActionJumpToAreaEntranceMove(IECString sArea)		{ return (this->*CCreatureObject_ActionJumpToAreaEntranceMove)(sArea); }
void CCreatureObject::UpdateFaceTalkerTimer()									{ return (this->*CCreatureObject_UpdateFaceTalkerTimer)(); }

bool CCreatureObject::NeedsAIUpdate(bool bRun, int nChitinUpdates)	{ return (this->*CCreatureObject_NeedsAIUpdate)(bRun, nChitinUpdates); }
BOOL CCreatureObject::EvaluateTrigger(Trigger& t)					{ return (this->*CCreatureObject_EvaluateTrigger)(t); }
ACTIONRESULT CCreatureObject::ExecuteAction()						{ return (this->*CCreatureObject_ExecuteAction)(); }
void CCreatureObject::SetCurrentAction(Action& a)					{ return (this->*CCreatureObject_SetCurrentAction)(a); }