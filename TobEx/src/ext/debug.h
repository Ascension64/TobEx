#ifndef DEBUG_H
#define DEBUG_H

#include "stdafx.h"

#define _CheckSize(size, object) CheckSize(#object, size, sizeof(object))

void Debug();
void CheckSize(LPCTSTR lpszName, size_t nExpectedSize, size_t nActualSize);

#endif //DEBUG_H
