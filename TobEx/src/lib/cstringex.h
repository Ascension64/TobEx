#ifndef CSTRINGEX_H
#define CSTRINGEX_H

#include "utils.h"

class IECString {
public:
	IECString(TCHAR, int);
	IECString& Construct(TCHAR ch, int nRepeat = 1) {return *this;} //dummy

	IECString(LPCSTR, int);
	IECString& Construct(LPCSTR lpch, int nLength) {return *this;} //dummy

	IECString(LPCWSTR, int);
	IECString& Construct(LPCWSTR lpch, int nLength) {return *this;} //dummy

	const IECString& operator=(TCHAR);
	const IECString& OpEq(TCHAR ch) {return *this;} //dummy

	friend IECString AFXAPI operator+(const IECString&, TCHAR);
	friend IECString AFXAPI IECString_OpAdd(const IECString& string, TCHAR ch) {return string;} //dummy

	friend IECString AFXAPI operator+(TCHAR, const IECString&);
	friend IECString AFXAPI IECString_OpAdd(TCHAR ch, const IECString& string) {return string;} //dummy

	int Delete(int, int);
	int Insert(int, TCHAR);
	int Insert(int, LPCTSTR);
	int Replace(TCHAR, TCHAR);
	int Replace(LPCTSTR, LPCTSTR);
	int Remove(TCHAR);
	IECString Mid(int, int) const;
	IECString Mid(int) const;
	IECString Left(int) const;
	IECString Right(int) const;
	IECString SpanIncluding(LPCTSTR) const;
	IECString SpanExcluding(LPCTSTR) const;
	int ReverseFind(TCHAR) const;
	int Find(LPCTSTR) const;
	int Find(LPCTSTR, int) const;
	void FormatV(LPCTSTR, va_list);
	//void AFX_CDECL Format(LPCTSTR, ...);
	//void AFX_CDECL Format(UINT, ...);
	//void AFX_CDECL FormatMessage(LPCTSTR, ...);
	//void AFX_CDECL FormatMessage(UINT, ...);
	void TrimRight(LPCTSTR);
	void TrimRight(TCHAR);
	void TrimRight();
	void TrimLeft(LPCTSTR);
	void TrimLeft(TCHAR);
	void TrimLeft();

	IECString();
	IECString& Construct(void) {return *this;} //dummy

	IECString(const IECString&);
	IECString& Construct(const IECString& stringSrc) {return *this;} //dummy

	void Empty();

	~IECString();
	void Deconstruct(void) {} //dummy

	IECString(LPCSTR);
	IECString& Construct(LPCSTR lpsz) {return *this;} //dummy

	IECString(LPCWSTR);
	IECString& Construct(LPCWSTR lpsz) {return *this;} //dummy

	const IECString& operator=(const IECString&);
	const IECString& OpEq(const IECString& stringSrc) {return *this;} //dummy

	const IECString& operator=(LPCSTR);
	const IECString& OpEq(LPCSTR lpsz) {return *this;} //dummy

	const IECString& operator=(LPCWSTR);
	const IECString& OpEq(LPCWSTR lpsz) {return *this;} //dummy
	
	friend IECString AFXAPI operator+(const IECString&, const IECString&);
	friend IECString AFXAPI IECString_OpAdd(const IECString& string1, const IECString& string2) {return string1;} //dummy

	friend IECString AFXAPI operator+(const IECString&, LPCTSTR);
	friend IECString AFXAPI IECString_OpAdd(const IECString& string, LPCTSTR lpsz) {return string;} //dummy

	friend IECString AFXAPI operator+(LPCTSTR, const IECString&);
	friend IECString AFXAPI IECString_OpAdd(LPCTSTR lpsz, const IECString& string) {return string;} //dummy

	const IECString& operator+=(LPCTSTR);
	const IECString& OpAddEq(LPCTSTR lpsz) {return *this;} //dummy

	const IECString& operator+=(TCHAR);
	const IECString& OpAddEq(TCHAR ch) {return *this;} //dummy

	const IECString& operator+=(const IECString&);
	const IECString& OpAddEq(const IECString& string) {return *this;} //dummy

	LPTSTR GetBuffer(int);
	void ReleaseBuffer(int);
	LPTSTR GetBufferSetLength(int);
	void FreeExtra();
	LPTSTR LockBuffer();
	void UnlockBuffer();
	int Find(TCHAR) const;
	int Find(TCHAR, int) const;
	int FindOneOf(LPCTSTR) const;
	void MakeUpper();
	void MakeLower();
	void MakeReverse();
	void SetAt(int, TCHAR);
	void AnsiToOem();
	void OemToAnsi();

	//integration with IECString
	void* operator new(size_t);
	void operator delete(void*);
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
extern const IECString& (IECString::*IECString_OpEq_TCHAR)(TCHAR);
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
extern IECString (IECString::*IECString_Left_int)(int) const;
extern IECString (IECString::*IECString_Right_int)(int) const;
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

extern IECString& (IECString::*IECString_Construct_0)(void);
extern IECString& (IECString::*IECString_Construct_1CString)(const IECString&);
extern void (IECString::*IECString_Empty)(void);
extern void (IECString::*IECString_Deconstruct)(void);
extern IECString& (IECString::*IECString_Construct_1LPCSTR)(LPCSTR);
extern IECString& (IECString::*IECString_Construct_1LPCWSTR)(LPCWSTR);
extern const IECString& (IECString::*IECString_OpEq_CString)(const IECString&);
extern const IECString& (IECString::*IECString_OpEq_LPCSTR)(LPCSTR);
extern const IECString& (IECString::*IECString_OpEq_LPCWSTR)(LPCWSTR);
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