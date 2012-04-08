#ifndef CONSOLE_H
#define CONSOLE_H

#include "win32def.h"
#include "resref.h"

#define CONSOLEFORECOLOR_NORMAL		0x07
#define CONSOLEFORECOLOR_ERROR		0x0C
#define CONSOLEFORECOLOR_WARNING	0x0E
#define CONSOLEFORECOLOR_HEADER		0x0F

class Console {
public:
    Console();
    ~Console();
	BOOL Init();

    Console& write(ResRef& rText);
    Console& write(LPCTSTR lpsz);
	Console& write(CString& s);
	Console& writef(LPCTSTR format, ...);
	Console& writef(char color, LPCTSTR format, ...);

    BOOL bAlloc;
protected:
    HANDLE hInput, hOutput, hError;
	CRITICAL_SECTION csConsole;
};

extern Console console;

#endif //CONSOLE_H