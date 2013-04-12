//TobExEE
#ifndef MAIN_H
#define MAIN_H

#include "stdafx.h"

void Init();
void Deinit();
BOOL DllGetVersion(char** lplpsz);
BOOL CheckExeVersion(LPCSTR lpFile);

#endif //MAIN_H