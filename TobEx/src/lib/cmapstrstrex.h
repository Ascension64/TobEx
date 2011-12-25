#ifndef CMAPSTRSTREX_H
#define CMAPSTRSTREX_H

#include "win32def.h"
#include "cstringex.h"

class IECMapStringToString : public CObject { //Size 1Ch
	DECLARE_SERIAL(IECMapStringToString)

public:
	IECMapStringToString(int nBlockSize = 10);
	IECMapStringToString& Construct(int nBlockSize = 10) { return *this; } //dummy

	void InitHashTable(UINT nHashSize, BOOL bAllocNow);

	void RemoveAll();

	~IECMapStringToString();
	void Deconstruct() {} //dummy

	BOOL Lookup(LPCTSTR key, IECString& rValue) const;
	BOOL LookupKey(LPCTSTR key, LPCTSTR& rKey) const;

	IECString& operator[](LPCTSTR key);
	IECString& OpArray(LPCTSTR key) { return *(new IECString()); } //dummy

	BOOL RemoveKey(LPCTSTR key);
	void GetNextAssoc(POSITION& rNextPosition, IECString& rKey, IECString& rValue) const;
	void Serialize(CArchive& ar);

	//integration with CMapStringToString
	const CMapStringToString& ToCMapStringToString() const;
	CMapStringToString& ToCMapStringToString();

	int GetCount() const;
	BOOL IsEmpty() const;
	//void SetAt(LPCTSTR key, LPCTSTR newValue);
	POSITION GetStartPosition() const;
	UINT GetHashTableSize() const;

protected:
	struct CAssoc
	{
		CAssoc* pNext;
		UINT nHashValue;  // needed for efficient iteration
		CString key;
		CString value;
	};

	CAssoc** m_pHashTable;
	UINT m_nHashTableSize;
	int m_nCount;
	CAssoc* m_pFreeList;
	struct CPlex* m_pBlocks;
	int m_nBlockSize;
};

extern IECMapStringToString& (IECMapStringToString::*IECMapStringToString_Construct_1)(int);
extern void (IECMapStringToString::*IECMapStringToString_InitHashTable)(UINT, BOOL);
extern void (IECMapStringToString::*IECMapStringToString_RemoveAll)();
extern void (IECMapStringToString::*IECMapStringToString_Deconstruct)();
extern BOOL (IECMapStringToString::*IECMapStringToString_Lookup)(LPCTSTR, IECString&) const;
extern BOOL (IECMapStringToString::*IECMapStringToString_LookupKey)(LPCTSTR, LPCTSTR&) const;
extern IECString& (IECMapStringToString::*IECMapStringToString_OpArray)(LPCTSTR);
extern BOOL (IECMapStringToString::*IECMapStringToString_RemoveKey)(LPCTSTR);
extern void (IECMapStringToString::*IECMapStringToString_GetNextAssoc)(POSITION&, IECString&, IECString&) const;
extern void (IECMapStringToString::*IECMapStringToString_Serialize)(CArchive&);

#endif //CMAPSTRSTREX_H