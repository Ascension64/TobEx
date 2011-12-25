#ifndef CONSOLE_H
#define CONSOLE_H

#include "win32def.h"
#include "resref.h"

class Console {
public:
    Console();
    ~Console();
	BOOL Init();

    Console& write(ResRef& rText);
    Console& write(LPCTSTR lpsz);
	Console& write(CString& s);
	Console& write(LPCTSTR format, int n, ...);

    BOOL bAlloc;
protected:
    HANDLE hInput, hOutput, hError;
	CRITICAL_SECTION csConsole;
};

extern Console console;

#endif //CONSOLE_H