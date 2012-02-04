#include "stocore.h"

CStore& (CStore::*CStore_Construct_0)() =
	SetFP(static_cast<CStore& (CStore::*)()>			(&CStore::Construct),			0x643CB0);
CStore& (CStore::*CStore_Construct_1_ResRef)(ResRef&) =
	SetFP(static_cast<CStore& (CStore::*)(ResRef&)>		(&CStore::Construct),			0x643D4B);
void (CStore::*CStore_Deconstruct)() =
	SetFP(static_cast<void (CStore::*)()>				(&CStore::Deconstruct),			0x643E21);
void (CStore::*CStore_Unmarshal)(ResRef&) =
	SetFP(static_cast<void (CStore::*)(ResRef&)>		(&CStore::Unmarshal),			0x64424C);
int (CStore::*CStore_GetNumItemsInStock)() =
	SetFP(static_cast<int (CStore::*)()>				(&CStore::GetNumItemsInStock),	0x645758);
int (CStore::*CStore_GetItemAmount)(int) =
	SetFP(static_cast< int (CStore::*)(int)>			(&CStore::GetItemAmount),		0x6457E7);
BOOL (CStore::*CStore_UnmarshalItem)(int, CItem*) =
	SetFP(static_cast<BOOL (CStore::*)(int, CItem*)>	(&CStore::UnmarshalItem),		0x64583E);
ResRef (CStore::*CStore_GetItemName)(int) =
	SetFP(static_cast<ResRef (CStore::*)(int)>			(&CStore::GetItemName),			0x645B43);

CStore::CStore() { (this->*CStore_Construct_0)(); }
CStore::CStore(ResRef& rName) { (this->*CStore_Construct_1_ResRef)(rName); }
CStore::~CStore() { (this->*CStore_Deconstruct)(); }
void CStore::Unmarshal(ResRef& rName) { return (this->*CStore_Unmarshal)(rName); }
int CStore::GetNumItemsInStock() { return (this->*CStore_GetNumItemsInStock)(); }
BOOL CStore::UnmarshalItem(int nIndex, CItem* ptr) { return (this->*CStore_UnmarshalItem)(nIndex, ptr); }
int CStore::GetItemAmount(int nIndex) { return (this->*CStore_GetItemAmount)(nIndex); }
ResRef CStore::GetItemName(int nIndex) { return (this->*CStore_GetItemName)(nIndex); }

