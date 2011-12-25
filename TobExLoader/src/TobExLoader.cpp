#ifndef __A64
#define __A64
#include <windows.h>
#pragma comment (lib, "version.lib")
#endif

#include "TobExLoader.h"
#include <iostream>
using namespace std;

int WINAPI WinMain (HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {

	char* szFileName = "BGMain.exe";
	char* szClassName = "ChitinClass";
	char* szWindowName = NULL; //"Baldur's Gate II - Shadows of Amn - Throne of Bhaal";
	char* szLibPath = "TobEx.dll";
	WIN32_FIND_DATAA FileData;
	STARTUPINFOA si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	si.cb = sizeof(si);

	if (FindWindowA((LPCSTR)szClassName, (LPCSTR)szWindowName)) {
		displayErrorMessage("WinMain(): Please close existing game before running TobEx.", 0);
		return -1;
	}

	if (FindFirstFileA(szFileName, &FileData) != INVALID_HANDLE_VALUE) {
		if (!checkFileVersion(szFileName, "2, 5, 0, 2")) return -1;
	} else {
		displayErrorMessage("WinMain(): FindFirstFileA() failed.", GetLastError());
		return -1;
	}

	if ( CreateProcessA(
		reinterpret_cast<LPCSTR>(szFileName),
		NULL, //pointer to cmd arguments
		NULL, //process security
		NULL, //default thread security
		FALSE, //inherit handles?
		CREATE_SUSPENDED,
		NULL, //environment
		NULL, //current directory
		&si,
		&pi )
	) {
		DWORD dwExitCode = injectDLL(pi.hProcess, szLibPath);
		ResumeThread(pi.hThread);
	    CloseHandle(pi.hThread);
	    CloseHandle(pi.hProcess);
		if (!dwExitCode) return -1;
	} else {
		displayErrorMessage("WinMain(): CreateProcessA() failed.", GetLastError());
	}

	return 0;
}

void displayErrorMessage(const char* szMessage, DWORD dwError) {

	char* szProcName = "TobEx Loader";

	if (dwError) {
		LPSTR lpError = 0;

		FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dwError,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)&lpError,
			0,
			NULL
		);

		size_t nFormatLength = strlen(szMessage) + 4;
		char* szFormat = new char[nFormatLength];
		strcpy_s(szFormat, nFormatLength, szMessage);
		strcat_s(szFormat, nFormatLength, "\n%s");

		size_t nMessageLength = lstrlenA((LPCSTR)lpError) + strlen(szFormat);

		char* pMessage = new char[nMessageLength];
		sprintf_s(pMessage, 
	    nMessageLength,
			szFormat, 
			lpError
		);

		MessageBoxA(NULL, pMessage, szProcName, MB_OK);

		LocalFree(lpError);
		delete[] szFormat, pMessage;
	} else {
		MessageBoxA(NULL, szMessage, szProcName, MB_OK);
	}

	return;
}

BOOL checkFileVersion(char* szFileName, const char* szVer) {
 	LPVOID lpFileVerInfo, lpProdVer;
	UINT nProdVerSize;
	BOOL bSuccess;

	DWORD dwFileVerInfoSize = GetFileVersionInfoSizeA((LPCSTR)szFileName, 0);

	if (dwFileVerInfoSize) {
  		lpFileVerInfo = (LPVOID)new BYTE[dwFileVerInfoSize];

		if ( GetFileVersionInfoA((LPCSTR)szFileName, 0, dwFileVerInfoSize, lpFileVerInfo) ) {

			//0409 = US English, 04B0 = charset
			if ( VerQueryValueA(lpFileVerInfo, "\\StringFileInfo\\040904B0\\ProductVersion", &lpProdVer, &nProdVerSize) ) {
				if (!strcmp((const char*)lpProdVer, szVer)) {
					bSuccess = TRUE;
				} else {
					bSuccess = FALSE;
				}
			} else {
				displayErrorMessage("checkFileVersion(): VerQueryValue() failed.", GetLastError());
				bSuccess = FALSE;
			}
		} else {
			displayErrorMessage("checkFileVersion(): GetFileVersionInfoA() failed.", GetLastError());
			bSuccess = FALSE;
		}

		delete[] lpFileVerInfo;

	} else {
		displayErrorMessage("checkFileVersion(): GetFileVersionInfoSizeA() failed.", GetLastError());
		bSuccess = FALSE;
	}

	return bSuccess;
}

DWORD injectDLL(HANDLE hProcess, char* szLibPath) {

	size_t szLibPathSize = strlen(szLibPath);

	LPVOID lpLibAddress;
	lpLibAddress = VirtualAllocEx(hProcess, NULL, szLibPathSize, MEM_COMMIT, PAGE_READWRITE);
	if (!lpLibAddress) {
		displayErrorMessage("injectDLL(): VirtualAllocEx() failed.", GetLastError());
		return 0;
	}
  
	if ( !WriteProcessMemory(hProcess, lpLibAddress, szLibPath, szLibPathSize, NULL) ) {
		displayErrorMessage("injectDLL(): WriteProcessMemory() failed.", GetLastError());
		return 0;
	}

	HMODULE hKernel32 = GetModuleHandleA(reinterpret_cast<LPCSTR>("KERNEL32.DLL"));
	if (!hKernel32) {
		displayErrorMessage("injectDLL(): GetModuleHandleA() failed.", GetLastError());
		return 0;
	}

	HANDLE hRemoteThread;
	DWORD dwRemoteThreadID;
	LPTHREAD_START_ROUTINE lpStartRoutine = reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(hKernel32, "LoadLibraryA"));
	if (!lpStartRoutine) {
		displayErrorMessage("injectDLL(): GetProcAddress() failed.", GetLastError());
		return 0;
	}

	hRemoteThread = CreateRemoteThread(hProcess, NULL, 0, lpStartRoutine, lpLibAddress, 0, &dwRemoteThreadID); 
	if (!hRemoteThread) {
		displayErrorMessage("injectDLL(): CreateRemoteThread() failed.", GetLastError());
		return 0;
	}

	switch (WaitForSingleObject(hRemoteThread, INFINITE)) {
		case WAIT_ABANDONED:
			break;
		case WAIT_OBJECT_0:
			break;
		case WAIT_TIMEOUT:
			break;
		case WAIT_FAILED:
			displayErrorMessage("injectDLL(): WaitForSingleObject() failed.", GetLastError());
			return 0;
		default:
			displayErrorMessage("injectDLL(): WaitForSingleObject() returned invalid value.", 0);
			return 0;
	}

	DWORD dwExitCode;
	BOOL result = GetExitCodeThread(hRemoteThread, &dwExitCode);
	if (!result) {
		displayErrorMessage("injectDLL(): GetExitCodeThread() failed.", GetLastError());
		return 0;
	}

	if (dwExitCode == STILL_ACTIVE) {
		displayErrorMessage("injectDLL(): hRemoteThread still active.", 0);
		return 0;
	}

	if (!CloseHandle(hRemoteThread)) {
		displayErrorMessage("injectDLL(): CloseHandle() failed.", GetLastError());
		return 0;
	}

	if (!VirtualFreeEx(hProcess, lpLibAddress, 0, MEM_RELEASE)) {
		displayErrorMessage("injectDLL(): VirtualFreeEx() failed.", GetLastError());
		return 0;
	}

	return dwExitCode;
}
