//TobExEE
#include "main.h"

#include "stdafx.h"
#include "debug.h"
#include "optionsext.h"
#include "patchext.h"
#include "hook.h"
#include "crc32.h"
#include "crcexe.h"

void Init() {

	char* lpVersion = NULL;
	DllGetVersion(&lpVersion);
		
	time_t tmTime = time(NULL);
	tm tmLocal;
	localtime_s(&tmLocal, &tmTime);
	const char* buffer = "%sThrone of Bhaal Extender: Enhanced Edition %s (%s %.2d %s %.4d %.2d:%.2d:%.2d)\r\n";
	const char* bufferD = "%sTobEx:EE Dialogue Log (%s %.2d %s %.4d %.2d:%.2d:%.2d)\r\n";

	//init console
	if (console.Init()) {
		console.writef(CONSOLEFORECOLOR_HEADER, buffer, "", lpVersion ? lpVersion : "", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);
		SetForegroundWindow(FindWindow("SDL_app",NULL));
	}

	//init log
	int nDebugLogFileMode = GetCoreIniValue("Debug", "Log File Mode");
	if (L.Init(nDebugLogFileMode))
		L.appendf(buffer, "-----", lpVersion ? lpVersion : "", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);

	char lpFile[MAX_PATH];

	if (GetModuleFileName(NULL, lpFile, MAX_PATH)) {
		if (CheckExeVersion(lpFile)) {
			const unsigned int nPEAddress = (unsigned int)GetModuleHandle(lpFile);
			if (nPEAddress == g_nPEAddressDefault) {
				InitOptions();

				if (pGameOptionsEx->GetOption("Debug_LogDialogueBar")) {
					if (LD.Init(nDebugLogFileMode))
						LD.appendf(bufferD, "-----", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);
				}

				InitPatches();
				InitHooks();

#ifdef _DEBUG
				Debug();
#endif //_DEBUG
			} else {
				LPCTSTR lpsz = "Init(): Executable loaded at incompatible address 0x%X. All TobExEE features disabled. Please report this error.\r\n";
				console.writef(lpsz, nPEAddress);
				L.timestamp();
				L.appendf(lpsz, nPEAddress);
			}
		}
	} else {
		LPCTSTR lpsz = "Init(): Unable to resolve module name. All TobExEE features disabled.\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
	}

	delete[] lpVersion;

	return;
}

void Deinit() {
  return;
}

BOOL DllGetVersion(char** lplpsz) {
 	LPVOID lpFileVerInfo;
	LPVOID lpFileVer;
	UINT nProdVerSize;
	BOOL bSuccess = FALSE;

	DWORD dwFileVerInfoSize = GetFileVersionInfoSizeA(DLL_INTERNAL_NAME, NULL);

	if (dwFileVerInfoSize) {
  		lpFileVerInfo = (LPVOID)new BYTE[dwFileVerInfoSize];
		if ( GetFileVersionInfoA(DLL_INTERNAL_NAME, 0, dwFileVerInfoSize, lpFileVerInfo) ) {
			//0409 = US English, 04E4 = charset
			if ( VerQueryValueA(lpFileVerInfo, "\\StringFileInfo\\040904E4\\FileVersion", &lpFileVer, &nProdVerSize) ) {
				size_t nLength = strlen((LPCTSTR)lpFileVer);
				char* lpsz = new char[nLength + 1];
				strcpy_s(lpsz, nLength + 1, (LPCTSTR)lpFileVer);
				lpsz[nLength] = '\0';
				*lplpsz = lpsz;

				bSuccess = TRUE;
			}
		}
		delete[] lpFileVerInfo;
	}
	return bSuccess;
}

BOOL CheckExeVersion(LPCSTR lpFile) {
	const char* lpFileTemp = "A6Baldur";
	DWORD nFileSize = 0;
	char* lpData = NULL;
	unsigned __int32 crc = 0;
	BOOL bSuccess = FALSE;

	if (CopyFile(lpFile, lpFileTemp, FALSE)) {
		HANDLE hFile = CreateFile(lpFileTemp, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
		if (hFile != INVALID_HANDLE_VALUE) {
			nFileSize = GetFileSize(hFile, NULL);
			if (nFileSize > 0) {
				char* lpData = new char[nFileSize];
				if (ReadFile(hFile, lpData, nFileSize, &nFileSize, NULL)) {
					crc = GetCRC32(lpData, nFileSize);
				} else {
					LPCTSTR lpsz = "CheckExeVersion(): could not read from file (error code %d)\r\n";
					console.writef(lpsz, GetLastError());
				}
			} else {
				LPCTSTR lpsz = "CheckExeVersion(): could not get file size (error code %d)\r\n";
				console.writef(lpsz, GetLastError());
			}

			CloseHandle(hFile);
		} else {
			LPCTSTR lpsz = "CheckExeVersion(): could not open temp file (error code %d)\r\n";
			console.writef(lpsz, GetLastError());
		}

		if ( !DeleteFile(lpFileTemp) ) {
			LPCTSTR lpsz = "CheckExeVersion(): could not copy delete temp file (error code %d)\r\n";
			console.writef(lpsz, GetLastError());
		}
	} else {
		LPCTSTR lpsz = "CheckExeVersion(): could not copy exe file (error code %d)\r\n";
		console.writef(lpsz, GetLastError());
	}

	if (lpData) {
		delete lpData;
		lpData = NULL;
	}

	SetLastError(0);

	if (crc == CRC32_BGEE) bSuccess = TRUE;

	if (bSuccess) {
#ifdef _DEBUG
		LPCTSTR lpsz = "Baldur.exe CRC32 = 0x%08X\r\n";
		console.writef(lpsz, crc);
		L.timestamp();
		L.appendf(lpsz, crc);
#endif //_DEBUG
	} else {
		LPCTSTR lpsz = "CheckExeVersion(): invalid executable CRC32. All TobExEE features disabled.\r\n";
		console.writef(lpsz);
		L.timestamp();
		L.appendf(lpsz);
	}

	return bSuccess;
}