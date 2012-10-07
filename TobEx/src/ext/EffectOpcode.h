#ifndef EFFECTOPCODE_H
#define EFFECTOPCODE_H

#include "effopcode.h"
#include "stdafx.h"
#include "objcre.h"

//CEffectAttacksPerRoundMod
extern BOOL (CEffectAttacksPerRoundMod::*Tramp_CEffectAttacksPerRoundMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectAttacksPerRoundMod : public CEffectAttacksPerRoundMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectCharismaMod
extern BOOL (CEffectCharismaMod::*Tramp_CEffectCharismaMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectCharismaMod : public CEffectCharismaMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectConstitutionMod
extern BOOL (CEffectConstitutionMod::*Tramp_CEffectConstitutionMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectConstitutionMod : public CEffectConstitutionMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDamage
extern BOOL (CEffectDamage::*Tramp_CEffectDamage_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDamage : public CEffectDamage {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDexterityMod
extern BOOL (CEffectDexterityMod::*Tramp_CEffectDexterityMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDexterityMod : public CEffectDexterityMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectIntelligenceMod
extern BOOL (CEffectIntelligenceMod::*Tramp_CEffectIntelligenceMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectIntelligenceMod : public CEffectIntelligenceMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectLoreMod
extern BOOL (CEffectLoreMod::*Tramp_CEffectLoreMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectLoreMod : public CEffectLoreMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectLuckMod
extern BOOL (CEffectLuckMod::*Tramp_CEffectLuckMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectLuckMod : public CEffectLuckMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPoison
extern BOOL (CEffectPoison::*Tramp_CEffectPoison_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectPoison : public CEffectPoison {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsDeathMod
extern BOOL (CEffectSaveVsDeathMod::*Tramp_CEffectSaveVsDeathMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectSaveVsDeathMod : public CEffectSaveVsDeathMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsWandsMod
extern BOOL (CEffectSaveVsWandsMod::*Tramp_CEffectSaveVsWandsMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectSaveVsWandsMod : public CEffectSaveVsWandsMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsPolyMod
extern BOOL (CEffectSaveVsPolyMod::*Tramp_CEffectSaveVsPolyMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectSaveVsPolyMod : public CEffectSaveVsPolyMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsBreathMod
extern BOOL (CEffectSaveVsBreathMod::*Tramp_CEffectSaveVsBreathMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectSaveVsBreathMod : public CEffectSaveVsBreathMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsSpellMod
extern BOOL (CEffectSaveVsSpellMod::*Tramp_CEffectSaveVsSpellMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectSaveVsSpellMod : public CEffectSaveVsSpellMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectMageMemSpellMod
extern BOOL (CEffectMageMemSpellMod::*Tramp_CEffectMageMemSpellMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectMageMemSpellMod : public CEffectMageMemSpellMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectStrengthMod
extern BOOL (CEffectStrengthMod::*Tramp_CEffectStrengthMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectStrengthMod : public CEffectStrengthMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectWisdomMod
extern BOOL (CEffectWisdomMod::*Tramp_CEffectWisdomMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectWisdomMod : public CEffectWisdomMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDispel
extern BOOL (CEffectDispel::*Tramp_CEffectDispel_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDispel : public CEffectDispel {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectStealthMod
extern BOOL (CEffectStealthMod::*Tramp_CEffectStealthMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectStealthMod : public CEffectStealthMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPriestMemSpellMod
extern BOOL (CEffectPriestMemSpellMod::*Tramp_CEffectPriestMemSpellMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectPriestMemSpellMod : public CEffectPriestMemSpellMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectBlindness
extern BOOL (CEffectBlindness::*Tramp_CEffectBlindness_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectBlindness : public CEffectBlindness {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDisease
extern BOOL (CEffectDisease::*Tramp_CEffectDisease_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDisease : public CEffectDisease {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectOpenLocksMod
extern BOOL (CEffectOpenLocksMod::*Tramp_CEffectOpenLocksMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectOpenLocksMod : public CEffectOpenLocksMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectFindTrapsMod
extern BOOL (CEffectFindTrapsMod::*Tramp_CEffectFindTrapsMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectFindTrapsMod : public CEffectFindTrapsMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPickPocketsMod
extern BOOL (CEffectPickPocketsMod::*Tramp_CEffectPickPocketsMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectPickPocketsMod : public CEffectPickPocketsMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectFatigueMod
extern BOOL (CEffectFatigueMod::*Tramp_CEffectFatigueMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectFatigueMod : public CEffectFatigueMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectIntoxicationMod
extern BOOL (CEffectIntoxicationMod::*Tramp_CEffectIntoxicationMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectIntoxicationMod : public CEffectIntoxicationMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectTrackingMod
extern BOOL (CEffectTrackingMod::*Tramp_CEffectTrackingMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectTrackingMod : public CEffectTrackingMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectLevelMod
extern BOOL (CEffectLevelMod::*Tramp_CEffectLevelMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectLevelMod : public CEffectLevelMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectStrengthExMod
extern BOOL (CEffectStrengthExMod::*Tramp_CEffectStrengthExMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectStrengthExMod : public CEffectStrengthExMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectRegeneration
extern BOOL (CEffectRegeneration::*Tramp_CEffectRegeneration_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectRegeneration : public CEffectRegeneration {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectMoraleBreakMod
extern BOOL (CEffectMoraleBreakMod::*Tramp_CEffectMoraleBreakMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectMoraleBreakMod : public CEffectMoraleBreakMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectReputationMod
extern BOOL (CEffectReputationMod::*Tramp_CEffectReputationMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectReputationMod : public CEffectReputationMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectAid
extern BOOL (CEffectAid::*Tramp_CEffectAid_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectAid : public CEffectAid {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectBless
extern BOOL (CEffectBless::*Tramp_CEffectBless_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectBless : public CEffectBless {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectChant
extern BOOL (CEffectChant::*Tramp_CEffectChant_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectChant : public CEffectChant {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectHolyMight
extern BOOL (CEffectHolyMight::*Tramp_CEffectHolyMight_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectHolyMight : public CEffectHolyMight {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectChantBad
extern BOOL (CEffectChantBad::*Tramp_CEffectChantBad_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectChantBad : public CEffectChantBad {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDisableSpelltype
extern BOOL (CEffectDisableSpelltype::*Tramp_CEffectDisableSpelltype_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDisableSpelltype : public CEffectDisableSpelltype {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDisableButton
extern BOOL (CEffectDisableButton::*Tramp_CEffectDisableButton_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDisableButton : public CEffectDisableButton {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectLearnSpell
extern BOOL (CEffectLearnSpell::*Tramp_CEffectLearnSpell_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectLearnSpell : public CEffectLearnSpell {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectMagicResistMod
extern BOOL (CEffectMagicResistMod::*Tramp_CEffectMagicResistMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectMagicResistMod : public CEffectMagicResistMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPoisonResistMod
extern BOOL (CEffectPoisonResistMod::*Tramp_CEffectPoisonResistMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectPoisonResistMod : public CEffectPoisonResistMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectUseEFFFile
extern BOOL (CEffectUseEFFFile::*Tramp_CEffectUseEFFFile_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectUseEFFFile : public CEffectUseEFFFile {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectCastSpellOnCondition
extern BOOL (CEffectCastSpellOnCondition::*Tramp_CEffectCastSpellOnCondition_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectCastSpellOnCondition : public CEffectCastSpellOnCondition {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectProficiencyMod
extern BOOL (CEffectProficiencyMod::*Tramp_CEffectProficiencyMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectProficiencyMod : public CEffectProficiencyMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectRepeatingEff
extern CEffectRepeatingEff& (CEffectRepeatingEff::*Tramp_CEffectRepeatingEff_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int);
extern BOOL (CEffectRepeatingEff::*Tramp_CEffectRepeatingEff_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectRepeatingEff : public CEffectRepeatingEff {
public:
	CEffectRepeatingEff& DETOUR_Construct(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY);
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectWingBuffet
extern BOOL (CEffectWingBuffet::*Tramp_CEffectWingBuffet_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectWingBuffet : public CEffectWingBuffet {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDisintegrate
extern BOOL (CEffectDisintegrate::*Tramp_CEffectDisintegrate_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDisintegrate : public CEffectDisintegrate {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectRemoveProjectile
extern BOOL (CEffectRemoveProjectile::*Tramp_CEffectRemoveProjectile_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectRemoveProjectile : public CEffectRemoveProjectile {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectEnableButton
extern BOOL (CEffectEnableButton::*Tramp_CEffectEnableButton_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectEnableButton : public CEffectEnableButton {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectCutScene2
extern BOOL (CEffectCutScene2::*Tramp_CEffectCutScene2_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectCutScene2 : public CEffectCutScene2 {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectAnimationRemoval
extern BOOL (CEffectAnimationRemoval::*Tramp_CEffectAnimationRemoval_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectAnimationRemoval : public CEffectAnimationRemoval {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSetStat
class CEffectSetStat : public CEffect {
public:
	CEffectSetStat(ITEM_EFFECT&, POINT&, Enum, int, int, BOOL, Enum);

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

void __stdcall CEffectPolymorph_ApplyEffect_ReinitAnimation(CEffect& eff, CCreatureObject& creTarget, CCreatureObject& creNew);

#endif //EFFECTOPCODE_H