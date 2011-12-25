#ifndef STOCORE_H
#define STOCORE_H

#include "stdafx.h"
#include "datatypes.h"
#include "rescore.h"

typedef IECPtrList CStoreItemList; //AACCB0

struct ResStoContainer { //Size 10h
//Constructor: 0x6463FC
	BOOL bLoaded; //0h
	ResSto* pRes; //4h
	ResRef name; //8h
};

struct CServerStore { //Size DCh
//constructor: 0x643CB0
public:
	ResRef m_filename; //0h
	StoFileData sto; //8h
	CStoreItemList items; //9ch, AACCB0
	StoFileBuyType* m_pBuyTypes; //b8h, array of 'Items Purchased Here' extended header
	int m_nBuyTypes; //bch, same as 30h
	StoFileDrink* m_pDrinks; //c0h, array 
	int m_nDrinks; //c4h, same as 50h
	StoFileSpell* m_pSpells; //c8h, array
	int m_nSpells; //cch, same as 74h
	ResRef m_header; //d0h, STORV1.0
	BOOL ud8;
};

#endif //STOCORE_H