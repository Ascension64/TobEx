#ifndef EFFOPCODE_H
#define EFFOPCODE_H

#include "effcore.h"

#include "stdafx.h"
#include "objcre.h"

//effect opcodes
#define CEFFECT_OPCODE_ATTACKS_PER_ROUND	0x001
#define CEFFECT_OPCODE_AWAKEN				0x002
#define CEFFECT_OPCODE_DAMAGE				0x00C
#define CEFFECT_OPCODE_INSTANT_DEATH		0x00D
#define CEFFECT_OPCODE_DEXTERITY_MOD		0x00F
#define CEFFECT_OPCODE_CURRENTHP_MOD		0x011
#define CEFFECT_OPCODE_POISON				0x019
#define CEFFECT_OPCODE_UNCONSCIOUSNESS		0x027
#define CEFFECT_OPCODE_MAGE_MEM_SPELL_MOD	0x02A
#define CEFFECT_OPCODE_STRENGTH_MOD			0x02C
#define CEFFECT_OPCODE_SLEEP				0x027
#define CEFFECT_OPCODE_DISPEL				0x03A
#define CEFFECT_OPCODE_PRIEST_MEM_SPELL_MOD	0x03E
#define CEFFECT_OPCODE_BLINDNESS			0x04A
#define CEFFECT_OPCODE_DISEASE				0x04E
#define CEFFECT_OPCODE_REGENERATION			0x062
#define CEFFECT_OPCODE_LEARN_SPELL			0x093
#define CEFFECT_OPCODE_MAGIC_RESIST_MOD		0x0A6
#define CEFFECT_OPCODE_FREEDOM				0x0D4
#define CEFFECT_OPCODE_CAST_SPELL_CONDITION	0x0E8
#define CEFFECT_OPCODE_WING_BUFFET			0x0EB
#define CEFFECT_OPCODE_DISINTEGRATE			0x0EE
#define CEFFECT_OPCODE_AVATAR_REMOVAL		0x10F
#define CEFFECT_OPCODE_REPEATING_EFFECT		0x110
#define CEFFECT_OPCODE_REMOVE_PROJECTILE	0x111
#define CEFFECT_OPCODE_CUTSCENE_2			0x12A
#define CEFFECT_OPCODE_ANIMATION_REMOVAL	0x13B
#define CEFFECT_OPCODE_SET_STAT				0x13E //added by TobEx

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

	void PlayHitSound(int nDamageType, CCreatureObject& creTarget);
};

extern void (CEffectDamage::*CEffectDamage_Deconstruct)();
extern CEffect& (CEffectDamage::*CEffectDamage_Duplicate)();
extern BOOL (CEffectDamage::*CEffectDamage_ApplyEffect)(CCreatureObject&);
extern void (CEffectDamage::*CEffectDamage_OnDelayFinished)(CCreatureObject&);
extern BOOL (CEffectDamage::*CEffectDamage_CheckNotSaved)(CCreatureObject&, char&, char&, char&, char&, char&, char&);
extern BOOL (CEffectDamage::*CEffectDamage_IgnoreLevelCheck)();
extern void (CEffectDamage::*CEffectDamage_PrintEffectText)(CCreatureObject&);
extern void (CEffectDamage::*CEffectDamage_PrintEffectTextOnApply)(CCreatureObject&);
extern void (CEffectDamage::*CEffectDamage_PlayHitSound)(int, CCreatureObject&);

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

//CEffectLearnSpell
//wParam1High
#define EFFECTLEARNSPELL_NO_XP_ALWAYS		0x0001 //new in GemRB, TobEx
#define EFFECTLEARNSPELL_PRINT_MESSAGE		0x0002 //reserved for GemRB
#define EFFECTLEARNSPELL_SUCCESS_ALWAYS		0x0004 //new in GemRB, TobEx
#define EFFECTLEARNSPELL_MEMORIZE_NOW		0x0008 //reserved for GemRB
#define EFFECTLEARNSPELL_NO_XP_DUPLICATE	0x0010 //new in TobEx
#define EFFECTLEARNSPELL_RESTRICT_SCHOOL	0x0020 //new in TobEx
#define EFFECTLEARNSPELL_NO_SORCERER		0x0040 //new in TobEx

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