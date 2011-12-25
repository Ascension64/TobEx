#ifndef CONSOLE_H
#define CONSOLE_H

#include "utils.h"
#include "resref.h"

class Console;
extern Console console;

class Console {
public:
    Console();
    ~Console();
	BOOL Init();

    Console& write(ResRef*);
    Console& write(LPCTSTR);
	Console& write(CString&);
	Console& write(LPCTSTR, int, ...);

    BOOL bAlloc;
protected:
    HANDLE hInput, hOutput, hError;
	CRITICAL_SECTION csConsole;
};

#endif //CONSOLE_H