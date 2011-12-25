#ifndef LOG_H
#define LOG_H

#include "win32def.h"
#include "resref.h"

class Log;
extern Log L;
extern Log LD;

class Log {
public:
	Log(LPCTSTR lpsz);
	~Log();
	BOOL Init(int mode);

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