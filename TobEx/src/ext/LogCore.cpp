#include "LogCore.h"

#include "stdafx.h"
#include "dbgcore.h"
#include "patchext.h"
#include "optionsext.h"
#include "LogCommon.h"

DefineTrampGlobalFuncPtr(void, __cdecl, AssertFailedQuit, (int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage), 0x99F06C);
DefineTrampGlobalFuncPtr(void, __cdecl, AssertFailedContinue, (int dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage), 0x99F193);
DefineTrampGlobalFuncPtr(void, __cdecl, WriteToFile, (CFile& file, CString& str), 0x99F371);
DefineTrampGlobalFuncPtr(void, __cdecl, CloseLogAndErr, (), 0x99F1BA);

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

void __stdcall DETOUR_CloseLogAndErr() {
	Tramp_CloseLogAndErr();

	//delete ClassAbilityTable;	- main program does this
	ClassAbilityTable = NULL;
	delete pGameOptionsEx;
	pGameOptionsEx = NULL;

	return;
}