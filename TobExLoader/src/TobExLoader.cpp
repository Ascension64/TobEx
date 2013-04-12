#ifndef __A64
#define __A64
#include <windows.h>
#pragma comment (lib, "version.lib")
#endif

#include "TobExLoader.h"
#include <iostream>
using namespace std;

int WINAPI WinMain (HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {

	char* szFileNameTOB = "BGMain.exe";
	char* szClassNameTOB = "ChitinClass";
	char* szWindowNameTOB = NULL; //"Baldur's Gate II - Shadows of Amn - Throne of Bhaal";
	char* szLibPathTOB = "TobEx.dll";

	char* szFileNameBGEE = "Baldur.exe";
	char* szClassNameBGEE = "SDL_app";
	char* szWindowNameBGEE = NULL; //"Baldur's Gate - Enhanced Edition";
	char* szLibPathBGEE = "TobExEE.dll";

	int nGameType = 0;

	WIN32_FIND_DATAA FileData;
	STARTUPINFOA si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	si.cb = sizeof(si);

	if (FindWindowA((LPCSTR)szClassNameTOB, (LPCSTR)szWindowNameTOB) ||
		FindWindowA((LPCSTR)szClassNameBGEE, (LPCSTR)szWindowNameBGEE)) {
		displayErrorMessage("WinMain(): Please close existing game before running TobEx.", 0);
		return -1;
	}

	if (FindFirstFileA(szFileNameTOB, &FileData) != INVALID_HANDLE_VALUE) {
		if (!checkFileVersion(szFileNameTOB, "2, 5, 0, 2")) return -1;
		nGameType = 0;
	} else if (FindFirstFileA(szFileNameBGEE, &FileData) != INVALID_HANDLE_VALUE) {
		if (!checkFileVersion(szFileNameBGEE, "0.1.0.0")) return -1;
		nGameType = 1;
	} else {
		displayErrorMessage("FindFirstFileA(): Could not find game executable.", GetLastError());
		return -1;
	}

	if ( CreateProcessA(
		reinterpret_cast<LPCSTR>(nGameType == 1 ? szFileNameBGEE : szFileNameTOB),
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
		DWORD dwExitCode = injectDLL(pi.hProcess, nGameType == 1 ? szLibPathBGEE : szLibPathTOB);
		ResumeThread(pi.hThread);
	    CloseHandle(pi.hThread);
	    CloseHandle(pi.hProcess);
		if (!dwExitCode) return -1;
	} else {
		displayErrorMessage("CreateProcessA(): Unable to start game.", GetLastError());
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
				displayErrorMessage("VerQueryValue(): Unable to check file version.", GetLastError());
				bSuccess = FALSE;
			}
		} else {
			displayErrorMessage("GetFileVersionInfoA(): Unable to check file version.", GetLastError());
			bSuccess = FALSE;
		}

		delete[] lpFileVerInfo;

	} else {
		displayErrorMessage("GetFileVersionInfoSizeA(): Unable to check file version.", GetLastError());
		bSuccess = FALSE;
	}

	return bSuccess;
}

DWORD injectDLL(HANDLE hProcess, char* szLibPath) {

	size_t szLibPathSize = strlen(szLibPath);

	LPVOID lpLibAddress;
	lpLibAddress = VirtualAllocEx(hProcess, NULL, szLibPathSize, MEM_COMMIT, PAGE_READWRITE);
	if (!lpLibAddress) {
		displayErrorMessage("VirtualAllocEx(): Unable to inject DLL.", GetLastError());
		return 0;
	}
  
	if ( !WriteProcessMemory(hProcess, lpLibAddress, szLibPath, szLibPathSize, NULL) ) {
		displayErrorMessage("WriteProcessMemory(): Unable to inject DLL.", GetLastError());
		return 0;
	}

	HMODULE hKernel32 = GetModuleHandleA(reinterpret_cast<LPCSTR>("KERNEL32.DLL"));
	if (!hKernel32) {
		displayErrorMessage("GetModuleHandleA(): Unable to inject DLL.", GetLastError());
		return 0;
	}

	HANDLE hRemoteThread;
	DWORD dwRemoteThreadID;
	LPTHREAD_START_ROUTINE lpStartRoutine = reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(hKernel32, "LoadLibraryA"));
	if (!lpStartRoutine) {
		displayErrorMessage("GetProcAddress(): Unable to inject DLL.", GetLastError());
		return 0;
	}

	hRemoteThread = CreateRemoteThread(hProcess, NULL, 0, lpStartRoutine, lpLibAddress, 0, &dwRemoteThreadID); 
	if (!hRemoteThread) {
		displayErrorMessage("CreateRemoteThread(): Unable to inject DLL.", GetLastError());
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
			displayErrorMessage("WaitForSingleObject(): Unable to inject DLL.", GetLastError());
			return 0;
		default:
			displayErrorMessage("WaitForSingleObject(): Unable to inject DLL.", 0);
			return 0;
	}

	DWORD dwExitCode;
	BOOL result = GetExitCodeThread(hRemoteThread, &dwExitCode);
	if (!result) {
		displayErrorMessage("GetExitCodeThread(): GetExitCodeThread() failed.", GetLastError());
		return 0;
	}

	if (dwExitCode == STILL_ACTIVE) {
		displayErrorMessage("hRemoteThread: TobExLoader exited prematurely.", 0);
		return 0;
	}

	if (!CloseHandle(hRemoteThread)) {
		displayErrorMessage("CloseHandle(): Unable to close thread handle.", GetLastError());
		return 0;
	}

	if (!VirtualFreeEx(hProcess, lpLibAddress, 0, MEM_RELEASE)) {
		displayErrorMessage("VirtualFreeEx(): Unable to free memory.", GetLastError());
		return 0;
	}

	return dwExitCode;
}
