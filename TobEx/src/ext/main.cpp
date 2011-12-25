#include "main.h"

#include "stdafx.h"
#include "debug.h"
#include "patch.h"
#include "hook.h"

void Init() {

	time_t tmTime = time(NULL);
	tm tmLocal;
	localtime_s(&tmLocal, &tmTime);
	const char* buffer = "%sTobEx: Throne of Bhaal Extender (%s %.2d %s %.4d %.2d:%.2d:%.2d)\r\n";
	const char* bufferD = "%sTobEx Dialogue Log (%s %.2d %s %.4d %.2d:%.2d:%.2d)\r\n";

	//init console
	if (console.Init())
		console.write(buffer, 8, "", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);

	//init log
	int nDebugLogFileMode = GetIniValue("Debug", "Log File Mode");
	if (L.Init(nDebugLogFileMode))
		L.append(buffer, 8, "-----", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);

	char lpFile[MAX_PATH];
	if (GetModuleFileName(NULL, lpFile, MAX_PATH)) {
		const int nPEAddress = (int)GetModuleHandle(lpFile);
		if (nPEAddress == g_nPEAddressDefault) {
			InitOptions();

			if (pGameOptionsEx->bDebugLogDialogueBar) {
				if (LD.Init(nDebugLogFileMode))
					LD.append(bufferD, 8, "-----", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);
			}

			InitPatches();
			InitHooks();

#ifdef _DEBUG
			Debug();
#endif //_DEBUG
		} else {
			LPCTSTR lpsz = "Init(): Executable loaded at incompatible address 0x%X. All TobEx features disabled. Please report this error.\r\n";
			console.write(lpsz, 1, nPEAddress);
			L.timestamp();
			L.append(lpsz, 1, nPEAddress);
		}
	} else {
		LPCTSTR lpsz = "Init(): Unable to resolve module name. All TobEx features disabled.\r\n";
		console.write(lpsz);
		L.timestamp();
		L.append(lpsz);
	}

	return;
}

void Deinit() {
  return;
}