#include "engmagebk.h"

#include "stdafx.h"

void (CScreenMageBook::*CScreenMageBook_SetLevel)(int) =
	SetFP(static_cast<void (CScreenMageBook::*)(int)>				(&CScreenMageBook::SetLevel),						0x7B7BDC);
BOOL (CScreenMageBook::*CScreenMageBook_UpdatePanel)(int) =
	SetFP(static_cast<BOOL (CScreenMageBook::*)(int)>				(&CScreenMageBook::UpdatePanel),					0x7B8F0E);
CPanel& (CScreenMageBook::*CScreenMageBook_GetTopPanel)() =
	SetFP(static_cast<CPanel& (CScreenMageBook::*)()>				(&CScreenMageBook::GetTopPanel),					0x7B9014);
BOOL (CScreenMageBook::*CScreenMageBook_CanContinue)() =
	SetFP(static_cast<BOOL (CScreenMageBook::*)()>					(&CScreenMageBook::CanContinue),					0x7B92E7);
void (CScreenMageBook::*CScreenMageBook_ContingencySelectOnLoad)(CPanel&) =
	SetFP(static_cast<void (CScreenMageBook::*)(CPanel&)>			(&CScreenMageBook::ContingencySelectOnLoad),		0x7BA23B);
void (CScreenMageBook::*CScreenMageBook_ContingencySelectOnUpdate)(int) =
	SetFP(static_cast<void (CScreenMageBook::*)(int)>				(&CScreenMageBook::ContingencySelectOnUpdate),		0x7BAC41);
bool (CScreenMageBook::*CScreenMageBook_AddContingencySpell)(IECString) =
	SetFP(static_cast<bool (CScreenMageBook::*)(IECString)>			(&CScreenMageBook::AddContingencySpell),			0x7BD3A3);
bool (CScreenMageBook::*CScreenMageBook_ClearContingencySpell)(char index) =
	SetFP(static_cast<bool (CScreenMageBook::*)(char)>				(&CScreenMageBook::ClearContingencySpell),			0x7BD516);
void (CScreenMageBook::*CScreenMageBook_SetSpellContingencyState)(IECString, bool) =
	SetFP(static_cast<void (CScreenMageBook::*)(IECString, bool)>	(&CScreenMageBook::SetSpellContingencyState),		0x7BDA4D);
void (CScreenMageBook::*CScreenMageBook_UpdateContingencySpellList)() =
	SetFP(static_cast<void (CScreenMageBook::*)()>					(&CScreenMageBook::UpdateContingencySpellList),		0x7BDC88);
void (CScreenMageBook::*CScreenMageBook_CreateContingencySpellList)(char, char) =
	SetFP(static_cast<void (CScreenMageBook::*)(char, char)>		(&CScreenMageBook::CreateContingencySpellList),		0x7BDCB1);
bool (CScreenMageBook::*CScreenMageBook_IsSpellAllowedInContingency)(int nLevel, IECString sSpell) =
	SetFP(static_cast<bool (CScreenMageBook::*)(int, IECString)>	(&CScreenMageBook::IsSpellAllowedInContingency),	0x7BDF3C);

void CScreenMageBook::SetLevel(int nLevel) { return (this->*CScreenMageBook_SetLevel)(nLevel); }
BOOL CScreenMageBook::UpdatePanel(int nPanelIdx) { return (this->*CScreenMageBook_UpdatePanel)(nPanelIdx); }
CPanel& CScreenMageBook::GetTopPanel() { return (this->*CScreenMageBook_GetTopPanel)(); }
BOOL CScreenMageBook::CanContinue() { return (this->*CScreenMageBook_CanContinue)(); }
void CScreenMageBook::ContingencySelectOnLoad(CPanel& panel) { return (this->*CScreenMageBook_ContingencySelectOnLoad)(panel); }
void CScreenMageBook::ContingencySelectOnUpdate(int nPanelIdx) { return (this->*CScreenMageBook_ContingencySelectOnUpdate)(nPanelIdx); }
void CScreenMageBook::SetSpellContingencyState(IECString sSpell, bool bState) { return (this->*CScreenMageBook_SetSpellContingencyState)(sSpell, bState); }
bool CScreenMageBook::AddContingencySpell(IECString sSpell) { return (this->*CScreenMageBook_AddContingencySpell)(sSpell); }
bool CScreenMageBook::ClearContingencySpell(char index) { return (this->*CScreenMageBook_ClearContingencySpell)(index); }
void CScreenMageBook::UpdateContingencySpellList() { return (this->*CScreenMageBook_UpdateContingencySpellList)(); }
void CScreenMageBook::CreateContingencySpellList(char nSpellType, char nLevel) { return (this->*CScreenMageBook_CreateContingencySpellList)(nSpellType, nLevel); }
bool CScreenMageBook::IsSpellAllowedInContingency(int nLevel, IECString sSpell) { return (this->*CScreenMageBook_IsSpellAllowedInContingency)(nLevel, sSpell); }