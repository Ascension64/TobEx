#include "effopcode.h"

//CEffectAttacksPerRoundMod
DefineLibNoRetFunc(void, CEffectAttacksPerRoundMod, ~CEffectAttacksPerRoundMod, (), Deconstruct, Deconstruct, (), 0x54A080);
DefineLibMemberFunc(CEffect&, CEffectAttacksPerRoundMod, Copy, (), Copy, Copy, (), 0x549F50);
DefineLibMemberFunc(BOOL, CEffectAttacksPerRoundMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x5030F6);

//CEffectAwaken
DefineLibNoRetFunc(void, CEffectAwaken, ~CEffectAwaken, (), Deconstruct, Deconstruct, (), 0x54A1E0);
DefineLibMemberFunc(CEffect&, CEffectAwaken, Copy, (), Copy, Copy, (), 0x54A0B0);
DefineLibMemberFunc(BOOL, CEffectAwaken, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x503597);

//CEffectCharismaMod
DefineLibNoRetFunc(void, CEffectCharismaMod, ~CEffectCharismaMod, (), Deconstruct, Deconstruct, (), 0x54A7A0);
DefineLibMemberFunc(CEffect&, CEffectCharismaMod, Copy, (), Copy, Copy, (), 0x54A670);
DefineLibMemberFunc(BOOL, CEffectCharismaMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x5046EC);

//CEffectConstitutionMod
DefineLibNoRetFunc(void, CEffectConstitutionMod, ~CEffectConstitutionMod, (), Deconstruct, Deconstruct, (), 0x54B140);
DefineLibMemberFunc(CEffect&, CEffectConstitutionMod, Copy, (), Copy, Copy, (), 0x54B010);
DefineLibMemberFunc(BOOL, CEffectConstitutionMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x50515F);

//CEffectDamage
DefineLibNoRetFunc(void, CEffectDamage, ~CEffectDamage, (), Deconstruct, Deconstruct, (), 0x4947C0);
DefineLibMemberFunc(CEffect&, CEffectDamage, Copy, (), Copy, Copy, (), 0x494680);
DefineLibMemberFunc(BOOL, CEffectDamage, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x505570);
DefineLibMemberFunc(void, CEffectDamage, OnDelayFinished, (CCreatureObject& creTarget), OnDelayFinished, OnDelayFinished, (creTarget), 0x507A0E);
DefineLibMemberFunc(BOOL, CEffectDamage, CheckNotSaved, (
	CCreatureObject& creTarget,
	char& rollSaveDeath,
	char& rollSaveWands,
	char& rollSavePoly,
	char& rollSaveBreath,
	char& rollSaveSpells,
	char& rollMagicResist
	), CheckNotSaved, CheckNotSaved, (creTarget, rollSaveDeath, rollSaveWands, rollSavePoly, rollSaveBreath, rollSaveSpells, rollMagicResist), 0x507EBD);
DefineLibMemberFunc(BOOL, CEffectDamage, IgnoreLevelCheck, (), IgnoreLevelCheck, IgnoreLevelCheck, (), 0x494780);
DefineLibMemberFunc(void, CEffectDamage, PrintEffectText, (CCreatureObject& creTarget), PrintEffectText, PrintEffectText, (creTarget), 0x5081B3);
DefineLibMemberFunc(void, CEffectDamage, PrintEffectTextOnApply, (CCreatureObject& creTarget), PrintEffectTextOnApply, PrintEffectTextOnApply, (creTarget), 0x5083D0);
DefineLibMemberFunc(void, CEffectDamage, PlayHitSound, (unsigned int nDamageType, CCreatureObject& creTarget), PlayHitSound, PlayHitSound, (nDamageType, creTarget), 0x507240);

//CEffectInstantDeath
CEffectInstantDeath::CEffectInstantDeath() {
	SetVT(this, 0xAA6A5C);
	effect.nOpcode = CEFFECT_OPCODE_INSTANT_DEATH;
}

DefineLibNoRetFunc(void, CEffectInstantDeath, ~CEffectInstantDeath, (), Deconstruct, Deconstruct, (), 0x494920);
DefineLibMemberFunc(CEffect&, CEffectInstantDeath, Copy, (), Copy, Copy, (), 0x4947F0);
DefineLibMemberFunc(BOOL, CEffectInstantDeath, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x508FBC);
DefineLibMemberFunc(void, CEffectInstantDeath, OnDelayFinished, (CCreatureObject& creTarget), OnDelayFinished, OnDelayFinished, (creTarget), 0x50D8BE);
DefineLibMemberFunc(void, CEffectInstantDeath, PrintEffectText, (CCreatureObject& creTarget), PrintEffectText, PrintEffectText, (creTarget), 0x510D3D);

//CEffectDexterityMod
DefineLibNoRetFunc(void, CEffectDexterityMod, ~CEffectDexterityMod, (), Deconstruct, Deconstruct, (), 0x54B560);
DefineLibMemberFunc(CEffect&, CEffectDexterityMod, Copy, (), Copy, Copy, (), 0x54B430);
DefineLibMemberFunc(BOOL, CEffectDexterityMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x510DCF);

//CEffectCurrentHPMod
DefineLibNoRetFunc(void, CEffectCurrentHPMod, ~CEffectCurrentHPMod, (), Deconstruct, Deconstruct, (), 0x54B830);
DefineLibMemberFunc(CEffect&, CEffectCurrentHPMod, Copy, (), Copy, Copy, (), 0x54B6F0);
DefineLibMemberFunc(BOOL, CEffectCurrentHPMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x54B7F0);
DefineLibMemberFunc(BOOL, CEffectCurrentHPMod, IgnoreLevelCheck, (), IgnoreLevelCheck, IgnoreLevelCheck, (), 0x494780);

//CEffectIntelligenceMod
DefineLibNoRetFunc(void, CEffectIntelligenceMod, ~CEffectIntelligenceMod, (), Deconstruct, Deconstruct, (), 0x54BB00);
DefineLibMemberFunc(CEffect&, CEffectIntelligenceMod, Copy, (), Copy, Copy, (), 0x54B9D0);
DefineLibMemberFunc(BOOL, CEffectIntelligenceMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x5121DB);

//CEffectLoreMod
DefineLibNoRetFunc(void, CEffectLoreMod, ~CEffectLoreMod, (), Deconstruct, Deconstruct, (), 0x54BDC0);
DefineLibMemberFunc(CEffect&, CEffectLoreMod, Copy, (), Copy, Copy, (), 0x54BC90);
DefineLibMemberFunc(BOOL, CEffectLoreMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x512733);

//CEffectLuckMod
DefineLibNoRetFunc(void, CEffectLuckMod, ~CEffectLuckMod, (), Deconstruct, Deconstruct, (), 0x54BF20);
DefineLibMemberFunc(CEffect&, CEffectLuckMod, Copy, (), Copy, Copy, (), 0x54BDF0);
DefineLibMemberFunc(BOOL, CEffectLuckMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x5129F3);

//CEffectPoison
DefineLibNoRetFunc(void, CEffectPoison, ~CEffectPoison, (), Deconstruct, Deconstruct, (), 0x54C340);
DefineLibMemberFunc(CEffect&, CEffectPoison, Copy, (), Copy, Copy, (), 0x54C210);
DefineLibMemberFunc(BOOL, CEffectPoison, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x513024);
DefineLibMemberFunc(void, CEffectPoison, OnDelayFinished, (CCreatureObject& creTarget), OnDelayFinished, OnDelayFinished, (creTarget), 0x512EA1);

//CEffectSaveVsDeathMod
DefineLibNoRetFunc(void, CEffectSaveVsDeathMod, ~CEffectSaveVsDeathMod, (), Deconstruct, Deconstruct, (), 0x54CE40);
DefineLibMemberFunc(CEffect&, CEffectSaveVsDeathMod, Copy, (), Copy, Copy, (), 0x54CD10);
DefineLibMemberFunc(BOOL, CEffectSaveVsDeathMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x514B87);

//CEffectSaveVsWandsMod
DefineLibNoRetFunc(void, CEffectSaveVsWandsMod, ~CEffectSaveVsWandsMod, (), Deconstruct, Deconstruct, (), 0x54CFA0);
DefineLibMemberFunc(CEffect&, CEffectSaveVsWandsMod, Copy, (), Copy, Copy, (), 0x54CE70);
DefineLibMemberFunc(BOOL, CEffectSaveVsWandsMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x514E4C);

//CEffectSaveVsPolyMod
DefineLibNoRetFunc(void, CEffectSaveVsPolyMod, ~CEffectSaveVsPolyMod, (), Deconstruct, Deconstruct, (), 0x54D100);
DefineLibMemberFunc(CEffect&, CEffectSaveVsPolyMod, Copy, (), Copy, Copy, (), 0x54CFD0);
DefineLibMemberFunc(BOOL, CEffectSaveVsPolyMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x515111);

//CEffectSaveVsBreathMod
DefineLibNoRetFunc(void, CEffectSaveVsBreathMod, ~CEffectSaveVsBreathMod, (), Deconstruct, Deconstruct, (), 0x54D260);
DefineLibMemberFunc(CEffect&, CEffectSaveVsBreathMod, Copy, (), Copy, Copy, (), 0x54D130);
DefineLibMemberFunc(BOOL, CEffectSaveVsBreathMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x5153C7);

//CEffectSaveVsSpellMod
DefineLibNoRetFunc(void, CEffectSaveVsSpellMod, ~CEffectSaveVsSpellMod, (), Deconstruct, Deconstruct, (), 0x54D3C0);
DefineLibMemberFunc(CEffect&, CEffectSaveVsSpellMod, Copy, (), Copy, Copy, (), 0x54D290);
DefineLibMemberFunc(BOOL, CEffectSaveVsSpellMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51568C);

//CEffectMageMemSpellMod
DefineLibNoRetFunc(void, CEffectMageMemSpellMod, ~CEffectMageMemSpellMod, (), Deconstruct, Deconstruct, (), 0x54DAA0);
DefineLibMemberFunc(CEffect&, CEffectMageMemSpellMod, Copy, (), Copy, Copy, (), 0x54D970);
DefineLibMemberFunc(BOOL, CEffectMageMemSpellMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x5161AB);

//CEffectStrengthMod
DefineLibNoRetFunc(void, CEffectStrengthMod, ~CEffectStrengthMod, (), Deconstruct, Deconstruct, (), 0x54DEF0);
DefineLibMemberFunc(CEffect&, CEffectStrengthMod, Copy, (), Copy, Copy, (), 0x54DD90);
DefineLibMemberFunc(BOOL, CEffectStrengthMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x516673);

//CEffectWisdomMod
DefineLibNoRetFunc(void, CEffectWisdomMod, ~CEffectWisdomMod, (), Deconstruct, Deconstruct, (), 0x54E5D0);
DefineLibMemberFunc(CEffect&, CEffectWisdomMod, Copy, (), Copy, Copy, (), 0x54E4A0);
DefineLibMemberFunc(BOOL, CEffectWisdomMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x516DF1);

//CEffectDispel
DefineLibNoRetFunc(void, CEffectDispel, ~CEffectDispel, (), Deconstruct, Deconstruct, (), 0x54EE10);
DefineLibMemberFunc(CEffect&, CEffectDispel, Copy, (), Copy, Copy, (), 0x54ECE0);
DefineLibMemberFunc(BOOL, CEffectDispel, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x5184DA);

//CEffectStealthMod
DefineLibNoRetFunc(void, CEffectStealthMod, ~CEffectStealthMod, (), Deconstruct, Deconstruct, (), 0x54EF70);
DefineLibMemberFunc(CEffect&, CEffectStealthMod, Copy, (), Copy, Copy, (), 0x54EE40);
DefineLibMemberFunc(BOOL, CEffectStealthMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51877E);

//CEffectPriestMemSpellMod
DefineLibNoRetFunc(void, CEffectPriestMemSpellMod, ~CEffectPriestMemSpellMod, (), Deconstruct, Deconstruct, (), 0x54DC00);
DefineLibMemberFunc(CEffect&, CEffectPriestMemSpellMod, Copy, (), Copy, Copy, (), 0x54DAD0);
DefineLibMemberFunc(BOOL, CEffectPriestMemSpellMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x518AA3);

//CEffectBlindness
DefineLibNoRetFunc(void, CEffectBlindness, ~CEffectBlindness, (), Deconstruct, Deconstruct, (), 0x5509E0);
DefineLibMemberFunc(CEffect&, CEffectBlindness, Copy, (), Copy, Copy, (), 0x5508B0);
DefineLibMemberFunc(BOOL, CEffectBlindness, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51ADF9);

//CEffectDisease
DefineLibNoRetFunc(void, CEffectDisease, ~CEffectDisease, (), Deconstruct, Deconstruct, (), 0x550F60);
DefineLibMemberFunc(CEffect&, CEffectDisease, Copy, (), Copy, Copy, (), 0x550E30);
DefineLibMemberFunc(BOOL, CEffectDisease, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51B1FB);
DefineLibMemberFunc(void, CEffectDisease, OnDelayFinished, (CCreatureObject& creTarget), OnDelayFinished, OnDelayFinished, (creTarget), 0x51B078);

//CEffectOpenLocksMod
DefineLibNoRetFunc(void, CEffectOpenLocksMod, ~CEffectOpenLocksMod, (), Deconstruct, Deconstruct, (), 0x551FE0);
DefineLibMemberFunc(CEffect&, CEffectOpenLocksMod, Copy, (), Copy, Copy, (), 0x551EB0);
DefineLibMemberFunc(BOOL, CEffectOpenLocksMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51D1B8);

//CEffectFindTrapsMod
DefineLibNoRetFunc(void, CEffectFindTrapsMod, ~CEffectFindTrapsMod, (), Deconstruct, Deconstruct, (), 0x552140);
DefineLibMemberFunc(CEffect&, CEffectFindTrapsMod, Copy, (), Copy, Copy, (), 0x552010);
DefineLibMemberFunc(BOOL, CEffectFindTrapsMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51D420);

//CEffectPickPocketsMod
DefineLibNoRetFunc(void, CEffectPickPocketsMod, ~CEffectPickPocketsMod, (), Deconstruct, Deconstruct, (), 0x5522A0);
DefineLibMemberFunc(CEffect&, CEffectPickPocketsMod, Copy, (), Copy, Copy, (), 0x552170);
DefineLibMemberFunc(BOOL, CEffectPickPocketsMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51D688);

//CEffectFatigueMod
DefineLibNoRetFunc(void, CEffectFatigueMod, ~CEffectFatigueMod, (), Deconstruct, Deconstruct, (), 0x552400);
DefineLibMemberFunc(CEffect&, CEffectFatigueMod, Copy, (), Copy, Copy, (), 0x5522D0);
DefineLibMemberFunc(BOOL, CEffectFatigueMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51D8F0);

//CEffectIntoxicationMod
DefineLibNoRetFunc(void, CEffectIntoxicationMod, ~CEffectIntoxicationMod, (), Deconstruct, Deconstruct, (), 0x552560);
DefineLibMemberFunc(CEffect&, CEffectIntoxicationMod, Copy, (), Copy, Copy, (), 0x552430);
DefineLibMemberFunc(BOOL, CEffectIntoxicationMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51DBB0);

//CEffectTrackingMod
DefineLibNoRetFunc(void, CEffectTrackingMod, ~CEffectTrackingMod, (), Deconstruct, Deconstruct, (), 0x5526C0);
DefineLibMemberFunc(CEffect&, CEffectTrackingMod, Copy, (), Copy, Copy, (), 0x552590);
DefineLibMemberFunc(BOOL, CEffectTrackingMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51DE70);

//CEffectLevelMod
DefineLibNoRetFunc(void, CEffectLevelMod, ~CEffectLevelMod, (), Deconstruct, Deconstruct, (), 0x552820);
DefineLibMemberFunc(CEffect&, CEffectLevelMod, Copy, (), Copy, Copy, (), 0x5526F0);
DefineLibMemberFunc(BOOL, CEffectLevelMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51E36C);

//CEffectStrengthExMod
DefineLibNoRetFunc(void, CEffectStrengthExMod, ~CEffectStrengthExMod, (), Deconstruct, Deconstruct, (), 0x552980);
DefineLibMemberFunc(CEffect&, CEffectStrengthExMod, Copy, (), Copy, Copy, (), 0x552850);
DefineLibMemberFunc(BOOL, CEffectStrengthExMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51E0AC);

//CEffectRegeneration
DefineLibNoRetFunc(void, CEffectRegeneration, ~CEffectRegeneration, (), Deconstruct, Deconstruct, (), 0x552AE0);
DefineLibMemberFunc(CEffect&, CEffectRegeneration, Copy, (), Copy, Copy, (), 0x5529B0);
DefineLibMemberFunc(BOOL, CEffectRegeneration, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51C615);
DefineLibMemberFunc(void, CEffectRegeneration, OnDelayFinished, (CCreatureObject& creTarget), OnDelayFinished, OnDelayFinished, (creTarget), 0x51C492);

//CEffectMoraleBreakMod
DefineLibNoRetFunc(void, CEffectMoraleBreakMod, ~CEffectMoraleBreakMod, (), Deconstruct, Deconstruct, (), 0x5535E0);
DefineLibMemberFunc(CEffect&, CEffectMoraleBreakMod, Copy, (), Copy, Copy, (), 0x5534B0);
DefineLibMemberFunc(BOOL, CEffectMoraleBreakMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51F080);

//CEffectReputationMod
DefineLibNoRetFunc(void, CEffectReputationMod, ~CEffectReputationMod, (), Deconstruct, Deconstruct, (), 0x5538A0);
DefineLibMemberFunc(CEffect&, CEffectReputationMod, Copy, (), Copy, Copy, (), 0x553770);
DefineLibMemberFunc(BOOL, CEffectReputationMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x51F4C1);

//CEffectAid
DefineLibNoRetFunc(void, CEffectAid, ~CEffectAid, (), Deconstruct, Deconstruct, (), 0x555C80);
DefineLibMemberFunc(CEffect&, CEffectAid, Copy, (), Copy, Copy, (), 0x555B50);
DefineLibMemberFunc(BOOL, CEffectAid, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x52720A);

//CEffectBless
DefineLibNoRetFunc(void, CEffectBless, ~CEffectBless, (), Deconstruct, Deconstruct, (), 0x555B20);
DefineLibMemberFunc(CEffect&, CEffectBless, Copy, (), Copy, Copy, (), 0x5559F0);
DefineLibMemberFunc(BOOL, CEffectBless, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x5273F7);

//CEffectChant
DefineLibNoRetFunc(void, CEffectChant, ~CEffectChant, (), Deconstruct, Deconstruct, (), 0x555DE0);
DefineLibMemberFunc(CEffect&, CEffectChant, Copy, (), Copy, Copy, (), 0x555CB0);
DefineLibMemberFunc(BOOL, CEffectChant, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x527499);

//CEffectHolyMight
DefineLibNoRetFunc(void, CEffectHolyMight, ~CEffectHolyMight, (), Deconstruct, Deconstruct, (), 0x5560A0);
DefineLibMemberFunc(CEffect&, CEffectHolyMight, Copy, (), Copy, Copy, (), 0x555F70);
DefineLibMemberFunc(BOOL, CEffectHolyMight, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x527563);

//CEffectChantBad
DefineLibNoRetFunc(void, CEffectChantBad, ~CEffectChantBad, (), Deconstruct, Deconstruct, (), 0x555F40);
DefineLibMemberFunc(CEffect&, CEffectChantBad, Copy, (), Copy, Copy, (), 0x555E10);
DefineLibMemberFunc(BOOL, CEffectChantBad, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x5274FE);

//CEffectDisableSpelltype
DefineLibNoRetFunc(void, CEffectDisableSpelltype, ~CEffectDisableSpelltype, (), Deconstruct, Deconstruct, (), 0x557280);
DefineLibMemberFunc(CEffect&, CEffectDisableSpelltype, Copy, (), Copy, Copy, (), 0x557150);
DefineLibMemberFunc(BOOL, CEffectDisableSpelltype, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x52BA62);

//CEffectDisableButton
DefineLibNoRetFunc(void, CEffectDisableButton, ~CEffectDisableButton, (), Deconstruct, Deconstruct, (), 0x556FC0);
DefineLibMemberFunc(CEffect&, CEffectDisableButton, Copy, (), Copy, Copy, (), 0x556E90);
DefineLibMemberFunc(BOOL, CEffectDisableButton, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x52B97B);

//CEffectCastSpell
DefineLibNoRetFunc(void, CEffectCastSpell, ~CEffectCastSpell, (), Deconstruct, Deconstruct, (), 0x5573E0);
DefineLibMemberFunc(CEffect&, CEffectCastSpell, Copy, (), Copy, Copy, (), 0x5572B0);
DefineLibMemberFunc(BOOL, CEffectCastSpell, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x52BD1B);

//CEffectLearnSpell
DefineLibNoRetFunc(void, CEffectLearnSpell, ~CEffectLearnSpell, (), Deconstruct, Deconstruct, (), 0x557540);
DefineLibMemberFunc(CEffect&, CEffectLearnSpell, Copy, (), Copy, Copy, (), 0x557410);
DefineLibMemberFunc(BOOL, CEffectLearnSpell, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x52C250);

//CEffectMagicResistMod
DefineLibNoRetFunc(void, CEffectMagicResistMod, ~CEffectMagicResistMod, (), Deconstruct, Deconstruct, (), 0x5585C0);
DefineLibMemberFunc(CEffect&, CEffectMagicResistMod, Copy, (), Copy, Copy, (), 0x558490);
DefineLibMemberFunc(BOOL, CEffectMagicResistMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x52EB97);

//CEffectPoisonResistMod
DefineLibNoRetFunc(void, CEffectPoisonResistMod, ~CEffectPoisonResistMod, (), Deconstruct, Deconstruct, (), 0x558F60);
DefineLibMemberFunc(CEffect&, CEffectPoisonResistMod, Copy, (), Copy, Copy, (), 0x558E30);
DefineLibMemberFunc(BOOL, CEffectPoisonResistMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x52F0A5);

//CEffectUseEFFFile
DefineLibNoRetFunc(void, CEffectUseEFFFile, ~CEffectUseEFFFile, (), Deconstruct, Deconstruct, (), 0x559380);
DefineLibMemberFunc(CEffect&, CEffectUseEFFFile, Copy, (), Copy, Copy, (), 0x559250);
DefineLibMemberFunc(BOOL, CEffectUseEFFFile, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x52FBAE);
DefineLibMemberFunc(void, CEffectUseEFFFile, OnRemove, (CCreatureObject& creTarget), OnRemove, OnRemove, (creTarget), 0x52FACD);

//CEffectCastSpellOnCondition
DefineLibNoRetFunc(void, CEffectCastSpellOnCondition, ~CEffectCastSpellOnCondition, (), Deconstruct, Deconstruct, (), 0x55DCE0);
DefineLibMemberFunc(CEffect&, CEffectCastSpellOnCondition, Copy, (), Copy, Copy, (), 0x55DBB0);
DefineLibMemberFunc(BOOL, CEffectCastSpellOnCondition, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x53AFB7);

//CEffectProficiencyMod
DefineLibNoRetFunc(void, CEffectProficiencyMod, ~CEffectProficiencyMod, (), Deconstruct, Deconstruct, (), 0x55DE80);
DefineLibMemberFunc(CEffect&, CEffectProficiencyMod, Copy, (), Copy, Copy, (), 0x55DD50);
DefineLibMemberFunc(BOOL, CEffectProficiencyMod, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x53B776);

//CEffectWingBuffet
DefineLibNoRetFunc(CEffectWingBuffet&, CEffectWingBuffet, CEffectWingBuffet, (ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY), Construct, Construct5, (eff, ptSource, eSource, ptDestX, ptDestY), 0x55E050);
DefineLibNoRetFunc(void, CEffectWingBuffet, ~CEffectWingBuffet, (), Deconstruct, Deconstruct, (), 0x55E1C0);
DefineLibMemberFunc(CEffect&, CEffectWingBuffet, Copy, (), Copy, Copy, (), 0x55E090);
DefineLibMemberFunc(BOOL, CEffectWingBuffet, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x53C791);
DefineLibMemberFunc(BOOL, CEffectWingBuffet, CheckNotSaved, (
	CCreatureObject& creTarget,
	char& rollSaveDeath,
	char& rollSaveWands,
	char& rollSavePoly,
	char& rollSaveBreath,
	char& rollSaveSpells,
	char& rollMagicResist
	), CheckNotSaved, CheckNotSaved, (creTarget, rollSaveDeath, rollSaveWands, rollSavePoly, rollSaveBreath, rollSaveSpells, rollMagicResist), 0x53C513);

//CEffectDisintegrate
DefineLibNoRetFunc(void, CEffectDisintegrate, ~CEffectDisintegrate, (), Deconstruct, Deconstruct, (), 0x55E730);
DefineLibMemberFunc(CEffect&, CEffectDisintegrate, Copy, (), Copy, Copy, (), 0x55E600);
DefineLibMemberFunc(BOOL, CEffectDisintegrate, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x53F01D);

//CEffectRepeatingEff
DefineLibNoRetFunc(CEffectRepeatingEff&, CEffectRepeatingEff, CEffectRepeatingEff, (ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY), Construct, Construct5, (eff, ptSource, eSource, ptDestX, ptDestY), 0x561AA0);
DefineLibNoRetFunc(void, CEffectRepeatingEff, ~CEffectRepeatingEff, (), Deconstruct, Deconstruct, (), 0x561C10);
DefineLibMemberFunc(CEffect&, CEffectRepeatingEff, Copy, (), Copy, Copy, (), 0x561AE0);
DefineLibMemberFunc(BOOL, CEffectRepeatingEff, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x541C3B);

//CEffectRemoveProjectile
DefineLibNoRetFunc(void, CEffectRemoveProjectile, ~CEffectRemoveProjectile, (), Deconstruct, Deconstruct, (), 0x55EB50);
DefineLibMemberFunc(CEffect&, CEffectRemoveProjectile, Copy, (), Copy, Copy, (), 0x55E9C0);
DefineLibMemberFunc(BOOL, CEffectRemoveProjectile, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x53F5D8);

//CEffectEnableButton
DefineLibNoRetFunc(void, CEffectEnableButton, ~CEffectEnableButton, (), Deconstruct, Deconstruct, (), 0x557120);
DefineLibMemberFunc(CEffect&, CEffectEnableButton, Copy, (), Copy, Copy, (), 0x556FF0);
DefineLibMemberFunc(BOOL, CEffectEnableButton, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x52B9AA);

//CEffectCutScene2
DefineLibNoRetFunc(void, CEffectCutScene2, ~CEffectCutScene2, (), Deconstruct, Deconstruct, (), 0x564310);
DefineLibMemberFunc(CEffect&, CEffectCutScene2, Copy, (), Copy, Copy, (), 0x5641E0);
DefineLibMemberFunc(BOOL, CEffectCutScene2, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x542815);

//CEffectAnimationRemoval
DefineLibNoRetFunc(void, CEffectAnimationRemoval, ~CEffectAnimationRemoval, (), Deconstruct, Deconstruct, (), 0x565E70);
DefineLibMemberFunc(CEffect&, CEffectAnimationRemoval, Copy, (), Copy, Copy, (), 0x565D40);
DefineLibMemberFunc(BOOL, CEffectAnimationRemoval, ApplyEffect, (CCreatureObject& creTarget), ApplyEffect, ApplyEffect, (creTarget), 0x549C0C);
