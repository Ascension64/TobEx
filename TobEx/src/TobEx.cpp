#define _EXPORTING

#include "TobEx.h"

#include "win32def.h"
#include "main.h"

//Use as Extension DLL
/*#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static AFX_EXTENSION_MODULE PROJNAMEDLL = { NULL, NULL };*/

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
