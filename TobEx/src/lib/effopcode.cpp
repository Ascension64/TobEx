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

//CEffectCharismaMod
void (CEffectCharismaMod::*CEffectCharismaMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectCharismaMod::*)()>					(&CEffectCharismaMod::Deconstruct),	0x54A7A0);
CEffect& (CEffectCharismaMod::*CEffectCharismaMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectCharismaMod::*)()>				(&CEffectCharismaMod::Duplicate),	0x54A670);
BOOL (CEffectCharismaMod::*CEffectCharismaMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCharismaMod::*)(CCreatureObject&)>	(&CEffectCharismaMod::ApplyEffect),	0x5046EC);

CEffectCharismaMod::~CEffectCharismaMod()							{ (this->*CEffectCharismaMod_Deconstruct)(); }
CEffect& CEffectCharismaMod::Duplicate()							{ return (this->*CEffectCharismaMod_Duplicate)(); }
BOOL CEffectCharismaMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectCharismaMod_ApplyEffect)(creTarget); }

//CEffectConstitutionMod
void (CEffectConstitutionMod::*CEffectConstitutionMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectConstitutionMod::*)()>					(&CEffectConstitutionMod::Deconstruct),	0x54B140);
CEffect& (CEffectConstitutionMod::*CEffectConstitutionMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectConstitutionMod::*)()>				(&CEffectConstitutionMod::Duplicate),	0x54B010);
BOOL (CEffectConstitutionMod::*CEffectConstitutionMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectConstitutionMod::*)(CCreatureObject&)>	(&CEffectConstitutionMod::ApplyEffect),	0x50515F);

CEffectConstitutionMod::~CEffectConstitutionMod()						{ (this->*CEffectConstitutionMod_Deconstruct)(); }
CEffect& CEffectConstitutionMod::Duplicate()							{ return (this->*CEffectConstitutionMod_Duplicate)(); }
BOOL CEffectConstitutionMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectConstitutionMod_ApplyEffect)(creTarget); }

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
void (CEffectDamage::*CEffectDamage_PlayHitSound)(unsigned int, CCreatureObject&) =
	SetFP(static_cast<void (CEffectDamage::*)(unsigned int, CCreatureObject&)>	(&CEffectDamage::PlayHitSound),		0x507240);

CEffectDamage::~CEffectDamage()															{ (this->*CEffectDamage_Deconstruct)(); }
CEffect& CEffectDamage::Duplicate()														{ return (this->*CEffectDamage_Duplicate)(); }
BOOL CEffectDamage::ApplyEffect(CCreatureObject& creTarget)								{ return (this->*CEffectDamage_ApplyEffect)(creTarget); }
void CEffectDamage::OnDelayFinished(CCreatureObject& creTarget)							{ return (this->*CEffectDamage_OnDelayFinished)(creTarget); }
BOOL CEffectDamage::CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist)
	{ return (this->*CEffectDamage_CheckNotSaved)(creTarget, rollSaveDeath, rollSaveWands, rollSavePoly, rollSaveBreath, rollSaveSpells, rollMagicResist); }
BOOL CEffectDamage::IgnoreLevelCheck()													{ return (this->*CEffectDamage_IgnoreLevelCheck)(); }
void CEffectDamage::PrintEffectText(CCreatureObject& creTarget)							{ return (this->*CEffectDamage_PrintEffectText)(creTarget); }
void CEffectDamage::PrintEffectTextOnApply(CCreatureObject& creTarget)					{ return (this->*CEffectDamage_PrintEffectTextOnApply)(creTarget); }
void CEffectDamage::PlayHitSound(unsigned int nDamageType, CCreatureObject& creTarget)	{ return (this->*CEffectDamage_PlayHitSound)(nDamageType, creTarget); }

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

//CEffectIntelligenceMod
void (CEffectIntelligenceMod::*CEffectIntelligenceMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectIntelligenceMod::*)()>					(&CEffectIntelligenceMod::Deconstruct),	0x54BB00);
CEffect& (CEffectIntelligenceMod::*CEffectIntelligenceMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectIntelligenceMod::*)()>				(&CEffectIntelligenceMod::Duplicate),	0x54B9D0);
BOOL (CEffectIntelligenceMod::*CEffectIntelligenceMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectIntelligenceMod::*)(CCreatureObject&)>	(&CEffectIntelligenceMod::ApplyEffect),	0x5121DB);

CEffectIntelligenceMod::~CEffectIntelligenceMod()						{ (this->*CEffectIntelligenceMod_Deconstruct)(); }
CEffect& CEffectIntelligenceMod::Duplicate()							{ return (this->*CEffectIntelligenceMod_Duplicate)(); }
BOOL CEffectIntelligenceMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectIntelligenceMod_ApplyEffect)(creTarget); }

//CEffectLoreMod
void (CEffectLoreMod::*CEffectLoreMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectLoreMod::*)()>					(&CEffectLoreMod::Deconstruct),	0x54BDC0);
CEffect& (CEffectLoreMod::*CEffectLoreMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectLoreMod::*)()>				(&CEffectLoreMod::Duplicate),	0x54BC90);
BOOL (CEffectLoreMod::*CEffectLoreMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectLoreMod::*)(CCreatureObject&)>	(&CEffectLoreMod::ApplyEffect),	0x512733);

CEffectLoreMod::~CEffectLoreMod()								{ (this->*CEffectLoreMod_Deconstruct)(); }
CEffect& CEffectLoreMod::Duplicate()							{ return (this->*CEffectLoreMod_Duplicate)(); }
BOOL CEffectLoreMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectLoreMod_ApplyEffect)(creTarget); }

//CEffectLuckMod
void (CEffectLuckMod::*CEffectLuckMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectLuckMod::*)()>					(&CEffectLuckMod::Deconstruct),	0x54BF20);
CEffect& (CEffectLuckMod::*CEffectLuckMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectLuckMod::*)()>				(&CEffectLuckMod::Duplicate),	0x54BDF0);
BOOL (CEffectLuckMod::*CEffectLuckMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectLuckMod::*)(CCreatureObject&)>	(&CEffectLuckMod::ApplyEffect),	0x5129F3);

CEffectLuckMod::~CEffectLuckMod()								{ (this->*CEffectLuckMod_Deconstruct)(); }
CEffect& CEffectLuckMod::Duplicate()							{ return (this->*CEffectLuckMod_Duplicate)(); }
BOOL CEffectLuckMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectLuckMod_ApplyEffect)(creTarget); }

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

//CEffectSaveVsDeathMod
void (CEffectSaveVsDeathMod::*CEffectSaveVsDeathMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectSaveVsDeathMod::*)()>					(&CEffectSaveVsDeathMod::Deconstruct),	0x54CE40);
CEffect& (CEffectSaveVsDeathMod::*CEffectSaveVsDeathMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectSaveVsDeathMod::*)()>				(&CEffectSaveVsDeathMod::Duplicate),	0x54CD10);
BOOL (CEffectSaveVsDeathMod::*CEffectSaveVsDeathMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectSaveVsDeathMod::*)(CCreatureObject&)>	(&CEffectSaveVsDeathMod::ApplyEffect),	0x514B87);

CEffectSaveVsDeathMod::~CEffectSaveVsDeathMod()						{ (this->*CEffectSaveVsDeathMod_Deconstruct)(); }
CEffect& CEffectSaveVsDeathMod::Duplicate()							{ return (this->*CEffectSaveVsDeathMod_Duplicate)(); }
BOOL CEffectSaveVsDeathMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectSaveVsDeathMod_ApplyEffect)(creTarget); }

//CEffectSaveVsWandsMod
void (CEffectSaveVsWandsMod::*CEffectSaveVsWandsMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectSaveVsWandsMod::*)()>					(&CEffectSaveVsWandsMod::Deconstruct),	0x54CFA0);
CEffect& (CEffectSaveVsWandsMod::*CEffectSaveVsWandsMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectSaveVsWandsMod::*)()>				(&CEffectSaveVsWandsMod::Duplicate),	0x54CE70);
BOOL (CEffectSaveVsWandsMod::*CEffectSaveVsWandsMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectSaveVsWandsMod::*)(CCreatureObject&)>	(&CEffectSaveVsWandsMod::ApplyEffect),	0x514E4C);

CEffectSaveVsWandsMod::~CEffectSaveVsWandsMod()						{ (this->*CEffectSaveVsWandsMod_Deconstruct)(); }
CEffect& CEffectSaveVsWandsMod::Duplicate()							{ return (this->*CEffectSaveVsWandsMod_Duplicate)(); }
BOOL CEffectSaveVsWandsMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectSaveVsWandsMod_ApplyEffect)(creTarget); }

//CEffectSaveVsPolyMod
void (CEffectSaveVsPolyMod::*CEffectSaveVsPolyMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectSaveVsPolyMod::*)()>					(&CEffectSaveVsPolyMod::Deconstruct),	0x54D100);
CEffect& (CEffectSaveVsPolyMod::*CEffectSaveVsPolyMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectSaveVsPolyMod::*)()>				(&CEffectSaveVsPolyMod::Duplicate),		0x54CFD0);
BOOL (CEffectSaveVsPolyMod::*CEffectSaveVsPolyMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectSaveVsPolyMod::*)(CCreatureObject&)>	(&CEffectSaveVsPolyMod::ApplyEffect),	0x515111);

CEffectSaveVsPolyMod::~CEffectSaveVsPolyMod()						{ (this->*CEffectSaveVsPolyMod_Deconstruct)(); }
CEffect& CEffectSaveVsPolyMod::Duplicate()							{ return (this->*CEffectSaveVsPolyMod_Duplicate)(); }
BOOL CEffectSaveVsPolyMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectSaveVsPolyMod_ApplyEffect)(creTarget); }

//CEffectSaveVsBreathMod
void (CEffectSaveVsBreathMod::*CEffectSaveVsBreathMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectSaveVsBreathMod::*)()>					(&CEffectSaveVsBreathMod::Deconstruct),	0x54D260);
CEffect& (CEffectSaveVsBreathMod::*CEffectSaveVsBreathMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectSaveVsBreathMod::*)()>				(&CEffectSaveVsBreathMod::Duplicate),	0x54D130);
BOOL (CEffectSaveVsBreathMod::*CEffectSaveVsBreathMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectSaveVsBreathMod::*)(CCreatureObject&)>	(&CEffectSaveVsBreathMod::ApplyEffect),	0x5153C7);

CEffectSaveVsBreathMod::~CEffectSaveVsBreathMod()						{ (this->*CEffectSaveVsBreathMod_Deconstruct)(); }
CEffect& CEffectSaveVsBreathMod::Duplicate()							{ return (this->*CEffectSaveVsBreathMod_Duplicate)(); }
BOOL CEffectSaveVsBreathMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectSaveVsBreathMod_ApplyEffect)(creTarget); }

//CEffectSaveVsSpellMod
void (CEffectSaveVsSpellMod::*CEffectSaveVsSpellMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectSaveVsSpellMod::*)()>					(&CEffectSaveVsSpellMod::Deconstruct),	0x54D3C0);
CEffect& (CEffectSaveVsSpellMod::*CEffectSaveVsSpellMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectSaveVsSpellMod::*)()>				(&CEffectSaveVsSpellMod::Duplicate),	0x54D290);
BOOL (CEffectSaveVsSpellMod::*CEffectSaveVsSpellMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectSaveVsSpellMod::*)(CCreatureObject&)>	(&CEffectSaveVsSpellMod::ApplyEffect),	0x51568C);

CEffectSaveVsSpellMod::~CEffectSaveVsSpellMod()						{ (this->*CEffectSaveVsSpellMod_Deconstruct)(); }
CEffect& CEffectSaveVsSpellMod::Duplicate()							{ return (this->*CEffectSaveVsSpellMod_Duplicate)(); }
BOOL CEffectSaveVsSpellMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectSaveVsSpellMod_ApplyEffect)(creTarget); }

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

//CEffectWisdomMod
void (CEffectWisdomMod::*CEffectWisdomMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectWisdomMod::*)()>					(&CEffectWisdomMod::Deconstruct),	0x54E5D0);
CEffect& (CEffectWisdomMod::*CEffectWisdomMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectWisdomMod::*)()>				(&CEffectWisdomMod::Duplicate),		0x54E4A0);
BOOL (CEffectWisdomMod::*CEffectWisdomMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectWisdomMod::*)(CCreatureObject&)>	(&CEffectWisdomMod::ApplyEffect),	0x516DF1);

CEffectWisdomMod::~CEffectWisdomMod()							{ (this->*CEffectWisdomMod_Deconstruct)(); }
CEffect& CEffectWisdomMod::Duplicate()							{ return (this->*CEffectWisdomMod_Duplicate)(); }
BOOL CEffectWisdomMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectWisdomMod_ApplyEffect)(creTarget); }

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

//CEffectStealthMod
void (CEffectStealthMod::*CEffectStealthMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectStealthMod::*)()>					(&CEffectStealthMod::Deconstruct),	0x54EF70);
CEffect& (CEffectStealthMod::*CEffectStealthMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectStealthMod::*)()>				(&CEffectStealthMod::Duplicate),	0x54EE40);
BOOL (CEffectStealthMod::*CEffectStealthMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectStealthMod::*)(CCreatureObject&)>	(&CEffectStealthMod::ApplyEffect),	0x51877E);

CEffectStealthMod::~CEffectStealthMod()							{ (this->*CEffectStealthMod_Deconstruct)(); }
CEffect& CEffectStealthMod::Duplicate()							{ return (this->*CEffectStealthMod_Duplicate)(); }
BOOL CEffectStealthMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectStealthMod_ApplyEffect)(creTarget); }

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

//CEffectOpenLocksMod
void (CEffectOpenLocksMod::*CEffectOpenLocksMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectOpenLocksMod::*)()>					(&CEffectOpenLocksMod::Deconstruct),0x551FE0);
CEffect& (CEffectOpenLocksMod::*CEffectOpenLocksMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectOpenLocksMod::*)()>				(&CEffectOpenLocksMod::Duplicate),	0x551EB0);
BOOL (CEffectOpenLocksMod::*CEffectOpenLocksMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectOpenLocksMod::*)(CCreatureObject&)>	(&CEffectOpenLocksMod::ApplyEffect),0x51D1B8);

CEffectOpenLocksMod::~CEffectOpenLocksMod()							{ (this->*CEffectOpenLocksMod_Deconstruct)(); }
CEffect& CEffectOpenLocksMod::Duplicate()							{ return (this->*CEffectOpenLocksMod_Duplicate)(); }
BOOL CEffectOpenLocksMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectOpenLocksMod_ApplyEffect)(creTarget); }

//CEffectFindTrapsMod
void (CEffectFindTrapsMod::*CEffectFindTrapsMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectFindTrapsMod::*)()>					(&CEffectFindTrapsMod::Deconstruct),0x552140);
CEffect& (CEffectFindTrapsMod::*CEffectFindTrapsMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectFindTrapsMod::*)()>				(&CEffectFindTrapsMod::Duplicate),	0x552010);
BOOL (CEffectFindTrapsMod::*CEffectFindTrapsMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectFindTrapsMod::*)(CCreatureObject&)>	(&CEffectFindTrapsMod::ApplyEffect),0x51D420);

CEffectFindTrapsMod::~CEffectFindTrapsMod()							{ (this->*CEffectFindTrapsMod_Deconstruct)(); }
CEffect& CEffectFindTrapsMod::Duplicate()							{ return (this->*CEffectFindTrapsMod_Duplicate)(); }
BOOL CEffectFindTrapsMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectFindTrapsMod_ApplyEffect)(creTarget); }

//CEffectPickPocketsMod
void (CEffectPickPocketsMod::*CEffectPickPocketsMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectPickPocketsMod::*)()>					(&CEffectPickPocketsMod::Deconstruct),	0x5522A0);
CEffect& (CEffectPickPocketsMod::*CEffectPickPocketsMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectPickPocketsMod::*)()>				(&CEffectPickPocketsMod::Duplicate),	0x552170);
BOOL (CEffectPickPocketsMod::*CEffectPickPocketsMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectPickPocketsMod::*)(CCreatureObject&)>	(&CEffectPickPocketsMod::ApplyEffect),	0x51D688);

CEffectPickPocketsMod::~CEffectPickPocketsMod()						{ (this->*CEffectPickPocketsMod_Deconstruct)(); }
CEffect& CEffectPickPocketsMod::Duplicate()							{ return (this->*CEffectPickPocketsMod_Duplicate)(); }
BOOL CEffectPickPocketsMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectPickPocketsMod_ApplyEffect)(creTarget); }

//CEffectFatigueMod
void (CEffectFatigueMod::*CEffectFatigueMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectFatigueMod::*)()>					(&CEffectFatigueMod::Deconstruct),	0x552400);
CEffect& (CEffectFatigueMod::*CEffectFatigueMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectFatigueMod::*)()>				(&CEffectFatigueMod::Duplicate),	0x5522D0);
BOOL (CEffectFatigueMod::*CEffectFatigueMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectFatigueMod::*)(CCreatureObject&)>	(&CEffectFatigueMod::ApplyEffect),	0x51D8F0);

CEffectFatigueMod::~CEffectFatigueMod()							{ (this->*CEffectFatigueMod_Deconstruct)(); }
CEffect& CEffectFatigueMod::Duplicate()							{ return (this->*CEffectFatigueMod_Duplicate)(); }
BOOL CEffectFatigueMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectFatigueMod_ApplyEffect)(creTarget); }

//CEffectIntoxicationMod
void (CEffectIntoxicationMod::*CEffectIntoxicationMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectIntoxicationMod::*)()>					(&CEffectIntoxicationMod::Deconstruct),	0x552560);
CEffect& (CEffectIntoxicationMod::*CEffectIntoxicationMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectIntoxicationMod::*)()>				(&CEffectIntoxicationMod::Duplicate),	0x552430);
BOOL (CEffectIntoxicationMod::*CEffectIntoxicationMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectIntoxicationMod::*)(CCreatureObject&)>	(&CEffectIntoxicationMod::ApplyEffect),	0x51DBB0);

CEffectIntoxicationMod::~CEffectIntoxicationMod()						{ (this->*CEffectIntoxicationMod_Deconstruct)(); }
CEffect& CEffectIntoxicationMod::Duplicate()							{ return (this->*CEffectIntoxicationMod_Duplicate)(); }
BOOL CEffectIntoxicationMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectIntoxicationMod_ApplyEffect)(creTarget); }

//CEffectTrackingMod
void (CEffectTrackingMod::*CEffectTrackingMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectTrackingMod::*)()>					(&CEffectTrackingMod::Deconstruct),	0x5526C0);
CEffect& (CEffectTrackingMod::*CEffectTrackingMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectTrackingMod::*)()>				(&CEffectTrackingMod::Duplicate),	0x552590);
BOOL (CEffectTrackingMod::*CEffectTrackingMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectTrackingMod::*)(CCreatureObject&)>	(&CEffectTrackingMod::ApplyEffect),	0x51DE70);

CEffectTrackingMod::~CEffectTrackingMod()							{ (this->*CEffectTrackingMod_Deconstruct)(); }
CEffect& CEffectTrackingMod::Duplicate()							{ return (this->*CEffectTrackingMod_Duplicate)(); }
BOOL CEffectTrackingMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectTrackingMod_ApplyEffect)(creTarget); }

//CEffectLevelMod
void (CEffectLevelMod::*CEffectLevelMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectLevelMod::*)()>					(&CEffectLevelMod::Deconstruct),0x552820);
CEffect& (CEffectLevelMod::*CEffectLevelMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectLevelMod::*)()>				(&CEffectLevelMod::Duplicate),	0x5526F0);
BOOL (CEffectLevelMod::*CEffectLevelMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectLevelMod::*)(CCreatureObject&)>	(&CEffectLevelMod::ApplyEffect),0x51E36C);

CEffectLevelMod::~CEffectLevelMod()								{ (this->*CEffectLevelMod_Deconstruct)(); }
CEffect& CEffectLevelMod::Duplicate()							{ return (this->*CEffectLevelMod_Duplicate)(); }
BOOL CEffectLevelMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectLevelMod_ApplyEffect)(creTarget); }

//CEffectStrengthExMod
void (CEffectStrengthExMod::*CEffectStrengthExMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectStrengthExMod::*)()>					(&CEffectStrengthExMod::Deconstruct),	0x552980);
CEffect& (CEffectStrengthExMod::*CEffectStrengthExMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectStrengthExMod::*)()>				(&CEffectStrengthExMod::Duplicate),		0x552850);
BOOL (CEffectStrengthExMod::*CEffectStrengthExMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectStrengthExMod::*)(CCreatureObject&)>	(&CEffectStrengthExMod::ApplyEffect),	0x51E0AC);

CEffectStrengthExMod::~CEffectStrengthExMod()						{ (this->*CEffectStrengthExMod_Deconstruct)(); }
CEffect& CEffectStrengthExMod::Duplicate()							{ return (this->*CEffectStrengthExMod_Duplicate)(); }
BOOL CEffectStrengthExMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectStrengthExMod_ApplyEffect)(creTarget); }

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

//CEffectMoraleBreakMod
void (CEffectMoraleBreakMod::*CEffectMoraleBreakMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectMoraleBreakMod::*)()>					(&CEffectMoraleBreakMod::Deconstruct),	0x5535E0);
CEffect& (CEffectMoraleBreakMod::*CEffectMoraleBreakMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectMoraleBreakMod::*)()>				(&CEffectMoraleBreakMod::Duplicate),	0x5534B0);
BOOL (CEffectMoraleBreakMod::*CEffectMoraleBreakMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectMoraleBreakMod::*)(CCreatureObject&)>	(&CEffectMoraleBreakMod::ApplyEffect),	0x51F080);

CEffectMoraleBreakMod::~CEffectMoraleBreakMod()						{ (this->*CEffectMoraleBreakMod_Deconstruct)(); }
CEffect& CEffectMoraleBreakMod::Duplicate()							{ return (this->*CEffectMoraleBreakMod_Duplicate)(); }
BOOL CEffectMoraleBreakMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectMoraleBreakMod_ApplyEffect)(creTarget); }

//CEffectReputationMod
void (CEffectReputationMod::*CEffectReputationMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectReputationMod::*)()>					(&CEffectReputationMod::Deconstruct),	0x5538A0);
CEffect& (CEffectReputationMod::*CEffectReputationMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectReputationMod::*)()>				(&CEffectReputationMod::Duplicate),		0x553770);
BOOL (CEffectReputationMod::*CEffectReputationMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectReputationMod::*)(CCreatureObject&)>	(&CEffectReputationMod::ApplyEffect),	0x51F4C1);

CEffectReputationMod::~CEffectReputationMod()						{ (this->*CEffectReputationMod_Deconstruct)(); }
CEffect& CEffectReputationMod::Duplicate()							{ return (this->*CEffectReputationMod_Duplicate)(); }
BOOL CEffectReputationMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectReputationMod_ApplyEffect)(creTarget); }

//CEffectAid
void (CEffectAid::*CEffectAid_Deconstruct)() =
	SetFP(static_cast<void (CEffectAid::*)()>					(&CEffectAid::Deconstruct),	0x555C80);
CEffect& (CEffectAid::*CEffectAid_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectAid::*)()>				(&CEffectAid::Duplicate),	0x555B50);
BOOL (CEffectAid::*CEffectAid_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAid::*)(CCreatureObject&)>	(&CEffectAid::ApplyEffect),	0x52720A);

CEffectAid::~CEffectAid()									{ (this->*CEffectAid_Deconstruct)(); }
CEffect& CEffectAid::Duplicate()							{ return (this->*CEffectAid_Duplicate)(); }
BOOL CEffectAid::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectAid_ApplyEffect)(creTarget); }

//CEffectBless
void (CEffectBless::*CEffectBless_Deconstruct)() =
	SetFP(static_cast<void (CEffectBless::*)()>					(&CEffectBless::Deconstruct),	0x555B20);
CEffect& (CEffectBless::*CEffectBless_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectBless::*)()>				(&CEffectBless::Duplicate),		0x5559F0);
BOOL (CEffectBless::*CEffectBless_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectBless::*)(CCreatureObject&)>	(&CEffectBless::ApplyEffect),	0x5273F7);

CEffectBless::~CEffectBless()								{ (this->*CEffectBless_Deconstruct)(); }
CEffect& CEffectBless::Duplicate()							{ return (this->*CEffectBless_Duplicate)(); }
BOOL CEffectBless::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectBless_ApplyEffect)(creTarget); }

//CEffectChant
void (CEffectChant::*CEffectChant_Deconstruct)() =
	SetFP(static_cast<void (CEffectChant::*)()>					(&CEffectChant::Deconstruct),	0x555DE0);
CEffect& (CEffectChant::*CEffectChant_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectChant::*)()>				(&CEffectChant::Duplicate),		0x555CB0);
BOOL (CEffectChant::*CEffectChant_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectChant::*)(CCreatureObject&)>	(&CEffectChant::ApplyEffect),	0x527499);

CEffectChant::~CEffectChant()								{ (this->*CEffectChant_Deconstruct)(); }
CEffect& CEffectChant::Duplicate()							{ return (this->*CEffectChant_Duplicate)(); }
BOOL CEffectChant::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectChant_ApplyEffect)(creTarget); }

//CEffectHolyMight
void (CEffectHolyMight::*CEffectHolyMight_Deconstruct)() =
	SetFP(static_cast<void (CEffectHolyMight::*)()>					(&CEffectHolyMight::Deconstruct),	0x5560A0);
CEffect& (CEffectHolyMight::*CEffectHolyMight_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectHolyMight::*)()>				(&CEffectHolyMight::Duplicate),		0x555F70);
BOOL (CEffectHolyMight::*CEffectHolyMight_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectHolyMight::*)(CCreatureObject&)>	(&CEffectHolyMight::ApplyEffect),	0x527563);

CEffectHolyMight::~CEffectHolyMight()							{ (this->*CEffectHolyMight_Deconstruct)(); }
CEffect& CEffectHolyMight::Duplicate()							{ return (this->*CEffectHolyMight_Duplicate)(); }
BOOL CEffectHolyMight::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectHolyMight_ApplyEffect)(creTarget); }

//CEffectChantBad
void (CEffectChantBad::*CEffectChantBad_Deconstruct)() =
	SetFP(static_cast<void (CEffectChantBad::*)()>					(&CEffectChantBad::Deconstruct),	0x555F40);
CEffect& (CEffectChantBad::*CEffectChantBad_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectChantBad::*)()>				(&CEffectChantBad::Duplicate),		0x555E10);
BOOL (CEffectChantBad::*CEffectChantBad_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectChantBad::*)(CCreatureObject&)>	(&CEffectChantBad::ApplyEffect),	0x5274FE);

CEffectChantBad::~CEffectChantBad()								{ (this->*CEffectChantBad_Deconstruct)(); }
CEffect& CEffectChantBad::Duplicate()							{ return (this->*CEffectChantBad_Duplicate)(); }
BOOL CEffectChantBad::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectChantBad_ApplyEffect)(creTarget); }

//CEffectDisableSpelltype
void (CEffectDisableSpelltype::*CEffectDisableSpelltype_Deconstruct)() =
	SetFP(static_cast<void (CEffectDisableSpelltype::*)()>					(&CEffectDisableSpelltype::Deconstruct),	0x557280);
CEffect& (CEffectDisableSpelltype::*CEffectDisableSpelltype_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectDisableSpelltype::*)()>				(&CEffectDisableSpelltype::Duplicate),		0x557150);
BOOL (CEffectDisableSpelltype::*CEffectDisableSpelltype_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDisableSpelltype::*)(CCreatureObject&)>	(&CEffectDisableSpelltype::ApplyEffect),	0x52BA62);

CEffectDisableSpelltype::~CEffectDisableSpelltype()						{ (this->*CEffectDisableSpelltype_Deconstruct)(); }
CEffect& CEffectDisableSpelltype::Duplicate()							{ return (this->*CEffectDisableSpelltype_Duplicate)(); }
BOOL CEffectDisableSpelltype::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectDisableSpelltype_ApplyEffect)(creTarget); }

//CEffectDisableButton
void (CEffectDisableButton::*CEffectDisableButton_Deconstruct)() =
	SetFP(static_cast<void (CEffectDisableButton::*)()>					(&CEffectDisableButton::Deconstruct),	0x556FC0);
CEffect& (CEffectDisableButton::*CEffectDisableButton_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectDisableButton::*)()>				(&CEffectDisableButton::Duplicate),		0x556E90);
BOOL (CEffectDisableButton::*CEffectDisableButton_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDisableButton::*)(CCreatureObject&)>	(&CEffectDisableButton::ApplyEffect),	0x52B97B);

CEffectDisableButton::~CEffectDisableButton()						{ (this->*CEffectDisableButton_Deconstruct)(); }
CEffect& CEffectDisableButton::Duplicate()							{ return (this->*CEffectDisableButton_Duplicate)(); }
BOOL CEffectDisableButton::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectDisableButton_ApplyEffect)(creTarget); }

//CEffectCastSpell
void (CEffectCastSpell::*CEffectCastSpell_Deconstruct)() =
	SetFP(static_cast<void (CEffectCastSpell::*)()>					(&CEffectCastSpell::Deconstruct),	0x5573E0);
CEffect& (CEffectCastSpell::*CEffectCastSpell_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectCastSpell::*)()>				(&CEffectCastSpell::Duplicate),		0x5572B0);
BOOL (CEffectCastSpell::*CEffectCastSpell_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCastSpell::*)(CCreatureObject&)>	(&CEffectCastSpell::ApplyEffect),	0x52BD1B);

CEffectCastSpell::~CEffectCastSpell()							{ (this->*CEffectCastSpell_Deconstruct)(); }
CEffect& CEffectCastSpell::Duplicate()							{ return (this->*CEffectCastSpell_Duplicate)(); }
BOOL CEffectCastSpell::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectCastSpell_ApplyEffect)(creTarget); }

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

//CEffectUseEFFFile
void (CEffectUseEFFFile::*CEffectUseEFFFile_Deconstruct)() =
	SetFP(static_cast<void (CEffectUseEFFFile::*)()>				(&CEffectUseEFFFile::Deconstruct),	0x559380);
CEffect& (CEffectUseEFFFile::*CEffectUseEFFFile_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectUseEFFFile::*)()>			(&CEffectUseEFFFile::Duplicate),	0x559250);
BOOL (CEffectUseEFFFile::*CEffectUseEFFFile_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectUseEFFFile::*)(CCreatureObject&)>(&CEffectUseEFFFile::ApplyEffect),	0x52FBAE);
void (CEffectUseEFFFile::*CEffectUseEFFFile_OnRemove)(CCreatureObject&) =
	SetFP(static_cast<void (CEffectUseEFFFile::*)(CCreatureObject&)>(&CEffectUseEFFFile::OnRemove),		0x52FACD);

CEffectUseEFFFile::~CEffectUseEFFFile()							{ (this->*CEffectUseEFFFile_Deconstruct)(); }
CEffect& CEffectUseEFFFile::Duplicate()							{ return (this->*CEffectUseEFFFile_Duplicate)(); }
BOOL CEffectUseEFFFile::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectUseEFFFile_ApplyEffect)(creTarget); }
void CEffectUseEFFFile::OnRemove(CCreatureObject& creTarget)	{ return (this->*CEffectUseEFFFile_OnRemove)(creTarget); }

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

//CEffectProficiencyMod
void (CEffectProficiencyMod::*CEffectProficiencyMod_Deconstruct)() =
	SetFP(static_cast<void (CEffectProficiencyMod::*)()>					(&CEffectProficiencyMod::Deconstruct),	0x55DE80);
CEffect& (CEffectProficiencyMod::*CEffectProficiencyMod_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectProficiencyMod::*)()>				(&CEffectProficiencyMod::Duplicate),	0x55DD50);
BOOL (CEffectProficiencyMod::*CEffectProficiencyMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectProficiencyMod::*)(CCreatureObject&)>	(&CEffectProficiencyMod::ApplyEffect),	0x53B776);

CEffectProficiencyMod::~CEffectProficiencyMod()						{ (this->*CEffectProficiencyMod_Deconstruct)(); }
CEffect& CEffectProficiencyMod::Duplicate()							{ return (this->*CEffectProficiencyMod_Duplicate)(); }
BOOL CEffectProficiencyMod::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectProficiencyMod_ApplyEffect)(creTarget); }

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

//CEffectEnableButton
void (CEffectEnableButton::*CEffectEnableButton_Deconstruct)() =
	SetFP(static_cast<void (CEffectEnableButton::*)()>					(&CEffectEnableButton::Deconstruct),	0x557120);
CEffect& (CEffectEnableButton::*CEffectEnableButton_Duplicate)() =
	SetFP(static_cast<CEffect& (CEffectEnableButton::*)()>				(&CEffectEnableButton::Duplicate),		0x556FF0);
BOOL (CEffectEnableButton::*CEffectEnableButton_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectEnableButton::*)(CCreatureObject&)>	(&CEffectEnableButton::ApplyEffect),	0x52B9AA);

CEffectEnableButton::~CEffectEnableButton()							{ (this->*CEffectEnableButton_Deconstruct)(); }
CEffect& CEffectEnableButton::Duplicate()							{ return (this->*CEffectEnableButton_Duplicate)(); }
BOOL CEffectEnableButton::ApplyEffect(CCreatureObject& creTarget)	{ return (this->*CEffectEnableButton_ApplyEffect)(creTarget); }

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
