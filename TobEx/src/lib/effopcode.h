#ifndef EFFOPCODE_H
#define EFFOPCODE_H

#include "effcore.h"

#include "utils.h"
#include "objcre.h"

//effect opcodes
#define CEFFECT_OPCODE_AWAKEN 0x002

class CEffectAwaken: public CEffect { //opcode 2h
public:
	~CEffectAwaken() {} //v0
	CEffect& Duplicate() {return *this;} //v4
	BOOL ApplyEffect(CCreatureObject&) { return FALSE; } //v8
	void ApplyTiming(CCreatureObject&) {} //vc
	void v10() {} //v10
	void v14() {} //v14
	BOOL TrySave(CCreatureObject&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&) { return FALSE; } //v18
	void v1c() {} //v1c
	void PrintEffectText(CCreatureObject&) {} //v20
	void v24(CCreatureObject&) {} //v24
};

extern BOOL (CEffectAwaken::*CEffectAwaken_ApplyEffect)(CCreatureObject&);

class CEffectDamage : public CEffect { //opcode Ch
public:
	~CEffectDamage() {} //v0
	CEffect& Duplicate() {return *this;} //v4
	BOOL ApplyEffect(CCreatureObject&) { return FALSE; } //v8
	void ApplyTiming(CCreatureObject&) {} //vc
	void v10() {} //v10
	void v14() {} //v14
	BOOL TrySave(CCreatureObject&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&) { return FALSE; } //v18
	void v1c() {} //v1c
	void PrintEffectText(CCreatureObject&) {} //v20
	void v24(CCreatureObject&) {} //v24
};

extern BOOL (CEffectDamage::*CEffectDamage_ApplyEffect)(CCreatureObject&);

class CEffectBlindness : public CEffect { //opcode 4Ah
public:
	~CEffectBlindness() {} //v0
	CEffect& Duplicate() {return *this;} //v4
	BOOL ApplyEffect(CCreatureObject&) { return FALSE; } //v8
	void ApplyTiming(CCreatureObject&) {} //vc
	void v10() {} //v10
	void v14() {} //v14
	BOOL TrySave(CCreatureObject&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&) { return FALSE; } //v18
	void v1c() {} //v1c
	void PrintEffectText(CCreatureObject&) {} //v20
	void v24(CCreatureObject&) {} //v24
};

extern BOOL (CEffectBlindness::*CEffectBlindness_ApplyEffect)(CCreatureObject&);

class CEffectMagicResistMod : public CEffect { //opcode A6h
public:
	~CEffectMagicResistMod() {} //v0
	CEffect& Duplicate() {return *this;} //v4
	BOOL ApplyEffect(CCreatureObject&) { return FALSE; } //v8
	void ApplyTiming(CCreatureObject&) {} //vc
	void v10() {} //v10
	void v14() {} //v14
	BOOL TrySave(CCreatureObject&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&) { return FALSE; } //v18
	void v1c() {} //v1c
	void PrintEffectText(CCreatureObject&) {} //v20
	void v24(CCreatureObject&) {} //v24
};

extern BOOL (CEffectMagicResistMod::*CEffectMagicResistMod_ApplyEffect)(CCreatureObject&);

class CEffectCutScene2 : public CEffect { //opcode 12Ah
public:
	~CEffectCutScene2() {} //v0
	CEffect& Duplicate() {return *this;} //v4
	BOOL ApplyEffect(CCreatureObject&) { return FALSE; } //v8
	void ApplyTiming(CCreatureObject&) {} //vc
	void v10() {} //v10
	void v14() {} //v14
	BOOL TrySave(CCreatureObject&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&) { return FALSE; } //v18
	void v1c() {} //v1c
	void PrintEffectText(CCreatureObject&) {} //v20
	void v24(CCreatureObject&) {} //v24
};

extern BOOL (CEffectCutScene2::*CEffectCutScene2_ApplyEffect)(CCreatureObject&);

#endif //EFFOPCODE_H