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

//CEffectDexterityMod
extern BOOL (CEffectDexterityMod::*Tramp_CEffectDexterityMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDexterityMod : public CEffectDexterityMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject& creTarget);
};

//CEffectPoison
extern BOOL (CEffectPoison::*Tramp_CEffectPoison_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectPoison : public CEffectPoison {
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

//CEffectDispel
extern BOOL (CEffectDispel::*Tramp_CEffectDispel_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDispel : public CEffectDispel {
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

//CEffectLearnSpell
extern BOOL (CEffectLearnSpell::*Tramp_CEffectLearnSpell_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectLearnSpell : public CEffectLearnSpell {
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

#endif //EFFECTOPCODE_H