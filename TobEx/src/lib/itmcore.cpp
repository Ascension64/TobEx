#include "itmcore.h"

#include "stdafx.h"

CItem& (CItem::*CItem_Construct_0)() =
	SetFP(static_cast<CItem& (CItem::*)()>							(&CItem::Construct),		0x5A83F0);
void (CItem::*CItem_Deconstruct)() =
	SetFP(static_cast<void (CItem::*)()>							(&CItem::Deconstruct),		0x5A9E16);
BOOL (CItem::*CItem_Demand)() =
	SetFP(static_cast<BOOL (CItem::*)()>							(&CItem::Demand),			0x5AA032);
BOOL (CItem::*CItem_Release)() =
	SetFP(static_cast<BOOL (CItem::*)()>							(&CItem::Release),			0x5AA07F);
void (CItem::*CItem_LoadResource)(ResRef&, BOOL) =
	SetFP(static_cast<void (CItem::*)(ResRef&, BOOL)>				(&CItem::LoadResource),		0x5AA0A7);
void (CItem::*CItem_Equip)(CCreatureObject&, int, BOOL) =
	SetFP(static_cast<void (CItem::*)(CCreatureObject&, int, BOOL)>	(&CItem::Equip),			0x5AA430);
ItmFileAbility& (CItem::*CItem_GetAbility)(int) =
	SetFP(static_cast<ItmFileAbility& (CItem::*)(int)>				(&CItem::GetAbility),		0x5AB0D7);
CEffect& (CItem::*CItem_GetAbilityEffect)(int, int, CCreatureObject&) =
	SetFP(static_cast<CEffect& (CItem::*)(int, int, CCreatureObject&)>
																	(&CItem::GetAbilityEffect),	0x5AB168);
short (CItem::*CItem_GetType)() =
	SetFP(static_cast<short (CItem::*)()>							(&CItem::GetType),			0x5AB32B);
unsigned int (CItem::*CItem_GetFlags)() =
	SetFP(static_cast<unsigned int (CItem::*)()>					(&CItem::GetFlags),			0x5AB591);
unsigned int (CItem::*CItem_GetUnusableFlags)() =
	SetFP(static_cast<unsigned int (CItem::*)()>					(&CItem::GetUnusableFlags),	0x5AB609);

CItem::CItem()																{ (this->*CItem_Construct_0)(); }
CItem::~CItem()																{ (this->*CItem_Deconstruct)(); }
BOOL CItem::Demand()														{ return (this->*CItem_Demand)(); }
BOOL CItem::Release()														{ return (this->*CItem_Release)(); }
void CItem::LoadResource(ResRef& res, BOOL bAddToHandler)					{ return (this->*CItem_LoadResource)(res, bAddToHandler); }
void CItem::Equip(CCreatureObject& cre, int nSlot, BOOL bDoNotApplyEffects)	{ return (this->*CItem_Equip)(cre, nSlot, bDoNotApplyEffects); }
ItmFileAbility& CItem::GetAbility(int nAbilityIdx)							{ return (this->*CItem_GetAbility)(nAbilityIdx); }
CEffect& CItem::GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource)
	{return (this->*CItem_GetAbilityEffect)(nAbilityIdx, nEffectIdx, creSource); }
short CItem::GetType()														{ return (this->*CItem_GetType)(); }
unsigned int CItem::GetFlags()												{ return (this->*CItem_GetFlags)(); }
unsigned int CItem::GetUnusableFlags()										{ return (this->*CItem_GetUnusableFlags)(); }