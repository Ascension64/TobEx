#include "LogCore.h"

#include "stdafx.h"
#include "dbgcore.h"
#include "patch.h"
#include "options.h"
#include "console.h"
#include "log.h"
#include "LogCommon.h"

void (__cdecl *Tramp_AssertFailedQuit)(int, LPCTSTR, LPCTSTR, LPCTSTR) =
	reinterpret_cast<void (__cdecl *)(int, LPCTSTR, LPCTSTR, LPCTSTR)>	(0x99F06C);
void (__cdecl *Tramp_AssertFailedContinue)(int, LPCTSTR, LPCTSTR, LPCTSTR) =
	reinterpret_cast<void (__cdecl *)(int, LPCTSTR, LPCTSTR, LPCTSTR)>	(0x99F193);
void (__cdecl *Tramp_WriteToFile)(CFile&, CString&) =
	reinterpret_cast<void (__cdecl *)(CFile&, CString&)>				(0x99F371);
void (__stdcall *Tramp_CloseLogAndErr)() =
	reinterpret_cast<void (__stdcall *)()>								(0x99F1BA);

void __stdcall DETOUR_CloseLogAndErr() {
	Tramp_CloseLogAndErr();

	//delete ClassAbilityTable;	- main program does this
	ClassAbilityTable = NULL;
	delete pGameOptionsEx;
	pGameOptionsEx = NULL;

	return;
}

void __cdecl DETOUR_WriteToFile(CFile& file, CString& str) {

	Tramp_WriteToFile(file, str);

	str.TrimRight('\n');
	str.TrimLeft('\n');

	if (!str.IsEmpty()) { 
		str += '\r';
		str += '\n';
		console.write(str);

		L.timestamp();
		L.append(str);
	}

	return;
}

void __cdecl DETOUR_AssertFailedQuit(int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage) {
	int Eip;
	GetEip(Eip);

	CString sFile(szPath);
	if (!sFile.IsEmpty()) {
		int n = sFile.ReverseFind('\\');
		sFile = sFile.Mid(n+1, sFile.GetLength() - 1);
	}

	LPCTSTR szReason = szMessage == NULL ? Assertion_GetReason(Eip) : szMessage;
	LPCTSTR szFormat = "ASSERTION FAILED! Return Address: 0x%X File: %s Line: %d Expression: %s Message: %s\r\n";

	console.writef(CONSOLEFORECOLOR_ERROR, szFormat, Eip, (LPCTSTR)sFile, dwLine, szExpression, szReason);
	L.timestamp();
	L.appendf(szFormat, Eip, (LPCTSTR)sFile, dwLine, szExpression, szReason);

	return Tramp_AssertFailedQuit(dwLine, szPath, szExpression, szMessage);
}
	
void __cdecl DETOUR_AssertFailedContinue(int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage) {
	int Eip;
	GetEip(Eip);

	CString sFile(szPath);
	if (!sFile.IsEmpty()) {
		int n = sFile.ReverseFind('\\');
		sFile = sFile.Mid(n+1, sFile.GetLength() - 1);
	}

	LPCTSTR szReason = szMessage == NULL ? Assertion_GetReason(Eip) : szMessage;
	LPCTSTR szFormat = "Assertion warning. Return Address: 0x%X File: %s Line: %d Expression: %s Message: %s\r\n";

	console.writef(CONSOLEFORECOLOR_WARNING, szFormat, Eip, (LPCTSTR)sFile, dwLine, szExpression, szReason);
	L.timestamp();
	L.appendf(szFormat, Eip, (LPCTSTR)sFile, dwLine, szExpression, szReason);

	return Tramp_AssertFailedContinue(dwLine, szPath, szExpression, szMessage);
}
