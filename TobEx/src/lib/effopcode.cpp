#include "effopcode.h"

//CEffectAttacksPerRoundMod
BOOL (CEffectAttacksPerRoundMod::*CEffectAttacksPerRoundMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAttacksPerRoundMod::*)(CCreatureObject&)>	(&CEffectAttacksPerRoundMod::ApplyEffect),	0x5030F6);

BOOL CEffectAttacksPerRoundMod::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectAttacksPerRoundMod_ApplyEffect)(cre); }

//CEffectAwaken
BOOL (CEffectAwaken::*CEffectAwaken_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAwaken::*)(CCreatureObject&)>				(&CEffectAwaken::ApplyEffect),				0x503597);

BOOL CEffectAwaken::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectAwaken_ApplyEffect)(cre); }

//CEffectDamage
BOOL (CEffectDamage::*CEffectDamage_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDamage::*)(CCreatureObject&)>				(&CEffectDamage::ApplyEffect),				0x505570);

BOOL CEffectDamage::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectDamage_ApplyEffect)(cre); }

//CEffectPoison
BOOL (CEffectPoison::*CEffectPoison_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectPoison::*)(CCreatureObject&)>				(&CEffectPoison::ApplyEffect),				0x513024);

BOOL CEffectPoison::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectPoison_ApplyEffect)(cre); }

//CEffectCurrentHPMod
void (CEffectCurrentHPMod::*CEffectCurrentHPMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectCurrentHPMod::*)()>							(&CEffectCurrentHPMod::Deconstruct),		0x54B830);
CEffect& (CEffectCurrentHPMod::*CEffectCurrentHPMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectCurrentHPMod::*)()>						(&CEffectCurrentHPMod::Duplicate),			0x54B6F0);
BOOL (CEffectCurrentHPMod::*CEffectCurrentHPMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCurrentHPMod::*)(CCreatureObject&)>			(&CEffectCurrentHPMod::ApplyEffect),		0x5115B9);

//CEffectDispel
BOOL (CEffectDispel::*CEffectDispel_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDispel::*)(CCreatureObject&)>				(&CEffectDispel::ApplyEffect),				0x5184DA);

BOOL CEffectDispel::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectDispel_ApplyEffect)(cre); }

//CEffectBlindness
BOOL (CEffectBlindness::*CEffectBlindness_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectBlindness::*)(CCreatureObject&)>				(&CEffectBlindness::ApplyEffect),			0x51ADF9);

BOOL CEffectBlindness::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectBlindness_ApplyEffect)(cre); }

//CEffectDisease
BOOL (CEffectDisease::*CEffectDisease_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDisease::*)(CCreatureObject&)>				(&CEffectDisease::ApplyEffect),				0x51B1FB);

BOOL CEffectDisease::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectDisease_ApplyEffect)(cre); }

//CEffectRegeneration
BOOL (CEffectRegeneration::*CEffectRegeneration_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRegeneration::*)(CCreatureObject&)>			(&CEffectRegeneration::ApplyEffect),		0x51C615);

BOOL CEffectRegeneration::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectRegeneration_ApplyEffect)(cre); }

//CEffectMagicResistMod
BOOL (CEffectMagicResistMod::*CEffectMagicResistMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectMagicResistMod::*)(CCreatureObject&)>		(&CEffectMagicResistMod::ApplyEffect),		0x52EB97);

BOOL CEffectMagicResistMod::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectMagicResistMod_ApplyEffect)(cre); }

//CEffectRepeatingEff
CEffectRepeatingEff& (CEffectRepeatingEff::*CEffectRepeatingEff_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int) =
	SetFP(static_cast<CEffectRepeatingEff& (CEffectRepeatingEff::*)(ITEM_EFFECT&, POINT&, Enum, int, int)>
																				(&CEffectRepeatingEff::Construct),			0x561AA0);
BOOL (CEffectRepeatingEff::*CEffectRepeatingEff_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRepeatingEff::*)(CCreatureObject&)>			(&CEffectRepeatingEff::ApplyEffect),		0x541C3B);

CEffectRepeatingEff::CEffectRepeatingEff(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY) {
	(this->*CEffectRepeatingEff_Construct_5)(eff, ptSource, eSource, ptDestX, ptDestY); }
BOOL CEffectRepeatingEff::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectRepeatingEff_ApplyEffect)(cre); }

//CEffectWingBuffet
CEffectWingBuffet& (CEffectWingBuffet::*CEffectWingBuffet_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int) =
	SetFP(static_cast<CEffectWingBuffet& (CEffectWingBuffet::*)(ITEM_EFFECT&, POINT&, Enum, int, int)>
																				(&CEffectWingBuffet::Construct),		0x55E050);
BOOL (CEffectWingBuffet::*CEffectWingBuffet_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectWingBuffet::*)(CCreatureObject&)>			(&CEffectWingBuffet::ApplyEffect),		0x53C791);

CEffectWingBuffet::CEffectWingBuffet(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY) {
	(this->*CEffectWingBuffet_Construct_5)(eff, ptSource, eSource, ptDestX, ptDestY); }
BOOL CEffectWingBuffet::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectWingBuffet_ApplyEffect)(cre); }

//CEffectCutScene2
BOOL (CEffectCutScene2::*CEffectCutScene2_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCutScene2::*)(CCreatureObject&)>				(&CEffectCutScene2::ApplyEffect),			0x542815);

BOOL CEffectCutScene2::ApplyEffect(CCreatureObject& cre) { return (this->*CEffectCutScene2_ApplyEffect)(cre); }
