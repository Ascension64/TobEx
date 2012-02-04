#include "engrecord.h"

#include "stdafx.h"

void (CScreenRecord::*CScreenRecord_MageBookPanelOnLoad)(CCreatureObject&) =
	SetFP(static_cast<void (CScreenRecord::*)(CCreatureObject&)>		(&CScreenRecord::MageBookPanelOnLoad),	0x6E0FE6);
void (CScreenRecord::*CScreenRecord_MageBookPanelOnUpdate)(CCreatureObject&) =
	SetFP(static_cast<void (CScreenRecord::*)(CCreatureObject&)>		(&CScreenRecord::MageBookPanelOnUpdate),0x6E563F);
void (CScreenRecord::*CScreenRecord_UpdatePanel)(int, CCreatureObject&) =
	SetFP(static_cast<void (CScreenRecord::*)(int, CCreatureObject&)>	(&CScreenRecord::UpdatePanel),			0x6E93BD);
CPanel& (CScreenRecord::*CScreenRecord_GetTopPanel)(void) =
	SetFP(static_cast<CPanel& (CScreenRecord::*)()>						(&CScreenRecord::GetTopPanel),			0x6E96B3);
void (CScreenRecord::*CScreenRecord_UpdateCharacter)(void) =
	SetFP(static_cast<void (CScreenRecord::*)(void)>					(&CScreenRecord::UpdateCharacter),		0x6E9F57);

void CScreenRecord::MageBookPanelOnLoad(CCreatureObject& cre)			{ return (this->*CScreenRecord_MageBookPanelOnLoad)(cre); }
void CScreenRecord::MageBookPanelOnUpdate(CCreatureObject& cre)			{ return (this->*CScreenRecord_MageBookPanelOnUpdate)(cre); }
void CScreenRecord::UpdatePanel(int nPanelIdx, CCreatureObject& cre)	{ return (this->*CScreenRecord_UpdatePanel)(nPanelIdx, cre); }
CPanel& CScreenRecord::GetTopPanel()									{ return (this->*CScreenRecord_GetTopPanel)(); }
void CScreenRecord::UpdateCharacter()									{ return (this->*CScreenRecord_UpdateCharacter)(); }