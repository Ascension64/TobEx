#include "ChitinCore.h"

#include "console.h"

DefineTrampMemberFunc(CBaldurChitin&, CBaldurChitin, Construct, (), Construct, Construct, 0x432108);

CBaldurChitin& DETOUR_CBaldurChitin::DETOUR_Construct() {
	CBaldurChitin& chitin = (this->*Tramp_CBaldurChitin_Construct)();
	g_pChitin = &chitin;
	return chitin;
}

int __stdcall CBaldurChitin_MessageBox(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {
	if (0) IECString("CBaldurChitin_MessageBox");

	int dwThreadProcessId = GetWindowThreadProcessId(hWnd, NULL);
	HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, dwThreadProcessId);
	int dwSuspendCount;
	do {
		dwSuspendCount = ResumeThread(hThread);
	} while (dwSuspendCount > 1);
	return MessageBox(hWnd, lpText, lpCaption, uType);
}