#include "console.h"

#include "stdafx.h"
#include "resref.h"

Console console;

Console::Console() {
	bAlloc = FALSE;
    hInput = NULL;
	hOutput = NULL;
	hError = NULL;
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

Console& Console::write(ResRef& rText) {
	DWORD size = 8;

	EnterCriticalSection(&csConsole);
	WriteConsole(hOutput, &rText, size, &size, NULL);
	LeaveCriticalSection(&csConsole);
  
	return *this;
}

Console& Console::write(LPCTSTR lpsz) {
	DWORD size = (DWORD)strlen(lpsz);

	EnterCriticalSection(&csConsole);
	WriteConsole(hOutput, lpsz, size, &size, NULL);
	LeaveCriticalSection(&csConsole);
  
	return *this;
}

Console& Console::write(CString& s) {
	DWORD size = s.GetLength();
	WriteConsoleA(hOutput, (LPCTSTR)s, size, &size, NULL);
	return *this;
}

Console& Console::writef(LPCTSTR format, ...) {
	CString s;
    va_list v;
    va_start(v, format);
	s.FormatV(format, v);
	DWORD size = s.GetLength();

	EnterCriticalSection(&csConsole);
	WriteConsoleA(hOutput, (LPCTSTR)s, size, &size, NULL);
	LeaveCriticalSection(&csConsole);

	return *this;
}

Console& Console::writef(char color, LPCTSTR format, ...) {
	CString s;
    va_list v;
    va_start(v, format);
	s.FormatV(format, v);
	DWORD size = s.GetLength();

	CONSOLE_SCREEN_BUFFER_INFO cbsi;

	GetConsoleScreenBufferInfo(hOutput, &cbsi);

	EnterCriticalSection(&csConsole);
	SetConsoleTextAttribute(hOutput, color);
	WriteConsoleA(hOutput, (LPCTSTR)s, size, &size, NULL);
	SetConsoleTextAttribute(hOutput, cbsi.wAttributes);
	LeaveCriticalSection(&csConsole);

	return *this;
}