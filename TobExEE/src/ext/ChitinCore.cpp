//TobExEE
#include "ChitinCore.h"
#include "p_chitin.h"

#include "console.h"

//CBaldurChitin
DefineTrampMemberFunc(CBaldurChitin&, CBaldurChitin, Construct, (int argc, char* argv[]), Construct, Construct, CBALDURCHITIN_CONSTRUCT);
DefineTrampMemberFunc(void, CBaldurChitin, DoExit, (unsigned int dwLine, const char* szFile, const char* szReason), DoExit, DoExit, CBALDURCHITIN_DOEXIT);

CBaldurChitin& DETOUR_CBaldurChitin::DETOUR_Construct(int argc, char* argv[]) {
	CBaldurChitin& chitin = (this->*Tramp_CBaldurChitin_Construct)(argc, argv);
	g_pChitin = &chitin;
	*(IECString*)CSTRING_BGEE_BUILD += ".TobEx";
	return chitin;
}

void DETOUR_CBaldurChitin::DETOUR_DoExit(unsigned int dwLine, const char* szFile, const char* szReason) {
	int Eip;
	GetEip(Eip);

	if (dwLine != UINT_MAX) {
		CString sFile(szFile);
		if (!sFile.IsEmpty()) {
			int n = sFile.ReverseFind('\\');
			sFile = sFile.Mid(n+1, sFile.GetLength() - 1);
		}

		LPCTSTR szFormat = "Assertion failed! Return Address: 0x%X File: %s Line: %d Reason: %s\r\n";

		console.writef(CONSOLEFORECOLOR_ERROR, szFormat, Eip, (LPCTSTR)sFile, dwLine, szReason);
		L.timestamp();
		L.appendf(szFormat, Eip, (LPCTSTR)sFile, dwLine, szReason);
	}

	//delete TobEx globals here

	return (this->*Tramp_CBaldurChitin_DoExit)(dwLine, szFile, szReason);
}