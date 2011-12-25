#include "objcre.h"

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
void (CCreatureObject::*CCreatureObject_CreateGore)(int, short, short) =
	SetFP(static_cast<void (CCreatureObject::*)(int, short, short)>			(&CCreatureObject::CreateGore),				0x8862FE);
void (CCreatureObject::*CCreatureObject_UpdateHPStatusTooltip)(CUIControl&) =
	SetFP(static_cast<void (CCreatureObject::*)(CUIControl&)>				(&CCreatureObject::UpdateHPStatusTooltip),	0x8AC3C5);
short (CCreatureObject::*CCreatureObject_GetOrientationTo)(POINT&) =
	SetFP(static_cast<short (CCreatureObject::*)(POINT&)>					(&CCreatureObject::GetOrientationTo),		0x8ACFC2);
void (CCreatureObject::*CCreatureObject_SetAnimationSequence)(short) =
	SetFP(static_cast<void (CCreatureObject::*)(short)>						(&CCreatureObject::SetAnimationSequence),	0x8AD630);
void (CCreatureObject::*CCreatureObject_StartSpriteEffect)(char, char, int) =
	SetFP(static_cast<void (CCreatureObject::*)(char, char, int)>			(&CCreatureObject::StartSpriteEffect),		0x8B10DE);
CItem& (CCreatureObject::*CCreatureObject_GetFirstEquippedLauncherOfAbility)(ItmFileAbility& ability, int* pnSlot) =
	SetFP(static_cast<CItem& (CCreatureObject::*)(ItmFileAbility&, int*)>	(&CCreatureObject::GetFirstEquippedLauncherOfAbility),
																														0x8C5981);
void (CCreatureObject::*CCreatureObject_UnequipAll)(BOOL) =
	SetFP(static_cast<void (CCreatureObject::*)(BOOL)>						(&CCreatureObject::UnequipAll),				0x8CA628);
void (CCreatureObject::*CCreatureObject_EquipAll)(BOOL) =
	SetFP(static_cast<void (CCreatureObject::*)(BOOL)>						(&CCreatureObject::EquipAll),				0x8CA88D);
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
IECString& (CCreatureObject::*CCreatureObject_GetLongName)() =
	SetFP(static_cast<IECString& (CCreatureObject::*)()>					(&CCreatureObject::GetLongName),			0x8D49D9);
STRREF (CCreatureObject::*CCreatureObject_GetLongNameStrRef)() =
	SetFP(static_cast<STRREF (CCreatureObject::*)()>						(&CCreatureObject::GetLongNameStrRef),		0x8D4AAC);
void (CCreatureObject::*CCreatureObject_ValidateAttackSequence)(char*) =
	SetFP(static_cast<void (CCreatureObject::*)(char*)>						(&CCreatureObject::ValidateAttackSequence),	0x8D6D78);
unsigned int (CCreatureObject::*CCreatureObject_GetKitUnusableFlag)() =
	SetFP(static_cast<unsigned int (CCreatureObject::*)()>					(&CCreatureObject::GetKitUnusableFlag),		0x8E066B);
void (CCreatureObject::*CCreatureObject_PrintEventMessage)(short, int, int, int, STRREF, BOOL, IECString&) =
	SetFP(static_cast<void (CCreatureObject::*)(short, int, int, int, STRREF, BOOL, IECString&)>
																			(&CCreatureObject::PrintEventMessage),		0x8FAE5A);

CGameObject& CCreatureObject::SetTarget(Object& o, char type)					{ return (this->*CCreatureObject_SetTarget)(o, type); }
void CCreatureObject::GetSpellIdsName(int nSpellIdx, IECString* ptr)			{ return (this->*CCreatureObject_GetSpellIdsName)(nSpellIdx, ptr); }
CDerivedStats& CCreatureObject::GetDerivedStats()								{ return (this->*CCreatureObject_GetDerivedStats)(); }
ACTIONRESULT CCreatureObject::CastSpell(ResRef& rResource, CGameObject& cgoTarget, BOOL bPrintStrref, STRREF strref, void* pMod, BOOL bPrintEventMsg, BOOL bDoNotApplySplAbil)
	{ return (this->*CCreatureObject_CastSpell)(rResource, cgoTarget, bPrintStrref, strref, pMod, bPrintEventMsg, bDoNotApplySplAbil); }
void CCreatureObject::RemoveItem(CCreatureObject& cre, int nSlot)				{ return (*CCreatureObject_RemoveItem)(cre, nSlot); }
CEffectList& CCreatureObject::GetEquippedEffectsList()							{ return (this->*CCreatureObject_GetEquippedEffectsList)(); }
CEffectList& CCreatureObject::GetMainEffectsList()								{ return (this->*CCreatureObject_GetMainEffectsList)(); }
void CCreatureObject::CreateGore(int dwUnused, short wOrient, short wType)		{ return (this->*CCreatureObject_CreateGore)(dwUnused, wOrient, wType); }
void CCreatureObject::UpdateHPStatusTooltip(CUIControl& control)				{ return (this->*CCreatureObject_UpdateHPStatusTooltip)(control); }
short CCreatureObject::GetOrientationTo(POINT& pt)								{ return (this->*CCreatureObject_GetOrientationTo)(pt); }
void CCreatureObject::SetAnimationSequence(short wSeq)							{ return (this->*CCreatureObject_SetAnimationSequence)(wSeq); }
void CCreatureObject::StartSpriteEffect(char nEffectType, char nParticleType, int nParticles)
	{ return (this->*CCreatureObject_StartSpriteEffect)(nEffectType, nParticleType, nParticles); }
CItem& CCreatureObject::GetFirstEquippedLauncherOfAbility(ItmFileAbility& ability, int* pnSlot)
	{ return (this->*CCreatureObject_GetFirstEquippedLauncherOfAbility)(ability, pnSlot); }
void CCreatureObject::UnequipAll(BOOL bKeepEffects)								{ return (this->*CCreatureObject_UnequipAll)(bKeepEffects); }
void CCreatureObject::EquipAll(BOOL bDoNotApplyEffects)							{ return (this->*CCreatureObject_EquipAll)(bDoNotApplyEffects); }
CreFileKnownSpell& CCreatureObject::GetKnownSpellPriest(int nLevel, int nIndex)	{ return (this->*CCreatureObject_GetKnownSpellPriest)(nLevel, nIndex); }
CreFileKnownSpell& CCreatureObject::GetKnownSpellMage(int nLevel, int nIndex)	{ return (this->*CCreatureObject_GetKnownSpellMage)(nLevel, nIndex); }
CreFileKnownSpell& CCreatureObject::GetKnownSpellInnate(int nLevel, int nIndex)	{ return (this->*CCreatureObject_GetKnownSpellInnate)(nLevel, nIndex); }
CreFileMemSpell& CCreatureObject::GetMemSpellPriest(int nLevel, int nIndex)		{ return (this->*CCreatureObject_GetMemSpellPriest)(nLevel, nIndex); }
CreFileMemSpell& CCreatureObject::GetMemSpellMage(int nLevel, int nIndex)		{ return (this->*CCreatureObject_GetMemSpellMage)(nLevel, nIndex); }
CreFileMemSpell& CCreatureObject::GetMemSpellInnate(int nLevel, int nIndex)		{ return (this->*CCreatureObject_GetMemSpellInnate)(nLevel, nIndex); }
BOOL CCreatureObject::AddMemSpellPriest(int nLevel, int nIndex, int* pIndex)	{ return (this->*CCreatureObject_AddMemSpellPriest)(nLevel, nIndex, pIndex); }
BOOL CCreatureObject::AddMemSpellMage(int nLevel, int nIndex, int* pIndex)		{ return (this->*CCreatureObject_AddMemSpellMage)(nLevel, nIndex, pIndex); }
BOOL CCreatureObject::AddMemSpellInnate(int nLevel, int nIndex, int* pIndex)	{ return (this->*CCreatureObject_AddMemSpellInnate)(nLevel, nIndex, pIndex); }
IECString& CCreatureObject::GetLongName()										{ return (this->*CCreatureObject_GetLongName)(); }
STRREF CCreatureObject::GetLongNameStrRef()										{ return (this->*CCreatureObject_GetLongNameStrRef)(); }
void CCreatureObject::ValidateAttackSequence(char* pSeq)						{ return (this->*CCreatureObject_ValidateAttackSequence)(pSeq); }
unsigned int CCreatureObject::GetKitUnusableFlag()								{ return (this->*CCreatureObject_GetKitUnusableFlag)(); }
void CCreatureObject::PrintEventMessage(short wEventId, int nParam1, int nParam2, int nParam3, STRREF strrefParam4, BOOL bParam5, IECString& sParam6) {
	return (this->*CCreatureObject_PrintEventMessage)(wEventId, nParam1, nParam2, nParam3, strrefParam4, bParam5, sParam6);
}