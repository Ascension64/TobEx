#include "stocore.h"

DefineLibNoRetFunc(CStore&, CStore, CStore, (), Construct, Construct0, (), 0x643CB0);
DefineLibNoRetFunc(CStore&, CStore, CStore, (ResRef& rName), Construct, Construct1, (rName), 0x643D4B);
DefineLibNoRetFunc(void, CStore, ~CStore, (), Deconstruct, Deconstruct, (), 0x643E21);
DefineLibMemberFunc(void, CStore, Unmarshal, (ResRef& rName), Unmarshal, Unmarshal, (rName), 0x64424C);
DefineLibMemberFunc(int, CStore, GetNumItemsInStock, (), GetNumItemsInStock, GetNumItemsInStock, (), 0x645758);
DefineLibMemberFunc(int, CStore, GetItemAmount, (int nIndex), GetItemAmount, GetItemAmount, (nIndex), 0x6457E7);
DefineLibMemberFunc(BOOL, CStore, UnmarshalItem, (int nIndex, CItem* ptr), UnmarshalItem, UnmarshalItem, (nIndex, ptr), 0x64583E);
DefineLibMemberFunc(ResRef, CStore, GetItemName, (int nIndex), GetItemName, GetItemName, (nIndex), 0x645B43);
