#ifndef INFGAMECORE_H
#define INFGAMECORE_H

#include "stdafx.h"
#include "infgame.h"
#include "cstringex.h"
#include "objcre.h"
#include "resref.h"

//CRuleTables
DeclareTrampMemberFunc(CRuleTables&, CRuleTables, Construct, (), Construct);
DeclareTrampMemberFunc(void, CRuleTables, Deconstruct, (), Deconstruct);
DeclareTrampMemberFunc(int, CRuleTables, CalculateNewHPSubclass, (
	char nClass,
	char nSubclass,
	CDerivedStats& cdsOld,
	CDerivedStats& cdsNew,
	int nMinRoll,
	int nDivisor
	), CalculateNewHPSubclass);
DeclareTrampMemberFunc(ResRef, CRuleTables, GetMageSpellRef, (int nSpellLevel, int nIndex), GetMageSpellRef);
DeclareTrampMemberFunc(int, CRuleTables, GetWeapProfMax, (
	char nClassId,
	char nClassPrimary,
	char nClassSecondary,
	BOOL bTwoClasses,
	int nWeapProfId,
	unsigned int dwKit
	), GetWeapProfMax);
DeclareTrampMemberFunc(BOOL, CRuleTables, IsMageSchoolAllowed, (unsigned int dwKit, unsigned char nRace), IsMageSchoolAllowed);
DeclareTrampMemberFunc(ResRef, CRuleTables, GetMageSpellRefAutoPick, (char nSpellLevel, char nIndex), GetMageSpellRefAutoPick);

class DETOUR_CRuleTables : public CRuleTables {
public:
	CRuleTables& DETOUR_Construct();
	void DETOUR_Deconstruct();
	int DETOUR_CalculateNewHPSubclass(char nClass, char nSubclass, CDerivedStats& cdsOld, CDerivedStats& cdsNew, int nMinRoll, int nDivisor);
	ResRef DETOUR_GetMageSpellRef(int nSpellLevel, int nIndex);
	int DETOUR_GetWeapProfMax(char nClassId, char nClassPrimary, char nClassSecondary, BOOL bTwoClasses, int nWeapProfId, unsigned int dwKit);
	BOOL DETOUR_IsMageSchoolAllowed(unsigned int dwKit, unsigned char nRace);
	ResRef DETOUR_GetMageSpellRefAutoPick(char nSpellLevel, char nIndex);
};

//CMoveAreasList
DeclareTrampMemberFunc(void, CMoveAreasList, MoveAllTo, (CArea& area), MoveAllTo);

class DETOUR_CMoveAreasList : public CMoveAreasList {
public:
	void DETOUR_MoveAllTo(CArea& area);

	struct MoveAreasComparator { //size 14h
		IECString sCreLongName; //0h
		CPoint ptDest; //4h
		ResRef rArea; //ch 
	};
};

//CInfGame
DeclareTrampMemberFunc(void, CInfGame, InitGame, (int nUnused, int nUnused2), InitGame);
DeclareTrampMemberFunc(int, CInfGame, GetNumOfItemInBag, (ResRef& rBag, ResRef& rItem, BOOL bIdentifiedOnly), GetNumOfItemInBag);
DeclareTrampMemberFunc(void, CInfGame, SetLoseCutscene, (), SetLoseCutscene);

class DETOUR_CInfGame : public CInfGame {
public:
	void DETOUR_InitGame(int nUnused, int nUnused2);
	int DETOUR_GetNumOfItemInBag(ResRef& rBag, ResRef& rItem, BOOL bIdentifiedOnly);
	void DETOUR_SetLoseCutscene();
};

BOOL __stdcall CRuleTables_HasKnownMageSpells(CCreatureObject& cre);
ResRef CRuleTables_TryHideSpell(ResRef& rSpell);
IECString& __stdcall CRuleTables_GetMaxProfs(CCreatureObject& cre, IECString& sRowName);
STRREF __stdcall CInfGame_GetRaceText(unsigned int nRace);
BOOL __stdcall CRuleTables_DoesEquipSlotPassCreExclude(CCreatureObject& cre, short wSlot, CItem& itmGrabbed, STRREF* pStrRef);
BOOL __stdcall CRuleTables_DoesInvSlotPassCreExclude(CCreatureObject& cre, short wSlot, CItem& itmGrabbed, STRREF* pStrRef);
BOOL __stdcall CRuleTables_IsLowEncumbrance(unsigned int nWeight, unsigned int nWeightAllowance);
BOOL __stdcall CRuleTables_IsHighEncumbrance(unsigned int nWeight, unsigned int nWeightAllowance);
int __stdcall CRuleTables_GetWeightAllowance(CDerivedStats& cds);
void __stdcall CInfGame_SetDifficultyMultiplier(CInfGame* pGame);
void __stdcall CInfGame_SetDifficultyMultiplierFeedback(CInfGame* pGame, STRREF* pFeedback);

#endif //INFGAMECORE_H