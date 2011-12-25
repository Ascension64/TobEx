#include "sndcore.h"

BOOL (CSoundMixer::*CSoundMixer_InitSonglist)(DWORD, char**) =
	SetFP(static_cast<BOOL (CSoundMixer::*)(DWORD, char**)>		(&CSoundMixer::InitSonglist),	0x9E209B);

BOOL CSoundMixer::InitSonglist(DWORD nSongs, char** pSongFileArray) { return (this->*CSoundMixer_InitSonglist)(nSongs, pSongFileArray); }