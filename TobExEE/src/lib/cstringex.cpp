//TobExEE
#include "cstringex.h"
#include "p_cstring.h"

#include "utils.h"

DefineLibNoRetFunc(IECString&, IECString, IECString, (TCHAR ch, int nRepeat), Construct, Construct2_TCHAR, (ch, nRepeat), IECSTRING_CONSTRUCT2_TCHAR);
DefineLibNoRetFunc(IECString&, IECString, IECString, (LPCSTR lpch, int nLength), Construct, Construct2_LPCSTR, (lpch, nLength), IECSTRING_CONSTRUCT2_LPCSTR);
DefineLibMemberFunc(const IECString&, IECString, operator=, (TCHAR ch), OpAssign, OpAssign_TCHAR, (ch), IECSTRING_OPASSIGN_TCHAR);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (const IECString& string, TCHAR ch), OpAdd, OpAdd_IECString_TCHAR, (string, ch), IECSTRING_OPADD_IECSTRING_TCHAR);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (TCHAR ch, const IECString& string), OpAdd, OpAdd_TCHAR_IECString, (ch, string), IECSTRING_OPADD_TCHAR_IECSTRING);
DefineLibMemberFunc(int, IECString, Delete, (int nIndex, int nCount), Delete, Delete, (nIndex, nCount), IECSTRING_DELETE);

int IECString::Insert(int nIndex, TCHAR ch)
{
	CopyBeforeWrite();

	if (nIndex < 0)
		nIndex = 0;

	int nNewLength = GetData()->nDataLength;
	if (nIndex > nNewLength)
		nIndex = nNewLength;
	nNewLength++;

	if (GetData()->nAllocLength < nNewLength)
	{
		CStringData* pOldData = GetData();
		LPTSTR pstr = m_pchData;
		AllocBuffer(nNewLength);
		memcpy(m_pchData, pstr, (pOldData->nDataLength+1)*sizeof(TCHAR));
		IECString::Release(pOldData);
	}

	// move existing bytes down
	memcpy(m_pchData + nIndex + 1,
		m_pchData + nIndex, (nNewLength-nIndex)*sizeof(TCHAR));
	m_pchData[nIndex] = ch;
	GetData()->nDataLength = nNewLength;

	return nNewLength;
}

int IECString::Insert(int nIndex, LPCTSTR pstr)
{
	if (nIndex < 0)
		nIndex = 0;

	int nInsertLength = SafeStrlen(pstr);
	int nNewLength = GetData()->nDataLength;
	if (nInsertLength > 0)
	{
		CopyBeforeWrite();
		if (nIndex > nNewLength)
			nIndex = nNewLength;
		nNewLength += nInsertLength;

		if (GetData()->nAllocLength < nNewLength)
		{
			CStringData* pOldData = GetData();
			LPTSTR pstr = m_pchData;
			AllocBuffer(nNewLength);
			memcpy(m_pchData, pstr, (pOldData->nDataLength+1)*sizeof(TCHAR));
			IECString::Release(pOldData);
		}

		// move existing bytes down
		memcpy(m_pchData + nIndex + nInsertLength,
			m_pchData + nIndex,
			(nNewLength-nIndex-nInsertLength+1)*sizeof(TCHAR));
		memcpy(m_pchData + nIndex,
			pstr, nInsertLength*sizeof(TCHAR));
		GetData()->nDataLength = nNewLength;
	}

	return nNewLength;
}

DefineLibMemberFunc(int, IECString, Replace, (TCHAR chOld, TCHAR chNew), Replace, Replace2_THCAR, (chOld, chNew), IECSTRING_REPLACE2_THCAR);

int IECString::Replace(LPCTSTR lpszOld, LPCTSTR lpszNew)
{
	// can't have empty or NULL lpszOld

	int nSourceLen = SafeStrlen(lpszOld);
	if (nSourceLen == 0)
		return 0;
	int nReplacementLen = SafeStrlen(lpszNew);

	// loop once to figure out the size of the result string
	int nCount = 0;
	LPTSTR lpszStart = m_pchData;
	LPTSTR lpszEnd = m_pchData + GetData()->nDataLength;
	LPTSTR lpszTarget;
	while (lpszStart < lpszEnd)
	{
		while ((lpszTarget = _tcsstr(lpszStart, lpszOld)) != NULL)
		{
			nCount++;
			lpszStart = lpszTarget + nSourceLen;
		}
		lpszStart += lstrlen(lpszStart) + 1;
	}

	// if any changes were made, make them
	if (nCount > 0)
	{
		CopyBeforeWrite();

		// if the buffer is too small, just
		//   allocate a new buffer (slow but sure)
		int nOldLength = GetData()->nDataLength;
		int nNewLength =  nOldLength + (nReplacementLen-nSourceLen)*nCount;
		if (GetData()->nAllocLength < nNewLength || GetData()->nRefs > 1)
		{
			CStringData* pOldData = GetData();
			LPTSTR pstr = m_pchData;
			AllocBuffer(nNewLength);
			memcpy(m_pchData, pstr, pOldData->nDataLength*sizeof(TCHAR));
			IECString::Release(pOldData);
		}
		// else, we just do it in-place
		lpszStart = m_pchData;
		lpszEnd = m_pchData + GetData()->nDataLength;

		// loop again to actually do the work
		while (lpszStart < lpszEnd)
		{
			while ( (lpszTarget = _tcsstr(lpszStart, lpszOld)) != NULL)
			{
				int nBalance = nOldLength - (lpszTarget - m_pchData + nSourceLen);
				memmove(lpszTarget + nReplacementLen, lpszTarget + nSourceLen,
					nBalance * sizeof(TCHAR));
				memcpy(lpszTarget, lpszNew, nReplacementLen*sizeof(TCHAR));
				lpszStart = lpszTarget + nReplacementLen;
				lpszStart[nBalance] = '\0';
				nOldLength += (nReplacementLen - nSourceLen);
			}
			lpszStart += lstrlen(lpszStart) + 1;
		}
		ASSERT(m_pchData[nNewLength] == '\0');
		GetData()->nDataLength = nNewLength;
	}

	return nCount;
}

int IECString::Remove(TCHAR chRemove)
{
	CopyBeforeWrite();

	LPTSTR pstrSource = m_pchData;
	LPTSTR pstrDest = m_pchData;
	LPTSTR pstrEnd = m_pchData + GetData()->nDataLength;

	while (pstrSource < pstrEnd)
	{
		if (*pstrSource != chRemove)
		{
			*pstrDest = *pstrSource;
			pstrDest = _tcsinc(pstrDest);
		}
		pstrSource = _tcsinc(pstrSource);
	}
	*pstrDest = '\0';
	int nCount = pstrSource - pstrDest;
	GetData()->nDataLength -= nCount;

	return nCount;
}

DefineLibMemberFunc(IECString, IECString, Mid, (int nFirst, int nCount) const, Mid, Mid2, (nFirst, nCount), IECSTRING_MID2);
DefineLibMemberFunc(IECString, IECString, Mid, (int nFirst) const, Mid, Mid1, (nFirst), IECSTRING_MID1);
DefineLibMemberFunc(IECString, IECString, Right, (int nCount) const, Right, Right, (nCount), IECSTRING_RIGHT);
DefineLibMemberFunc(IECString, IECString, Left, (int nCount) const, Left, Left, (nCount), IECSTRING_LEFT);
DefineLibMemberFunc(IECString, IECString, SpanIncluding, (LPCTSTR lpszCharSet) const, SpanIncluding, SpanIncluding, (lpszCharSet), IECSTRING_SPANINCLUDING);
DefineLibMemberFunc(IECString, IECString, SpanExcluding, (LPCTSTR lpszCharSet) const, SpanExcluding, SpanExcluding, (lpszCharSet), IECSTRING_SPANEXCLUDING);
DefineLibMemberFunc(int, IECString, ReverseFind, (TCHAR ch) const, ReverseFind, ReverseFind, (ch), IECSTRING_REVERSEFIND);
DefineLibMemberFunc(int, IECString, Find, (LPCTSTR lpszSub) const, Find, Find1, (lpszSub), IECSTRING_FIND1);
DefineLibMemberFunc(int, IECString, Find, (LPCTSTR lpszSub, int nStart) const, Find, Find2, (lpszSub, nStart), IECSTRING_FIND2);
DefineLibMemberFunc(void, IECString, FormatV, (LPCTSTR lpszFormat, va_list argList), FormatV, FormatV, (lpszFormat, argList), IECSTRING_FORMATV);

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

void IECString::TrimRight(LPCTSTR lpszTargetList)
{
	// find beginning of trailing matches
	// by starting at beginning (DBCS aware)

	CopyBeforeWrite();
	LPTSTR lpsz = m_pchData;
	LPTSTR lpszLast = NULL;

	while (*lpsz != '\0')
	{
		if (_tcschr(lpszTargetList, *lpsz) != NULL)
		{
			if (lpszLast == NULL)
				lpszLast = lpsz;
		}
		else
			lpszLast = NULL;
		lpsz = _tcsinc(lpsz);
	}

	if (lpszLast != NULL)
	{
		// truncate at left-most matching character
		*lpszLast = '\0';
		GetData()->nDataLength = lpszLast - m_pchData;
	}
}

DefineLibMemberFunc(void, IECString, TrimRight, (TCHAR chTarget), TrimRight, TrimRight1_TCHAR, (chTarget), IECSTRING_TRIMRIGHT1_TCHAR);
DefineLibMemberFunc(void, IECString, TrimRight, (), TrimRight, TrimRight0, (), IECSTRING_TRIMRIGHT0);

void IECString::TrimLeft(LPCTSTR lpszTargets)
{
	// if we're not trimming anything, we're not doing any work
	if (SafeStrlen(lpszTargets) == 0)
		return;

	CopyBeforeWrite();
	LPCTSTR lpsz = m_pchData;

	while (*lpsz != '\0')
	{
		if (_tcschr(lpszTargets, *lpsz) == NULL)
			break;
		lpsz = _tcsinc(lpsz);
	}

	if (lpsz != m_pchData)
	{
		// fix up data and length
		int nDataLength = GetData()->nDataLength - (lpsz - m_pchData);
		memmove(m_pchData, lpsz, (nDataLength+1)*sizeof(TCHAR));
		GetData()->nDataLength = nDataLength;
	}
}

void IECString::TrimLeft(TCHAR chTarget)
{
	// find first non-matching character

	CopyBeforeWrite();
	LPCTSTR lpsz = m_pchData;

	while (chTarget == *lpsz)
		lpsz = _tcsinc(lpsz);

	if (lpsz != m_pchData)
	{
		// fix up data and length
		int nDataLength = GetData()->nDataLength - (lpsz - m_pchData);
		memmove(m_pchData, lpsz, (nDataLength+1)*sizeof(TCHAR));
		GetData()->nDataLength = nDataLength;
	}
}

DefineLibMemberFunc(void, IECString, TrimLeft, (), TrimLeft, TrimLeft0, (), IECSTRING_TRIMLEFT0);

DefineLibNoRetFunc(IECString&, IECString, IECString, (), Construct, Construct0, (), IECSTRING_CONSTRUCT0);
DefineLibNoRetFunc(IECString&, IECString, IECString, (const IECString& stringSrc), Construct, Construct1_IECString, (stringSrc), IECSTRING_CONSTRUCT1_IECSTRING);
DefineLibMemberFunc(void, IECString, Empty, (), Empty, Empty, (), IECSTRING_EMPTY);
DefineLibNoRetFunc(void, IECString, ~IECString, (), Deconstruct, Deconstruct, (), IECSTRING_DECONSTRUCT);
DefineLibNoRetFunc(IECString&, IECString, IECString, (LPCSTR lpsz), Construct, Construct1_LPCTSTR, (lpsz), IECSTRING_CONSTRUCT1_LPCTSTR);
DefineLibMemberFunc(const IECString&, IECString, operator=, (const IECString& stringSrc), OpAssign, OpAssign_IECString, (stringSrc), IECSTRING_OPASSIGN_IECSTRING);
DefineLibMemberFunc(const IECString&, IECString, operator=, (LPCSTR lpsz), OpAssign, OpAssign_LPCSTR, (lpsz), IECSTRING_OPASSIGN_LPCSTR);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (const IECString& string1, const IECString& string2), OpAdd, OpAdd_IECString_IECString, (string1, string2), IECSTRING_OPADD_IECSTRING_IECSTRING);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (const IECString& string, LPCTSTR lpsz), OpAdd, OpAdd_IECString_LPCTSTR, (string, lpsz), IECSTRING_OPADD_IECSTRING_LPCTSTR);
DefineLibFriendFunc(IECString, AFXAPI, IECString, operator+, (LPCTSTR lpsz, const IECString& string), OpAdd, OpAdd_LPCTSTR_IECString, (lpsz, string), IECSTRING_OPADD_LPCTSTR_IECSTRING);
DefineLibMemberFunc(const IECString&, IECString, operator+=, (LPCTSTR lpsz), OpAddEq, OpAddEq_LPCTSTR, (lpsz), IECSTRING_OPADDEQ_LPCTSTR);
DefineLibMemberFunc(const IECString&, IECString, operator+=, (TCHAR ch), OpAddEq, OpAddEq_TCHAR, (ch), IECSTRING_OPADDEQ_TCHAR);
DefineLibMemberFunc(const IECString&, IECString, operator+=, (const IECString& string), OpAddEq, OpAddEq_IECString, (string), IECSTRING_OPADDEQ_IECSTRING);
DefineLibMemberFunc(LPTSTR, IECString, GetBuffer, (int nMinBufLength), GetBuffer, GetBuffer, (nMinBufLength), IECSTRING_GETBUFFER);
DefineLibMemberFunc(void, IECString, ReleaseBuffer, (int nNewLength), ReleaseBuffer, ReleaseBuffer, (nNewLength), IECSTRING_RELEASEBUFFER);
DefineLibMemberFunc(LPTSTR, IECString, GetBufferSetLength, (int nNewLength), GetBufferSetLength, GetBufferSetLength, (nNewLength), IECSTRING_GETBUFFERSETLENGTH);

void IECString::FreeExtra()
{
	ASSERT(GetData()->nDataLength <= GetData()->nAllocLength);
	if (GetData()->nDataLength != GetData()->nAllocLength)
	{
		CStringData* pOldData = GetData();
		AllocBuffer(GetData()->nDataLength);
		memcpy(m_pchData, pOldData->data(), pOldData->nDataLength*sizeof(TCHAR));
		ASSERT(m_pchData[GetData()->nDataLength] == '\0');
		IECString::Release(pOldData);
	}
	ASSERT(GetData() != NULL);
}

LPTSTR IECString::LockBuffer()
{
	LPTSTR lpsz = GetBuffer(0);
	GetData()->nRefs = -1;
	return lpsz;
}

void IECString::UnlockBuffer()
{
	ASSERT(GetData()->nRefs == -1);
	if (GetData() != (CStringData*)(IECSTRING_AFXDATANIL))
		GetData()->nRefs = 1;
}

DefineLibMemberFunc(int, IECString, Find, (TCHAR ch) const, Find, Find_TCHAR, (ch), IECSTRING_FIND_TCHAR);
DefineLibMemberFunc(int, IECString, Find, (TCHAR ch, int nStart) const, Find, Find_TCHAR_int, (ch, nStart), IECSTRING_FIND_TCHAR_INT);
DefineLibMemberFunc(int, IECString, FindOneOf, (LPCTSTR lpszCharSet) const, FindOneOf, FindOneOf, (lpszCharSet), IECSTRING_FINDONEOF);
DefineLibMemberFunc(void, IECString, MakeUpper, (), MakeUpper, MakeUpper, (), IECSTRING_MAKEUPPER);
DefineLibMemberFunc(void, IECString, MakeLower, (), MakeLower, MakeLower, (), IECSTRING_MAKELOWER);

void IECString::MakeReverse()
{
	CopyBeforeWrite();
	_tcsrev(m_pchData);
}

DefineLibMemberFunc(void, IECString, SetAt, (int nIndex, TCHAR ch), SetAt, SetAt, (nIndex, ch), IECSTRING_SETAT);
DefineLibMemberFunc(BOOL, IECString, LoadString, (UINT nID), LoadStringA, LoadStringA, (nID), IECSTRING_LOADSTRINGA);

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

DefineLibMemberFunc(CStringData*, IECString, GetData, () const, GetData, GetData, (), IECSTRING_GETDATA);
DefineLibMemberFunc(void, IECString, Init, (), Init, Init, (), IECSTRING_INIT);
DefineLibMemberFunc(void, IECString, AllocCopy, (CString& dest, int nCopyLen, int nCopyIndex, int nExtraLen) const, AllocCopy, AllocCopy, (dest, nCopyLen, nCopyIndex, nExtraLen), IECSTRING_ALLOCCOPY);
DefineLibMemberFunc(void, IECString, AllocBuffer, (int nLen), AllocBuffer, AllocBuffer, (nLen), IECSTRING_ALLOCBUFFER);
DefineLibMemberFunc(void, IECString, AssignCopy, (int nSrcLen, LPCTSTR lpszSrcData), AssignCopy, AssignCopy, (nSrcLen, lpszSrcData), IECSTRING_ASSIGNCOPY);
DefineLibMemberFunc(void, IECString, ConcatCopy, (int nSrc1Len, LPCTSTR lpszSrc1Data, int nSrc2Len, LPCTSTR lpszSrc2Data), ConcatCopy, ConcatCopy, (nSrc1Len, lpszSrc1Data, nSrc2Len, lpszSrc2Data), IECSTRING_CONCATCOPY);
DefineLibMemberFunc(void, IECString, ConcatInPlace, (int nSrcLen, LPCTSTR lpszSrcData), ConcatInPlace, ConcatInPlace, (nSrcLen, lpszSrcData), IECSTRING_CONCATINPLACE);
DefineLibMemberFunc(void, IECString, CopyBeforeWrite, (), CopyBeforeWrite, CopyBeforeWrite, (), IECSTRING_COPYBEFOREWRITE);
DefineLibMemberFunc(void, IECString, AllocBeforeWrite, (int nLen), AllocBeforeWrite, AllocBeforeWrite, (nLen), IECSTRING_ALLOCBEFOREWRITE);
DefineLibMemberFunc(void, IECString, Release, (), Release, Release0, (), IECSTRING_RELEASE0);
DefineLibStaticFunc(void, PASCAL, IECString, Release, (CStringData* pData), Release1, (pData), IECSTRING_RELEASE1);
DefineLibStaticFunc(int, PASCAL, IECString, SafeStrlen, (LPCTSTR lpsz), SafeStrlen, (lpsz), IECSTRING_SAFESTRLEN);
DefineLibStaticFunc(void, FASTCALL, IECString, FreeData, (CStringData* pData), FreeData, (pData), IECSTRING_FREEDATA);
