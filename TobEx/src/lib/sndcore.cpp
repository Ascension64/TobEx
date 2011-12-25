#include "sndcore.h"

BOOL (CSoundMixer::*CSoundMixer_InitSonglist)(int, char**) =
	SetFP(static_cast<BOOL (CSoundMixer::*)(int, char**)>		(&CSoundMixer::InitSonglist),	0x9E209B);

BOOL CSoundMixer::InitSonglist(int nSongs, char** pSongFileArray) { return (this->*CSoundMixer_InitSonglist)(nSongs, pSongFileArray); }