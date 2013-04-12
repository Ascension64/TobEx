#include "SoundCore.h"

#include "stdafx.h"
#include "sndcore.h"
#include "sndmus.h"
#include "console.h"

DefineTrampMemberFunc(BOOL, CSoundMixer, InitSonglist, (int nSongs, char** pSongFileArray), InitSonglist, InitSonglist, 0x9E209B);

BOOL DETOUR_CSoundMixer::DETOUR_InitSonglist(int nSongs, char** pSongFileArray) {
	if (!bSosDriverLoaded) return FALSE;
	if (nNumSongs) return FALSE; //normally an assert
	LPTSTR szSongPath = sSongPath.GetBuffer(0);
#ifndef _DEBUG
	CSingleLock csl = CSingleLock(&csSos, TRUE);
#endif
	Sos_LoadSongPath(szSongPath, "acm");
	sSongPath.ReleaseBuffer(-1);

	SongResource* pArray = (SongResource*)malloc(nSongs * sizeof(SongResource));
	SongResource** ppArray = (SongResource**)malloc(nSongs * 4);

	for (int i = 0; i < nSongs; i++) {
		*(ppArray+i) = pArray+i;
		sprintf_s( (pArray+i)->path, 256, "%s/%s", sSongPath, *(pSongFileArray+i) );
	}

	Sos_InitSonglist(ppArray, nSongs);

#ifndef _DEBUG
	csl.Unlock();
#endif

	nNumSongs = nSongs;

	free(pArray);
	free(ppArray);

	return TRUE;
}