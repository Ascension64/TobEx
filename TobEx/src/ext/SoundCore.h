#ifndef SOUNDCORE_H
#define SOUNDCORE_H

#include "sndcore.h"

extern BOOL (CSoundMixer::*Tramp_CSoundMixer_InitSonglist)(DWORD, char**);

struct DETOUR_CSoundMixer : public CSoundMixer {
	BOOL DETOUR_InitSonglist(DWORD, char**);
};

#endif //SOUNDCORE_H