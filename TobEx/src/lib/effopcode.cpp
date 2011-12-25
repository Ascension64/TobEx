#include "effopcode.h"

//CEffectAttacksPerRoundMod
void (CEffectAttacksPerRoundMod::*CEffectAttacksPerRoundMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectAttacksPerRoundMod::*)()>					(&CEffectAttacksPerRoundMod::Deconstruct),	0x54A080);
CEffect& (CEffectAttacksPerRoundMod::*CEffectAttacksPerRoundMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectAttacksPerRoundMod::*)()>				(&CEffectAttacksPerRoundMod::Duplicate),	0x549F50);
BOOL (CEffectAttacksPerRoundMod::*CEffectAttacksPerRoundMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAttacksPerRoundMod::*)(CCreatureObject&)>	(&CEffectAttacksPerRoundMod::ApplyEffect),	0x5030F6);

CEffectAttacksPerRoundMod::~CEffectAttacksPerRoundMod()					{ (this->*CEffectAttacksPerRoundMod_Deconstruct)(); }
CEffect& CEffectAttacksPerRoundMod::Duplicate()							{ return (this->*CEffectAttacksPerRoundMod_Duplicate)(); }
BOOL CEffectAttacksPerRoundMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectAttacksPerRoundMod_ApplyEffect)(creTarget); }

//CEffectAwaken
void (CEffectAwaken::*CEffectAwaken_Deconstruct)() =
	SetFP(static_cast<void (CEffectAwaken::*)()>					(&CEffectAwaken::Deconstruct),	0x54A1E0);
CEffect& (CEffectAwaken::*CEffectAwaken_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectAwaken::*)()>				(&CEffectAwaken::Duplicate),	0x54A0B0);
BOOL (CEffectAwaken::*CEffectAwaken_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAwaken::*)(CCreatureObject&)>	(&CEffectAwaken::ApplyEffect),	0x503597);

CEffectAwaken::~CEffectAwaken()								{ (this->*CEffectAwaken_Deconstruct)(); }
CEffect& CEffectAwaken::Duplicate()							{ return (this->*CEffectAwaken_Duplicate)(); }
BOOL CEffectAwaken::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectAwaken_ApplyEffect)(creTarget); }

//CEffectDamage
void (CEffectDamage::*CEffectDamage_Deconstruct)() =
	SetFP(static_cast<void (CEffectDamage::*)()>						(&CEffectDamage::Deconstruct),				0x4947C0);
CEffect& (CEffectDamage::*CEffectDamage_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectDamage::*)()>					(&CEffectDamage::Duplicate),				0x494680);
BOOL (CEffectDamage::*CEffectDamage_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDamage::*)(CCreatureObject&)>		(&CEffectDamage::ApplyEffect),				0x505570);
void (CEffectDamage::*CEffectDamage_OnDelayFinished)(CCreatureObject&) =
	SetFP(static_cast<void (CEffectDamage::*)(CCreatureObject&)>		(&CEffectDamage::OnDelayFinished),			0x507A0E);
BOOL (CEffectDamage::*CEffectDamage_CheckNotSaved)(CCreatureObject&, char&, char&, char&, char&, char&, char&) =
	SetFP(static_cast<BOOL (CEffectDamage::*)(CCreatureObject&, char&, char&, char&, char&, char&, char&)>
																		(&CEffectDamage::CheckNotSaved),			0x507EBD);
BOOL (CEffectDamage::*CEffectDamage_IgnoreLevelCheck)() =
	SetFP(static_cast<BOOL (CEffectDamage::*)()>						(&CEffectDamage::IgnoreLevelCheck),			0x494780);
void (CEffectDamage::*CEffectDamage_PrintEffectText)(CCreatureObject&) =
	SetFP(static_cast<void (CEffectDamage::*)(CCreatureObject&)>		(&CEffectDamage::PrintEffectText),			0x5081B3);
void (CEffectDamage::*CEffectDamage_PrintEffectTextOnApply)(CCreatureObject&) =
	SetFP(static_cast<void (CEffectDamage::*)(CCreatureObject&)>		(&CEffectDamage::PrintEffectTextOnApply),	0x5083D0);
void (CEffectDamage::*CEffectDamage_PlayHitSound)(int, CCreatureObject&) =
	SetFP(static_cast<void (CEffectDamage::*)(int, CCreatureObject&)>	(&CEffectDamage::PlayHitSound),				0x507240);

CEffectDamage::~CEffectDamage()													{ (this->*CEffectDamage_Deconstruct)(); }
CEffect& CEffectDamage::Duplicate()												{ return (this->*CEffectDamage_Duplicate)(); }
BOOL CEffectDamage::ApplyEffect(CCreatureObject& creTarget)						{ return (this->*CEffectDamage_ApplyEffect)(creTarget); }
void CEffectDamage::OnDelayFinished(CCreatureObject& creTarget)					{ return (this->*CEffectDamage_OnDelayFinished)(creTarget); }
BOOL CEffectDamage::CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist)
	{ return (this->*CEffectDamage_CheckNotSaved)(creTarget, rollSaveDeath, rollSaveWands, rollSavePoly, rollSaveBreath, rollSaveSpells, rollMagicResist); }
BOOL CEffectDamage::IgnoreLevelCheck()											{ return (this->*CEffectDamage_IgnoreLevelCheck)(); }
void CEffectDamage::PrintEffectText(CCreatureObject& creTarget)					{ return (this->*CEffectDamage_PrintEffectText)(creTarget); }
void CEffectDamage::PrintEffectTextOnApply(CCreatureObject& creTarget)			{ return (this->*CEffectDamage_PrintEffectTextOnApply)(creTarget); }
void CEffectDamage::PlayHitSound(int nDamageType, CCreatureObject& creTarget)	{ return (this->*CEffectDamage_PlayHitSound)(nDamageType, creTarget); }

//CEffectInstantDeath
CEffectInstantDeath::CEffectInstantDeath() {
	SetVT(this, 0xAA6A5C);
	effect.nOpcode = CEFFECT_OPCODE_INSTANT_DEATH;
}

void (CEffectInstantDeath::*CEffectInstantDeath_Deconstruct)() =
	SetFP(static_cast<void (CEffectInstantDeath::*)()>					(&CEffectInstantDeath::Deconstruct),	0x494920);
CEffect& (CEffectInstantDeath::*CEffectInstantDeath_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectInstantDeath::*)()>				(&CEffectInstantDeath::Duplicate),		0x4947F0);
BOOL (CEffectInstantDeath::*CEffectInstantDeath_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectInstantDeath::*)(CCreatureObject&)>	(&CEffectInstantDeath::ApplyEffect),	0x508FBC);
void (CEffectInstantDeath::*CEffectInstantDeath_OnDelayFinished)(CCreatureObject&) =
	SetFP(static_cast<void (CEffectInstantDeath::*)(CCreatureObject&)>	(&CEffectInstantDeath::OnDelayFinished),0x50D8BE);
void (CEffectInstantDeath::*CEffectInstantDeath_PrintEffectText)(CCreatureObject&) =
	SetFP(static_cast<void (CEffectInstantDeath::*)(CCreatureObject&)>	(&CEffectInstantDeath::PrintEffectText),0x510D3D);

CEffectInstantDeath::~CEffectInstantDeath()								{ (this->*CEffectInstantDeath_Deconstruct)(); }
CEffect& CEffectInstantDeath::Duplicate()								{ return (this->*CEffectInstantDeath_Duplicate)(); }
BOOL CEffectInstantDeath::ApplyEffect(CCreatureObject& creTarget)		{ return (this->*CEffectInstantDeath_ApplyEffect)(creTarget); }
void CEffectInstantDeath::OnDelayFinished(CCreatureObject& creTarget)	{ return (this->*CEffectInstantDeath_OnDelayFinished)(creTarget); }
void CEffectInstantDeath::PrintEffectText(CCreatureObject& creTarget)	{ return (this->*CEffectInstantDeath_PrintEffectText)(creTarget); }

//CEffectDexterityMod
void (CEffectDexterityMod::*CEffectDexterityMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectDexterityMod::*)()>					(&CEffectDexterityMod::Deconstruct),0x54B560);
CEffect& (CEffectDexterityMod::*CEffectDexterityMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectDexterityMod::*)()>				(&CEffectDexterityMod::Duplicate),	0x54B430);
BOOL (CEffectDexterityMod::*CEffectDexterityMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDexterityMod::*)(CCreatureObject&)>	(&CEffectDexterityMod::ApplyEffect),0x510DCF);

CEffectDexterityMod::~CEffectDexterityMod()							{ (this->*CEffectDexterityMod_Deconstruct)(); }
CEffect& CEffectDexterityMod::Duplicate()							{ return (this->*CEffectDexterityMod_Duplicate)(); }
BOOL CEffectDexterityMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectDexterityMod_ApplyEffect)(creTarget); }

//CEffectCurrentHPMod
void (CEffectCurrentHPMod::*CEffectCurrentHPMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectCurrentHPMod::*)()>					(&CEffectCurrentHPMod::Deconstruct),		0x54B830);
CEffect& (CEffectCurrentHPMod::*CEffectCurrentHPMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectCurrentHPMod::*)()>				(&CEffectCurrentHPMod::Duplicate),			0x54B6F0);
BOOL (CEffectCurrentHPMod::*CEffectCurrentHPMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCurrentHPMod::*)(CCreatureObject&)>	(&CEffectCurrentHPMod::ApplyEffect),		0x54B7F0);
BOOL (CEffectCurrentHPMod::*CEffectCurrentHPMod_IgnoreLevelCheck)() =
	SetFP(static_cast<BOOL (CEffectCurrentHPMod::*)()>					(&CEffectCurrentHPMod::IgnoreLevelCheck),	0x494780);

CEffectCurrentHPMod::~CEffectCurrentHPMod()							{ (this->*CEffectCurrentHPMod_Deconstruct)(); }
CEffect& CEffectCurrentHPMod::Duplicate()							{ return (this->*CEffectCurrentHPMod_Duplicate)(); }
BOOL CEffectCurrentHPMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectCurrentHPMod_ApplyEffect)(creTarget); }
BOOL CEffectCurrentHPMod::IgnoreLevelCheck()						{ return (this->*CEffectCurrentHPMod_IgnoreLevelCheck)(); }

//CEffectPoison
void (CEffectPoison::*CEffectPoison_Deconstruct)() =
	SetFP(static_cast<void (CEffectPoison::*)()>					(&CEffectPoison::Deconstruct),		0x54C340);
CEffect& (CEffectPoison::*CEffectPoison_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectPoison::*)()>				(&CEffectPoison::Duplicate),		0x54C210);
BOOL (CEffectPoison::*CEffectPoison_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectPoison::*)(CCreatureObject&)>	(&CEffectPoison::ApplyEffect),		0x513024);
void (CEffectPoison::*CEffectPoison_OnDelayFinished)(CCreatureObject&) =
	SetFP(static_cast<void (CEffectPoison::*)(CCreatureObject&)>	(&CEffectPoison::OnDelayFinished),	0x512EA1);

CEffectPoison::~CEffectPoison()									{ (this->*CEffectPoison_Deconstruct)(); }
CEffect& CEffectPoison::Duplicate()								{ return (this->*CEffectPoison_Duplicate)(); }
BOOL CEffectPoison::ApplyEffect(CCreatureObject& creTarget)		{ return (this->*CEffectPoison_ApplyEffect)(creTarget); }
void CEffectPoison::OnDelayFinished(CCreatureObject& creTarget)	{ return (this->*CEffectPoison_OnDelayFinished)(creTarget); }

//CEffectMageMemSpellMod
void (CEffectMageMemSpellMod::*CEffectMageMemSpellMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectMageMemSpellMod::*)()>					(&CEffectMageMemSpellMod::Deconstruct),		0x54DAA0);
CEffect& (CEffectMageMemSpellMod::*CEffectMageMemSpellMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectMageMemSpellMod::*)()>				(&CEffectMageMemSpellMod::Duplicate),		0x54D970);
BOOL (CEffectMageMemSpellMod::*CEffectMageMemSpellMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectMageMemSpellMod::*)(CCreatureObject&)>	(&CEffectMageMemSpellMod::ApplyEffect),		0x5161AB);

CEffectMageMemSpellMod::~CEffectMageMemSpellMod()						{ (this->*CEffectMageMemSpellMod_Deconstruct)(); }
CEffect& CEffectMageMemSpellMod::Duplicate()							{ return (this->*CEffectMageMemSpellMod_Duplicate)(); }
BOOL CEffectMageMemSpellMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectMageMemSpellMod_ApplyEffect)(creTarget); }

//CEffectStrengthMod
void (CEffectStrengthMod::*CEffectStrengthMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectStrengthMod::*)()>					(&CEffectStrengthMod::Deconstruct),		0x54DEF0);
CEffect& (CEffectStrengthMod::*CEffectStrengthMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectStrengthMod::*)()>				(&CEffectStrengthMod::Duplicate),		0x54DD90);
BOOL (CEffectStrengthMod::*CEffectStrengthMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectStrengthMod::*)(CCreatureObject&)>	(&CEffectStrengthMod::ApplyEffect),		0x516673);

CEffectStrengthMod::~CEffectStrengthMod()							{ (this->*CEffectStrengthMod_Deconstruct)(); }
CEffect& CEffectStrengthMod::Duplicate()							{ return (this->*CEffectStrengthMod_Duplicate)(); }
BOOL CEffectStrengthMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectStrengthMod_ApplyEffect)(creTarget); }

//CEffectDispel
void (CEffectDispel::*CEffectDispel_Deconstruct)() =
	SetFP(static_cast<void (CEffectDispel::*)()>					(&CEffectDispel::Deconstruct),		0x54EE10);
CEffect& (CEffectDispel::*CEffectDispel_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectDispel::*)()>				(&CEffectDispel::Duplicate),		0x54ECE0);
BOOL (CEffectDispel::*CEffectDispel_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDispel::*)(CCreatureObject&)>	(&CEffectDispel::ApplyEffect),		0x5184DA);

CEffectDispel::~CEffectDispel()								{ (this->*CEffectDispel_Deconstruct)(); }
CEffect& CEffectDispel::Duplicate()							{ return (this->*CEffectDispel_Duplicate)(); }
BOOL CEffectDispel::ApplyEffect(CCreatureObject& creTarget) { return (this->*CEffectDispel_ApplyEffect)(creTarget); }

//CEffectPriestMemSpellMod
void (CEffectPriestMemSpellMod::*CEffectPriestMemSpellMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectPriestMemSpellMod::*)()>					(&CEffectPriestMemSpellMod::Deconstruct),	0x54DC00);
CEffect& (CEffectPriestMemSpellMod::*CEffectPriestMemSpellMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectPriestMemSpellMod::*)()>				(&CEffectPriestMemSpellMod::Duplicate),		0x54DAD0);
BOOL (CEffectPriestMemSpellMod::*CEffectPriestMemSpellMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectPriestMemSpellMod::*)(CCreatureObject&)>	(&CEffectPriestMemSpellMod::ApplyEffect),	0x518AA3);

CEffectPriestMemSpellMod::~CEffectPriestMemSpellMod()					{ (this->*CEffectPriestMemSpellMod_Deconstruct)(); }
CEffect& CEffectPriestMemSpellMod::Duplicate()							{ return (this->*CEffectPriestMemSpellMod_Duplicate)(); }
BOOL CEffectPriestMemSpellMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectPriestMemSpellMod_ApplyEffect)(creTarget); }

//CEffectBlindness
void (CEffectBlindness::*CEffectBlindness_Deconstruct)() =
	SetFP(static_cast<void (CEffectBlindness::*)()>					(&CEffectBlindness::Deconstruct),	0x5509E0);
CEffect& (CEffectBlindness::*CEffectBlindness_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectBlindness::*)()>				(&CEffectBlindness::Duplicate),		0x5508B0);
BOOL (CEffectBlindness::*CEffectBlindness_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectBlindness::*)(CCreatureObject&)>	(&CEffectBlindness::ApplyEffect),	0x51ADF9);

CEffectBlindness::~CEffectBlindness()							{ (this->*CEffectBlindness_Deconstruct)(); }
CEffect& CEffectBlindness::Duplicate()							{ return (this->*CEffectBlindness_Duplicate)(); }
BOOL CEffectBlindness::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectBlindness_ApplyEffect)(creTarget); }

//CEffectDisease
void (CEffectDisease::*CEffectDisease_Deconstruct)() =
	SetFP(static_cast<void (CEffectDisease::*)()>					(&CEffectDisease::Deconstruct),		0x550F60);
CEffect& (CEffectDisease::*CEffectDisease_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectDisease::*)()>				(&CEffectDisease::Duplicate),		0x550E30);
BOOL (CEffectDisease::*CEffectDisease_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDisease::*)(CCreatureObject&)>	(&CEffectDisease::ApplyEffect),		0x51B1FB);
void (CEffectDisease::*CEffectDisease_OnDelayFinished)(CCreatureObject&) =
	SetFP(static_cast<void (CEffectDisease::*)(CCreatureObject&)>	(&CEffectDisease::OnDelayFinished),	0x51B078);

CEffectDisease::~CEffectDisease()								{ (this->*CEffectDisease_Deconstruct)(); }
CEffect& CEffectDisease::Duplicate()							{ return (this->*CEffectDisease_Duplicate)(); }
BOOL CEffectDisease::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectDisease_ApplyEffect)(creTarget); }
void CEffectDisease::OnDelayFinished(CCreatureObject& creTarget){ return (this->*CEffectDisease_OnDelayFinished)(creTarget); }

//CEffectRegeneration
void (CEffectRegeneration::*CEffectRegeneration_Deconstruct)() =
	SetFP(static_cast<void (CEffectRegeneration::*)()>					(&CEffectRegeneration::Deconstruct),		0x552AE0);
CEffect& (CEffectRegeneration::*CEffectRegeneration_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectRegeneration::*)()>				(&CEffectRegeneration::Duplicate),			0x5529B0);
BOOL (CEffectRegeneration::*CEffectRegeneration_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRegeneration::*)(CCreatureObject&)>	(&CEffectRegeneration::ApplyEffect),		0x51C615);
void (CEffectRegeneration::*CEffectRegeneration_OnDelayFinished)(CCreatureObject&) =
	SetFP(static_cast<void (CEffectRegeneration::*)(CCreatureObject&)>	(&CEffectRegeneration::OnDelayFinished),	0x51C492);

CEffectRegeneration::~CEffectRegeneration()								{ (this->*CEffectRegeneration_Deconstruct)(); }
CEffect& CEffectRegeneration::Duplicate()								{ return (this->*CEffectRegeneration_Duplicate)(); }
BOOL CEffectRegeneration::ApplyEffect(CCreatureObject& creTarget)		{ return (this->*CEffectRegeneration_ApplyEffect)(creTarget); }
void CEffectRegeneration::OnDelayFinished(CCreatureObject& creTarget)	{ return (this->*CEffectRegeneration_OnDelayFinished)(creTarget); }

//CEffectLearnSpell
void (CEffectLearnSpell::*CEffectLearnSpell_Deconstruct)() =
	SetFP(static_cast<void (CEffectLearnSpell::*)()>				(&CEffectLearnSpell::Deconstruct),	0x557540);
CEffect& (CEffectLearnSpell::*CEffectLearnSpell_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectLearnSpell::*)()>			(&CEffectLearnSpell::Duplicate),	0x557410);
BOOL (CEffectLearnSpell::*CEffectLearnSpell_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectLearnSpell::*)(CCreatureObject&)>(&CEffectLearnSpell::ApplyEffect),	0x52C250);

CEffectLearnSpell::~CEffectLearnSpell()							{ (this->*CEffectLearnSpell_Deconstruct)(); }
CEffect& CEffectLearnSpell::Duplicate()							{ return (this->*CEffectLearnSpell_Duplicate)(); }
BOOL CEffectLearnSpell::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectLearnSpell_ApplyEffect)(creTarget); }

//CEffectMagicResistMod
void (CEffectMagicResistMod::*CEffectMagicResistMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectMagicResistMod::*)()>				(&CEffectMagicResistMod::Deconstruct),	0x5585C0);
CEffect& (CEffectMagicResistMod::*CEffectMagicResistMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectMagicResistMod::*)()>			(&CEffectMagicResistMod::Duplicate),	0x558490);
BOOL (CEffectMagicResistMod::*CEffectMagicResistMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectMagicResistMod::*)(CCreatureObject&)>(&CEffectMagicResistMod::ApplyEffect),	0x52EB97);

CEffectMagicResistMod::~CEffectMagicResistMod()						{ (this->*CEffectMagicResistMod_Deconstruct)(); }
CEffect& CEffectMagicResistMod::Duplicate()							{ return (this->*CEffectMagicResistMod_Duplicate)(); }
BOOL CEffectMagicResistMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectMagicResistMod_ApplyEffect)(creTarget); }

//CEffectCastSpellOnCondition
void (CEffectCastSpellOnCondition::*CEffectCastSpellOnCondition_Deconstruct)() =
	SetFP(static_cast<void (CEffectCastSpellOnCondition::*)()>					(&CEffectCastSpellOnCondition::Deconstruct),	0x55DCE0);
CEffect& (CEffectCastSpellOnCondition::*CEffectCastSpellOnCondition_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectCastSpellOnCondition::*)()>				(&CEffectCastSpellOnCondition::Duplicate),		0x55DBB0);
BOOL (CEffectCastSpellOnCondition::*CEffectCastSpellOnCondition_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCastSpellOnCondition::*)(CCreatureObject&)>	(&CEffectCastSpellOnCondition::ApplyEffect),	0x53AFB7);

CEffectCastSpellOnCondition::~CEffectCastSpellOnCondition()					{ (this->*CEffectCastSpellOnCondition_Deconstruct)(); }
CEffect& CEffectCastSpellOnCondition::Duplicate()							{ return (this->*CEffectCastSpellOnCondition_Duplicate)(); }
BOOL CEffectCastSpellOnCondition::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectCastSpellOnCondition_ApplyEffect)(creTarget); }

//CEffectWingBuffet
CEffectWingBuffet& (CEffectWingBuffet::*CEffectWingBuffet_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int) =
	SetFP(static_cast<CEffectWingBuffet& (CEffectWingBuffet::*)(ITEM_EFFECT&, POINT&, Enum, int, int)>
																	(&CEffectWingBuffet::Construct),	0x55E050);
void (CEffectWingBuffet::*CEffectWingBuffet_Deconstruct)() =
	SetFP(static_cast<void (CEffectWingBuffet::*)()>				(&CEffectWingBuffet::Deconstruct),	0x55E1C0);
CEffect& (CEffectWingBuffet::*CEffectWingBuffet_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectWingBuffet::*)()>			(&CEffectWingBuffet::Duplicate),	0x55E090);
BOOL (CEffectWingBuffet::*CEffectWingBuffet_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectWingBuffet::*)(CCreatureObject&)>(&CEffectWingBuffet::ApplyEffect),	0x53C791);
BOOL (CEffectWingBuffet::*CEffectWingBuffet_CheckNotSaved)(CCreatureObject&, char&, char&, char&, char&, char&, char&) =
	SetFP(static_cast<BOOL (CEffectWingBuffet::*)(CCreatureObject&, char&, char&, char&, char&, char&, char&)>
																	(&CEffectWingBuffet::CheckNotSaved),0x53C513);

CEffectWingBuffet::CEffectWingBuffet(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY) {
	(this->*CEffectWingBuffet_Construct_5)(eff, ptSource, eSource, ptDestX, ptDestY); }
CEffectWingBuffet::~CEffectWingBuffet()							{ (this->*CEffectWingBuffet_Deconstruct)(); }
CEffect& CEffectWingBuffet::Duplicate()							{ return (this->*CEffectWingBuffet_Duplicate)(); }
BOOL CEffectWingBuffet::ApplyEffect(CCreatureObject& creTarget) { return (this->*CEffectWingBuffet_ApplyEffect)(creTarget); }
BOOL CEffectWingBuffet::CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist)
	{ return (this->*CEffectWingBuffet_CheckNotSaved)(creTarget, rollSaveDeath, rollSaveWands, rollSavePoly, rollSaveBreath, rollSaveSpells, rollMagicResist); }

//CEffectDisintegrate
void (CEffectDisintegrate::*CEffectDisintegrate_Deconstruct)() =
	SetFP(static_cast<void (CEffectDisintegrate::*)()>					(&CEffectDisintegrate::Deconstruct),0x55E730);
CEffect& (CEffectDisintegrate::*CEffectDisintegrate_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectDisintegrate::*)()>				(&CEffectDisintegrate::Duplicate),	0x55E600);
BOOL (CEffectDisintegrate::*CEffectDisintegrate_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDisintegrate::*)(CCreatureObject&)>	(&CEffectDisintegrate::ApplyEffect),0x53F01D);

CEffectDisintegrate::~CEffectDisintegrate()							{ (this->*CEffectDisintegrate_Deconstruct)(); }
CEffect& CEffectDisintegrate::Duplicate()							{ return (this->*CEffectDisintegrate_Duplicate)(); }
BOOL CEffectDisintegrate::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectDisintegrate_ApplyEffect)(creTarget); }

//CEffectRepeatingEff
CEffectRepeatingEff& (CEffectRepeatingEff::*CEffectRepeatingEff_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int) =
	SetFP(static_cast<CEffectRepeatingEff& (CEffectRepeatingEff::*)(ITEM_EFFECT&, POINT&, Enum, int, int)>
																		(&CEffectRepeatingEff::Construct),	0x561AA0);
void (CEffectRepeatingEff::*CEffectRepeatingEff_Deconstruct)() =
	SetFP(static_cast<void (CEffectRepeatingEff::*)()>					(&CEffectRepeatingEff::Deconstruct),0x561C10);
CEffect& (CEffectRepeatingEff::*CEffectRepeatingEff_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectRepeatingEff::*)()>				(&CEffectRepeatingEff::Duplicate),	0x561AE0);
BOOL (CEffectRepeatingEff::*CEffectRepeatingEff_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRepeatingEff::*)(CCreatureObject&)>	(&CEffectRepeatingEff::ApplyEffect),0x541C3B);

CEffectRepeatingEff::CEffectRepeatingEff(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY) {
	(this->*CEffectRepeatingEff_Construct_5)(eff, ptSource, eSource, ptDestX, ptDestY); }
CEffectRepeatingEff::~CEffectRepeatingEff()							{ (this->*CEffectRepeatingEff_Deconstruct)(); }
CEffect& CEffectRepeatingEff::Duplicate()							{ return (this->*CEffectRepeatingEff_Duplicate)(); }
BOOL CEffectRepeatingEff::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectRepeatingEff_ApplyEffect)(creTarget); }

//CEffectRemoveProjectile
void (CEffectRemoveProjectile::*CEffectRemoveProjectile_Deconstruct)() =
	SetFP(static_cast<void (CEffectRemoveProjectile::*)()>					(&CEffectRemoveProjectile::Deconstruct),0x55EB50);
CEffect& (CEffectRemoveProjectile::*CEffectRemoveProjectile_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectRemoveProjectile::*)()>				(&CEffectRemoveProjectile::Duplicate),	0x55E9C0);
BOOL (CEffectRemoveProjectile::*CEffectRemoveProjectile_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectRemoveProjectile::*)(CCreatureObject&)>	(&CEffectRemoveProjectile::ApplyEffect),0x53F5D8);

CEffectRemoveProjectile::~CEffectRemoveProjectile()						{ (this->*CEffectRemoveProjectile_Deconstruct)(); }
CEffect& CEffectRemoveProjectile::Duplicate()							{ return (this->*CEffectRemoveProjectile_Duplicate)(); }
BOOL CEffectRemoveProjectile::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectRemoveProjectile_ApplyEffect)(creTarget); }

//CEffectCutScene2
void (CEffectCutScene2::*CEffectCutScene2_Deconstruct)() =
	SetFP(static_cast<void (CEffectCutScene2::*)()>					(&CEffectCutScene2::Deconstruct),	0x564310);
CEffect& (CEffectCutScene2::*CEffectCutScene2_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectCutScene2::*)()>				(&CEffectCutScene2::Duplicate),		0x5641E0);
BOOL (CEffectCutScene2::*CEffectCutScene2_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCutScene2::*)(CCreatureObject&)>	(&CEffectCutScene2::ApplyEffect),	0x542815);

CEffectCutScene2::~CEffectCutScene2()							{ (this->*CEffectCutScene2_Deconstruct)(); }
CEffect& CEffectCutScene2::Duplicate()							{ return (this->*CEffectCutScene2_Duplicate)(); }
BOOL CEffectCutScene2::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectCutScene2_ApplyEffect)(creTarget); }

//CEffectAnimationRemoval
void (CEffectAnimationRemoval::*CEffectAnimationRemoval_Deconstruct)() =
	SetFP(static_cast<void (CEffectAnimationRemoval::*)()>					(&CEffectAnimationRemoval::Deconstruct),	0x565E70);
CEffect& (CEffectAnimationRemoval::*CEffectAnimationRemoval_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectAnimationRemoval::*)()>				(&CEffectAnimationRemoval::Duplicate),		0x565D40);
BOOL (CEffectAnimationRemoval::*CEffectAnimationRemoval_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAnimationRemoval::*)(CCreatureObject&)>	(&CEffectAnimationRemoval::ApplyEffect),	0x549C0C);

CEffectAnimationRemoval::~CEffectAnimationRemoval()						{ (this->*CEffectAnimationRemoval_Deconstruct)(); }
CEffect& CEffectAnimationRemoval::Duplicate()							{ return (this->*CEffectAnimationRemoval_Duplicate)(); }
BOOL CEffectAnimationRemoval::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectAnimationRemoval_ApplyEffect)(creTarget); }
