#include "engchargen.h"

#include "utils.h"

void (CCharGen::*CCharGen_KitPanelOnLoad)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::KitPanelOnLoad),		0x71A081);
void (CCharGen::*CCharGen_MageBookPanelOnLoad)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::MageBookPanelOnLoad),	0x71B220);
void (CCharGen::*CCharGen_UpdatePanel)(DWORD, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(DWORD, CCreatureObject&)>		(&CCharGen::UpdatePanel),			0x71DEA7);
void (CCharGen::*CCharGen_KitPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::KitPanelOnUpdate),		0x71E3A5);
void (CCharGen::*CCharGen_MageBookPanelOnUpdate)(CPanel&, CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CPanel&, CCreatureObject&)>	(&CCharGen::MageBookPanelOnUpdate),	0x720425);
void (CCharGen::*CCharGen_InitSoundset)(CCreatureObject&) =
	SetFP(static_cast<void (CCharGen::*)(CCreatureObject&)>				(&CCharGen::InitSoundset),			0x724E37);
BOOL (CCharGen::*CCharGen_CanContinue)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CCharGen::*)(CCreatureObject&)>				(&CCharGen::CanContinue),			0x72B11D);

void CCharGen::KitPanelOnLoad(CPanel& panel, CCreatureObject& cre)			{ return (this->*CCharGen_KitPanelOnLoad)(panel, cre); }
void CCharGen::MageBookPanelOnLoad(CPanel& panel, CCreatureObject& cre)		{ return (this->*CCharGen_MageBookPanelOnLoad)(panel, cre); }
void CCharGen::UpdatePanel(DWORD nPanelIdx, CCreatureObject& cre)			{ return (this->*CCharGen_UpdatePanel)(nPanelIdx, cre); }
void CCharGen::KitPanelOnUpdate(CPanel& panel, CCreatureObject& cre)		{ return (this->*CCharGen_KitPanelOnUpdate)(panel, cre); }
void CCharGen::MageBookPanelOnUpdate(CPanel& panel, CCreatureObject& cre)	{ return (this->*CCharGen_MageBookPanelOnUpdate)(panel, cre); }
void CCharGen::InitSoundset(CCreatureObject& cre)							{ return (this->*CCharGen_InitSoundset)(cre); }
BOOL CCharGen::CanContinue(CCreatureObject& cre)							{ return (this->*CCharGen_CanContinue)(cre); }