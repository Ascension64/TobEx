//TobExEE
#ifndef ITMCORE_H
#define ITMCORE_H

#include "effcore.h"
#include "rescore.h"
#include "sndcore.h"

//CItem flags (20h)
#define CITEMFLAG_IDENTIFIED	0x00000001

typedef IECPtrList CItemList; //AA7264

class CCreatureObject;

struct ResItmFile { //Size 10h
	BOOL m_bLoaded; //0h
	ResItm* m_pRes; //4h
	ResRef m_rName; //8h
};

class CItem { //Size 84h
public:
	virtual ~CItem();
	void Deconstruct() {} //dummy

	ResItmFile m_itm; //4h
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
	unsigned int m_dwFlags; //20h, Arg7 (as per Cre/StoFileItem)
	CSoundWrapper m_sndAttack1; //24h
	CSoundWrapper m_sndAttack2; //3ch
	short m_wNumAttackSounds; //54h

	struct unk1 { //Size 2Ch
		IECPtrList u0;
		int u1c;
		int u20;
		int u24;
		int u28;
	} u58;
};

struct CCreInventory { //Size A4h
	CItem* m_items[39]; //0h, as SLOTS.IDS
	char m_nSlotSelected; //9ch
	char p9d;
	short m_nAbilitySelected; //9eh
	CItem* m_pGrabbedItem; //a0h, pCItem is bit 16 set in creature flags
};

#endif //ITMCORE_H