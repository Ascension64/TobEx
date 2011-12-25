#include "effopcode.h"

BOOL (CEffectAwaken::*CEffectAwaken_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectAwaken::*)(CCreatureObject&)>			(&CEffectAwaken::ApplyEffect),			0x503597);
BOOL (CEffectDamage::*CEffectDamage_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectDamage::*)(CCreatureObject&)>			(&CEffectDamage::ApplyEffect),			0x505570);
BOOL (CEffectBlindness::*CEffectBlindness_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectBlindness::*)(CCreatureObject&)>			(&CEffectBlindness::ApplyEffect),		0x51ADF9);
BOOL (CEffectMagicResistMod::*CEffectMagicResistMod_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectMagicResistMod::*)(CCreatureObject&)>	(&CEffectMagicResistMod::ApplyEffect),	0x52EB97);
BOOL (CEffectCutScene2::*CEffectCutScene2_ApplyEffect)(CCreatureObject&) =
	SetFP(static_cast<BOOL (CEffectCutScene2::*)(CCreatureObject&)>			(&CEffectCutScene2::ApplyEffect),		0x542815);