#include "itmcore.h"

#include "stdafx.h"

BOOL (CItem::*CItem_Demand)() =
	SetFP(static_cast<BOOL (CItem::*)()>				(&CItem::Demand),			0x5AA032);
BOOL (CItem::*CItem_Release)() =
	SetFP(static_cast<BOOL (CItem::*)()>				(&CItem::Release),			0x5AA07F);
void (CItem::*CItem_LoadResource)(ResRef&, BOOL) =
	SetFP(static_cast<void (CItem::*)(ResRef&, BOOL)>	(&CItem::LoadResource),		0x5AA0A7);
short (CItem::*CItem_GetType)() =
	SetFP(static_cast<short (CItem::*)()>				(&CItem::GetType),			0x5AB32B);
unsigned int (CItem::*CItem_GetFlags)() =
	SetFP(static_cast<unsigned int (CItem::*)()>		(&CItem::GetFlags),			0x5AB591);
unsigned int (CItem::*CItem_GetUnusableFlags)() =
	SetFP(static_cast<unsigned int (CItem::*)()>		(&CItem::GetUnusableFlags),	0x5AB609);

BOOL CItem::Demand()										{ return (this->*CItem_Demand)(); }
BOOL CItem::Release()										{ return (this->*CItem_Release)(); }
void CItem::LoadResource(ResRef& res, BOOL bAddToHandler)	{ return (this->*CItem_LoadResource)(res, bAddToHandler); }
short CItem::GetType()										{ return (this->*CItem_GetType)(); }
unsigned int CItem::GetFlags()								{ return (this->*CItem_GetFlags)(); }
unsigned int CItem::GetUnusableFlags()						{ return (this->*CItem_GetUnusableFlags)(); }