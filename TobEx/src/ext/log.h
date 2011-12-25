#ifndef LOG_H
#define LOG_H

#include "utils.h"
#include "resref.h"

class Log;
extern Log L;

class Log {
public:
	Log();
	~Log();
	BOOL Init();

	Log& append(ResRef*);
	Log& append(LPCTSTR);
	Log& append(CString&);
	Log& append(LPCTSTR, int, ...);
	Log& timestamp();

	//members
	BOOL bFileOpen;
protected:
    HANDLE hFile;
    LPCTSTR szFile;
};

#endif //LOG_H