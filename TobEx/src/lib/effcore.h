#ifndef EFFCORE_H
#define EFFCORE_H

#include "utils.h"
#include "datatypes.h"
#include "resref.h"
#include "rescore.h"
#include "sndcore.h"

typedef void* CEffectVirtualTable[10];

class CCreatureObject;

struct ResEffContainer { //Size 10h
//Constructor: 0x4F2810
	BOOL bLoaded; //0h
	ResEff* pRes; //4h
	ResRef name; //8h
};

class CEffect { //Size 19Ah
//Notes: there is one derived class for each opcode
public:
	//0xAA6378
	CEffect(ITEM_EFFECT&, POINT&, Enum, DWORD, DWORD, BOOL, Enum); //0x4F34C8
	CEffect& Construct(ITEM_EFFECT&, POINT&, Enum, DWORD, DWORD, BOOL, Enum) {return *this;} //dummy

	void Unmarshal(EffFileData&);

	CEffect(EffFileData&);
	CEffect& Construct(EffFileData&) {return *this;} //dummy

	static CEffect& CreateEffect(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum);
	static void CEffect::CreateItemEffect(ITEM_EFFECT&, DWORD);
	ITEM_EFFECT& CEffect::ToItemEffect();

	//virtuals
	virtual ~CEffect(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4, identical for all opcodes except vtable assignation
	virtual BOOL ApplyEffect(CCreatureObject&); //v8
	virtual void ApplyTiming(CCreatureObject&); //vc, timing, then calls applyEffect
	virtual void v10(); //v10
	virtual void v14(); //v14
	virtual BOOL TrySave(CCreatureObject&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&); //v18, saving throw, dispel, resistance, BYTE* are random numbers stored in Sprite
	virtual void v1c(); //v1c
	virtual void PrintEffectText(CCreatureObject&); //v20
	virtual void v24(CCreatureObject&); //v24, on removal from CPtrListEffect

	EffFileData effect; //4h
	Enum eSource; //10ch
	BOOL bPurge; //110h - deconstruct and remove effect from CPtrListEffect after application
	BOOL bRefreshCurrentState; //114h - use if you change a m_BaseStats member, sets bApplyEffectsAgain in CPtrListEffect, repeating effect application
	DWORD nDuration2; //118h, used for duration after delayed timing
	DWORD u11c;
	DWORD u120;
	DWORD u124;
	DWORD u128;
	CSound sound;
	Enum enum2; //196h, Arg7, inherits value of Cre+30h for a global effect of an item equipped by the Cre
};

extern CEffect& (CEffect::*CEffect_Construct_7)(ITEM_EFFECT&, POINT&, Enum, DWORD, DWORD, BOOL, Enum);
extern void (CEffect::*CEffect_Unmarshal)(EffFileData&);
extern CEffect& (CEffect::*CEffect_Construct_1)(EffFileData&);
extern CEffect& (*CEffect_CreateEffect)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum);
extern void (*CEffect_CreateItemEffect)(ITEM_EFFECT&, DWORD);
extern ITEM_EFFECT& (CEffect::*CEffect_ToItemEffect)();
extern void (CEffect::*CEffect_Deconstruct)();
extern CEffect& (CEffect::*CEffect_Duplicate)();
extern BOOL (CEffect::*CEffect_ApplyEffect)(CCreatureObject&);
extern void (CEffect::*CEffect_ApplyTiming)(CCreatureObject&);
extern void (CEffect::*CEffect_v10)();
extern void (CEffect::*CEffect_v14)();
extern BOOL (CEffect::*CEffect_TrySave)(CCreatureObject&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&, BYTE&);
extern void (CEffect::*CEffect_v1c)();
extern void (CEffect::*CEffect_PrintEffectText)(CCreatureObject&);
extern void (CEffect::*CEffect_v24)(CCreatureObject&);

class CPtrListEffect : public CPtrList { //Size 2Ch
public:
	//0xAAA8A8
	void RemoveEffect(CCreatureObject&, DWORD, POSITION, DWORD, ResRef, BOOL);

	POSITION posItrNext; //1ch
	POSITION posItrPrev; //20h
	DWORD u24; //24h
	BOOL bRefreshCurrentState; //28h
};

extern void (CPtrListEffect::*CPtrListEffect_RemoveEffect)(CCreatureObject&, DWORD, POSITION, DWORD, ResRef, BOOL);

#endif //EFFCORE_H