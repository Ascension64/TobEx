#include "LogCore.h"

#include "utils.h"
#include "dbgcore.h"
#include "patch.h"
#include "console.h"
#include "log.h"

void (__cdecl *Tramp_AssertFailedQuit)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR) =
	reinterpret_cast<void (__cdecl *)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR)>	(0x99F06C);
void (__cdecl *Tramp_AssertFailedContinue)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR) =
	reinterpret_cast<void (__cdecl *)(DWORD, LPCTSTR, LPCTSTR, LPCTSTR)>	(0x99F193);
void (__cdecl *Tramp_WriteToFile)(CFile&, CString&) =
	reinterpret_cast<void (__cdecl *)(CFile&, CString&)>					(0x99F371);
void (__stdcall *Tramp_CloseLogAndErr)() =
	reinterpret_cast<void (__stdcall *)()>									(0x99F1BA);

void __stdcall DETOUR_CloseLogAndErr() {
	//delete ClassAbilityTable;	- main program does this
	ClassAbilityTable = NULL;

	Tramp_CloseLogAndErr();

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

	return Tramp_AssertFailedQuit(dwLine, szPath, szExpression, szMessage);
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

	return Tramp_AssertFailedContinue(dwLine, szPath, szExpression, szMessage);
}
