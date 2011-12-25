#include "sndmus.h"

void (__cdecl *Sos_LoadSongPath)(LPTSTR, LPTSTR) =
	reinterpret_cast<void (__cdecl *)(LPTSTR, LPTSTR)>			(0xA160F8);
BOOL (__cdecl *Sos_InitSonglist)(SongResource**, DWORD) =
	reinterpret_cast<BOOL (__cdecl *)(SongResource**, DWORD)>	(0xA145D6);