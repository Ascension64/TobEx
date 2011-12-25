#include "log.h"

#include "utils.h"
#include "resref.h"

Log L;

Log::Log() {
	hFile = NULL;
	bFileOpen = FALSE;
	szFile = "TobEx.log";
}

Log::~Log() {
	if (hFile) CloseHandle(hFile);
}

BOOL Log::Init() {
	hFile = CreateFile(szFile, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile) SetFilePointer(hFile, 0, 0, FILE_END);
	bFileOpen = hFile ? TRUE : FALSE;
	return bFileOpen;
}

Log& Log::append(ResRef* text) {
	DWORD size = 8;
	WriteFile(hFile, (LPCVOID)text, size, &size, NULL);
	return *this;
}

Log& Log::append(LPCTSTR text) {
	DWORD size = static_cast<DWORD>(strlen(text));
	WriteFile(hFile, (LPCVOID)text, size, &size, NULL);
	return *this;
}

Log& Log::append(CString& s) {
	DWORD size = s.GetLength();
	WriteFile(hFile, (LPCVOID)s, size, &size, NULL);
	return *this;
}

Log& Log::append(LPCTSTR format, int n, ...) {
	char text[256];
	DWORD length = sizeof(text);

    va_list v;
    va_start(v, n);
	vsprintf_s(text, length, format, v);
	DWORD size = (DWORD)strlen(text);

	WriteFile(hFile, (LPCVOID)text, size, &size, NULL);
	return *this;
}

Log& Log::timestamp() {
	time_t tmTime = time(NULL);
	tm tmLocal;
	localtime_s(&tmLocal, &tmTime);
	char* buffer = new char [50];
	sprintf_s(buffer, 50, "[%s %.2d %s %.4d %.2d:%.2d:%.2d] ", days[tmLocal.tm_wday], tmLocal.tm_mday, months[tmLocal.tm_mon], tmLocal.tm_year + 1900, tmLocal.tm_hour, tmLocal.tm_min, tmLocal.tm_sec);
	append(buffer);

	delete[] buffer;
	buffer = NULL;

	return *this;
}
