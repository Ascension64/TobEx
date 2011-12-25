#include "main.h"

#include "utils.h"
#include "debug.h"
#include "console.h"
#include "log.h"
#include "patch.h"
#include "hook.h"

void Init() {

	time_t tmTime = time(NULL);
	tm tmLocal;
	localtime_s(&tmLocal, &tmTime);
	const char* buffer = "%sTobEx: Throne of Bhaal Extender (%s %.2d %s %.4d %.2d:%.2d:%.2d)\r\n";

	//init console
	if (console.Init()) console.write(buffer, 8, "", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);

	//init log
	if (L.Init()) L.append(buffer, 8, "-----", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);

	char lpFile[MAX_PATH];
	if (GetModuleFileName(NULL, lpFile, MAX_PATH)) {
		const DWORD nPEAddress = (DWORD)GetModuleHandle(lpFile);
		if (nPEAddress == g_nPEAddressDefault) {
			InitPatches();
			InitHooks();

			debug();
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