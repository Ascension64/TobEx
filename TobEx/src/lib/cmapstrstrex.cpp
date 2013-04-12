#include "cmapstrstrex.h"

#include "utils.h"

DefineLibNoRetFunc(IECMapStringToString&, IECMapStringToString, IECMapStringToString, (int nBlockSize), Construct, Construct, (nBlockSize), 0xA4FB1F);
DefineLibMemberFunc(void, IECMapStringToString, InitHashTable, (UINT nHashSize, BOOL bAllocNow), InitHashTable, InitHashTable, (nHashSize, bAllocNow), 0xA4FB62);
DefineLibMemberFunc(void, IECMapStringToString, RemoveAll, (), RemoveAll, RemoveAll, (), 0xA4FBA7);
DefineLibNoRetFunc(void, IECMapStringToString, ~IECMapStringToString, (), Deconstruct, Deconstruct, (), 0xA4FC01);
DefineLibMemberFunc(BOOL, IECMapStringToString, Lookup, (LPCTSTR key, IECString& rValue) const, Lookup, Lookup, (key, rValue), 0xA4FD1C);
DefineLibMemberFunc(BOOL, IECMapStringToString, LookupKey, (LPCTSTR key, LPCTSTR& rKey) const, LookupKey, LookupKey, (key, rKey), 0xA4FD42);
DefineLibMemberFunc(IECString&, IECMapStringToString, operator[], (LPCTSTR key), OpArray, OpArray, (key), 0xA4FD64);
DefineLibMemberFunc(BOOL, IECMapStringToString, RemoveKey, (LPCTSTR key), RemoveKey, RemoveKey, (key), 0xA4FDC6);
DefineLibMemberFunc(void, IECMapStringToString, GetNextAssoc, (POSITION& rNextPosition, IECString& rKey, IECString& rValue) const, GetNextAssoc, GetNextAssoc, (rNextPosition, rKey, rValue), 0xA4FE2A);
DefineLibMemberFunc(void, IECMapStringToString, Serialize, (CArchive& ar), Serialize, Serialize, (ar), 0xA4FE99);

const CMapStringToString& IECMapStringToString::ToCMapStringToString() const	{ return reinterpret_cast<const CMapStringToString&>(*this); }
CMapStringToString& IECMapStringToString::ToCMapStringToString()				{ return reinterpret_cast<CMapStringToString&>(*this); }
int IECMapStringToString::GetCount() const										{ return (*this).ToCMapStringToString().GetCount(); }
BOOL IECMapStringToString::IsEmpty() const										{ return (*this).ToCMapStringToString().IsEmpty(); }
//void IECMapStringToString::SetAt(LPCTSTR key, LPCTSTR newValue)				{ return (*this).ToCMapStringToString().SetAt(key, newValue); }
POSITION IECMapStringToString::GetStartPosition() const							{ return (*this).ToCMapStringToString().GetStartPosition(); }
UINT IECMapStringToString::GetHashTableSize() const								{ return (*this).ToCMapStringToString().GetHashTableSize(); }

IMPLEMENT_SERIAL(IECMapStringToString, CObject, 0)
