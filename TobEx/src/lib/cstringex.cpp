#include "cstringex.h"

#include "utils.h"

DefineLibNoRetFunc(IECString&, IECString, IECString, (TCHAR ch, int nRepeat), Construct, Construct2_TCHAR, (ch, nRepeat), 0xA4D075);
DefineLibNoRetFunc(IECString&, IECString, IECString, (LPCSTR lpch, int nLength), Construct, Construct2_LPCSTR, (lpch, nLength), 0xA4D0A9);
DefineLibNoRetFunc(IECString&, IECString, IECString, (LPCWSTR lpch, int nLength), Construct, Construct2_LPCWSTR, (lpch, nLength), 0xA4D0DB);
DefineLibMemberFunc(const IECString&, IECString, operator=, (TCHAR ch), OpAssign, OpAssign_TCHAR, (ch), 0xA4D124);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (const IECString& string, TCHAR ch), OpAdd, OpAdd_IECString_TCHAR, (string, ch), 0xA4D139);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (TCHAR ch, const IECString& string), OpAdd, OpAdd_TCHAR_IECString, (ch, string), 0xA4D19B);
DefineLibMemberFunc(int, IECString, Delete, (int nIndex, int nCount), Delete, Delete, (nIndex, nCount), 0xA4D1FD);
DefineLibMemberFunc(int, IECString, Insert, (int nIndex, TCHAR ch), Insert, Insert2_TCHAR, (nIndex, ch), 0xA4D255);
DefineLibMemberFunc(int, IECString, Insert, (int nIndex, LPCTSTR pstr), Insert, Insert2_LPCTSTR, (nIndex, pstr), 0xA4D2D9);
DefineLibMemberFunc(int, IECString, Replace, (TCHAR chOld, TCHAR chNew), Replace, Replace2_THCAR, (chOld, chNew), 0xA4D38E);
DefineLibMemberFunc(int, IECString, Replace, (LPCTSTR lpszOld, LPCTSTR lpszNew), Replace, Replace2_LPCTSTR, (lpszOld, lpszNew), 0xA4D3CB);
DefineLibMemberFunc(int, IECString, Remove, (TCHAR chRemove), Remove, Remove, (chRemove), 0xA4D52E);
DefineLibMemberFunc(IECString, IECString, Mid, (int nFirst, int nCount) const, Mid, Mid2, (nFirst, nCount), 0xA4D57F);
DefineLibMemberFunc(IECString, IECString, Mid, (int nFirst) const, Mid, Mid1, (nFirst), 0xA4D5A2);
DefineLibMemberFunc(IECString, IECString, Right, (int nCount) const, Right, Right, (nCount), 0xA4D638);
DefineLibMemberFunc(IECString, IECString, Left, (int nCount) const, Left, Left, (nCount), 0xA4D6B4);
DefineLibMemberFunc(IECString, IECString, SpanIncluding, (LPCTSTR lpszCharSet) const, SpanIncluding, SpanIncluding, (lpszCharSet), 0xA4D72C);
DefineLibMemberFunc(IECString, IECString, SpanExcluding, (LPCTSTR lpszCharSet) const, SpanExcluding, SpanExcluding, (lpszCharSet), 0xA4D757);
DefineLibMemberFunc(int, IECString, ReverseFind, (TCHAR ch) const, ReverseFind, ReverseFind, (ch), 0xA4D782);
DefineLibMemberFunc(int, IECString, Find, (LPCTSTR lpszSub) const, Find, Find1, (lpszSub), 0xA4D7A4);
DefineLibMemberFunc(int, IECString, Find, (LPCTSTR lpszSub, int nStart) const, Find, Find2, (lpszSub, nStart), 0xA4D7B2);
DefineLibMemberFunc(void, IECString, FormatV, (LPCTSTR lpszFormat, va_list argList), FormatV, FormatV, (lpszFormat, argList), 0xA4D7DD);

//re-implementations from STREX.CPP
void AFX_CDECL IECString::Format(LPCTSTR lpszFormat, ...) {
	va_list argList;
	va_start(argList, lpszFormat);
	FormatV(lpszFormat, argList);
	va_end(argList);
	return;
}

void AFX_CDECL IECString::Format(UINT nFormatID, ...) {
	IECString strFormat;
	VERIFY(strFormat.LoadString(nFormatID) != 0);

	va_list argList;
	va_start(argList, nFormatID);
	FormatV(strFormat, argList);
	va_end(argList);
	return;
}

void AFX_CDECL IECString::FormatMessage(LPCTSTR lpszFormat, ...) {
	// format message into temporary buffer lpszTemp
	va_list argList;
	va_start(argList, lpszFormat);
	LPTSTR lpszTemp;

	if (::FormatMessage(FORMAT_MESSAGE_FROM_STRING|FORMAT_MESSAGE_ALLOCATE_BUFFER,
		lpszFormat, 0, 0, (LPTSTR)&lpszTemp, 0, &argList) == 0 ||
		lpszTemp == NULL)
	{
		AfxThrowMemoryException();
	}

	// assign lpszTemp into the resulting string and free the temporary
	*this = lpszTemp;
	LocalFree(lpszTemp);
	va_end(argList);
	return;
}

void AFX_CDECL IECString::FormatMessage(UINT nFormatID, ...) {
	// get format string from string table
	IECString strFormat;
	VERIFY(strFormat.LoadString(nFormatID) != 0);

	// format message into temporary buffer lpszTemp
	va_list argList;
	va_start(argList, nFormatID);
	LPTSTR lpszTemp;
	if (::FormatMessage(FORMAT_MESSAGE_FROM_STRING|FORMAT_MESSAGE_ALLOCATE_BUFFER,
		strFormat, 0, 0, (LPTSTR)&lpszTemp, 0, &argList) == 0 ||
		lpszTemp == NULL)
	{
		AfxThrowMemoryException();
	}

	// assign lpszTemp into the resulting string and free lpszTemp
	*this = lpszTemp;
	LocalFree(lpszTemp);
	va_end(argList);
	return;
}

DefineLibMemberFunc(void, IECString, TrimRight, (LPCTSTR lpszTargets), TrimRight, TrimRight1_LPCTSTR, (lpszTargets), 0xA4DC10);
DefineLibMemberFunc(void, IECString, TrimRight, (TCHAR chTarget), TrimRight, TrimRight1_TCHAR, (chTarget), 0xA4DC63);
DefineLibMemberFunc(void, IECString, TrimRight, (), TrimRight, TrimRight0, (), 0xA4DCA5);
DefineLibMemberFunc(void, IECString, TrimLeft, (LPCTSTR lpszTargets), TrimLeft, TrimLeft1_LPCTSTR, (lpszTargets), 0xA4DCF1);
DefineLibMemberFunc(void, IECString, TrimLeft, (TCHAR chTarget), TrimLeft, TrimLeft1_TCHAR, (chTarget), 0xA4DD59);
DefineLibMemberFunc(void, IECString, TrimLeft, (), TrimLeft, TrimLeft0, (), 0xA4DD9C);

IECString::IECString()	{ m_pchData = reinterpret_cast<LPTSTR>(0xB72024); }

DefineLibNoRetFunc(IECString&, IECString, IECString, (const IECString& stringSrc), Construct, Construct1_IECString, (stringSrc), 0xA50642);
DefineLibMemberFunc(void, IECString, Empty, (), Empty, Empty, (), 0xA50858);
DefineLibNoRetFunc(void, IECString, ~IECString, (), Deconstruct, Deconstruct, (), 0xA508CD);
DefineLibNoRetFunc(IECString&, IECString, IECString, (LPCSTR lpsz), Construct, Construct1_LPCTSTR, (lpsz), 0xA5093B);
DefineLibNoRetFunc(IECString&, IECString, IECString, (LPCWSTR lpsz), Construct, Construct1_LPCWSTR, (lpsz), 0xA5098D);
DefineLibMemberFunc(const IECString&, IECString, operator=, (const IECString& stringSrc), OpAssign, OpAssign_IECString, (stringSrc), 0xA50A06);
DefineLibMemberFunc(const IECString&, IECString, operator=, (LPCSTR lpsz), OpAssign, OpAssign_LPCSTR, (lpsz), 0xA50A56);
DefineLibMemberFunc(const IECString&, IECString, operator=, (LPCWSTR lpsz), OpAssign, OpAssign_LPCWSTR, (lpsz), 0xA50A7D);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (const IECString& string1, const IECString& string2), OpAdd, OpAdd_IECString_IECString, (string1, string2), 0xA50AFC);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (const IECString& string, LPCTSTR lpsz), OpAdd, OpAdd_IECString_LPCTSTR, (string, lpsz), 0xA50B62);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (LPCTSTR lpsz, const IECString& string), OpAdd, OpAdd_LPCTSTR_IECString, (lpsz, string), 0xA50BD6);
DefineLibMemberFunc(const IECString&, IECString, operator+=, (LPCTSTR lpsz), OpAddEq, OpAddEq_LPCTSTR, (lpsz), 0xA50CA9);
DefineLibMemberFunc(const IECString&, IECString, operator+=, (TCHAR ch), OpAddEq, OpAddEq_TCHAR, (ch), 0xA50CD0);
DefineLibMemberFunc(const IECString&, IECString, operator+=, (const IECString& string), OpAddEq, OpAddEq_IECString, (string), 0xA50CE5);
DefineLibMemberFunc(LPTSTR, IECString, GetBuffer, (int nMinBufLength), GetBuffer, GetBuffer, (nMinBufLength), 0xA50CFD);
DefineLibMemberFunc(void, IECString, ReleaseBuffer, (int nNewLength), ReleaseBuffer, ReleaseBuffer, (nNewLength), 0xA50D4C);
DefineLibMemberFunc(LPTSTR, IECString, GetBufferSetLength, (int nNewLength), GetBufferSetLength, GetBufferSetLength, (nNewLength), 0xA50D74);
DefineLibMemberFunc(void, IECString, FreeExtra, (), FreeExtra, FreeExtra, (), 0xA50D94);
DefineLibMemberFunc(LPTSTR, IECString, LockBuffer, (), LockBuffer, LockBuffer, (), 0xA50DC7);
DefineLibMemberFunc(void, IECString, UnlockBuffer, (), UnlockBuffer, UnlockBuffer, (), 0xA50DD9);
DefineLibMemberFunc(int, IECString, Find, (TCHAR ch) const, Find, Find_TCHAR, (ch), 0xA50DEE);
DefineLibMemberFunc(int, IECString, Find, (TCHAR ch, int nStart) const, Find, Find_TCHAR_int, (ch, nStart), 0xA50DFC);
DefineLibMemberFunc(int, IECString, FindOneOf, (LPCTSTR lpszCharSet) const, FindOneOf, FindOneOf, (lpszCharSet), 0xA50E29);
DefineLibMemberFunc(void, IECString, MakeUpper, (), MakeUpper, MakeUpper, (), 0xA50E49);
DefineLibMemberFunc(void, IECString, MakeLower, (), MakeLower, MakeLower, (), 0xA50E5B);
DefineLibMemberFunc(void, IECString, MakeReverse, (), MakeReverse, MakeReverse, (), 0xA50E6D);
DefineLibMemberFunc(void, IECString, SetAt, (int nIndex, TCHAR ch), SetAt, SetAt, (nIndex, ch), 0xA50E7F);
DefineLibMemberFunc(void, IECString, AnsiToOem, (), AnsiToOem, AnsiToOem, (), 0xA50E98);
DefineLibMemberFunc(void, IECString, OemToAnsi, (), OemToAnsi, OemToAnsi, (), 0xA50EAC);
DefineLibMemberFunc(BOOL, IECString, LoadString, (UINT nID), LoadStringA, LoadStringA, (nID), 0xA52004);

IECString::operator CString() const								{ return reinterpret_cast<const CString&>(*this); }
IECString::operator LPCTSTR() const								{ return (LPCTSTR)((CString)(*this)); }

int IECString::GetLength() const								{ return ((CString)(*this)).GetLength(); }
BOOL IECString::IsEmpty() const									{ return ((CString)(*this)).IsEmpty(); }
TCHAR IECString::GetAt(int nIndex) const						{ return ((CString)(*this)).GetAt(nIndex); }
TCHAR IECString::operator[](int nIndex) const					{ return ((CString)(*this)).operator[](nIndex); }
int IECString::Compare(LPCTSTR lpsz) const						{ return ((CString)(*this)).Compare(lpsz); }
int IECString::CompareNoCase(LPCTSTR lpsz) const				{ return ((CString)(*this)).CompareNoCase(lpsz); }
int IECString::Collate(LPCTSTR lpsz) const						{ return ((CString)(*this)).Collate(lpsz); }
int IECString::CollateNoCase(LPCTSTR lpsz) const				{ return ((CString)(*this)).CollateNoCase(lpsz); }
int IECString::GetAllocLength() const							{ return ((CString)(*this)).GetAllocLength(); }