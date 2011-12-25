#ifndef SOUNDMUSIC_H
#define SOUNDMUSIC_H

#include "sndcore.h"

struct DETOUR_CSoundMixer : public CSoundMixer {
	BOOL DETOUR_InitSonglist(DWORD, char**);
};

#endif //SOUNDMUSIC_H