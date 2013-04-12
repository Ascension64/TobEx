#ifndef EFFECTOPCODE_H
#define EFFECTOPCODE_H

#include "effopcode.h"
#include "stdafx.h"
#include "objcre.h"

//CEffectAttacksPerRoundMod
DeclareTrampMemberFunc(BOOL, CEffectAttacksPerRoundMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectAttacksPerRoundMod : public CEffectAttacksPerRoundMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectCharismaMod
DeclareTrampMemberFunc(BOOL, CEffectCharismaMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectCharismaMod : public CEffectCharismaMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectConstitutionMod
DeclareTrampMemberFunc(BOOL, CEffectConstitutionMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectConstitutionMod : public CEffectConstitutionMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDamage
DeclareTrampMemberFunc(BOOL, CEffectDamage, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectDamage : public CEffectDamage {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDexterityMod
DeclareTrampMemberFunc(BOOL, CEffectDexterityMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectDexterityMod : public CEffectDexterityMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectIntelligenceMod
DeclareTrampMemberFunc(BOOL, CEffectIntelligenceMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectIntelligenceMod : public CEffectIntelligenceMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectLoreMod
DeclareTrampMemberFunc(BOOL, CEffectLoreMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectLoreMod : public CEffectLoreMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectLuckMod
DeclareTrampMemberFunc(BOOL, CEffectLuckMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectLuckMod : public CEffectLuckMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPoison
DeclareTrampMemberFunc(BOOL, CEffectPoison, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectPoison : public CEffectPoison {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsDeathMod
DeclareTrampMemberFunc(BOOL, CEffectSaveVsDeathMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectSaveVsDeathMod : public CEffectSaveVsDeathMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsWandsMod
DeclareTrampMemberFunc(BOOL, CEffectSaveVsWandsMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectSaveVsWandsMod : public CEffectSaveVsWandsMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsPolyMod
DeclareTrampMemberFunc(BOOL, CEffectSaveVsPolyMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectSaveVsPolyMod : public CEffectSaveVsPolyMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsBreathMod
DeclareTrampMemberFunc(BOOL, CEffectSaveVsBreathMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectSaveVsBreathMod : public CEffectSaveVsBreathMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSaveVsSpellMod
DeclareTrampMemberFunc(BOOL, CEffectSaveVsSpellMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectSaveVsSpellMod : public CEffectSaveVsSpellMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectMageMemSpellMod
DeclareTrampMemberFunc(BOOL, CEffectMageMemSpellMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectMageMemSpellMod : public CEffectMageMemSpellMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectStrengthMod
DeclareTrampMemberFunc(BOOL, CEffectStrengthMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectStrengthMod : public CEffectStrengthMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectWisdomMod
DeclareTrampMemberFunc(BOOL, CEffectWisdomMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectWisdomMod : public CEffectWisdomMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDispel
DeclareTrampMemberFunc(BOOL, CEffectDispel, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectDispel : public CEffectDispel {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectStealthMod
DeclareTrampMemberFunc(BOOL, CEffectStealthMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectStealthMod : public CEffectStealthMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPriestMemSpellMod
DeclareTrampMemberFunc(BOOL, CEffectPriestMemSpellMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectPriestMemSpellMod : public CEffectPriestMemSpellMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectBlindness
DeclareTrampMemberFunc(BOOL, CEffectBlindness, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectBlindness : public CEffectBlindness {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDisease
DeclareTrampMemberFunc(BOOL, CEffectDisease, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectDisease : public CEffectDisease {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectOpenLocksMod
DeclareTrampMemberFunc(BOOL, CEffectOpenLocksMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectOpenLocksMod : public CEffectOpenLocksMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectFindTrapsMod
DeclareTrampMemberFunc(BOOL, CEffectFindTrapsMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectFindTrapsMod : public CEffectFindTrapsMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPickPocketsMod
DeclareTrampMemberFunc(BOOL, CEffectPickPocketsMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectPickPocketsMod : public CEffectPickPocketsMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectFatigueMod
DeclareTrampMemberFunc(BOOL, CEffectFatigueMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectFatigueMod : public CEffectFatigueMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectIntoxicationMod
DeclareTrampMemberFunc(BOOL, CEffectIntoxicationMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectIntoxicationMod : public CEffectIntoxicationMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectTrackingMod
DeclareTrampMemberFunc(BOOL, CEffectTrackingMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectTrackingMod : public CEffectTrackingMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectLevelMod
DeclareTrampMemberFunc(BOOL, CEffectLevelMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectLevelMod : public CEffectLevelMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectStrengthExMod
DeclareTrampMemberFunc(BOOL, CEffectStrengthExMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectStrengthExMod : public CEffectStrengthExMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectRegeneration
DeclareTrampMemberFunc(BOOL, CEffectRegeneration, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectRegeneration : public CEffectRegeneration {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectMoraleBreakMod
DeclareTrampMemberFunc(BOOL, CEffectMoraleBreakMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectMoraleBreakMod : public CEffectMoraleBreakMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectReputationMod
DeclareTrampMemberFunc(BOOL, CEffectReputationMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectReputationMod : public CEffectReputationMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectAid
DeclareTrampMemberFunc(BOOL, CEffectAid, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectAid : public CEffectAid {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectBless
DeclareTrampMemberFunc(BOOL, CEffectBless, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectBless : public CEffectBless {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectChant
DeclareTrampMemberFunc(BOOL, CEffectChant, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectChant : public CEffectChant {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectHolyMight
DeclareTrampMemberFunc(BOOL, CEffectHolyMight, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectHolyMight : public CEffectHolyMight {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectChantBad
DeclareTrampMemberFunc(BOOL, CEffectChantBad, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectChantBad : public CEffectChantBad {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDisableSpelltype
DeclareTrampMemberFunc(BOOL, CEffectDisableSpelltype, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectDisableSpelltype : public CEffectDisableSpelltype {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDisableButton
DeclareTrampMemberFunc(BOOL, CEffectDisableButton, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectDisableButton : public CEffectDisableButton {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectLearnSpell
DeclareTrampMemberFunc(BOOL, CEffectLearnSpell, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectLearnSpell : public CEffectLearnSpell {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectMagicResistMod
DeclareTrampMemberFunc(BOOL, CEffectMagicResistMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectMagicResistMod : public CEffectMagicResistMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPoisonResistMod
DeclareTrampMemberFunc(BOOL, CEffectPoisonResistMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectPoisonResistMod : public CEffectPoisonResistMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectUseEFFFile
DeclareTrampMemberFunc(BOOL, CEffectUseEFFFile, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectUseEFFFile : public CEffectUseEFFFile {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectCastSpellOnCondition
DeclareTrampMemberFunc(BOOL, CEffectCastSpellOnCondition, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectCastSpellOnCondition : public CEffectCastSpellOnCondition {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectProficiencyMod
DeclareTrampMemberFunc(BOOL, CEffectProficiencyMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectProficiencyMod : public CEffectProficiencyMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectRepeatingEff
DeclareTrampMemberFunc(CEffectRepeatingEff&, CEffectRepeatingEff, Construct, (ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY), Construct5);
DeclareTrampMemberFunc(BOOL, CEffectRepeatingEff, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectRepeatingEff : public CEffectRepeatingEff {
public:
	CEffectRepeatingEff& DETOUR_Construct(ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY);
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectWingBuffet
DeclareTrampMemberFunc(BOOL, CEffectWingBuffet, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectWingBuffet : public CEffectWingBuffet {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDisintegrate
DeclareTrampMemberFunc(BOOL, CEffectDisintegrate, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectDisintegrate : public CEffectDisintegrate {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectRemoveProjectile
DeclareTrampMemberFunc(BOOL, CEffectRemoveProjectile, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectRemoveProjectile : public CEffectRemoveProjectile {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectEnableButton
DeclareTrampMemberFunc(BOOL, CEffectEnableButton, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectEnableButton : public CEffectEnableButton {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectCutScene2
DeclareTrampMemberFunc(BOOL, CEffectCutScene2, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectCutScene2 : public CEffectCutScene2 {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectAnimationRemoval
DeclareTrampMemberFunc(BOOL, CEffectAnimationRemoval, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect);

class DETOUR_CEffectAnimationRemoval : public CEffectAnimationRemoval {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectSetStat
class CEffectSetStat : public CEffect {
public:
	CEffectSetStat(ItmFileEffect&, CPoint&, ENUM, int, int, BOOL, ENUM);

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

void __stdcall CEffectPolymorph_ApplyEffect_ReinitAnimation(CEffect& eff, CCreatureObject& creTarget, CCreatureObject& creNew);

#endif //EFFECTOPCODE_H