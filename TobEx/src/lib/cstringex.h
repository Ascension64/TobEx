#ifndef CSTRINGEX_H
#define CSTRINGEX_H

#include "win32def.h"

class IECString {
public:
	IECString(TCHAR ch, int nRepeat = 1);
	IECString& Construct(TCHAR ch, int nRepeat = 1) {return *this;} //dummy

	IECString(LPCSTR lpch, int nLength);
	IECString& Construct(LPCSTR lpch, int nLength) {return *this;} //dummy

	IECString(LPCWSTR lpch, int nLength);
	IECString& Construct(LPCWSTR lpch, int nLength) {return *this;} //dummy

	const IECString& operator=(TCHAR ch);
	const IECString& OpAssign(TCHAR ch) {return *this;} //dummy

	friend IECString AFXAPI operator+(const IECString& string, TCHAR ch);
	friend IECString AFXAPI IECString_OpAdd(const IECString& string, TCHAR ch) {return string;} //dummy

	friend IECString AFXAPI operator+(TCHAR, const IECString& string);
	friend IECString AFXAPI IECString_OpAdd(TCHAR ch, const IECString& string) {return string;} //dummy

	int Delete(int nIndex, int nCount = 1);
	int Insert(int nIndex, TCHAR ch);
	int Insert(int nIndex, LPCTSTR pstr);
	int Replace(TCHAR chOld, TCHAR chNew);
	int Replace(LPCTSTR lpszOld, LPCTSTR lpszNew);
	int Remove(TCHAR chRemove);
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
	//void AFX_CDECL Format(LPCTSTR lpszFormat, ...);
	//void AFX_CDECL Format(UINT nFormatID, ...);
	//void AFX_CDECL FormatMessage(LPCTSTR lpszFormat, ...);
	//void AFX_CDECL FormatMessage(UINT nFormatID, ...);
	void TrimRight(LPCTSTR lpszTargets);
	void TrimRight(TCHAR chTarget);
	void TrimRight();
	void TrimLeft(LPCTSTR lpszTargets);
	void TrimLeft(TCHAR chTarget);
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

	IECString(LPCWSTR lpsz);
	IECString& Construct(LPCWSTR lpsz) {return *this;} //dummy

	const IECString& operator=(const IECString& stringSrc);
	const IECString& OpAssign(const IECString& stringSrc) {return *this;} //dummy

	const IECString& operator=(LPCSTR lpsz);
	const IECString& OpAssign(LPCSTR lpsz) {return *this;} //dummy

	const IECString& operator=(LPCWSTR lpsz);
	const IECString& OpAssign(LPCWSTR lpsz) {return *this;} //dummy
	
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
	void FreeExtra();
	LPTSTR LockBuffer();
	void UnlockBuffer();
	int Find(TCHAR ch) const;
	int Find(TCHAR ch, int nStart) const;
	int FindOneOf(LPCTSTR lpszCharSet) const;
	void MakeUpper();
	void MakeLower();
	void MakeReverse();
	void SetAt(int nIndex, TCHAR ch);
	void AnsiToOem();
	void OemToAnsi();

	//integration with IECString
	void* operator new(size_t size);
	void operator delete(void* mem);
	void operator delete[](void* mem);
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
	BOOL LoadString(UINT nID);
	int GetAllocLength() const;

protected:
	LPTSTR m_pchData;
};

extern IECString& (IECString::*IECString_Construct_2TCHAR_int)(TCHAR, int);
extern IECString& (IECString::*IECString_Construct_2LPCSTR_int)(LPCSTR, int);
extern IECString& (IECString::*IECString_Construct_2LPCWSTR_int)(LPCWSTR, int);
extern const IECString& (IECString::*IECString_OpAssign_TCHAR)(TCHAR);
extern IECString (AFXAPI *IECString_OpAdd_IECString_TCHAR)(const IECString&, TCHAR);
extern IECString (AFXAPI *IECString_OpAdd_TCHAR_IECString)(TCHAR, const IECString&);
extern int (IECString::*IECString_Delete)(int, int);
extern int (IECString::*IECString_Insert_int_TCHAR)(int, TCHAR);
extern int (IECString::*IECString_Insert_int_LPCTSTR)(int, LPCTSTR);
extern int (IECString::*IECString_Replace_TCHAR)(TCHAR, TCHAR);
extern int (IECString::*IECString_Replace_LPCTSTR)(LPCTSTR, LPCTSTR);
extern int (IECString::*IECString_Remove)(TCHAR);
extern IECString (IECString::*IECString_Mid_int_int)(int, int) const;
extern IECString (IECString::*IECString_Mid_int)(int) const;
extern IECString (IECString::*IECString_Right_int)(int) const;
extern IECString (IECString::*IECString_Left_int)(int) const;
extern IECString (IECString::*IECString_SpanIncluding)(LPCTSTR) const;
extern IECString (IECString::*IECString_SpanExcluding)(LPCTSTR) const;
extern int (IECString::*IECString_ReverseFind)(TCHAR) const;
extern int (IECString::*IECString_Find_LPCTSTR)(LPCTSTR) const;
extern int (IECString::*IECString_Find_LPCTSTR_valist)(LPCTSTR, int) const;
extern void (IECString::*IECString_FormatV)(LPCTSTR, va_list);
//extern void (AFX_CDECL IECString::*IECString_Format_LPCTSTR)(LPCTSTR, ...);
//extern void (AFX_CDECL IECString::*IECString_Format_UINT)(UINT, ...);
//extern void (AFX_CDECL IECString::*IECString_FormatMessage_LPCTSTR)(LPCTSTR, ...);
//extern void (AFX_CDECL IECString::*IECString_FormatMessage_UINT)(UINT, ...);
extern void (IECString::*IECString_TrimRight_LPCTSTR)(LPCTSTR);
extern void (IECString::*IECString_TrimRight_TCHAR)(TCHAR);
extern void (IECString::*IECString_TrimRight)();
extern void (IECString::*IECString_TrimLeft_LPCTSTR)(LPCTSTR);
extern void (IECString::*IECString_TrimLeft_TCHAR)(TCHAR);
extern void (IECString::*IECString_TrimLeft)();

extern IECString& (IECString::*IECString_Construct_0)();
extern IECString& (IECString::*IECString_Construct_1CString)(const IECString&);
extern void (IECString::*IECString_Empty)();
extern void (IECString::*IECString_Deconstruct)();
extern IECString& (IECString::*IECString_Construct_1LPCSTR)(LPCSTR);
extern IECString& (IECString::*IECString_Construct_1LPCWSTR)(LPCWSTR);
extern const IECString& (IECString::*IECString_OpAssign_CString)(const IECString&);
extern const IECString& (IECString::*IECString_OpAssign_LPCSTR)(LPCSTR);
extern const IECString& (IECString::*IECString_OpAssign_LPCWSTR)(LPCWSTR);
extern IECString (AFXAPI *IECString_OpAdd_CString_CString)(const IECString&, const IECString&);
extern IECString (AFXAPI *IECString_OpAdd_CString_LPCTSTR)(const IECString&, LPCTSTR);
extern IECString (AFXAPI *IECString_OpAdd_LPCTSTR_CString)(LPCTSTR, const IECString&);
extern const IECString& (IECString::*IECString_OpAddEq_LPCTSTR)(LPCTSTR);
extern const IECString& (IECString::*IECString_OpAddEq_TCHAR)(TCHAR);
extern const IECString& (IECString::*IECString_OpAddEq_CString)(const IECString&);
extern LPTSTR (IECString::*IECString_GetBuffer)(int);
extern void (IECString::*IECString_ReleaseBuffer)(int);
extern LPTSTR (IECString::*IECString_GetBufferSetLength)(int);
extern void (IECString::*IECString_FreeExtra)();
extern LPTSTR (IECString::*IECString_LockBuffer)();
extern void (IECString::*IECString_UnlockBuffer)();
extern int (IECString::*IECString_Find_TCHAR)(TCHAR) const;
extern int (IECString::*IECString_Find_THCAR_int)(TCHAR, int) const;
extern int (IECString::*IECString_FindOneOf)(LPCTSTR) const;
extern void (IECString::*IECString_MakeUpper)();
extern void (IECString::*IECString_MakeLower)();
extern void (IECString::*IECString_MakeReverse)();
extern void (IECString::*IECString_SetAt)(int, TCHAR);
extern void (IECString::*IECString_AnsiToOem)();
extern void (IECString::*IECString_OemToAnsi)();

#endif //CSTRINGEX_H