#define _EXPORTING

#include "win32def.h"
#include "main.h"

//Force inclusion of this module for _USRDLL
extern "C" { int _afxForceUSRDLL; }

BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {

    switch (dwReason) {
		case DLL_PROCESS_ATTACH:
			Init();
			break;
		case DLL_PROCESS_DETACH:
			Deinit();
			break;
		case DLL_THREAD_ATTACH:
	        break;
		case DLL_THREAD_DETACH:
	        break;
    }

    return true;
}
