#ifndef ITMCORE_H
#define ITMCORE_H

#include "effcore.h"
#include "rescore.h"
#include "sndcore.h"

//CItem flags (20h)
#define CITEMFLAG_IDENTIFIED	0x00000001

typedef IECPtrList CItemList; //AA7264

class CCreatureObject;

struct ResItmContainer { //Size 10h
	BOOL bLoaded; //0h
	ResItm* pRes; //4h
	ResRef name; //8h
};

class CItem { //Size FAh
//Constructor: 0x5A83F0 (0 args), 0x5A9538 (6 args), 0x5A84BE (1 arg)
public:
	CItem();
	CItem& Construct() { return *this; } //dummy

	CItem(CItem& itm);
	CItem& Construct(CItem& itm) { return *this; } //dummy

	BOOL Demand();
	BOOL Release();
	void LoadResource(ResRef& res, BOOL bAddToHandler);
	int GetNumAbilities();
	short GetNumUsage(int nUsageIdx);
	short GetNumCharges(int nAbilityIdx);
	void SetNumUsage(int nUsageIdx, short wValue);
	void Equip(CCreatureObject& cre, int nSlot, BOOL bDoNotApplyEffects);
	ItmFileAbility& GetAbility(int nAbilityIdx);
	CEffect& GetAbilityEffect(int nAbilityIdx, int nEffectIdx, CCreatureObject& creSource);
	short GetType();
	unsigned int GetFlags();
	unsigned int GetUnusableFlags();
	short GetMaximumStackSize();
	char GetProficiencyType();

	//AAB400
	virtual ~CItem();
	void Deconstruct() {} //dummy

	ResItmContainer m_itm; //4h
	int m_nNumAbilities; //14h
	short m_wUsage1; //18h, nUsesAbility0, usage1, is it a randomly generated item?, Arg3
	short m_wUsage2; //1ah, nUsesAbility1, usage2, Arg4
	short m_wUsage3; //1ch, nUsesAbility2, usage3 (time to recharge in ai updates?), Arg5

	//0: disabled
	//1-255: hours until recharge
	//255 + x: x is absolute game hours until recharge
	short m_wWear; //1eh, Arg6

	//bit0: identified
	//bit1: unstealable
	//bit2: stolen
	//bit3: undroppable, used during simulacrum
	unsigned int dwFlags; //20h, Arg7 (as per Cre/StoFileItem)
	CSound sndAttack1; //24h
	CSound sndAttack2; //8eh
	short m_wNumAttackSounds; //f8h
};

extern CItem& (CItem::*CItem_Construct_0)();
extern CItem& (CItem::*CItem_Construct_1)(CItem&);
extern void (CItem::*CItem_Deconstruct)();
extern BOOL (CItem::*CItem_Demand)();
extern BOOL (CItem::*CItem_Release)();
extern void (CItem::*CItem_LoadResource)(ResRef&, BOOL);
extern int (CItem::*CItem_GetNumAbilities)();
extern short (CItem::*CItem_GetNumUsage)(int);
extern short (CItem::*CItem_GetNumCharges)(int);
extern void (CItem::*CItem_SetNumUsage)(int, short);
extern void (CItem::*CItem_Equip)(CCreatureObject&, int, BOOL);
extern ItmFileAbility& (CItem::*CItem_GetAbility)(int);
extern CEffect& (CItem::*CItem_GetAbilityEffect)(int, int, CCreatureObject&);
extern short (CItem::*CItem_GetType)();
extern unsigned int (CItem::*CItem_GetFlags)();
extern unsigned int (CItem::*CItem_GetUnusableFlags)();
extern short (CItem::*CItem_GetMaximumStackSize)();
extern char (CItem::*CItem_GetProficiencyType)();

struct CCreInventory { //Size A4h
//Constructor: 0x8BE36A
	CItem* items[39]; //0h, slots follow SLOTS.IDS
	char nSlotSelected; //9ch
	char u9d; //pad
	short nAbilitySelected; //9eh
	CItem* pGrabbedItem; //a0h, pCItem is bit 16 set in creature flags
};

#endif //ITMCORE_H