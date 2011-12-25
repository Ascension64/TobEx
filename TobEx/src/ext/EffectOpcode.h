#ifndef EFFECTOPCODE_H
#define EFFECTOPCODE_H

#include "effopcode.h"
#include "utils.h"
#include "objcre.h"

extern BOOL (CEffectDamage::*Tramp_CEffectDamage_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectDamage : public CEffectDamage {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject&);
};

extern BOOL (CEffectBlindness::*Tramp_CEffectBlindness_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectBlindness : public CEffectBlindness {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject&);
};

extern BOOL (CEffectMagicResistMod::*Tramp_CEffectMagicResistMod_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectMagicResistMod : public CEffectMagicResistMod {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject&);
};

extern BOOL (CEffectCutScene2::*Tramp_CEffectCutScene2_ApplyEffect)(CCreatureObject&);

class DETOUR_CEffectCutScene2 : public CEffectCutScene2 {
public:
	BOOL DETOUR_ApplyEffect(CCreatureObject&);
};

class CEffect13E : public CEffect {
public:
	CEffect13E(ITEM_EFFECT&, POINT&, Enum, DWORD, DWORD, BOOL, Enum);

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject&); //v8
};

#endif //EFFECTOPCODE_H