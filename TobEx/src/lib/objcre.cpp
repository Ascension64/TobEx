#include "objcre.h"

//CCreatureObject
CDerivedStats& (CCreatureObject::*CCreatureObject_GetDerivedStats)() =
	SetFP(static_cast<CDerivedStats& (CCreatureObject::*)()>				(&CCreatureObject::GetDerivedStats),		0x495630);
void (*CCreatureObject_RemoveItem)(CCreatureObject&, int) =
	reinterpret_cast<void (*)(CCreatureObject&, int)>						(0x52033C);
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
unsigned int (CCreatureObject::*CCreatureObject_GetKitUnusableFlag)() =
	SetFP(static_cast<unsigned int (CCreatureObject::*)()>					(&CCreatureObject::GetKitUnusableFlag),		0x8E066B);
void (CCreatureObject::*CCreatureObject_PrintEventMessage)(short, int, int, int, STRREF, BOOL, IECString&) =
	SetFP(static_cast<void (CCreatureObject::*)(short, int, int, int, STRREF, BOOL, IECString&)>
																			(&CCreatureObject::PrintEventMessage),		0x8FAE5A);

CDerivedStats& CCreatureObject::GetDerivedStats()								{ return (this->*CCreatureObject_GetDerivedStats)(); }
void CCreatureObject::RemoveItem(CCreatureObject& cre, int nSlot)				{ return (*CCreatureObject_RemoveItem)(cre, nSlot); }
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
unsigned int CCreatureObject::GetKitUnusableFlag()								{ return (this->*CCreatureObject_GetKitUnusableFlag)(); }
void CCreatureObject::PrintEventMessage(short wEventId, int nParam1, int nParam2, int nParam3, STRREF strrefParam4, BOOL bParam5, IECString& sParam6) {
	return (this->*CCreatureObject_PrintEventMessage)(wEventId, nParam1, nParam2, nParam3, strrefParam4, bParam5, sParam6);
}