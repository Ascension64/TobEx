#ifndef SOUNDCORE_H
#define SOUNDCORE_H

#include "sndcore.h"

extern BOOL (CSoundMixer::*Tramp_CSoundMixer_InitSonglist)(int, char**);

struct DETOUR_CSoundMixer : public CSoundMixer {
	BOOL DETOUR_InitSonglist(int nSongs, char** pSongFileArray);
};

#endif //SOUNDCORE_H