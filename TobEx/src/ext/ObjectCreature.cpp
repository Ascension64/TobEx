#include "ObjectCreature.h"

#include "UserMageBook.h"
#include "UserPriestBook.h"

CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellPriest)(DWORD, DWORD) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(DWORD, DWORD)>	(&CCreatureObject::GetKnownSpellPriest),	0x8CB91F);
CreFileKnownSpell& (CCreatureObject::*Tramp_CCreatureObject_GetKnownSpellMage)(DWORD, DWORD) =
	SetFP(static_cast<CreFileKnownSpell& (CCreatureObject::*)(DWORD, DWORD)>	(&CCreatureObject::GetKnownSpellMage),		0x8CB949);
BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellPriest)(DWORD, DWORD, DWORD*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(DWORD, DWORD, DWORD*)>			(&CCreatureObject::AddMemSpellPriest),		0x8CBB64);
BOOL (CCreatureObject::*Tramp_CCreatureObject_AddMemSpellMage)(DWORD, DWORD, DWORD*) =
	SetFP(static_cast<BOOL (CCreatureObject::*)(DWORD, DWORD, DWORD*)>			(&CCreatureObject::AddMemSpellMage),		0x8CBBEA);

CreFileKnownSpell& DETOUR_CCreatureObject::DETOUR_GetKnownSpellPriest(DWORD nLevel, DWORD nIndex) {
	DWORD Eip;
	GetEip(Eip);

	if (Eip == 0x78744E) { //from CPriestBook::Update()
		nIndex += CUIButtonPriestBook_KnownSpellOffset;
	}

	return (this->*Tramp_CCreatureObject_GetKnownSpellPriest)(nLevel, nIndex);
}

CreFileKnownSpell& DETOUR_CCreatureObject::DETOUR_GetKnownSpellMage(DWORD nLevel, DWORD nIndex) {
	DWORD Eip;
	GetEip(Eip);

	if (Eip == 0x7B8952) { //from CMageBook::Update()
		nIndex += CUIButtonMageBook_KnownSpellOffset;
	}

	return (this->*Tramp_CCreatureObject_GetKnownSpellMage)(nLevel, nIndex);
}

BOOL DETOUR_CCreatureObject::DETOUR_AddMemSpellPriest(DWORD nLevel , DWORD nIndex, DWORD* pIndex) {
	DWORD Eip;
	GetEip(Eip);

	if (Eip == 0x7892C9) { //from CUIButtonPriestBookKnownSpell::OnLClicked()
		nIndex += CUIButtonPriestBook_KnownSpellOffset;
	}

	return (this->*Tramp_CCreatureObject_AddMemSpellPriest)(nLevel, nIndex, pIndex);
}

BOOL DETOUR_CCreatureObject::DETOUR_AddMemSpellMage(DWORD nLevel , DWORD nIndex, DWORD* pIndex) {
	DWORD Eip;
	GetEip(Eip);

	if (Eip == 0x7BEEC7) { //from CUIButtonMageBookKnownSpell::OnLClicked()
		nIndex += CUIButtonMageBook_KnownSpellOffset;
	}

	return (this->*Tramp_CCreatureObject_AddMemSpellMage)(nLevel, nIndex, pIndex);
}

