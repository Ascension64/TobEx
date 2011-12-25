#ifndef ITMCORE_H
#define ITMCORE_H

#include "rescore.h"
#include "sndcore.h"

//Item flags
#define ITEMFLAG_CRITICAL			0x00000001
#define ITEMFLAG_TWO_HANDED			0x00000002
#define ITEMFLAG_DROPPABLE			0x00000004
#define ITEMFLAG_DISPLAYABLE		0x00000008 //unused in BG2?
#define ITEMFLAG_CURSED				0x00000010
#define ITEMFLAG_NOT_COPYABLE		0x00000020 //unused in BG2?
#define ITEMFLAG_MAGICAL			0x00000040 //unused in BG2?
#define ITEMFLAG_BOW				0x00000080 //unused in BG2?
#define ITEMFLAG_SILVER				0x00000100
#define ITEMFLAG_COLD_IRON			0x00000200
#define ITEMFLAG_STOLEN				0x00000400
#define ITEMFLAG_CONVERSABLE		0x00000800
#define ITEMFLAG_NOT_DISPELLABLE	0x01000000 //new in TobEx, tob_hacks, Spell Revisions
#define ITEMFLAG_TOGGLE_CRITICALHIT	0x02000000 //new in TobEx

//Item types
#define ITEMTYPE_MISC			0x00
#define ITEMTYPE_AMULET			0x01
#define ITEMTYPE_ARMOR			0x02
#define ITEMTYPE_BELT			0x03
#define ITEMTYPE_BOOTS			0x04
#define ITEMTYPE_ARROW			0x05
#define ITEMTYPE_GAUNTLET		0x06
#define ITEMTYPE_HELMET			0x07
#define ITEMTYPE_KEY			0x08
#define ITEMTYPE_POTION			0x09
#define ITEMTYPE_RING			0x0A
#define ITEMTYPE_SCROLL			0x0B
#define ITEMTYPE_SHIELD			0x0C
#define ITEMTYPE_FOOD			0x0D
#define ITEMTYPE_BULLET			0x0E
#define ITEMTYPE_BOW			0x0F
#define ITEMTYPE_DAGGER			0x10
#define ITEMTYPE_MACE			0x11
#define ITEMTYPE_SLING			0x12
#define ITEMTYPE_SMALL_SWORD	0x13
#define ITEMTYPE_LARGE_SWORD	0x14
#define ITEMTYPE_HAMMER			0x15
#define ITEMTYPE_MORNING_STAR	0x16
#define ITEMTYPE_FLAIL			0x17
#define ITEMTYPE_DART			0x18
#define ITEMTYPE_AXE			0x19
#define ITEMTYPE_STAFF			0x1A
#define ITEMTYPE_XBOW			0x1B
#define ITEMTYPE_HAND			0x1C
#define ITEMTYPE_SPEAR			0x1D
#define ITEMTYPE_HALBERD		0x1E
#define ITEMTYPE_BOLT			0x1F
#define ITEMTYPE_CLOAK			0x20
#define ITEMTYPE_GOLD			0x21
#define ITEMTYPE_GEM			0x22
#define ITEMTYPE_WAND			0x23

//Item unusable flags
#define ITEMUNUSABLE_THIEF		0x00400000

//Item ability attack types
#define ITEMABILITYATTACKTYPE_DEFAULT	0
#define ITEMABILITYATTACKTYPE_MELEE	1
#define ITEMABILITYATTACKTYPE_RANGED	2
#define ITEMABILITYATTACKTYPE_MAGICAL	3
#define ITEMABILITYATTACKTYPE_LAUNCHER	4

//Item ability flags
#define ITEMABILITYFLAG_STRENGTH_BONUS			0x00000001
#define ITEMABILITYFLAG_BREAKABLE				0x00000002 //unused in BG2?
#define ITEMABILITYFLAG_RECHARGES				0x00000800
#define ITEMABILITYFLAG_IWD2_BYPASS_ARMOR		0x00010000 //IWD2 only
#define ITEMABILITYFLAG_IWD2_KEEN				0x00020000 //IWD2 only
#define ITEMABILITYFLAG_BYPASS_MIRROR_IMAGE		0x01000000 //new in TobEx, tob_hacks, Spell Revisions
#define ITEMABILITYFLAG_TOGGLE_BACKSTAB			0x02000000 //new by TobEx

typedef IECPtrList CItemList;

struct ResItmContainer { //Size 10h
	BOOL bLoaded; //0x0
	ResItm* pRes; //0x4
	ResRef name; //0x8
};

class CItem { //Size FAh
//Constructor: 0x5A83F0 (0 args), 0x5A9538 (6 args), 0x5A84BE (1 arg)
public:
	BOOL Demand();
	BOOL Release();
	void LoadResource(ResRef& res, BOOL bAddToHandler);
	short GetType();
	unsigned int GetFlags();
	unsigned int GetUnusableFlags();

	//AAB400
	virtual ~CItem() {}

	ResItmContainer m_itm; //4h
	int numAbilities; //14h
	short Arg3; //18h, usage1? is it a randomly generated item?
	short Arg4; //1ah, usage2?
	short Arg5; //1ch, usage3? (time to recharge in ai updates?)
	short Arg6; //1eh, related to usage3 (time to recharge in days?)
	BOOL bIdentified; //20h, Arg7
	CSound sound; //24h
	CSound sound2; //8eh
	short uf8; //f8h
};

extern BOOL (CItem::*CItem_Demand)();
extern BOOL (CItem::*CItem_Release)();
extern void (CItem::*CItem_LoadResource)(ResRef&, BOOL);
extern short (CItem::*CItem_GetType)();
extern unsigned int (CItem::*CItem_GetFlags)();
extern unsigned int (CItem::*CItem_GetUnusableFlags)();

struct CInventory { //Size A4h
//Constructor: 0x8BE36A
	CItem* items[39]; //0h, slots follow SLOTS.IDS
	char nSlotSelected; //9ch
	char u9d; //pad
	short nAbilitySelected; //9eh
	int a0h; //pCItem is bit 16 set in creature flags
};

#endif //ITMCORE_H