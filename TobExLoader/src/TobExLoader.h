#ifndef __A64
#define __A64
#include <windows.h>
#pragma comment (lib,"version.lib")
#endif

void displayErrorMessage(const char*, DWORD);
BOOL checkFileVersion(char*, const char*);
DWORD injectDLL(HANDLE, char*);
HINSTANCE startDLL (HANDLE, char*, HINSTANCE);
