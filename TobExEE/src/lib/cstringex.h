//TobExEE
#ifndef CSTRINGEX_H
#define CSTRINGEX_H

#include "win32def.h"
#include "globals.h"

class IECString {
	DEFINE_MEMALLOC_FUNC;
public:
	IECString(TCHAR ch, int nRepeat = 1);
	IECString& Construct(TCHAR ch, int nRepeat = 1) {return *this;} //dummy

	IECString(LPCSTR lpch, int nLength);
	IECString& Construct(LPCSTR lpch, int nLength) {return *this;} //dummy

	//IECString(LPCWSTR lpch, int nLength);
	//IECString& Construct(LPCWSTR lpch, int nLength) {return *this;} //dummy

	const IECString& operator=(TCHAR ch);
	const IECString& OpAssign(TCHAR ch) {return *this;} //dummy

	friend IECString AFXAPI operator+(const IECString& string, TCHAR ch);
	friend IECString AFXAPI IECString_OpAdd(const IECString& string, TCHAR ch) {return string;} //dummy

	friend IECString AFXAPI operator+(TCHAR ch, const IECString& string);
	friend IECString AFXAPI IECString_OpAdd(TCHAR ch, const IECString& string) {return string;} //dummy

	int Delete(int nIndex, int nCount = 1);
	int Insert(int nIndex, TCHAR ch); //re-implemented
	int Insert(int nIndex, LPCTSTR pstr); //re-implemented
	int Replace(TCHAR chOld, TCHAR chNew);
	int Replace(LPCTSTR lpszOld, LPCTSTR lpszNew); //re-implemented
	int Remove(TCHAR chRemove); //re-implemented
	IECString Mid(int nFirst, int nCount) const;
	IECString Mid(int nFirst) const;
	IECString Right(int nCount) const;
	IECString Left(int nCount) const;
	IECString SpanIncluding(LPCTSTR lpszCharSet) const;
	IECString SpanExcluding(LPCTSTR lpszCharSet) const;
	int ReverseFind(TCHAR ch) const;
	int Find(LPCTSTR lpszSub) const;
	int Find(LPCTSTR lpszSub, int nStart) const;
	void FormatV(LPCTSTR lpzFormat, va_list argList);
	void AFX_CDECL Format(LPCTSTR lpszFormat, ...); //re-implemented
	void AFX_CDECL Format(UINT nFormatID, ...); //re-implemented
	void AFX_CDECL FormatMessage(LPCTSTR lpszFormat, ...); //re-implemented
	void AFX_CDECL FormatMessage(UINT nFormatID, ...); //re-implemented
	void TrimRight(LPCTSTR lpszTargetList); //re-implemented
	void TrimRight(TCHAR chTarget);
	void TrimRight();
	void TrimLeft(LPCTSTR lpszTargets); //re-implemented
	void TrimLeft(TCHAR chTarget); //re-implemented
	void TrimLeft();

	IECString();
	IECString& Construct() {return *this;} //dummy

	IECString(const IECString& stringSrc);
	IECString& Construct(const IECString& stringSrc) {return *this;} //dummy

	void Empty();

	~IECString();
	void Deconstruct() {} //dummy

	IECString(LPCSTR lpsz);
	IECString& Construct(LPCSTR lpsz) {return *this;} //dummy

	//IECString(LPCWSTR lpsz);
	//IECString& Construct(LPCWSTR lpsz) {return *this;} //dummy

	const IECString& operator=(const IECString& stringSrc);
	const IECString& OpAssign(const IECString& stringSrc) {return *this;} //dummy

	const IECString& operator=(LPCSTR lpsz);
	const IECString& OpAssign(LPCSTR lpsz) {return *this;} //dummy

	//const IECString& operator=(LPCWSTR lpsz);
	//const IECString& OpAssign(LPCWSTR lpsz) {return *this;} //dummy
	
	friend IECString AFXAPI operator+(const IECString& string1, const IECString& string2);
	friend IECString AFXAPI IECString_OpAdd(const IECString& string1, const IECString& string2) {return string1;} //dummy

	friend IECString AFXAPI operator+(const IECString& string, LPCTSTR lpsz);
	friend IECString AFXAPI IECString_OpAdd(const IECString& string, LPCTSTR lpsz) {return string;} //dummy

	friend IECString AFXAPI operator+(LPCTSTR lpsz, const IECString& string);
	friend IECString AFXAPI IECString_OpAdd(LPCTSTR lpsz, const IECString& string) {return string;} //dummy

	const IECString& operator+=(LPCTSTR lpsz);
	const IECString& OpAddEq(LPCTSTR lpsz) {return *this;} //dummy

	const IECString& operator+=(TCHAR ch);
	const IECString& OpAddEq(TCHAR ch) {return *this;} //dummy

	const IECString& operator+=(const IECString& string);
	const IECString& OpAddEq(const IECString& string) {return *this;} //dummy

	LPTSTR GetBuffer(int nMinBufLength);
	void ReleaseBuffer(int nNewLength = -1);
	LPTSTR GetBufferSetLength(int nNewLength);
	void FreeExtra(); //re-implemented
	LPTSTR LockBuffer(); //re-implemented
	void UnlockBuffer(); //re-implemented
	int Find(TCHAR ch) const;
	int Find(TCHAR ch, int nStart) const;
	int FindOneOf(LPCTSTR lpszCharSet) const;
	void MakeUpper();
	void MakeLower();
	void MakeReverse(); //re-implemented
	void SetAt(int nIndex, TCHAR ch);
	//void AnsiToOem();
	//void OemToAnsi();
	BOOL LoadString(UINT nID);

	//integration with CString
	operator CString() const;
	operator LPCTSTR() const;

	int GetLength() const;
	BOOL IsEmpty() const;
	TCHAR GetAt(int nIndex) const;
	TCHAR operator[](int nIndex) const;
	int Compare(LPCTSTR lpsz) const;
	int CompareNoCase(LPCTSTR lpsz) const;
	int Collate(LPCTSTR lpsz) const;
	int CollateNoCase(LPCTSTR lpsz) const;
	int GetAllocLength() const;

protected:
	LPTSTR m_pchData;

public:
	// implementation helpers - added TobExEE to support new re-implemented functions
	CStringData* GetData() const;
	void Init();
	void AllocCopy(CString& dest, int nCopyLen, int nCopyIndex, int nExtraLen) const;
	void AllocBuffer(int nLen);
	void AssignCopy(int nSrcLen, LPCTSTR lpszSrcData);
	void ConcatCopy(int nSrc1Len, LPCTSTR lpszSrc1Data, int nSrc2Len, LPCTSTR lpszSrc2Data);
	void ConcatInPlace(int nSrcLen, LPCTSTR lpszSrcData);
	void CopyBeforeWrite();
	void AllocBeforeWrite(int nLen);
	void Release();
	static void PASCAL Release(CStringData* pData);
	static int PASCAL SafeStrlen(LPCTSTR lpsz);
	static void FASTCALL FreeData(CStringData* pData);
};

#endif //CSTRINGEX_H