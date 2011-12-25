#include "cmapstrstrex.h"

#include "utils.h"

IECMapStringToString& (IECMapStringToString::*IECMapStringToString_Construct_1)(int) =
	SetFP(static_cast<IECMapStringToString& (IECMapStringToString::*)(int)>						(&IECMapStringToString::Construct),		0xA4FB1F);
void (IECMapStringToString::*IECMapStringToString_InitHashTable)(UINT, BOOL) =
	SetFP(static_cast<void (IECMapStringToString::*)(UINT, BOOL)>								(&IECMapStringToString::InitHashTable),	0xA4FB62);
void (IECMapStringToString::*IECMapStringToString_RemoveAll)() =
	SetFP(static_cast<void (IECMapStringToString::*)()>											(&IECMapStringToString::RemoveAll),		0xA4FBA7);
void (IECMapStringToString::*IECMapStringToString_Deconstruct)() =
	SetFP(static_cast<void (IECMapStringToString::*)()>											(&IECMapStringToString::Deconstruct),	0xA4FC01);
BOOL (IECMapStringToString::*IECMapStringToString_Lookup)(LPCTSTR, IECString&) const =
	SetFP(static_cast<BOOL (IECMapStringToString::*)(LPCTSTR, IECString&) const>				(&IECMapStringToString::Lookup),		0xA4FD1C);
BOOL (IECMapStringToString::*IECMapStringToString_LookupKey)(LPCTSTR, LPCTSTR&) const =
	SetFP(static_cast<BOOL (IECMapStringToString::*)(LPCTSTR, LPCTSTR&) const>					(&IECMapStringToString::LookupKey),		0xA4FD42);
IECString& (IECMapStringToString::*IECMapStringToString_OpArray)(LPCTSTR) =
	SetFP(static_cast<IECString& (IECMapStringToString::*)(LPCTSTR)>							(&IECMapStringToString::OpArray),		0xA4FD64);
BOOL (IECMapStringToString::*IECMapStringToString_RemoveKey)(LPCTSTR) =
	SetFP(static_cast<BOOL (IECMapStringToString::*)(LPCTSTR)>									(&IECMapStringToString::RemoveKey),		0xA4FDC6);
void (IECMapStringToString::*IECMapStringToString_GetNextAssoc)(POSITION&, IECString&, IECString&) const =
	SetFP(static_cast<void (IECMapStringToString::*)(POSITION&, IECString&, IECString&) const>	(&IECMapStringToString::GetNextAssoc),	0xA4FE2A);
void (IECMapStringToString::*IECMapStringToString_Serialize)(CArchive&) =
	SetFP(static_cast<void (IECMapStringToString::*)(CArchive&)>								(&IECMapStringToString::Serialize),		0xA4FE99);

IECMapStringToString::IECMapStringToString(int nBlockSize)													{ (this->*IECMapStringToString_Construct_1)(nBlockSize); }
void IECMapStringToString::InitHashTable(UINT nHashSize, BOOL bAllocNow)									{ return (this->*IECMapStringToString_InitHashTable)(nHashSize, bAllocNow); }
void IECMapStringToString::RemoveAll()																		{ return (this->*IECMapStringToString_RemoveAll)(); }
IECMapStringToString::~IECMapStringToString()																{ (this->*IECMapStringToString_Deconstruct)(); }
BOOL IECMapStringToString::Lookup(LPCTSTR key, IECString& rValue) const										{ return (this->*IECMapStringToString_Lookup)(key, rValue); }
BOOL IECMapStringToString::LookupKey(LPCTSTR key, LPCTSTR& rKey) const										{ return (this->*IECMapStringToString_LookupKey)(key, rKey); }
IECString& IECMapStringToString::operator[](LPCTSTR key)													{ return (this->*IECMapStringToString_OpArray)(key); }
BOOL IECMapStringToString::RemoveKey(LPCTSTR key)															{ return (this->*IECMapStringToString_RemoveKey)(key); }
void IECMapStringToString::GetNextAssoc(POSITION& rNextPosition, IECString& rKey, IECString& rValue) const	{ return (this->*IECMapStringToString_GetNextAssoc)(rNextPosition, rKey, rValue); }
void IECMapStringToString::Serialize(CArchive& ar)															{ return (this->*IECMapStringToString_Serialize)(ar); }

const CMapStringToString& IECMapStringToString::ToCMapStringToString() const	{ return reinterpret_cast<const CMapStringToString&>(*this); }
CMapStringToString& IECMapStringToString::ToCMapStringToString()				{ return reinterpret_cast<CMapStringToString&>(*this); }
int IECMapStringToString::GetCount() const										{ return (*this).ToCMapStringToString().GetCount(); }
BOOL IECMapStringToString::IsEmpty() const										{ return (*this).ToCMapStringToString().IsEmpty(); }
//void IECMapStringToString::SetAt(LPCTSTR key, LPCTSTR newValue)				{ return (*this).ToCMapStringToString().SetAt(key, newValue); }
POSITION IECMapStringToString::GetStartPosition() const							{ return (*this).ToCMapStringToString().GetStartPosition(); }
UINT IECMapStringToString::GetHashTableSize() const								{ return (*this).ToCMapStringToString().GetHashTableSize(); }

IMPLEMENT_SERIAL(IECMapStringToString, CObject, 0)
