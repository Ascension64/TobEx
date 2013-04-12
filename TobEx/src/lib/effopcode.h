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

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectAwaken
class CEffectAwaken : public CEffect { //opcode 2h
public:
	//AA96E0
	virtual ~CEffectAwaken(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectCharismaMod
class CEffectCharismaMod : public CEffect { //opcode 6h
public:
	//AA9640
	virtual ~CEffectCharismaMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectConstitutionMod
class CEffectConstitutionMod : public CEffect { //opcode Ah
public:
	//AA95A0
	virtual ~CEffectConstitutionMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

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

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
	virtual BOOL CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist); //v18
	virtual BOOL IgnoreLevelCheck(); //v1c
	virtual void PrintEffectText(CCreatureObject& creTarget); //v20
	virtual void PrintEffectTextOnApply(CCreatureObject& creTarget); //v28

	void PlayHitSound(unsigned int nDamageType, CCreatureObject& creTarget);
};

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

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
	virtual void PrintEffectText(CCreatureObject& creTarget); //v20
};

//CEffectDexterityMod
class CEffectDexterityMod : public CEffect { //opcode Fh
public:
	//AA9528
	virtual ~CEffectDexterityMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectCurrentHPMod
class CEffectCurrentHPMod : public CEffect { //opcode 11h
public:
	//AA94B0
	virtual ~CEffectCurrentHPMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual BOOL IgnoreLevelCheck(); //v1c
};

//CEffectIntelligenceMod
class CEffectIntelligenceMod : public CEffect { //opcode 13h
public:
	//AA9460
	virtual ~CEffectIntelligenceMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectLoreMod
class CEffectLoreMod : public CEffect { //opcode 15h
public:
	//AA9410
	virtual ~CEffectLoreMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectLuckMod
class CEffectLuckMod : public CEffect { //opcode 16h
public:
	//AA93E8
	virtual ~CEffectLuckMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectPoison
class CEffectPoison : public CEffect { //opcode 19h
public:
	//AA9370
	virtual ~CEffectPoison(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
};

//CEffectSaveVsDeathMod
class CEffectSaveVsDeathMod : public CEffect { //opcode 21h
public:
	//AA9230
	virtual ~CEffectSaveVsDeathMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectSaveVsWandsMod
class CEffectSaveVsWandsMod : public CEffect { //opcode 22h
public:
	//AA9208
	virtual ~CEffectSaveVsWandsMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectSaveVsPolyMod
class CEffectSaveVsPolyMod : public CEffect { //opcode 23h
public:
	//AA91E0
	virtual ~CEffectSaveVsPolyMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectSaveVsBreathMod
class CEffectSaveVsBreathMod : public CEffect { //opcode 24h
public:
	//AA91B8
	virtual ~CEffectSaveVsBreathMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectSaveVsSpellMod
class CEffectSaveVsSpellMod : public CEffect { //opcode 25h
public:
	//AA9190
	virtual ~CEffectSaveVsSpellMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectMageMemSpellMod
class CEffectMageMemSpellMod : public CEffect { //opcode 2Ah
public:
	//AA90C8
	virtual ~CEffectMageMemSpellMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectStrengthMod
class CEffectStrengthMod : public CEffect { //opcode 2Ch
public:
	//AA9078
	virtual ~CEffectStrengthMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectWisdomMod
class CEffectWisdomMod : public CEffect { //opcode 31h
public:
	//AA8FB0
	virtual ~CEffectWisdomMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectDispel
class CEffectDispel : public CEffect { //opcode 3Ah
public:
	//AA8E48
	virtual ~CEffectDispel(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectStealthMod
class CEffectStealthMod : public CEffect { //opcode 3Bh
public:
	//AA8E20
	virtual ~CEffectStealthMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectPriestMemSpellMod
class CEffectPriestMemSpellMod : public CEffect { //opcode 3Eh
public:
	//AA8DD0
	virtual ~CEffectPriestMemSpellMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectBlindness
class CEffectBlindness : public CEffect { //opcode 4Ah
public:
	//AA8B00
	virtual ~CEffectBlindness(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectDisease
class CEffectDisease : public CEffect { //opcode 4Eh
public:
	//AA8A60
	virtual ~CEffectDisease(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
};

//CEffectOpenLocksMod
class CEffectOpenLocksMod : public CEffect { //opcode 5Ah
public:
	//AA8880
	virtual ~CEffectOpenLocksMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectFindTrapsMod
class CEffectFindTrapsMod : public CEffect { //opcode 5Bh
public:
	//AA8858
	virtual ~CEffectFindTrapsMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectPickPocketsMod
class CEffectPickPocketsMod : public CEffect { //opcode 5Ch
public:
	//AA8830
	virtual ~CEffectPickPocketsMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectFatigueMod
class CEffectFatigueMod : public CEffect { //opcode 5Dh
public:
	//AA8808
	virtual ~CEffectFatigueMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectIntoxicationMod
class CEffectIntoxicationMod : public CEffect { //opcode 5Eh
public:
	//AA87E0
	virtual ~CEffectIntoxicationMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectTrackingMod
class CEffectTrackingMod : public CEffect { //opcode 5Fh
public:
	//AA87B8
	virtual ~CEffectTrackingMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectLevelMod
class CEffectLevelMod : public CEffect { //opcode 60h
public:
	//AA8790
	virtual ~CEffectLevelMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectStrengthExMod
class CEffectStrengthExMod : public CEffect { //opcode 61h
public:
	//AA8768
	virtual ~CEffectStrengthExMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectRegeneration
class CEffectRegeneration : public CEffect { //opcode 62h
public:
	//AA8740
	virtual ~CEffectRegeneration(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
};

//CEffectMoraleBreakMod
class CEffectMoraleBreakMod : public CEffect { //opcode 6Ah
public:
	//AA8600
	virtual ~CEffectMoraleBreakMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectReputationMod
class CEffectReputationMod : public CEffect { //opcode 6Ch
public:
	//AA85B0
	virtual ~CEffectReputationMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectAid
class CEffectAid : public CEffect { //opcode 81h
public:
	//AA8268
	virtual ~CEffectAid(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectBless
class CEffectBless : public CEffect { //opcode 82h
public:
	//AA8240
	virtual ~CEffectBless(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectChant
class CEffectChant : public CEffect { //opcode 83h
public:
	//AA8218
	virtual ~CEffectChant(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectHolyMight
class CEffectHolyMight : public CEffect { //opcode 84h
public:
	//AA81F0
	virtual ~CEffectHolyMight(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectChantBad
class CEffectChantBad : public CEffect { //opcode 89h
public:
	//AA8128
	virtual ~CEffectChantBad(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectDisableSpelltype
class CEffectDisableSpelltype : public CEffect { //opcode 91h
public:
	//AA7FC0
	virtual ~CEffectDisableSpelltype(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectDisableButton
class CEffectDisableButton : public CEffect { //opcode 90h
public:
	//AA8010
	virtual ~CEffectDisableButton(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectCastSpell
class CEffectCastSpell : public CEffect { //opcode 92h
public:
	//AA7F70
	virtual ~CEffectCastSpell(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

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

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectMagicResistMod
class CEffectMagicResistMod : public CEffect { //opcode A6h
public:
	//AA7D68
	virtual ~CEffectMagicResistMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectPoisonResistMod
class CEffectPoisonResistMod : public CEffect { //opcode ADh
public:
	//AA7C50
	virtual ~CEffectPoisonResistMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectUseEFFFile
class CEffectUseEFFFile : public CEffect { //opcode B1h
public:
	//AA7BD8
	virtual ~CEffectUseEFFFile(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnRemove(CCreatureObject& creTarget); //v24
};

//CEffectCastSpellOnCondition
class CEffectCastSpellOnCondition : public CEffect { //opcode E8h
public:
	//AA9C08
	virtual ~CEffectCastSpellOnCondition(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectProficiencyMod
class CEffectProficiencyMod : public CEffect { //opcode E9h
public:
	//AA9C30
	virtual ~CEffectProficiencyMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectWingBuffet
class CEffectWingBuffet : public CEffect { //opcode EBh
public:
	CEffectWingBuffet(ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY);
	CEffectWingBuffet& Construct(ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY) { return *this; } //dummy

	//AA9C80
	virtual ~CEffectWingBuffet(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual BOOL CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist); //v18
};

//CEffectDisintegrate
class CEffectDisintegrate : public CEffect { //opcode EEh
public:
	//AA9D40
	virtual ~CEffectDisintegrate(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectRepeatingEff
class CEffectRepeatingEff : public CEffect { //opcode 110h
public:
	CEffectRepeatingEff(ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY);
	CEffectRepeatingEff& Construct(ItmFileEffect& eff, CPoint& ptSource, ENUM eSource, int ptDestX, int ptDestY) { return *this; } //dummy

	//AAA218
	virtual ~CEffectRepeatingEff(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectRemoveProjectile
class CEffectRemoveProjectile : public CEffect { //opcode 111h
public:
	//AA9D90
	virtual ~CEffectRemoveProjectile(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectEnableButton
class CEffectEnableButton : public CEffect { //opcode 117h
public:
	//AA7FE8
	virtual ~CEffectEnableButton(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectCutScene2
class CEffectCutScene2 : public CEffect { //opcode 12Ah
public:
	//AAA5D8
	virtual ~CEffectCutScene2(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

//CEffectAnimationRemoval
class CEffectAnimationRemoval : public CEffect { //opcode 13Bh
public:
	//AAA858
	virtual ~CEffectAnimationRemoval(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Copy(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

#endif //EFFOPCODE_H