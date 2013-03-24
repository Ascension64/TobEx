#include "engchargen.h"

#include "stdafx.h"

void (CScreenCharGen::*CScreenCharGen_KitPanelOnLoad)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CScreenCharGen::*)(CPanel&, CCreatureObject&)>	(&CScreenCharGen::KitPanelOnLoad),			0x71A081);
void (CScreenCharGen::*CScreenCharGen_MageBookPanelOnLoad)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CScreenCharGen::*)(CPanel&, CCreatureObject&)>	(&CScreenCharGen::MageBookPanelOnLoad),		0x71B220);
BOOL (CScreenCharGen::*CScreenCharGen_RollAbilityScore)(CCreatureObject&, IECString&, IECString&, IECString&, char*, char&, char&) =
	SetFP(static_cast<BOOL (CScreenCharGen::*)(CCreatureObject&, IECString&, IECString&, IECString&, char*, char&, char&)>
																			(&CScreenCharGen::RollAbilityScore),		0x71C518);
void (CScreenCharGen::*CScreenCharGen_UpdatePanel)(int, CCreatureObject&) =
	SetFP(static_cast<void (CScreenCharGen::*)(int, CCreatureObject&)>		(&CScreenCharGen::UpdatePanel),				0x71DEA7);
void (CScreenCharGen::*CScreenCharGen_KitPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CScreenCharGen::*)(CPanel&, CCreatureObject&)>	(&CScreenCharGen::KitPanelOnUpdate),		0x71E3A5);
void (CScreenCharGen::*CScreenCharGen_MageBookPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CScreenCharGen::*)(CPanel&, CCreatureObject&)>	(&CScreenCharGen::MageBookPanelOnUpdate),	0x720425);
void (CScreenCharGen::*CScreenCharGen_ClassPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CScreenCharGen::*)(CPanel&, CCreatureObject&)>	(&CScreenCharGen::ClassPanelOnUpdate),		0x720B4B);
void (CScreenCharGen::*CScreenCharGen_MulticlassPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CScreenCharGen::*)(CPanel&, CCreatureObject&)>	(&CScreenCharGen::MulticlassPanelOnUpdate),	0x721518);
void (CScreenCharGen::*CScreenCharGen_MageSchoolPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CScreenCharGen::*)(CPanel&, CCreatureObject&)>	(&CScreenCharGen::MageSchoolPanelOnUpdate),	0x721BA6);
int (CScreenCharGen::*CScreenCharGen_RollAbilityDice)(int, int, BOOL) =
	SetFP(static_cast<int (CScreenCharGen::*)(int, int, BOOL)>				(&CScreenCharGen::RollAbilityDice),			0x72252A);
void (CScreenCharGen::*CScreenCharGen_InitSoundset)(CCreatureObject&) =
	SetFP(static_cast<void (CScreenCharGen::*)(CCreatureObject&)>			(&CScreenCharGen::InitSoundset),			0x724E37);
BOOL (CScreenCharGen::*CScreenCharGen_CanContinue)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CScreenCharGen::*)(CCreatureObject&)>			(&CScreenCharGen::CanContinue),				0x72B11D);

void CScreenCharGen::KitPanelOnLoad(CPanel& panel, CCreatureObject& cre)			{ return (this->*CScreenCharGen_KitPanelOnLoad)(panel, cre); }
void CScreenCharGen::MageBookPanelOnLoad(CPanel& panel, CCreatureObject& cre)		{ return (this->*CScreenCharGen_MageBookPanelOnLoad)(panel, cre); }
BOOL CScreenCharGen::RollAbilityScore(CCreatureObject& cre, IECString& sColNameMin, IECString& sColNameMax, IECString& sColNameMod, char* ptr, char& cMinVal, char& cMaxVal)
	{ return (this->*CScreenCharGen_RollAbilityScore)(cre, sColNameMin, sColNameMax, sColNameMod, ptr, cMinVal, cMaxVal); }
void CScreenCharGen::UpdatePanel(int nPanelIdx, CCreatureObject& cre)				{ return (this->*CScreenCharGen_UpdatePanel)(nPanelIdx, cre); }
void CScreenCharGen::KitPanelOnUpdate(CPanel& panel, CCreatureObject& cre)			{ return (this->*CScreenCharGen_KitPanelOnUpdate)(panel, cre); }
void CScreenCharGen::MageBookPanelOnUpdate(CPanel& panel, CCreatureObject& cre)		{ return (this->*CScreenCharGen_MageBookPanelOnUpdate)(panel, cre); }
void CScreenCharGen::ClassPanelOnUpdate(CPanel& panel, CCreatureObject& cre)		{ return (this->*CScreenCharGen_ClassPanelOnUpdate)(panel, cre); }
void CScreenCharGen::MulticlassPanelOnUpdate(CPanel& panel, CCreatureObject& cre)	{ return (this->*CScreenCharGen_MulticlassPanelOnUpdate)(panel, cre); }
void CScreenCharGen::MageSchoolPanelOnUpdate(CPanel& panel, CCreatureObject& cre)	{ return (this->*CScreenCharGen_MageSchoolPanelOnUpdate)(panel, cre); }
int CScreenCharGen::RollAbilityDice(int nSize, int nNumDice, BOOL bRemoveSmallestRoll)
	{ return (this->*CScreenCharGen_RollAbilityDice)(nSize, nNumDice, bRemoveSmallestRoll); }
void CScreenCharGen::InitSoundset(CCreatureObject& cre)								{ return (this->*CScreenCharGen_InitSoundset)(cre); }
BOOL CScreenCharGen::CanContinue(CCreatureObject& cre)								{ return (this->*CScreenCharGen_CanContinue)(cre); }