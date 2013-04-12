#include "rescore.h"

//Res
DefineLibMemberFunc(void, Res, RemoveFromHandler, (), RemoveFromHandler, RemoveFromHandler, (), 0x987FCD);
DefineLibMemberFunc(void, Res, AddToHandler, (), AddToHandler, AddToHandler, (), 0x98827D);

//ResItm
DefineLibMemberFunc(void*, ResItm, Demand, (), Demand, Demand, (), 0x40191C);
DefineLibMemberFunc(int, ResItm, Release, (), Release, Release, (), 0x401AFD);

//KeyTable
DefineLibMemberFunc(KeyTableEntry&, KeyTable, FindKey, (ResRef& rName, CRES_TYPE nResType, BOOL bLogError), FindKey, FindKey, (rName, nResType, bLogError), 0x99B009);

//CResHandler
DefineLibMemberFunc(void, CResHandler, Free, (Res& res), Free, Free, (res), 0x99555F);
