//TobExEE
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

struct CStoreProduct { //2Ch size, FIX_ME
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

class CScreenStore : public CEngine { //Size 894h
public:
	CHotkey m_keymap[95]; //d0h, size 474h
	int m_keybuffer[95]; //544h, size 17Ch

	char u6c0;
	char p6c1[3];
	int u6c4;
	CPanel* m_pMainPanel; //6c8h, active panel
	int m_nTopCustomerItem; //6cch
	CStoreProductList m_cplCustomerItems; //6d0h
	int m_nTopHostItem; //6ech
	CStoreProductList m_cplHostItems; //6f0h
	int m_nTopSpellItem; //70ch
	CStoreProductList m_cplSpellItems; //710h
	int m_nTopIdentifyItem; //72ch
	CStoreProductList m_cplIdentifyItems; //730h, 2Ch size as above
	int m_nTopDrinkItem; //74ch, for drinks
	ResRef m_rStoreName; //750h
	ResRef u758;
	int m_nButtonBarPanelArray[4]; //760h, for the 4 button bar buttons, specifies the associated panel
	CStore* m_pStore; //770h
	CStore* m_pBag; //774h, for when opening containers within stores
	int m_nTotalBuyPrice; //778h
	int m_nTotalSellPrice; //77ch
	int m_nTotalSpellItemsPrice; //780h
	int m_nTotalIdentifyItemsPrice; //784h
	int m_nRoomQuality; //788h, 0 = nil, 1 = peasant, 2 = merchant, 3 = noble, 4 = royal
	Object m_oHost; //78ch
	Object m_oCustomer; //7a0h
	int u7b4; //m_nTotalDonatePrice?, related to donate panel
	int u7b8;
	int u7bc;
	IECPtrList u7c0;
	int u7dc[2];
	ResRef u7e4;
	CPanel* m_pButtonBar; //7ech, either 3 (Single) or 15 (Multi)
	CUITextArea* m_pChatArea; //7f0h
	int u7f4;
	STRREF m_strrefErrorButtonArray[3]; //7f8h, 0 = done, 1 = info (e.g. not enough gold, etc.)
	int u804;
	int u808;
	int u80c;
	char m_cCustomerCharisma; //810h
	char p811[3];
	CVidFont m_fntRealms; //814h
	CVidFont m_fntStoneSml; //838h
	CVidFont m_fntToolFont; //85ch
	int u880;
	int u884;
	int u888;
	int u88c;
	int m_nNumBags; //890h, when in a bag, gets count of number of other bags in inventory
};

#endif //ENGSTORE_H