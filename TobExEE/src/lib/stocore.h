//TobExEE
#ifndef STOCORE_H
#define STOCORE_H

#include "stdafx.h"
#include "itmcore.h"
#include "rescore.h"

typedef IECPtrList CStoFileItemList;

struct ResStoFile { //Size 10h
	BOOL m_bLoaded; //0h
	ResSto* m_pRes; //4h
	ResRef m_rName; //8h
};

struct CStore { //Size DCh
public:
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

#endif //STOCORE_H