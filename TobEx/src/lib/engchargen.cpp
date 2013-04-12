#include "engchargen.h"

#include "stdafx.h"

DefineLibMemberFunc(void, CScreenCharGen, KitPanelOnLoad, (CPanel& panel, CCreatureObject& cre), KitPanelOnLoad, KitPanelOnLoad, (panel, cre), 0x71A081);
DefineLibMemberFunc(void, CScreenCharGen, MageBookPanelOnLoad, (CPanel& panel, CCreatureObject& cre), MageBookPanelOnLoad, MageBookPanelOnLoad, (panel, cre), 0x71A081);
DefineLibMemberFunc(BOOL, CScreenCharGen, RollAbilityScore, (
	CCreatureObject& cre,
	IECString& sColNameMin,
	IECString& sColNameMax,
	IECString& sColNameMod,
	char* ptr,
	char& cMinVal,
	char& cMaxVal
	), RollAbilityScore, RollAbilityScore, (cre, sColNameMin, sColNameMax, sColNameMod, ptr, cMinVal, cMaxVal), 0x71C518);
DefineLibMemberFunc(void, CScreenCharGen, UpdatePanel, (int nPanelIdx, CCreatureObject& cre), UpdatePanel, UpdatePanel, (nPanelIdx, cre), 0x71DEA7);
DefineLibMemberFunc(void, CScreenCharGen, KitPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), KitPanelOnUpdate, KitPanelOnUpdate, (panel, cre), 0x71E3A5);
DefineLibMemberFunc(void, CScreenCharGen, MageBookPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), MageBookPanelOnUpdate, MageBookPanelOnUpdate, (panel, cre), 0x720425);
DefineLibMemberFunc(void, CScreenCharGen, ClassPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), ClassPanelOnUpdate, ClassPanelOnUpdate, (panel, cre), 0x720B4B);
DefineLibMemberFunc(void, CScreenCharGen, MulticlassPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), MulticlassPanelOnUpdate, MulticlassPanelOnUpdate, (panel, cre), 0x721518);
DefineLibMemberFunc(void, CScreenCharGen, MageSchoolPanelOnUpdate, (CPanel& panel, CCreatureObject& cre), MageSchoolPanelOnUpdate, MageSchoolPanelOnUpdate, (panel, cre), 0x721BA6);
DefineLibMemberFunc(int, CScreenCharGen, RollAbilityDice, (int nSize, int nNumDice, BOOL bRemoveSmallestRoll), RollAbilityDice, RollAbilityDice, (nSize, nNumDice, bRemoveSmallestRoll), 0x72252A);
DefineLibMemberFunc(void, CScreenCharGen, InitSoundset, (CCreatureObject& cre), InitSoundset, InitSoundset, (cre), 0x724E37);
DefineLibMemberFunc(BOOL, CScreenCharGen, CanContinue, (CCreatureObject& cre), CanContinue, CanContinue, (cre), 0x72B11D);
