#ifndef ENGSTORE_H
#define ENGSTORE_H

#include "engine.h"
#include "uitext.h"

#define CSTOREPANEL_BUYSELL		2;
#define CSTOREPANEL_3			3;
#define CSTOREPANEL_IDENTIFY	4;
#define CSTOREPANEL_CURE		5;
#define CSTOREPANEL_STEAL		6;
#define CSTOREPANEL_ROOMS		7;
#define CSTOREPANEL_DRINKS		8;
#define CSTOREPANEL_DONATE		9;

typedef IECPtrList CStoreProductList;

struct CStoreProduct { //2Ch size
//constructor: see 0x7A2AA5
	ResRef rSpell; //0h, for cures
	CItem* pItem; //8h
	BOOL bSelected; //ch
	BOOL bEnabled; //10h, for identify, can it be bought/sold, depends on lore, ITEM_CRITICAL, and whether store will buy it
	unsigned int nIndex; //14h
	unsigned int nPrice; //18h, as in STO file
	unsigned int nSellPrice; //1ch, adjusted for charisma, etc.
	unsigned int nNumBuyableAtOnce; //20h, gets the smaller of u20h and u24h
	unsigned int nNumFittableInInventorySlots; //24h
	unsigned int nNumInStock; //28h, directly from store, 0FFFF if infinite
};

class CScreenStore : public CEngine { //Size 148Ah
//constructor: 0x799A53
public:
	//AB3FD4
	virtual void v0() {}

	CHotkey keymap[91];
	char keybuffer[92]; //3d6h

	char u432;
	char u433; //pad
	int u434;
	CPanel* m_pMainPanel; //438h, active panel
	int m_nTopCustomerItem; //43ch
	CStoreProductList m_cplCustomerItems; //440h
	int m_nTopHostItem; //45ch
	CStoreProductList m_cplHostItems; //460h
	int m_nTopSpellItem; //47ch
	CStoreProductList m_cplSpellItems; //480h
	int m_nTopIdentifyItem; //49ch
	CStoreProductList m_cplIdentifyItems; //4a0h, 2Ch size as above
	int m_nTopDrinkItem; //4bch, for drinks
	ResRef m_rStoreName; //4c0h
	ResRef u4c8;
	int m_nButtonBarPanelArray[4]; //for the 4 button bar buttons, specifies the associated panel
	CStore* m_pStore; //4e0h
	CStore* m_pBag; //4e4h, for when opening containers within stores
	int m_nTotalBuyPrice; //4e8h
	int m_nTotalSellPrice; //4ech
	int m_nTotalSpellItemsPrice; //4f0h
	int m_nTotalIdentifyItemsPrice; //4f4h
	int m_nRoomQuality; //4f8h, 0 = nil, 1 = peasant, 2 = merchant, 3 = noble, 4 = royal
	Object m_oHost; //4fch
	Object m_oCustomer; //510h
	int u524; //m_nTotalDonatePrice?, related to donate panel
	int u528;
	int u52c;
	IECPtrList u530;
	int u54c[2];
	ResRef u554;
	CPanel* m_pButtonBar; //55ch, either 3 (Single) or 15 (Multi)
	CUITextArea* m_pChatArea; //560h
	int u564;
	STRREF m_strrefErrorButtonArray[3]; //568h, 0 = done, 1 = info (e.g. not enough gold, etc.)
	int u574;
	int u578;
	int u57c;
	char m_cCustomerCharisma; //580h
	char u581; //pad
	CVidFont cvf_realms; //582h
	CVidFont cvf_stonesml; //a7eh
	CVidFont cvf_toolfont; //f7ah
	int u1476;
	int u147a;
	int u147e;
	int u1482;
	int m_nNumBags; //1486h, when in a bag, gets count of number of other bags in inventory
};

#endif //ENGSTORE_H