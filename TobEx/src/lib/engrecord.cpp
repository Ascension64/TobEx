#include "engrecord.h"

#include "stdafx.h"

void (CRecord::*CRecord_MageBookPanelOnLoad)(CCreatureObject&) =
	SetFP(static_cast<void (CRecord::*)(CCreatureObject&)>			(&CRecord::MageBookPanelOnLoad),	0x6E0FE6);
void (CRecord::*CRecord_MageBookPanelOnUpdate)(CCreatureObject&) =
	SetFP(static_cast<void (CRecord::*)(CCreatureObject&)>			(&CRecord::MageBookPanelOnUpdate),	0x6E563F);
void (CRecord::*CRecord_UpdatePanel)(int, CCreatureObject&) =
	SetFP(static_cast<void (CRecord::*)(int, CCreatureObject&)>		(&CRecord::UpdatePanel),			0x6E93BD);
CPanel& (CRecord::*CRecord_GetTopPanel)(void) =
	SetFP(static_cast<CPanel& (CRecord::*)()>						(&CRecord::GetTopPanel),			0x6E96B3);
void (CRecord::*CRecord_UpdateCharacter)(void) =
	SetFP(static_cast<void (CRecord::*)(void)>						(&CRecord::UpdateCharacter),		0x6E9F57);

void CRecord::MageBookPanelOnLoad(CCreatureObject& cre)				{ return (this->*CRecord_MageBookPanelOnLoad)(cre); }
void CRecord::MageBookPanelOnUpdate(CCreatureObject& cre)			{ return (this->*CRecord_MageBookPanelOnUpdate)(cre); }
void CRecord::UpdatePanel(int nPanelIdx, CCreatureObject& cre)		{ return (this->*CRecord_UpdatePanel)(nPanelIdx, cre); }
CPanel& CRecord::GetTopPanel()										{ return (this->*CRecord_GetTopPanel)(); }
void CRecord::UpdateCharacter()										{ return (this->*CRecord_UpdateCharacter)(); }