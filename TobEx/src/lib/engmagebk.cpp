#include "engmagebk.h"

#include "stdafx.h"

void (CMageBook::*CMageBook_SetLevel)(int) =
	SetFP(static_cast<void (CMageBook::*)(int)>				(&CMageBook::SetLevel),						0x7B7BDC);
BOOL (CMageBook::*CMageBook_UpdatePanel)(int) =
	SetFP(static_cast<BOOL (CMageBook::*)(int)>				(&CMageBook::UpdatePanel),					0x7B8F0E);
CPanel& (CMageBook::*CMageBook_GetTopPanel)() =
	SetFP(static_cast<CPanel& (CMageBook::*)()>				(&CMageBook::GetTopPanel),					0x7B9014);
BOOL (CMageBook::*CMageBook_CanContinue)() =
	SetFP(static_cast<BOOL (CMageBook::*)()>				(&CMageBook::CanContinue),					0x7B92E7);
void (CMageBook::*CMageBook_ContingencySelectOnLoad)(CPanel&) =
	SetFP(static_cast<void (CMageBook::*)(CPanel&)>			(&CMageBook::ContingencySelectOnLoad),		0x7BA23B);
void (CMageBook::*CMageBook_ContingencySelectOnUpdate)(int) =
	SetFP(static_cast<void (CMageBook::*)(int)>				(&CMageBook::ContingencySelectOnUpdate),	0x7BAC41);
bool (CMageBook::*CMageBook_AddContingencySpell)(IECString) =
	SetFP(static_cast<bool (CMageBook::*)(IECString)>		(&CMageBook::AddContingencySpell),			0x7BD3A3);
bool (CMageBook::*CMageBook_ClearContingencySpell)(char index) =
	SetFP(static_cast<bool (CMageBook::*)(char)>			(&CMageBook::ClearContingencySpell),		0x7BD516);
void (CMageBook::*CMageBook_SetSpellContingencyState)(IECString, bool) =
	SetFP(static_cast<void (CMageBook::*)(IECString, bool)>	(&CMageBook::SetSpellContingencyState),		0x7BDA4D);
void (CMageBook::*CMageBook_UpdateContingencySpellList)() =
	SetFP(static_cast<void (CMageBook::*)()>				(&CMageBook::UpdateContingencySpellList),	0x7BDC88);
void (CMageBook::*CMageBook_CreateContingencySpellList)(char, char) =
	SetFP(static_cast<void (CMageBook::*)(char, char)>		(&CMageBook::CreateContingencySpellList),	0x7BDCB1);
bool (CMageBook::*CMageBook_IsSpellAllowedInContingency)(int nLevel, IECString sSpell) =
	SetFP(static_cast<bool (CMageBook::*)(int, IECString)>	(&CMageBook::IsSpellAllowedInContingency),	0x7BDF3C);

void CMageBook::SetLevel(int nLevel) { return (this->*CMageBook_SetLevel)(nLevel); }
BOOL CMageBook::UpdatePanel(int nPanelIdx) { return (this->*CMageBook_UpdatePanel)(nPanelIdx); }
CPanel& CMageBook::GetTopPanel() { return (this->*CMageBook_GetTopPanel)(); }
BOOL CMageBook::CanContinue() { return (this->*CMageBook_CanContinue)(); }
void CMageBook::ContingencySelectOnLoad(CPanel& panel) { return (this->*CMageBook_ContingencySelectOnLoad)(panel); }
void CMageBook::ContingencySelectOnUpdate(int nPanelIdx) { return (this->*CMageBook_ContingencySelectOnUpdate)(nPanelIdx); }
void CMageBook::SetSpellContingencyState(IECString sSpell, bool bState) { return (this->*CMageBook_SetSpellContingencyState)(sSpell, bState); }
bool CMageBook::AddContingencySpell(IECString sSpell) { return (this->*CMageBook_AddContingencySpell)(sSpell); }
bool CMageBook::ClearContingencySpell(char index) { return (this->*CMageBook_ClearContingencySpell)(index); }
void CMageBook::UpdateContingencySpellList() { return (this->*CMageBook_UpdateContingencySpellList)(); }
void CMageBook::CreateContingencySpellList(char nSpellType, char nLevel) { return (this->*CMageBook_CreateContingencySpellList)(nSpellType, nLevel); }
bool CMageBook::IsSpellAllowedInContingency(int nLevel, IECString sSpell) { return (this->*CMageBook_IsSpellAllowedInContingency)(nLevel, sSpell); }