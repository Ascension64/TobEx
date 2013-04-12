//TobExEE
#include "cmapstrstrex.h"
#include "p_cmapss.h"

#include "utils.h"

DefineLibNoRetFunc(IECMapStringToString&, IECMapStringToString, IECMapStringToString, (int nBlockSize), Construct, Construct, (nBlockSize), IECMAPSTRINGTOSTRING_CONSTRUCT);
DefineLibMemberFunc(void, IECMapStringToString, InitHashTable, (UINT nHashSize, BOOL bAllocNow), InitHashTable, InitHashTable, (nHashSize, bAllocNow), IECMAPSTRINGTOSTRING_INITHASHTABLE);
DefineLibMemberFunc(void, IECMapStringToString, RemoveAll, (), RemoveAll, RemoveAll, (), IECMAPSTRINGTOSTRING_REMOVEALL);
DefineLibNoRetFunc(void, IECMapStringToString, ~IECMapStringToString, (), Deconstruct, Deconstruct, (), IECMAPSTRINGTOSTRING_DECONSTRUCT);
DefineLibMemberFunc(BOOL, IECMapStringToString, Lookup, (LPCTSTR key, IECString& rValue) const, Lookup, Lookup, (key, rValue), IECMAPSTRINGTOSTRING_LOOKUP);

BOOL IECMapStringToString::LookupKey(LPCTSTR key, LPCTSTR& rKey) const
{
	ASSERT_VALID(this);

	UINT nHash;
	CAssoc* pAssoc = GetAssocAt(key, nHash);
	if (pAssoc == NULL)
		return FALSE;  // not in map

	rKey = pAssoc->key;
	return TRUE;
}

DefineLibMemberFunc(IECString&, IECMapStringToString, operator[], (LPCTSTR key), OpArray, OpArray, (key), IECMAPSTRINGTOSTRING_OPARRAY);
DefineLibMemberFunc(BOOL, IECMapStringToString, RemoveKey, (LPCTSTR key), RemoveKey, RemoveKey, (key), IECMAPSTRINGTOSTRING_REMOVEKEY);
DefineLibMemberFunc(void, IECMapStringToString, GetNextAssoc, (POSITION& rNextPosition, IECString& rKey, IECString& rValue) const, GetNextAssoc, GetNextAssoc, (rNextPosition, rKey, rValue), IECMAPSTRINGTOSTRING_GETASSOCAT);

DefineLibMemberFunc(IECMapStringToString::CAssoc*, IECMapStringToString, GetAssocAt, (LPCTSTR key, UINT& nHash) const, GetAssocAt, GetAssocAt, (key, nHash), IECMAPSTRINGTOSTRING_GETASSOCAT);

const CMapStringToString& IECMapStringToString::ToCMapStringToString() const	{ return reinterpret_cast<const CMapStringToString&>(*this); }
CMapStringToString& IECMapStringToString::ToCMapStringToString()				{ return reinterpret_cast<CMapStringToString&>(*this); }
int IECMapStringToString::GetCount() const										{ return (*this).ToCMapStringToString().GetCount(); }
BOOL IECMapStringToString::IsEmpty() const										{ return (*this).ToCMapStringToString().IsEmpty(); }
//void IECMapStringToString::SetAt(LPCTSTR key, LPCTSTR newValue)				{ return (*this).ToCMapStringToString().SetAt(key, newValue); }
POSITION IECMapStringToString::GetStartPosition() const							{ return (*this).ToCMapStringToString().GetStartPosition(); }
UINT IECMapStringToString::GetHashTableSize() const								{ return (*this).ToCMapStringToString().GetHashTableSize(); }

IMPLEMENT_SERIAL(IECMapStringToString, CObject, 0)
