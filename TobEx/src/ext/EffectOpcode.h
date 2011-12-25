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

//CEffectDamage
extern BOOL (CEffectDamage::*Tramp_CEffectDamage_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDamage : public CEffectDamage {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPoison
extern BOOL (CEffectPoison::*Tramp_CEffectPoison_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectPoison : public CEffectPoison {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectDispel
extern BOOL (CEffectDispel::*Tramp_CEffectDispel_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDispel : public CEffectDispel {
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

//CEffectRegeneration
extern BOOL (CEffectRegeneration::*Tramp_CEffectRegeneration_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectRegeneration : public CEffectRegeneration {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectMagicResistMod
extern BOOL (CEffectMagicResistMod::*Tramp_CEffectMagicResistMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectMagicResistMod : public CEffectMagicResistMod {
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

//CEffectCutScene2
extern BOOL (CEffectCutScene2::*Tramp_CEffectCutScene2_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectCutScene2 : public CEffectCutScene2 {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffect13E
class CEffect13E : public CEffect {
public:
	CEffect13E(ITEM_EFFECT&, POINT&, Enum, int, int, BOOL, Enum);

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
};

#endif //EFFECTOPCODE_H