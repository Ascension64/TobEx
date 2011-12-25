#include "effcore.h"

#include "stdafx.h"

//CEffect
CEffect& (CEffect::*CEffect_Construct_0)() =
	SetFP(static_cast<CEffect& (CEffect::*)()>														(&CEffect::Construct),			0x465440);
CEffect& (CEffect::*CEffect_Construct_7)(ITEM_EFFECT&, POINT&, Enum, int, int, BOOL, Enum) =
	SetFP(static_cast<CEffect& (CEffect::*)(ITEM_EFFECT&, POINT&, Enum, int, int, BOOL, Enum)>	(&CEffect::Construct),			0x4F34C8);
void (CEffect::*CEffect_Unmarshal)(EffFileData&) =
	SetFP(static_cast<void (CEffect::*)(EffFileData&)>												(&CEffect::Unmarshal),			0x4F3BEC);
CEffect& (CEffect::*CEffect_Construct_1)(EffFileData&) =
	SetFP(static_cast<CEffect& (CEffect::*)(EffFileData&)>											(&CEffect::Construct),			0x4F3E67);
CEffect& (*CEffect_CreateEffect)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum) =
	SetFP(static_cast<CEffect& (*)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum)>						(&CEffect::CreateEffect),		0x4F3EC2);
void (*CEffect_CreateItemEffect)(ITEM_EFFECT&, int) =
	SetFP(static_cast<void (*)(ITEM_EFFECT&, int)>												(&CEffect::CreateItemEffect),	0x4FFC3E);
ITEM_EFFECT& (CEffect::*CEffect_ToItemEffect)() =
	SetFP(static_cast<ITEM_EFFECT& (CEffect::*)()>													(&CEffect::ToItemEffect),		0x50270A);
void (CEffect::*CEffect_Deconstruct)() =
	SetFP(static_cast<void (CEffect::*)()>															(&CEffect::Deconstruct),		0x465810);
CEffect& (CEffect::*CEffect_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffect::*)()>														(&CEffect::Duplicate),			0x465730);
BOOL (CEffect::*CEffect_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffect::*)(CCreatureObject&)>											(&CEffect::ApplyEffect),		0x465760);
BOOL (CEffect::*CEffect_ApplyTiming)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffect::*)(CCreatureObject&)>											(&CEffect::ApplyTiming),		0x4FFFA0);
void (CEffect::*CEffect_OnDelayFinished)(CCreatureObject&) =
	SetFP(static_cast<void (CEffect::*)(CCreatureObject&)>											(&CEffect::OnDelayFinished),	0x4657A0);
void (CEffect::*CEffect_v14)() =
	SetFP(static_cast<void (CEffect::*)()>															(&CEffect::v14),				0x4657B0);
BOOL (CEffect::*CEffect_CheckNotSaved)(CCreatureObject&, char&, char&, char&, char&, char&, char&) =
	SetFP(static_cast<BOOL (CEffect::*)(CCreatureObject&, char&, char&, char&, char&, char&, char&)>(&CEffect::CheckNotSaved),		0x501B29);
BOOL (CEffect::*CEffect_IgnoreLevelCheck)() =
	SetFP(static_cast<BOOL (CEffect::*)()>															(&CEffect::IgnoreLevelCheck),	0x4657C0);
void (CEffect::*CEffect_PrintEffectText)(CCreatureObject&) =
	SetFP(static_cast<void (CEffect::*)(CCreatureObject&)>											(&CEffect::PrintEffectText),	0x50284F);
void (CEffect::*CEffect_OnRemove)(CCreatureObject&) =
	SetFP(static_cast<void (CEffect::*)(CCreatureObject&)>											(&CEffect::OnRemove),			0x4657D0);

CEffect::CEffect() { (this->*CEffect_Construct_0)(); }
CEffect::CEffect(ITEM_EFFECT& data, POINT& ptSource, Enum eSource, int destX, int destY, BOOL bUseDice, Enum e2) {
	(this->*CEffect_Construct_7)(data, ptSource, eSource, destX, destY, bUseDice, e2);
}
void CEffect::Unmarshal(EffFileData& data) { (this->*CEffect_Unmarshal)(data); }
CEffect::CEffect(EffFileData& data)	{ (this->*CEffect_Construct_1)(data); }																						
CEffect& CEffect::CreateEffect(ITEM_EFFECT& data, POINT& ptSource, Enum eSource, POINT& ptDest, Enum e2) {
	return (*CEffect_CreateEffect)(data, ptSource, eSource, ptDest, e2);
}
void CEffect::CreateItemEffect(ITEM_EFFECT& ptr, int nOpcode) { return (*CEffect_CreateItemEffect)(ptr, nOpcode); }
ITEM_EFFECT& CEffect::ToItemEffect() {return (this->*CEffect_ToItemEffect)(); }
CEffect::~CEffect() { (this->*CEffect_Deconstruct)(); }
CEffect& CEffect::Duplicate() { return (this->*CEffect_Duplicate)(); }
BOOL CEffect::ApplyEffect(CCreatureObject& creTarget) { return (this->*CEffect_ApplyEffect)(creTarget); }
BOOL CEffect::ApplyTiming(CCreatureObject& creTarget) { return (this->*CEffect_ApplyTiming)(creTarget); }
void CEffect::OnDelayFinished(CCreatureObject& creTarget) { return (this->*CEffect_OnDelayFinished)(creTarget); }
void CEffect::v14() { return (this->*CEffect_v14)(); }
BOOL CEffect::CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist) {
	return (this->*CEffect_CheckNotSaved)(creTarget, rollSaveDeath, rollSaveWands, rollSavePoly, rollSaveBreath, rollSaveSpells, rollMagicResist);
}
BOOL CEffect::IgnoreLevelCheck() { return (this->*CEffect_IgnoreLevelCheck)(); }
void CEffect::PrintEffectText(CCreatureObject& creTarget) { return (this->*CEffect_PrintEffectText)(creTarget); }
void CEffect::OnRemove(CCreatureObject& creTarget) { return (this->*CEffect_OnRemove)(creTarget); }

//CEffectList
void (CEffectList::*CEffectList_RemoveEffect)(CCreatureObject&, int, POSITION, int, ResRef, BOOL) =
	SetFP(static_cast<void (CEffectList::*)(CCreatureObject&, int, POSITION, int, ResRef, BOOL)>	(&CEffectList::RemoveEffect),	0x54306D);
void (CEffectList::*CEffectList_TryDispel)(CCreatureObject&, POSITION, BOOL, BOOL, char, char) =
	SetFP(static_cast<void (CEffectList::*)(CCreatureObject&, POSITION, BOOL, BOOL, char, char)>		(&CEffectList::TryDispel),		0x543EC8);

void CEffectList::RemoveEffect(CCreatureObject& creTarget, int nOpcode, POSITION posSkip, int nParam2, ResRef rResource, BOOL bCheckPermTiming) {
	return (this->*CEffectList_RemoveEffect)(creTarget, nOpcode, posSkip, nParam2, rResource, bCheckPermTiming);
}
void CEffectList::TryDispel(CCreatureObject& creTarget, POSITION posSkip, BOOL bCheckDispellableFlag, BOOL bCheckProbability, char nRand, char nMaxLevel) {
	return (this->*CEffectList_TryDispel)(creTarget, posSkip, bCheckDispellableFlag, bCheckProbability, nRand, nMaxLevel);
}
