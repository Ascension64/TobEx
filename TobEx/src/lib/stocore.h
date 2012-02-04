#ifndef STOCORE_H
#define STOCORE_H

#include "stdafx.h"
#include "datatypes.h"
#include "itmcore.h"
#include "rescore.h"

typedef IECPtrList CStoFileItemList; //AACCB0

struct ResStoContainer { //Size 10h
//Constructor: 0x6463FC
	BOOL bLoaded; //0h
	ResSto* pRes; //4h
	ResRef name; //8h
};

struct CStore { //Size DCh
//constructor: 0x643CB0
public:
	CStore();
	CStore& Construct() { return *this; } //dummy

	CStore(ResRef& rName);
	CStore& Construct(ResRef& rName) { return *this; } //dummy

	~CStore();
	void Deconstruct() {} //dummy

	void Unmarshal(ResRef& rName);
	int GetNumItemsInStock();
	int GetItemAmount(int nIndex);
	BOOL UnmarshalItem(int nIndex, CItem* ptr);
	ResRef GetItemName(int nIndex);

	ResRef m_filename; //0h
	StoFileData sto; //8h
	CStoFileItemList m_items; //9ch
	StoFileBuyType* m_pBuyTypesArray; //b8h, 'Items Purchased Here' extended header
	int m_nBuyTypes; //bch, same as 30h
	StoFileDrink* m_pDrinksArray; //c0h
	int m_nDrinks; //c4h, same as 50h
	StoFileSpell* m_pSpellsArray; //c8h
	int m_nSpells; //cch, same as 74h
	ResRef m_header; //d0h, STORV1.0
	BOOL bUnmarshaled; //d8h
};

extern CStore& (CStore::*CStore_Construct_0)();
extern CStore& (CStore::*CStore_Construct_1_ResRef)(ResRef&);
extern void (CStore::*CStore_Deconstruct)();
extern void (CStore::*CStore_Unmarshal)(ResRef&);
extern int (CStore::*CStore_GetNumItemsInStock)();
extern int (CStore::*CStore_GetItemAmount)(int);
extern BOOL (CStore::*CStore_UnmarshalItem)(int, CItem*);
extern ResRef (CStore::*CStore_GetItemName)(int);

#endif //STOCORE_H