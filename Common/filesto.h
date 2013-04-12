#ifndef FILESTO_H
#define FILESTO_H

#include "stdafx.h"
#include "resref.h"

//Store flags
#define STOREFLAG_BUY		0x1
#define STOREFLAG_SELL		0x2
#define STOREFLAG_IDENTIFY	0x4
#define STOREFLAG_STEAL		0x8
#define STOREFLAG_DONATE	0x10
#define STOREFLAG_SPELLS	0x20
#define STOREFLAG_DRINKS	0x40
#define STOREFLAG_QUALITY_1	0x200
#define STOREFLAG_QUALITY_2	0x400
#define STOREFLAG_FENCE		0x1000
#define STOREFLAG_RECHARGE	0x4000

//Store types
#define STORETYPE_STORE		0
#define STORETYPE_TAVERN	1
#define STORETYPE_INN		2
#define STORETYPE_TEMPLE	3
#define STORETYPE_4			4
#define STORETYPE_BAG		5

//Sto
struct StoFileData { //Size 94h
	int m_nType; //0h
	STRREF m_strrefName; //4h
	unsigned int m_dwFlags; //8h
	int m_nSellPercent; //ch
	int m_nBuyPercent; //10h
	int m_nDepreciationRate; //14h
	short m_nStealFailPercent; //18h
	short m_nMaxItems; //1ah
	long u1c[2]; //1ch
	int* m_pItemTypesBought; //24h
	int m_nItemTypesBought; //28h
	int* m_pItemsSold; //2ch
	int m_nItemsSold; //30h
	int m_nLore; //34h
	int m_nPriceID; //38h
	ResRef m_rRumoursTavern; //3ch
	int* m_pDrinks; //40h
	int m_nDrinks; //48h
	ResRef m_rRumoursTemple; //4ch
	int m_dwFlagsRoom; //54h
	int m_nPriceRoomPeasant; //58h
	int m_nPriceRoomMerchant; //5ch
	int m_nPriceRoomNoble; //60h
	int m_nPriceRoomRoyal; //64h
	int* m_pSpells; //68h
	int m_nSpells; //6ch
	int u70[9];
};

struct StoFileBuyType { //Size 4h
	int m_nType;
};

struct StoFileDrink { //Size 14h
//corresponds to 'Drinks for sale' extended header
	ResRef m_rRumour; //0h
	STRREF m_strrefName; //8h
	int m_nPrice; //ch
	int m_nStrength; //10h
};

struct StoFileItem { //Size 1Ch
//corresponds to 'Item for sale' extended header
	ResRef m_rName; //0h
	short m_wWear; //8h, 0xFF + time until recharge in absolute game hours
	short m_wUsage[3]; //ah
	unsigned int dwFlags; //10h
	int m_nNumInStock; //14h
	BOOL m_bInfinite; //18h
};

struct StoFileSpell { //Size 10h
//corresponds to 'Cures for sale' extended header
	ResRef m_rSpell; //0h
	int m_nPrice; //8h
};

#endif //FILESTO_H