#ifndef STOCORE_H
#define STOCORE_H

#include "utils.h"
#include "rescore.h"
#include "resref.h"

typedef DWORD CStoreBuyType;
typedef CPtrList CStoreItemList; //AACCB0

struct ResStoContainer {
//Size: 0x10
//Constructor: 0x6463FC
	BOOL bLoaded; //0h
	ResEff* pRes; //4h
	ResRef name; //8h
};

struct CStoreItem {
//size: 0x1c
//corresponds to 'Item for sale' extended header
	ResRef name; //0h
	WORD arg6; //8h
	WORD usage1; //ah
	WORD usage2; //ch
	WORD usage3; //eh
	DWORD flags; //10h
	DWORD nInStock; //14h
	BOOL bInfinite; //18h
};

struct CStoreDrink {
//size: 0x14
//corresponds to 'Drinks for sale' extended header
	ResRef rumour; //0h
	STRREF name; //8h
	DWORD price; //ch
	DWORD drinkStrength; //10h
};

struct CStoreSpell {
//size: 0x10
//corresponds to 'Cures for sale' extended header
	ResRef spell; //0h
	DWORD price; //8h
};

struct CServerStore {
//size: 0xDC
//constructor: 0x643CB0
public:

	//corresponds to STORV1.0 header
	ResRef m_filename; //0h
	DWORD type; //8h
	STRREF name; //ch
	DWORD flags; //10h
	DWORD nSellPercent; //14h
	DWORD nBuyPercent; //18h
	DWORD nDepreciationRate; //1ch
	WORD nStealFailPercent; //20h
	WORD nMaxItems; //22h
	QWORD u24;
	DWORD* pItemTypesBought; //2ch
	DWORD nItemTypesBought; //30h
	DWORD* pItemsSold; //34h
	DWORD nItemsSold; //38h
	DWORD nLore; //3ch
	DWORD nPriceID; //40h
	ResRef RumoursTavern; //44h
	DWORD* pDrinks; //4ch
	DWORD nDrinks; //50h
	ResRef RumoursTemple; //54h
	DWORD flagsRoom; //5ch
	DWORD nPriceRoomPeasant; //60h
	DWORD nPriceRoomMerchant; //64h
	DWORD nPriceRoomNoble; //68h
	DWORD nPriceRoomRoyal; //6ch
	DWORD* pCures; //70h
	DWORD nCures; //74h
	DWORD u78[9];

	CStoreItemList items; //9ch, AACCB0
	CStoreBuyType* m_pBuyTypes; //b8h, array of 'Items Purchased Here' extended header
	DWORD m_nBuyTypes; //bch, same as 30h
	CStoreDrink* m_pDrinks; //c0h, array 
	DWORD m_nDrinks; //c4h, same as 50h
	CStoreSpell* m_pSpells; //c8h, array
	DWORD m_nSpells; //cch, same as 74h
	ResRef m_header; //d0h, STORV1.0
	BOOL ud8;
};

#endif //STOCORE_H