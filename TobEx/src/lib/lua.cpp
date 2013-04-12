#include "lua.h"

#include "stdafx.h"

//CLUAConsole
DefineLibMemberFunc(void, CLUAConsole, DisplayText, (IECString s), DisplayText, DisplayText, (s), 0x5ACD00);
DefineLibMemberFunc(void, CLUAConsole, StartStore, (char* sz), StartStore, StartStore, (sz), 0x5ACF2E);
