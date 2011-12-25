#include "console.h"

#include "utils.h"
#include "resref.h"

Console console;

Console::Console() {
	bAlloc = FALSE;
    hInput, hOutput, hError = NULL;
	InitializeCriticalSection(&csConsole);
}

Console::~Console() {
	DeleteCriticalSection(&csConsole);
	if (bAlloc) FreeConsole();
}

BOOL Console::Init() {
  bAlloc = AllocConsole();
  if (bAlloc) {
	SetConsoleTitleA("TobEx Console");
	
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	hError = GetStdHandle(STD_ERROR_HANDLE);
	
	SetConsoleMode(hInput, ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);
	SetConsoleMode(hOutput, ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);

	SetForegroundWindow(FindWindowA("ChitinClass",NULL));
  }
  return bAlloc;
}

Console& Console::write(ResRef* text) {
	DWORD size = 8;

	EnterCriticalSection(&csConsole);
	WriteConsole(hOutput, text, size, &size, NULL);
	LeaveCriticalSection(&csConsole);
  
	return *this;
}

Console& Console::write(LPCTSTR text) {
	DWORD size = (DWORD)strlen(text);

	EnterCriticalSection(&csConsole);
	WriteConsole(hOutput, text, size, &size, NULL);
	LeaveCriticalSection(&csConsole);
  
	return *this;
}

Console& Console::write(CString& s) {
	DWORD size = s.GetLength();
	WriteConsoleA(hOutput, (LPCTSTR)s, size, &size, NULL);
	return *this;
}

Console& Console::write(LPCTSTR format, int n, ...) {
	char text[256];
	DWORD length = sizeof(text);

    va_list v;
    va_start(v, n);
	vsprintf_s(text, length, format, v);
	DWORD size = (DWORD)strlen(text);

	EnterCriticalSection(&csConsole);
	WriteConsoleA(hOutput, text, size, &size, NULL);
	LeaveCriticalSection(&csConsole);

	return *this;
}