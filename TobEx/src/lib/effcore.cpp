#include "effcore.h"

#include "utils.h"

CEffect& (CEffect::*CEffect_Construct_7)(ITEM_EFFECT&, POINT&, Enum, DWORD, DWORD, BOOL, Enum) =
	SetFP(static_cast<CEffect& (CEffect::*)(ITEM_EFFECT&, POINT&, Enum, DWORD, DWORD, BOOL, Enum)>	(&CEffect::Construct),			0x4F34C8);
void (CEffect::*CEffect_Unmarshal)(EffFileData&) =
	SetFP(static_cast<void (CEffect::*)(EffFileData&)>												(&CEffect::Unmarshal),			0x4F3BEC);
CEffect& (CEffect::*CEffect_Construct_1)(EffFileData&) =
	SetFP(static_cast<CEffect& (CEffect::*)(EffFileData&)>											(&CEffect::Construct),			0x4F3E67);
CEffect& (*CEffect_CreateEffect)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum) =
	SetFP(static_cast<CEffect& (*)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum)>						(&CEffect::CreateEffect),		0x4F3EC2);
void (*CEffect_CreateItemEffect)(ITEM_EFFECT&, DWORD) =
	SetFP(static_cast<void (*)(ITEM_EFFECT&, DWORD)>												(&CEffect::CreateItemEffect),	0x4FFC3E);
ITEM_EFFECT& (CEffect::*CEffect_ToItemEffect)() =
	SetFP(static_cast<ITEM_EFFECT& (CEffect::*)()>													(&CEffect::ToItemEffect),		0x50270A);
void (CEffect::*CEffect_Deconstruct)() =
	SetFP(static_cast<void (CEffect::*)()>															(&CEffect::Deconstruct),		0x465810);
CEffect& (CEffect::*CEffect_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffect::*)()>														(&CEffect::Duplicate),			0x465730);
BOOL (CEffect::*CEffect_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffect::*)(CCreatureObject&)>											(&CEffect::ApplyEffect),		0x465760);
void (CEffect::*CEffect_ApplyTiming)(CCreatureObject&) =
	SetFP(static_cast<void (CEffect::*)(CCreatureObject&)>											(&CEffect::ApplyTiming),		0x4FFFA0);
void (CEffect::*CEffect_v10)() =
	SetFP(static_cast<void (CEffect::*)()>															(&CEffect::v10),				0x4657A0);
void (CEffect::*CEffect_v14)() =
	SetFP(static_cast<void (CEffect::*)()>															(&CEffect::v14),				0x4657B0);
BOOL (CEffect::*CEffect_TrySave)(CCreatureObject&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&) =
	SetFP(static_cast<BOOL (CEffect::*)(CCreatureObject&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&)>(&CEffect::TrySave),			0x501B29);
void (CEffect::*CEffect_v1c)() =
	SetFP(static_cast<void (CEffect::*)()>															(&CEffect::v1c),				0x4657C0);
void (CEffect::*CEffect_PrintEffectText)(CCreatureObject&) =
	SetFP(static_cast<void (CEffect::*)(CCreatureObject&)>											(&CEffect::PrintEffectText),	0x50284F);
void (CEffect::*CEffect_v24)(CCreatureObject&) =
	SetFP(static_cast<void (CEffect::*)(CCreatureObject&)>															(&CEffect::v24),				0x4657D0);

CEffect::CEffect(ITEM_EFFECT& data, POINT& ptSource, Enum eSource, DWORD destX, DWORD destY, BOOL bUseDice, Enum e2) { (this->*CEffect_Construct_7)(data, ptSource, eSource, destX, destY, bUseDice, e2); }
void CEffect::Unmarshal(EffFileData& data) { (this->*CEffect_Unmarshal)(data); }
CEffect::CEffect(EffFileData& data)	{ (this->*CEffect_Construct_1)(data); }																						
CEffect& CEffect::CreateEffect(ITEM_EFFECT& data, POINT& ptSource, Enum eSource, POINT& ptDest, Enum e2) { return (*CEffect_CreateEffect)(data, ptSource, eSource, ptDest, e2); }
void CEffect::CreateItemEffect(ITEM_EFFECT& ptr, DWORD nOpcode) { return (*CEffect_CreateItemEffect)(ptr, nOpcode); }
ITEM_EFFECT& CEffect::ToItemEffect() {return (this->*CEffect_ToItemEffect)(); }
CEffect::~CEffect() { (this->*CEffect_Deconstruct)(); }
CEffect& CEffect::Duplicate() { return (this->*CEffect_Duplicate)(); }
BOOL CEffect::ApplyEffect(CCreatureObject& creTarget) { return (this->*CEffect_ApplyEffect)(creTarget); }
void CEffect::ApplyTiming(CCreatureObject& creTarget) { return (this->*CEffect_ApplyTiming)(creTarget); }
void CEffect::v10() { return (this->*CEffect_v10)(); }
void CEffect::v14() { return (this->*CEffect_v14)(); }
BOOL CEffect::TrySave(CCreatureObject& creTarget, BYTE& rnd1, BYTE& rnd2, BYTE& rnd3, BYTE& rnd4, BYTE& rnd5, BYTE& rnd6) { return (this->*CEffect_TrySave)(creTarget, rnd1, rnd2, rnd3, rnd4, rnd5, rnd6); }
void CEffect::v1c() { return (this->*CEffect_v1c)(); }
void CEffect::PrintEffectText(CCreatureObject& creTarget) { return (this->*CEffect_PrintEffectText)(creTarget); }
void CEffect::v24(CCreatureObject& creTarget) { return (this->*CEffect_v24)(creTarget); }

void (CPtrListEffect::*CPtrListEffect_RemoveEffect)(CCreatureObject&, DWORD, POSITION, DWORD, ResRef, BOOL) =
	SetFP(static_cast<void (CPtrListEffect::*)(CCreatureObject&, DWORD, POSITION, DWORD, ResRef, BOOL)>			(&CPtrListEffect::RemoveEffect),	0x54306D);

void CPtrListEffect::RemoveEffect(CCreatureObject& creTarget, DWORD nOpcode, POSITION posItrPrev, DWORD nParam2, ResRef rResource, BOOL bCheckPermTiming) { return (this->*CPtrListEffect_RemoveEffect)(creTarget, nOpcode, posItrPrev, nParam2, rResource, bCheckPermTiming); }
