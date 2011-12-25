#include "stocore.h"

CServerStore& (CServerStore::*CServerStore_Construct_0)() =
	SetFP(static_cast<CServerStore& (CServerStore::*)()>		(&CServerStore::Construct),			0x643CB0);
CServerStore& (CServerStore::*CServerStore_Construct_1_ResRef)(ResRef&) =
	SetFP(static_cast<CServerStore& (CServerStore::*)(ResRef&)>	(&CServerStore::Construct),			0x643D4B);
void (CServerStore::*CServerStore_Deconstruct)() =
	SetFP(static_cast<void (CServerStore::*)()>					(&CServerStore::Deconstruct),		0x643E21);
void (CServerStore::*CServerStore_Unmarshal)(ResRef&) =
	SetFP(static_cast<void (CServerStore::*)(ResRef&)>			(&CServerStore::Unmarshal),			0x64424C);
int (CServerStore::*CServerStore_GetNumItemsInStock)() =
	SetFP(static_cast<int (CServerStore::*)()>					(&CServerStore::GetNumItemsInStock),0x645758);
int (CServerStore::*CServerStore_GetItemAmount)(int) =
	SetFP(static_cast< int (CServerStore::*)(int)>				(&CServerStore::GetItemAmount),		0x6457E7);
BOOL (CServerStore::*CServerStore_UnmarshalItem)(int, CItem*) =
	SetFP(static_cast<BOOL (CServerStore::*)(int, CItem*)>		(&CServerStore::UnmarshalItem),		0x64583E);
ResRef (CServerStore::*CServerStore_GetItemName)(int) =
	SetFP(static_cast<ResRef (CServerStore::*)(int)>			(&CServerStore::GetItemName),		0x645B43);

CServerStore::CServerStore() { (this->*CServerStore_Construct_0)(); }
CServerStore::CServerStore(ResRef& rName) { (this->*CServerStore_Construct_1_ResRef)(rName); }
CServerStore::~CServerStore() { (this->*CServerStore_Deconstruct)(); }
void CServerStore::Unmarshal(ResRef& rName) { return (this->*CServerStore_Unmarshal)(rName); }
int CServerStore::GetNumItemsInStock() { return (this->*CServerStore_GetNumItemsInStock)(); }
BOOL CServerStore::UnmarshalItem(int nIndex, CItem* ptr) { return (this->*CServerStore_UnmarshalItem)(nIndex, ptr); }
int CServerStore::GetItemAmount(int nIndex) { return (this->*CServerStore_GetItemAmount)(nIndex); }
ResRef CServerStore::GetItemName(int nIndex) { return (this->*CServerStore_GetItemName)(nIndex); }

