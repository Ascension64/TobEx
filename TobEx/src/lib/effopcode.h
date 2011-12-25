#ifndef EFFOPCODE_H
#define EFFOPCODE_H

#include "effcore.h"

#include "stdafx.h"
#include "objcre.h"

//effect opcodes
#define CEFFECT_OPCODE_ATTACKS_PER_ROUND	0x001
#define CEFFECT_OPCODE_AWAKEN				0x002
#define CEFFECT_OPCODE_CURRENTHP_MOD		0x011
#define CEFFECT_OPCODE_POISON				0x019
#define CEFFECT_OPCODE_SLEEP				0x027
#define CEFFECT_OPCODE_DISPEL				0x03A
#define CEFFECT_OPCODE_DISEASE				0x04E
#define CEFFECT_OPCODE_REGENERATION			0x062
#define CEFFECT_OPCODE_WING_BUFFET			0x0EB
#define CEFFECT_OPCODE_REPEATING_EFFECT		0x110
#define CEFFECT_OPCODE_CUTSCENE_2			0x12A

//CEffectAttacksPerRoundMod
class CEffectAttacksPerRoundMod : public CEffect { //opcode 1h
public:
	//AA9708
	virtual ~CEffectAttacksPerRoundMod() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern BOOL (CEffectAttacksPerRoundMod::*CEffectAttacksPerRoundMod_ApplyEffect)(CCreatureObject&);

//CEffectAwaken
class CEffectAwaken : public CEffect { //opcode 2h
public:
	//AA96E0
	virtual ~CEffectAwaken() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern BOOL (CEffectAwaken::*CEffectAwaken_ApplyEffect)(CCreatureObject&);

//CEffectDamage
class CEffectDamage : public CEffect { //opcode Ch
public:
	//AA6950
	virtual ~CEffectDamage() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget) {} //v10
	virtual BOOL CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist) { return FALSE; } //v18
	virtual BOOL IgnoreLevelCheck() { return TRUE; } //v1c
	virtual void PrintEffectText(CCreatureObject& creTarget) {} //v20
};

extern BOOL (CEffectDamage::*CEffectDamage_ApplyEffect)(CCreatureObject&);

//CEffectCurrentHPMod
class CEffectCurrentHPMod : public CEffect { //opcode 11h
public:
	//AA94B0
	virtual ~CEffectCurrentHPMod(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern void (CEffectCurrentHPMod::*CEffectCurrentHPMod_Deconstruct)();
extern CEffect& (CEffectCurrentHPMod::*CEffectCurrentHPMod_Duplicate)();
extern BOOL (CEffectCurrentHPMod::*CEffectCurrentHPMod_ApplyEffect)(CCreatureObject&);

//CEffectPoison
class CEffectPoison : public CEffect { //opcode 19h
public:
	//AA9370
	virtual ~CEffectPoison() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget) {} //v10
};

extern BOOL (CEffectPoison::*CEffectPoison_ApplyEffect)(CCreatureObject&);

//CEffectDispel
class CEffectDispel : public CEffect { //opcode 3Ah
public:
	//AA8E48
	virtual ~CEffectDispel() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern BOOL (CEffectDispel::*CEffectDispel_ApplyEffect)(CCreatureObject&);

//CEffectBlindness
class CEffectBlindness : public CEffect { //opcode 4Ah
public:
	//AA8B00
	virtual ~CEffectBlindness() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern BOOL (CEffectBlindness::*CEffectBlindness_ApplyEffect)(CCreatureObject&);

//CEffectDisease
class CEffectDisease : public CEffect { //opcode 19h
public:
	//AA8A60
	virtual ~CEffectDisease() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget) {} //v10
};

extern BOOL (CEffectDisease::*CEffectDisease_ApplyEffect)(CCreatureObject&);

//CEffectRegeneration
class CEffectRegeneration : public CEffect { //opcode 62h
public:
	//AA8740
	virtual ~CEffectRegeneration() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual void OnDelayFinished(CCreatureObject& creTarget) {} //v10
};

extern BOOL (CEffectRegeneration::*CEffectRegeneration_ApplyEffect)(CCreatureObject&);

//CEffectMagicResistMod
class CEffectMagicResistMod : public CEffect { //opcode A6h
public:
	//AA7D68
	virtual ~CEffectMagicResistMod() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern BOOL (CEffectMagicResistMod::*CEffectMagicResistMod_ApplyEffect)(CCreatureObject&);

//CEffectRepeatingEff
class CEffectRepeatingEff : public CEffect { //opcode 110h
public:
	CEffectRepeatingEff(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY);
	CEffectRepeatingEff& Construct(ITEM_EFFECT&, POINT&, Enum, int, int) { return *this; } //dummy

	//AAA218
	virtual ~CEffectRepeatingEff() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern CEffectRepeatingEff& (CEffectRepeatingEff::*CEffectRepeatingEff_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int);
extern BOOL (CEffectRepeatingEff::*CEffectRepeatingEff_ApplyEffect)(CCreatureObject&);

//CEffectWingBuffet
class CEffectWingBuffet : public CEffect { //opcode EBh
public:
	CEffectWingBuffet(ITEM_EFFECT& eff, POINT& ptSource, Enum eSource, int ptDestX, int ptDestY);
	CEffectWingBuffet& Construct(ITEM_EFFECT&, POINT&, Enum, int, int) { return *this; } //dummy

	//AA9C80
	virtual ~CEffectWingBuffet() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual BOOL CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist) { return FALSE; } //v18
};

extern CEffectRepeatingEff& (CEffectRepeatingEff::*CEffectRepeatingEff_Construct_5)(ITEM_EFFECT&, POINT&, Enum, int, int);
extern BOOL (CEffectRepeatingEff::*CEffectRepeatingEff_ApplyEffect)(CCreatureObject&);

//CEffectCutScene2
class CEffectCutScene2 : public CEffect { //opcode 12Ah
public:
	//AAA5D8
	virtual ~CEffectCutScene2() {} //v0
	virtual CEffect& Duplicate() {return *this;} //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

extern BOOL (CEffectCutScene2::*CEffectCutScene2_ApplyEffect)(CCreatureObject&);

#endif //EFFOPCODE_H