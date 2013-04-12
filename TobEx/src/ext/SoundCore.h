#ifndef SOUNDCORE_H
#define SOUNDCORE_H

#include "sndcore.h"

DeclareTrampMemberFunc(BOOL, CSoundMixer, InitSonglist, (int nSongs, char** pSongFileArray), InitSonglist);

struct DETOUR_CSoundMixer : public CSoundMixer {
	BOOL DETOUR_InitSonglist(int nSongs, char** pSongFileArray);
};

#endif //SOUNDCORE_H