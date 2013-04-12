#include "engmagebk.h"

#include "stdafx.h"

DefineLibMemberFunc(void, CScreenMageBook, SetLevel, (int nLevel), SetLevel, SetLevel, (nLevel), 0x7B7BDC);
DefineLibMemberFunc(BOOL, CScreenMageBook, UpdatePanel, (int nPanelIdx), UpdatePanel, UpdatePanel, (nPanelIdx), 0x7B8F0E);
DefineLibMemberFunc(CPanel&, CScreenMageBook, GetTopPanel, (), GetTopPanel, GetTopPanel, (), 0x7B9014);
DefineLibMemberFunc(BOOL, CScreenMageBook, CanContinue, (), CanContinue, CanContinue, (), 0x7B92E7);
DefineLibMemberFunc(void, CScreenMageBook, ContingencySelectOnLoad, (CPanel& panel), ContingencySelectOnLoad, ContingencySelectOnLoad, (panel), 0x7BA23B);
DefineLibMemberFunc(void, CScreenMageBook, ContingencySelectOnUpdate, (int nPanelIdx), ContingencySelectOnUpdate, ContingencySelectOnUpdate, (nPanelIdx), 0x7BAC41);
DefineLibMemberFunc(bool, CScreenMageBook, AddContingencySpell, (IECString sSpell), AddContingencySpell, AddContingencySpell, (sSpell), 0x7BD3A3);
DefineLibMemberFunc(bool, CScreenMageBook, ClearContingencySpell, (char index), ClearContingencySpell, ClearContingencySpell, (index), 0x7BD516);
DefineLibMemberFunc(void, CScreenMageBook, SetSpellContingencyState, (IECString sSpell, bool bState), SetSpellContingencyState, SetSpellContingencyState, (sSpell, bState), 0x7BDA4D);
DefineLibMemberFunc(void, CScreenMageBook, UpdateContingencySpellList, (), UpdateContingencySpellList, UpdateContingencySpellList, (), 0x7BDC88);
DefineLibMemberFunc(void, CScreenMageBook, CreateContingencySpellList, (char nSpellType, char nLevel), CreateContingencySpellList, CreateContingencySpellList, (nSpellType, nLevel), 0x7BDCB1);
DefineLibMemberFunc(bool, CScreenMageBook, IsSpellAllowedInContingency, (int nLevel, IECString sSpell), IsSpellAllowedInContingency, IsSpellAllowedInContingency, (nLevel, sSpell), 0x7BDF3C);
