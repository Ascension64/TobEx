#ifndef EFFOPCODE_H
#define EFFOPCODE_H

#include "effcore.h"

#include "stdafx.h"
#include "objcre.h"

//CEffectAttacksPerRoundMod
class CEffectAttacksPerRoundMod : public CEffect { //opcode 1h
public:
	//AA9708
	virtual ~CEffectAttacksPerRoundMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectAttacksPerRoundMod::*CEffectAttacksPerRoundMod_Deconstruct)();
extern CEffect& (CEffectAttacksPerRoundMod::*CEffectAttacksPerRoundMod_Duplicate)();
extern BOOL (CEffectAttacksPerRoundMod::*CEffectAttacksPerRoundMod_ApplyEffect)(CCreatureObject&);

//CEffectAwaken
class CEffectAwaken : public CEffect { //opcode 2h
public:
	//AA96E0
	virtual ~CEffectAwaken(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectAwaken::*CEffectAwaken_Deconstruct)();
extern CEffect& (CEffectAwaken::*CEffectAwaken_Duplicate)();
extern BOOL (CEffectAwaken::*CEffectAwaken_ApplyEffect)(CCreatureObject&);

//CEffectCharismaMod
class CEffectCharismaMod : public CEffect { //opcode 6h
public:
	//AA9640
	virtual ~CEffectCharismaMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectCharismaMod::*CEffectCharismaMod_Deconstruct)();
extern CEffect& (CEffectCharismaMod::*CEffectCharismaMod_Duplicate)();
extern BOOL (CEffectCharismaMod::*CEffectCharismaMod_ApplyEffect)(CCreatureObject&);

//CEffectConstitutionMod
class CEffectConstitutionMod : public CEffect { //opcode Ah
public:
	//AA95A0
	virtual ~CEffectConstitutionMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectConstitutionMod::*CEffectConstitutionMod_Deconstruct)();
extern CEffect& (CEffectConstitutionMod::*CEffectConstitutionMod_Duplicate)();
extern BOOL (CEffectConstitutionMod::*CEffectConstitutionMod_ApplyEffect)(CCreatureObject&);

//CEffectDamage
#define EFFECTDAMAGE_BEHAVIOR_NORMAL		0x0
#define EFFECTDAMAGE_BEHAVIOR_SETVALUE		0x1
#define EFFECTDAMAGE_BEHAVIOR_SETPERCENT	0x2
#define EFFECTDAMAGE_BEHAVIOR_LOSEPERCENT	0x3

class CEffectDamage : public CEffect { //opcode Ch
public:
	//AA6950
	virtual ~CEffectDamage(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
	virtual BOOL CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist); //v18
	virtual BOOL IgnoreLevelCheck(); //v1c
	virtual void PrintEffectText(CCreatureObject& creTarget); //v20
	virtual void PrintEffectTextOnApply(CCreatureObject& creTarget); //v28

	void PlayHitSound(unsigned int nDamageType, CCreatureObject& creTarget);
};

extern void (CEffectDamage::*CEffectDamage_Deconstruct)();
extern CEffect& (CEffectDamage::*CEffectDamage_Duplicate)();
extern BOOL (CEffectDamage::*CEffectDamage_ApplyEffect)(CCreatureObject&);
extern void (CEffectDamage::*CEffectDamage_OnDelayFinished)(CCreatureObject&);
extern BOOL (CEffectDamage::*CEffectDamage_CheckNotSaved)(CCreatureObject&, char&, char&, char&, char&, char&, char&);
extern BOOL (CEffectDamage::*CEffectDamage_IgnoreLevelCheck)();
extern void (CEffectDamage::*CEffectDamage_PrintEffectText)(CCreatureObject&);
extern void (CEffectDamage::*CEffectDamage_PrintEffectTextOnApply)(CCreatureObject&);
extern void (CEffectDamage::*CEffectDamage_PlayHitSound)(unsigned int, CCreatureObject&);

//CEffectInstantDeath
#define EFFECTINSTANTDEATH_TYPE_ACID			0x000
#define EFFECTINSTANTDEATH_TYPE_BURNING			0x001
#define EFFECTINSTANTDEATH_TYPE_CRUSHED			0x002
#define EFFECTINSTANTDEATH_TYPE_NORMAL			0x004
#define EFFECTINSTANTDEATH_TYPE_CHUNKED			0x008
#define EFFECTINSTANTDEATH_TYPE_STONE			0x010
#define EFFECTINSTANTDEATH_TYPE_FROZEN			0x020
#define EFFECTINSTANTDEATH_TYPE_STONE_EXPLODE	0x040
#define EFFECTINSTANTDEATH_TYPE_FROZEN_EXPLODE	0x080
#define EFFECTINSTANTDEATH_TYPE_ELECTRIC		0x100
#define EFFECTINSTANTDEATH_TYPE_DISINTEGRATE	0x200

class CEffectInstantDeath : public CEffect { //opcode Dh
public:
	CEffectInstantDeath();

	//AA6A5C
	virtual ~CEffectInstantDeath(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
	virtual void PrintEffectText(CCreatureObject& creTarget); //v20
};

extern void (CEffectInstantDeath::*CEffectInstantDeath_Deconstruct)();
extern CEffect& (CEffectInstantDeath::*CEffectInstantDeath_Duplicate)();
extern BOOL (CEffectInstantDeath::*CEffectInstantDeath_ApplyEffect)(CCreatureObject&);
extern void (CEffectInstantDeath::*CEffectInstantDeath_OnDelayFinished)(CCreatureObject&);
extern void (CEffectInstantDeath::*CEffectInstantDeath_PrintEffectText)(CCreatureObject&);

//CEffectDexterityMod
class CEffectDexterityMod : public CEffect { //opcode Fh
public:
	//AA9528
	virtual ~CEffectDexterityMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectDexterityMod::*CEffectDexterityMod_Deconstruct)();
extern CEffect& (CEffectDexterityMod::*CEffectDexterityMod_Duplicate)();
extern BOOL (CEffectDexterityMod::*CEffectDexterityMod_ApplyEffect)(CCreatureObject&);

//CEffectCurrentHPMod
class CEffectCurrentHPMod : public CEffect { //opcode 11h
public:
	//AA94B0
	virtual ~CEffectCurrentHPMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual BOOL IgnoreLevelCheck(); //v1c
};

extern void (CEffectCurrentHPMod::*CEffectCurrentHPMod_Deconstruct)();
extern CEffect& (CEffectCurrentHPMod::*CEffectCurrentHPMod_Duplicate)();
extern BOOL (CEffectCurrentHPMod::*CEffectCurrentHPMod_ApplyEffect)(CCreatureObject&);
extern BOOL (CEffectCurrentHPMod::*CEffectCurrentHPMod_IgnoreLevelCheck)();

//CEffectIntelligenceMod
class CEffectIntelligenceMod : public CEffect { //opcode 13h
public:
	//AA9460
	virtual ~CEffectIntelligenceMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectIntelligenceMod::*CEffectIntelligenceMod_Deconstruct)();
extern CEffect& (CEffectIntelligenceMod::*CEffectIntelligenceMod_Duplicate)();
extern BOOL (CEffectIntelligenceMod::*CEffectIntelligenceMod_ApplyEffect)(CCreatureObject&);

//CEffectLoreMod
class CEffectLoreMod : public CEffect { //opcode 15h
public:
	//AA9410
	virtual ~CEffectLoreMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectLoreMod::*CEffectLoreMod_Deconstruct)();
extern CEffect& (CEffectLoreMod::*CEffectLoreMod_Duplicate)();
extern BOOL (CEffectLoreMod::*CEffectLoreMod_ApplyEffect)(CCreatureObject&);

//CEffectLuckMod
class CEffectLuckMod : public CEffect { //opcode 16h
public:
	//AA93E8
	virtual ~CEffectLuckMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectLuckMod::*CEffectLuckMod_Deconstruct)();
extern CEffect& (CEffectLuckMod::*CEffectLuckMod_Duplicate)();
extern BOOL (CEffectLuckMod::*CEffectLuckMod_ApplyEffect)(CCreatureObject&);

//CEffectPoison
class CEffectPoison : public CEffect { //opcode 19h
public:
	//AA9370
	virtual ~CEffectPoison(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
};

extern void (CEffectPoison::*CEffectPoison_Deconstruct)();
extern CEffect& (CEffectPoison::*CEffectPoison_Duplicate)();
extern BOOL (CEffectPoison::*CEffectPoison_ApplyEffect)(CCreatureObject&);
extern void (CEffectPoison::*CEffectPoison_OnDelayFinished)(CCreatureObject&);

//CEffectSaveVsDeathMod
class CEffectSaveVsDeathMod : public CEffect { //opcode 21h
public:
	//AA9230
	virtual ~CEffectSaveVsDeathMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectSaveVsDeathMod::*CEffectSaveVsDeathMod_Deconstruct)();
extern CEffect& (CEffectSaveVsDeathMod::*CEffectSaveVsDeathMod_Duplicate)();
extern BOOL (CEffectSaveVsDeathMod::*CEffectSaveVsDeathMod_ApplyEffect)(CCreatureObject&);

//CEffectSaveVsWandsMod
class CEffectSaveVsWandsMod : public CEffect { //opcode 22h
public:
	//AA9208
	virtual ~CEffectSaveVsWandsMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectSaveVsWandsMod::*CEffectSaveVsWandsMod_Deconstruct)();
extern CEffect& (CEffectSaveVsWandsMod::*CEffectSaveVsWandsMod_Duplicate)();
extern BOOL (CEffectSaveVsWandsMod::*CEffectSaveVsWandsMod_ApplyEffect)(CCreatureObject&);

//CEffectSaveVsPolyMod
class CEffectSaveVsPolyMod : public CEffect { //opcode 23h
public:
	//AA91E0
	virtual ~CEffectSaveVsPolyMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectSaveVsPolyMod::*CEffectSaveVsPolyMod_Deconstruct)();
extern CEffect& (CEffectSaveVsPolyMod::*CEffectSaveVsPolyMod_Duplicate)();
extern BOOL (CEffectSaveVsPolyMod::*CEffectSaveVsPolyMod_ApplyEffect)(CCreatureObject&);

//CEffectSaveVsBreathMod
class CEffectSaveVsBreathMod : public CEffect { //opcode 24h
public:
	//AA91B8
	virtual ~CEffectSaveVsBreathMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectSaveVsBreathMod::*CEffectSaveVsBreathMod_Deconstruct)();
extern CEffect& (CEffectSaveVsBreathMod::*CEffectSaveVsBreathMod_Duplicate)();
extern BOOL (CEffectSaveVsBreathMod::*CEffectSaveVsBreathMod_ApplyEffect)(CCreatureObject&);

//CEffectSaveVsSpellMod
class CEffectSaveVsSpellMod : public CEffect { //opcode 25h
public:
	//AA9190
	virtual ~CEffectSaveVsSpellMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectSaveVsSpellMod::*CEffectSaveVsSpellMod_Deconstruct)();
extern CEffect& (CEffectSaveVsSpellMod::*CEffectSaveVsSpellMod_Duplicate)();
extern BOOL (CEffectSaveVsSpellMod::*CEffectSaveVsSpellMod_ApplyEffect)(CCreatureObject&);

//CEffectMageMemSpellMod
class CEffectMageMemSpellMod : public CEffect { //opcode 2Ah
public:
	//AA90C8
	virtual ~CEffectMageMemSpellMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectMageMemSpellMod::*CEffectMageMemSpellMod_Deconstruct)();
extern CEffect& (CEffectMageMemSpellMod::*CEffectMageMemSpellMod_Duplicate)();
extern BOOL (CEffectMageMemSpellMod::*CEffectMageMemSpellMod_ApplyEffect)(CCreatureObject&);

//CEffectStrengthMod
class CEffectStrengthMod : public CEffect { //opcode 2Ch
public:
	//AA9078
	virtual ~CEffectStrengthMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectStrengthMod::*CEffectStrengthMod_Deconstruct)();
extern CEffect& (CEffectStrengthMod::*CEffectStrengthMod_Duplicate)();
extern BOOL (CEffectStrengthMod::*CEffectStrengthMod_ApplyEffect)(CCreatureObject&);

//CEffectWisdomMod
class CEffectWisdomMod : public CEffect { //opcode 31h
public:
	//AA8FB0
	virtual ~CEffectWisdomMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectWisdomMod::*CEffectWisdomMod_Deconstruct)();
extern CEffect& (CEffectWisdomMod::*CEffectWisdomMod_Duplicate)();
extern BOOL (CEffectWisdomMod::*CEffectWisdomMod_ApplyEffect)(CCreatureObject&);

//CEffectDispel
class CEffectDispel : public CEffect { //opcode 3Ah
public:
	//AA8E48
	virtual ~CEffectDispel(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectDispel::*CEffectDispel_Deconstruct)();
extern CEffect& (CEffectDispel::*CEffectDispel_Duplicate)();
extern BOOL (CEffectDispel::*CEffectDispel_ApplyEffect)(CCreatureObject&);

//CEffectStealthMod
class CEffectStealthMod : public CEffect { //opcode 3Bh
public:
	//AA8E20
	virtual ~CEffectStealthMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectStealthMod::*CEffectStealthMod_Deconstruct)();
extern CEffect& (CEffectStealthMod::*CEffectStealthMod_Duplicate)();
extern BOOL (CEffectStealthMod::*CEffectStealthMod_ApplyEffect)(CCreatureObject&);

//CEffectPriestMemSpellMod
class CEffectPriestMemSpellMod : public CEffect { //opcode 3Eh
public:
	//AA8DD0
	virtual ~CEffectPriestMemSpellMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectPriestMemSpellMod::*CEffectPriestMemSpellMod_Deconstruct)();
extern CEffect& (CEffectPriestMemSpellMod::*CEffectPriestMemSpellMod_Duplicate)();
extern BOOL (CEffectPriestMemSpellMod::*CEffectPriestMemSpellMod_ApplyEffect)(CCreatureObject&);

//CEffectBlindness
class CEffectBlindness : public CEffect { //opcode 4Ah
public:
	//AA8B00
	virtual ~CEffectBlindness(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectBlindness::*CEffectBlindness_Deconstruct)();
extern CEffect& (CEffectBlindness::*CEffectBlindness_Duplicate)();
extern BOOL (CEffectBlindness::*CEffectBlindness_ApplyEffect)(CCreatureObject&);

//CEffectDisease
class CEffectDisease : public CEffect { //opcode 4Eh
public:
	//AA8A60
	virtual ~CEffectDisease(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
};

extern void (CEffectDisease::*CEffectDisease_Deconstruct)();
extern CEffect& (CEffectDisease::*CEffectDisease_Duplicate)();
extern BOOL (CEffectDisease::*CEffectDisease_ApplyEffect)(CCreatureObject&);
extern void (CEffectDisease::*CEffectDisease_OnDelayFinished)(CCreatureObject&);

//CEffectOpenLocksMod
class CEffectOpenLocksMod : public CEffect { //opcode 5Ah
public:
	//AA8880
	virtual ~CEffectOpenLocksMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectOpenLocksMod::*CEffectOpenLocksMod_Deconstruct)();
extern CEffect& (CEffectOpenLocksMod::*CEffectOpenLocksMod_Duplicate)();
extern BOOL (CEffectOpenLocksMod::*CEffectOpenLocksMod_ApplyEffect)(CCreatureObject&);

//CEffectFindTrapsMod
class CEffectFindTrapsMod : public CEffect { //opcode 5Bh
public:
	//AA8858
	virtual ~CEffectFindTrapsMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectFindTrapsMod::*CEffectFindTrapsMod_Deconstruct)();
extern CEffect& (CEffectFindTrapsMod::*CEffectFindTrapsMod_Duplicate)();
extern BOOL (CEffectFindTrapsMod::*CEffectFindTrapsMod_ApplyEffect)(CCreatureObject&);

//CEffectPickPocketsMod
class CEffectPickPocketsMod : public CEffect { //opcode 5Ch
public:
	//AA8830
	virtual ~CEffectPickPocketsMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectPickPocketsMod::*CEffectPickPocketsMod_Deconstruct)();
extern CEffect& (CEffectPickPocketsMod::*CEffectPickPocketsMod_Duplicate)();
extern BOOL (CEffectPickPocketsMod::*CEffectPickPocketsMod_ApplyEffect)(CCreatureObject&);

//CEffectFatigueMod
class CEffectFatigueMod : public CEffect { //opcode 5Dh
public:
	//AA8808
	virtual ~CEffectFatigueMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectFatigueMod::*CEffectFatigueMod_Deconstruct)();
extern CEffect& (CEffectFatigueMod::*CEffectFatigueMod_Duplicate)();
extern BOOL (CEffectFatigueMod::*CEffectFatigueMod_ApplyEffect)(CCreatureObject&);

//CEffectIntoxicationMod
class CEffectIntoxicationMod : public CEffect { //opcode 5Eh
public:
	//AA87E0
	virtual ~CEffectIntoxicationMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectIntoxicationMod::*CEffectIntoxicationMod_Deconstruct)();
extern CEffect& (CEffectIntoxicationMod::*CEffectIntoxicationMod_Duplicate)();
extern BOOL (CEffectIntoxicationMod::*CEffectIntoxicationMod_ApplyEffect)(CCreatureObject&);

//CEffectTrackingMod
class CEffectTrackingMod : public CEffect { //opcode 5Fh
public:
	//AA87B8
	virtual ~CEffectTrackingMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectTrackingMod::*CEffectTrackingMod_Deconstruct)();
extern CEffect& (CEffectTrackingMod::*CEffectTrackingMod_Duplicate)();
extern BOOL (CEffectTrackingMod::*CEffectTrackingMod_ApplyEffect)(CCreatureObject&);

//CEffectLevelMod
class CEffectLevelMod : public CEffect { //opcode 60h
public:
	//AA8790
	virtual ~CEffectLevelMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectLevelMod::*CEffectLevelMod_Deconstruct)();
extern CEffect& (CEffectLevelMod::*CEffectLevelMod_Duplicate)();
extern BOOL (CEffectLevelMod::*CEffectLevelMod_ApplyEffect)(CCreatureObject&);

//CEffectStrengthExMod
class CEffectStrengthExMod : public CEffect { //opcode 61h
public:
	//AA8768
	virtual ~CEffectStrengthExMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectStrengthExMod::*CEffectStrengthExMod_Deconstruct)();
extern CEffect& (CEffectStrengthExMod::*CEffectStrengthExMod_Duplicate)();
extern BOOL (CEffectStrengthExMod::*CEffectStrengthExMod_ApplyEffect)(CCreatureObject&);

//CEffectRegeneration
class CEffectRegeneration : public CEffect { //opcode 62h
public:
	//AA8740
	virtual ~CEffectRegeneration(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
};

extern void (CEffectRegeneration::*CEffectRegeneration_Deconstruct)();
extern CEffect& (CEffectRegeneration::*CEffectRegeneration_Duplicate)();
extern BOOL (CEffectRegeneration::*CEffectRegeneration_ApplyEffect)(CCreatureObject&);
extern void (CEffectRegeneration::*CEffectRegeneration_OnDelayFinished)(CCreatureObject&);

//CEffectMoraleBreakMod
class CEffectMoraleBreakMod : public CEffect { //opcode 6Ah
public:
	//AA8600
	virtual ~CEffectMoraleBreakMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectMoraleBreakMod::*CEffectMoraleBreakMod_Deconstruct)();
extern CEffect& (CEffectMoraleBreakMod::*CEffectMoraleBreakMod_Duplicate)();
extern BOOL (CEffectMoraleBreakMod::*CEffectMoraleBreakMod_ApplyEffect)(CCreatureObject&);

//CEffectReputationMod
class CEffectReputationMod : public CEffect { //opcode 6Ch
public:
	//AA85B0
	virtual ~CEffectReputationMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectReputationMod::*CEffectReputationMod_Deconstruct)();
extern CEffect& (CEffectReputationMod::*CEffectReputationMod_Duplicate)();
extern BOOL (CEffectReputationMod::*CEffectReputationMod_ApplyEffect)(CCreatureObject&);

//CEffectAid
class CEffectAid : public CEffect { //opcode 81h
public:
	//AA8268
	virtual ~CEffectAid(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectAid::*CEffectAid_Deconstruct)();
extern CEffect& (CEffectAid::*CEffectAid_Duplicate)();
extern BOOL (CEffectAid::*CEffectAid_ApplyEffect)(CCreatureObject&);

//CEffectBless
class CEffectBless : public CEffect { //opcode 82h
public:
	//AA8240
	virtual ~CEffectBless(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectBless::*CEffectBless_Deconstruct)();
extern CEffect& (CEffectBless::*CEffectBless_Duplicate)();
extern BOOL (CEffectBless::*CEffectBless_ApplyEffect)(CCreatureObject&);

//CEffectChant
class CEffectChant : public CEffect { //opcode 83h
public:
	//AA8218
	virtual ~CEffectChant(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectChant::*CEffectChant_Deconstruct)();
extern CEffect& (CEffectChant::*CEffectChant_Duplicate)();
extern BOOL (CEffectChant::*CEffectChant_ApplyEffect)(CCreatureObject&);

//CEffectHolyMight
class CEffectHolyMight : public CEffect { //opcode 84h
public:
	//AA81F0
	virtual ~CEffectHolyMight(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectHolyMight::*CEffectHolyMight_Deconstruct)();
extern CEffect& (CEffectHolyMight::*CEffectHolyMight_Duplicate)();
extern BOOL (CEffectHolyMight::*CEffectHolyMight_ApplyEffect)(CCreatureObject&);

//CEffectChantBad
class CEffectChantBad : public CEffect { //opcode 89h
public:
	//AA8128
	virtual ~CEffectChantBad(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectChantBad::*CEffectChantBad_Deconstruct)();
extern CEffect& (CEffectChantBad::*CEffectChantBad_Duplicate)();
extern BOOL (CEffectChantBad::*CEffectChantBad_ApplyEffect)(CCreatureObject&);

//CEffectDisableSpelltype
class CEffectDisableSpelltype : public CEffect { //opcode 91h
public:
	//AA7FC0
	virtual ~CEffectDisableSpelltype(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectDisableSpelltype::*CEffectDisableSpelltype_Deconstruct)();
extern CEffect& (CEffectDisableSpelltype::*CEffectDisableSpelltype_Duplicate)();
extern BOOL (CEffectDisableSpelltype::*CEffectDisableSpelltype_ApplyEffect)(CCreatureObject&);

//CEffectDisableButton
class CEffectDisableButton : public CEffect { //opcode 90h
public:
	//AA8010
	virtual ~CEffectDisableButton(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectDisableButton::*CEffectDisableButton_Deconstruct)();
extern CEffect& (CEffectDisableButton::*CEffectDisableButton_Duplicate)();
extern BOOL (CEffectDisableButton::*CEffectDisableButton_ApplyEffect)(CCreatureObject&);

//CEffectCastSpell
class CEffectCastSpell : public CEffect { //opcode 92h
public:
	//AA7F70
	virtual ~CEffectCastSpell(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectCastSpell::*CEffectCastSpell_Deconstruct)();
extern CEffect& (CEffectCastSpell::*CEffectCastSpell_Duplicate)();
extern BOOL (CEffectCastSpell::*CEffectCastSpell_ApplyEffect)(CCreatureObject&);

//CEffectLearnSpell
//wParam1High
#define EFFECTLEARNSPELL_NO_XP_ALWAYS			0x0001 //new in GemRB, TobEx
#define EFFECTLEARNSPELL_PRINT_MESSAGE			0x0002 //reserved for GemRB
#define EFFECTLEARNSPELL_SUCCESS_ALWAYS			0x0004 //new in GemRB, TobEx
#define EFFECTLEARNSPELL_MEMORIZE_NOW			0x0008 //reserved for GemRB
#define EFFECTLEARNSPELL_NO_XP_DUPLICATE		0x0010 //new in TobEx
#define EFFECTLEARNSPELL_RESTRICT_SCHOOL		0x0020 //new in TobEx
#define EFFECTLEARNSPELL_NO_SORCERER			0x0040 //new in TobEx
#define EFFECTLEARNSPELL_RESTRICT_MAX_SPELLS	0x0080 //new in TobEx

class CEffectLearnSpell : public CEffect { //opcode 93h
public:
	//AA7F70
	virtual ~CEffectLearnSpell(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectLearnSpell::*CEffectLearnSpell_Deconstruct)();
extern CEffect& (CEffectLearnSpell::*CEffectLearnSpell_Duplicate)();
extern BOOL (CEffectLearnSpell::*CEffectLearnSpell_ApplyEffect)(CCreatureObject&);

//CEffectMagicResistMod
class CEffectMagicResistMod : public CEffect { //opcode A6h
public:
	//AA7D68
	virtual ~CEffectMagicResistMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectMagicResistMod::*CEffectMagicResistMod_Deconstruct)();
extern CEffect& (CEffectMagicResistMod::*CEffectMagicResistMod_Duplicate)();
extern BOOL (CEffectMagicResistMod::*CEffectMagicResistMod_ApplyEffect)(CCreatureObject&);

//CEffectUseEFFFile
class CEffectUseEFFFile : public CEffect { //opcode B1h
public:
	//AA7BD8
	virtual ~CEffectUseEFFFile(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnRemove(CCreatureObject& creTarget); //v24
};

extern void (CEffectUseEFFFile::*CEffectUseEFFFile_Deconstruct)();
extern CEffect& (CEffectUseEFFFile::*CEffectUseEFFFile_Duplicate)();
extern BOOL (CEffectUseEFFFile::*CEffectUseEFFFile_ApplyEffect)(CCreatureObject&);
extern void (CEffectUseEFFFile::*CEffectUseEFFFile_OnRemove)(CCreatureObject&);

//CEffectCastSpellOnCondition
class CEffectCastSpellOnCondition : public CEffect { //opcode E8h
public:
	//AA9C08
	virtual ~CEffectCastSpellOnCondition(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectCastSpellOnCondition::*CEffectCastSpellOnCondition_Deconstruct)();
extern CEffect& (CEffectCastSpellOnCondition::*CEffectCastSpellOnCondition_Duplicate)();
extern BOOL (CEffectCastSpellOnCondition::*CEffectCastSpellOnCondition_ApplyEffect)(CCreatureObject&);

//CEffectProficiencyMod
class CEffectProficiencyMod : public CEffect { //opcode E9h
public:
	//AA9C30
	virtual ~CEffectProficiencyMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectProficiencyMod::*CEffectProficiencyMod_Deconstruct)();
extern CEffect& (CEffectProficiencyMod::*CEffectProficiencyMod_Duplicate)();
extern BOOL (CEffectProficiencyMod::*CEffectProficiencyMod_ApplyEffect)(CCreatureObject&);

//CEffectWingBuffet
class CEffectWingBuffet : public CEffect { //opcode EBh
public:
	CEffectWingBuffet(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY);
	CEffectWingBuffet& Construct(ITEM_EFFECT&, POINT&, Enum, int, int) { return *this; } //dummy

	//AA9C80
	virtual ~CEffectWingBuffet(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual BOOL CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist); //v18
};

extern CEffectWingBuffet& (CEffectWingBuffet::*CEffectWingBuffet_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int);
extern void (CEffectWingBuffet::*CEffectWingBuffet_Deconstruct)();
extern CEffect& (CEffectWingBuffet::*CEffectWingBuffet_Duplicate)();
extern BOOL (CEffectWingBuffet::*CEffectWingBuffet_ApplyEffect)(CCreatureObject&);
extern BOOL (CEffectWingBuffet::*CEffectWingBuffet_CheckNotSaved)(CCreatureObject&, char&, char&, char&, char&, char&, char&);

//CEffectDisintegrate
class CEffectDisintegrate : public CEffect { //opcode EEh
public:
	//AA9D40
	virtual ~CEffectDisintegrate(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectDisintegrate::*CEffectDisintegrate_Deconstruct)();
extern CEffect& (CEffectDisintegrate::*CEffectDisintegrate_Duplicate)();
extern BOOL (CEffectDisintegrate::*CEffectDisintegrate_ApplyEffect)(CCreatureObject&);

//CEffectRepeatingEff
class CEffectRepeatingEff : public CEffect { //opcode 110h
public:
	CEffectRepeatingEff(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY);
	CEffectRepeatingEff& Construct(ITEM_EFFECT&, POINT&, Enum, int, int) { return *this; } //dummy

	//AAA218
	virtual ~CEffectRepeatingEff(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern CEffectRepeatingEff& (CEffectRepeatingEff::*CEffectRepeatingEff_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int);
extern void (CEffectRepeatingEff::*CEffectRepeatingEff_Deconstruct)();
extern CEffect& (CEffectRepeatingEff::*CEffectRepeatingEff_Duplicate)();
extern BOOL (CEffectRepeatingEff::*CEffectRepeatingEff_ApplyEffect)(CCreatureObject&);

//CEffectRemoveProjectile
class CEffectRemoveProjectile : public CEffect { //opcode 111h
public:
	//AA9D90
	virtual ~CEffectRemoveProjectile(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectRemoveProjectile::*CEffectRemoveProjectile_Deconstruct)();
extern CEffect& (CEffectRemoveProjectile::*CEffectRemoveProjectile_Duplicate)();
extern BOOL (CEffectRemoveProjectile::*CEffectRemoveProjectile_ApplyEffect)(CCreatureObject&);

//CEffectEnableButton
class CEffectEnableButton : public CEffect { //opcode 117h
public:
	//AA7FE8
	virtual ~CEffectEnableButton(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectEnableButton::*CEffectEnableButton_Deconstruct)();
extern CEffect& (CEffectEnableButton::*CEffectEnableButton_Duplicate)();
extern BOOL (CEffectEnableButton::*CEffectEnableButton_ApplyEffect)(CCreatureObject&);

//CEffectCutScene2
class CEffectCutScene2 : public CEffect { //opcode 12Ah
public:
	//AAA5D8
	virtual ~CEffectCutScene2(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectCutScene2::*CEffectCutScene2_Deconstruct)();
extern CEffect& (CEffectCutScene2::*CEffectCutScene2_Duplicate)();
extern BOOL (CEffectCutScene2::*CEffectCutScene2_ApplyEffect)(CCreatureObject&);

//CEffectAnimationRemoval
class CEffectAnimationRemoval : public CEffect { //opcode 13Bh
public:
	//AAA858
	virtual ~CEffectAnimationRemoval(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectAnimationRemoval::*CEffectAnimationRemoval_Deconstruct)();
extern CEffect& (CEffectAnimationRemoval::*CEffectAnimationRemoval_Duplicate)();
extern BOOL (CEffectAnimationRemoval::*CEffectAnimationRemoval_ApplyEffect)(CCreatureObject&);

#endif //EFFOPCODE_H