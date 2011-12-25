#include "ChitinCore.h"

#include "console.h"

CBaldurChitin& DETOUR_CBaldurChitin::DETOUR_Construct() {
	CBaldurChitin& chitin = (this->*CBaldurChitin_Construct0)();
	g_pChitin = &chitin;
	return chitin;
}

int __stdcall CBaldurChitin_MessageBox(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {
	DWORD dwThreadProcessId = GetWindowThreadProcessId(hWnd, NULL);
	HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, dwThreadProcessId);
	DWORD dwSuspendCount;
	do {
		dwSuspendCount = ResumeThread(hThread);
	} while (dwSuspendCount > 1);
	return MessageBox(hWnd, lpText, lpCaption, uType);
}