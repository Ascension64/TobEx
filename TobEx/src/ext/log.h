#ifndef LOG_H
#define LOG_H

#include "stdafx.h"
#include "resref.h"

class Log;
extern Log L;

class Log {
public:
	Log();
	~Log();
	BOOL Init();

	Log& append(ResRef& rText);
	Log& append(LPCTSTR lpsz);
	Log& append(CString& s);
	Log& append(LPCTSTR format, int n, ...);
	Log& timestamp();

	BOOL bFileOpen;
protected:
    HANDLE hFile;
    LPCTSTR szFile;
};

#endif //LOG_H