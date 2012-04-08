#include "main.h"

#include "stdafx.h"
#include "debug.h"
#include "patch.h"
#include "hook.h"

void Init() {

	char* lpVersion = NULL;
	DllGetVersion(&lpVersion);
	
	time_t tmTime = time(NULL);
	tm tmLocal;
	localtime_s(&tmLocal, &tmTime);
	const char* buffer = "%sTobEx: Throne of Bhaal Extender%s%s (%s %.2d %s %.4d %.2d:%.2d:%.2d)\r\n";
	const char* bufferD = "%sTobEx Dialogue Log (%s %.2d %s %.4d %.2d:%.2d:%.2d)\r\n";

	//init console
	if (console.Init())
		console.writef(CONSOLEFORECOLOR_HEADER, buffer, "", lpVersion ? " build " : "", lpVersion ? lpVersion : "", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);

	//init log
	int nDebugLogFileMode = GetCoreIniValue("Debug", "Log File Mode");
	if (L.Init(nDebugLogFileMode))
		L.appendf(buffer, "-----", lpVersion ? " build " : "", lpVersion ? lpVersion : "", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);

	char lpFile[MAX_PATH];
	if (GetModuleFileName(NULL, lpFile, MAX_PATH)) {
		const int nPEAddress = (int)GetModuleHandle(lpFile);
		if (nPEAddress == g_nPEAddressDefault) {
			InitOptions();

			if (pGameOptionsEx->bDebugLogDialogueBar) {
				if (LD.Init(nDebugLogFileMode))
					LD.appendf(bufferD, "-----", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);
			}

			InitPatches();
			InitHooks();

#ifdef _DEBUG
			Debug();
#endif //_DEBUG
		} else {
			LPCTSTR lpsz = "Init(): Executable loaded at incompatible address 0x%X. All TobEx features disabled. Please report this error.\r\n";
			console.writef(lpsz, nPEAddress);
			L.timestamp();
			L.appendf(lpsz, nPEAddress);
		}
	} else {
		LPCTSTR lpsz = "Init(): Unable to resolve module name. All TobEx features disabled.\r\n";
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