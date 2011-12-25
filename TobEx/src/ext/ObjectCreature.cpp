#include "ObjectCreature.h"

#include "UserMageBook.h"
#include "UserPriestBook.h"

CreFileKnownSpell& DETOUR_CCreatureObject::DETOUR_GetKnownSpellPriest(DWORD nLevel, DWORD nIndex) {
	DWORD Eip;
	GetEip(Eip);

	if (Eip == 0x78744E) { //from CPriestBook::Update()
		nIndex += CUIButtonPriestBook_KnownSpellOffset;
	}

	return GetKnownSpellPriest(nLevel, nIndex);
}

CreFileKnownSpell& DETOUR_CCreatureObject::DETOUR_GetKnownSpellMage(DWORD nLevel, DWORD nIndex) {
	DWORD Eip;
	GetEip(Eip);

	if (Eip == 0x7B8952) { //from CMageBook::Update()
		nIndex += CUIButtonMageBook_KnownSpellOffset;
	}

	return GetKnownSpellMage(nLevel, nIndex);
}

BOOL DETOUR_CCreatureObject::DETOUR_AddMemSpellPriest(DWORD nLevel , DWORD nIndex, DWORD* pIndex) {
	DWORD Eip;
	GetEip(Eip);

	if (Eip == 0x7892C9) { //from CUIButtonPriestBookKnownSpell::OnLClicked()
		nIndex += CUIButtonPriestBook_KnownSpellOffset;
	}

	return AddMemSpellPriest(nLevel, nIndex, pIndex);
}

BOOL DETOUR_CCreatureObject::DETOUR_AddMemSpellMage(DWORD nLevel , DWORD nIndex, DWORD* pIndex) {
	DWORD Eip;
	GetEip(Eip);

	if (Eip == 0x7BEEC7) { //from CUIButtonMageBookKnownSpell::OnLClicked()
		nIndex += CUIButtonMageBook_KnownSpellOffset;
	}

	return AddMemSpellMage(nLevel, nIndex, pIndex);
}

