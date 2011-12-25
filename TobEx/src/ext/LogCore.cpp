#include "LogCore.h"

#include "utils.h"
#include "dbgcore.h"
#include "patch.h"
#include "console.h"
#include "log.h"

void __stdcall DETOUR_CloseLogAndErr() {
	//delete ClassAbilityTable;	- main program does this
	ClassAbilityTable = NULL;

	CloseLogAndErr();

	return;
}

void __cdecl DETOUR_WriteToFile(CFile& file, CString& str) {

	WriteToFile(file, str);

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

void __cdecl DETOUR_AssertFailedQuit(DWORD dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage) {
	DWORD Eip;
	GetEip(Eip);

	CString sFile(szPath);
	if (!sFile.IsEmpty()) {
		int n = sFile.ReverseFind('\\');
		sFile = sFile.Mid(n+1, sFile.GetLength() - 1);
	}

	LPCTSTR szFormat = "ASSERTION FAILED! Return Address: 0x%X File: %s Line: %d Expression: %s Message: %s\r\n";

	console.write(szFormat, 5, Eip, (LPCTSTR)sFile, dwLine, szExpression, szMessage);
	L.timestamp();
	L.append(szFormat, 5, Eip, (LPCTSTR)sFile, dwLine, szExpression, szMessage);

	AssertFailedQuit(dwLine, szPath, szExpression, szMessage);
	return;
}
	
void __cdecl DETOUR_AssertFailedContinue(DWORD dwLine, LPCTSTR szPath, LPCTSTR szExpression, LPCTSTR szMessage) {
	DWORD Eip;
	GetEip(Eip);

	CString sFile(szPath);
	if (!sFile.IsEmpty()) {
		int n = sFile.ReverseFind('\\');
		sFile = sFile.Mid(n+1, sFile.GetLength() - 1);
	}

	LPCTSTR szFormat = "Assertion warning. Return Address: 0x%X File: %s Line: %d Expression: %s Message: %s\r\n";

	console.write(szFormat, 5, Eip, (LPCTSTR)sFile, dwLine, szExpression, szMessage);
	L.timestamp();
	L.append(szFormat, 5, Eip, (LPCTSTR)sFile, dwLine, szExpression, szMessage);

	AssertFailedContinue(dwLine, szPath, szExpression, szMessage);
	return;
}
