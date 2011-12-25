#include "objcre.h"

CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellPriest)(DWORD, DWORD) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(DWORD, DWORD)>	(&CCreatureObject::GetKnownSpellPriest),	0x8CB91F);
CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellMage)(DWORD, DWORD) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(DWORD, DWORD)>	(&CCreatureObject::GetKnownSpellMage),		0x8CB949);
CreFileKnownSpell& (CCreatureObject::*CCreatureObject_GetKnownSpellInnate)(DWORD, DWORD) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(DWORD, DWORD)>	(&CCreatureObject::GetKnownSpellInnate),	0x8CB973);
CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellPriest)(DWORD, DWORD) =
	SetFP(static_cast<CreFileMemSpell& (CCreatureObject::*)(DWORD, DWORD)>		(&CCreatureObject::GetMemSpellPriest),		0x8CB9D9);
CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellMage)(DWORD, DWORD) =
	SetFP(static_cast<CreFileMemSpell& (CCreatureObject::*)(DWORD, DWORD)>		(&CCreatureObject::GetMemSpellMage),		0x8CBA03);
CreFileMemSpell& (CCreatureObject::*CCreatureObject_GetMemSpellInnate)(DWORD, DWORD) =
	SetFP(static_cast<CreFileMemSpell& (CCreatureObject::*)(DWORD, DWORD)>		(&CCreatureObject::GetMemSpellInnate),		0x8CBA2D);
BOOL (CCreatureObject::*CCreatureObject_AddMemSpellPriest)(DWORD, DWORD, DWORD*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(DWORD, DWORD, DWORD*)>			(&CCreatureObject::AddMemSpellPriest),		0x8CBB64);
BOOL (CCreatureObject::*CCreatureObject_AddMemSpellMage)(DWORD, DWORD, DWORD*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(DWORD, DWORD, DWORD*)>			(&CCreatureObject::AddMemSpellMage),		0x8CBBEA);
BOOL (CCreatureObject::*CCreatureObject_AddMemSpellInnate)(DWORD, DWORD, DWORD*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(DWORD, DWORD, DWORD*)>			(&CCreatureObject::AddMemSpellInnate),		0x8CBC70);

CreFileKnownSpell& CCreatureObject::GetKnownSpellPriest(DWORD nLevel, DWORD nIndex)	{ return (this->*CCreatureObject_GetKnownSpellPriest)(nLevel, nIndex); }
CreFileKnownSpell& CCreatureObject::GetKnownSpellMage(DWORD nLevel, DWORD nIndex)	{ return (this->*CCreatureObject_GetKnownSpellMage)(nLevel, nIndex); }
CreFileKnownSpell& CCreatureObject::GetKnownSpellInnate(DWORD nLevel, DWORD nIndex)	{ return (this->*CCreatureObject_GetKnownSpellInnate)(nLevel, nIndex); }
CreFileMemSpell& CCreatureObject::GetMemSpellPriest(DWORD nLevel, DWORD nIndex)		{ return (this->*CCreatureObject_GetMemSpellPriest)(nLevel, nIndex); }
CreFileMemSpell& CCreatureObject::GetMemSpellMage(DWORD nLevel, DWORD nIndex)		{ return (this->*CCreatureObject_GetMemSpellMage)(nLevel, nIndex); }
CreFileMemSpell& CCreatureObject::GetMemSpellInnate(DWORD nLevel, DWORD nIndex)		{ return (this->*CCreatureObject_GetMemSpellInnate)(nLevel, nIndex); }
BOOL CCreatureObject::AddMemSpellPriest(DWORD nLevel, DWORD nIndex, DWORD* pIndex)  { return (this->*CCreatureObject_AddMemSpellPriest)(nLevel, nIndex, pIndex); }
BOOL CCreatureObject::AddMemSpellMage(DWORD nLevel, DWORD nIndex, DWORD* pIndex)	{ return (this->*CCreatureObject_AddMemSpellMage)(nLevel, nIndex, pIndex); }
BOOL CCreatureObject::AddMemSpellInnate(DWORD nLevel, DWORD nIndex, DWORD* pIndex)  { return (this->*CCreatureObject_AddMemSpellInnate)(nLevel, nIndex, pIndex); }
