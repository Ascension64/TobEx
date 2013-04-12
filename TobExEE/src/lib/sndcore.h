//TobExEE
#ifndef SNDCORE_H
#define SNDCORE_H

#include "stdafx.h"
#include "rescore.h"

//Sound channels
#define CSOUNDCHANNEL_NARRATION		0
#define CSOUNDCHANNEL_AREAAMBIENT	1
#define CSOUNDCHANNEL_ACTIONS		2
#define CSOUNDCHANNEL_SWINGS		3
#define CSOUNDCHANNEL_CASTING		4
#define CSOUNDCHANNEL_GUI			5
#define CSOUNDCHANNEL_DIALOG		6
#define CSOUNDCHANNEL_PARTYSLOT0	7
#define CSOUNDCHANNEL_PARTYSLOT1	8
#define CSOUNDCHANNEL_PARTYSLOT2	9
#define CSOUNDCHANNEL_PARTYSLOT3	10
#define CSOUNDCHANNEL_PARTYSLOT4	11
#define CSOUNDCHANNEL_PARTYSLOT5	12
#define CSOUNDCHANNEL_MONSTER		13
#define CSOUNDCHANNEL_HITS			14
#define CSOUNDCHANNEL_MISSILE		15
#define CSOUNDCHANNEL_AMBIENTL		16
#define CSOUNDCHANNEL_AMBIENTN		17
#define CSOUNDCHANNEL_WALKINGC		18
#define CSOUNDCHANNEL_WALKINGM		19
#define CSOUNDCHANNEL_ARMOR			20

#define CSOUNDMIXER_MAX_SONGS		100

typedef IECPtrList CSongPosList;

class CArea;

class CSoundChannel : public CObject { //34h
public:
	CObList m_lSounds; //4h
	int m_nVolumeCurrent; //20h (0-100)
	int m_nVolumeInternal; //24h, SNDCHANN.2DA (0-100)

	//0: all SFX, no additional behaviour
	//1: nil, use CPlaylistElement sounds list, always highest priority, always highest channel
	//2: nil, plays one sound at a time, no interrupt
	//3: all speech, interruptible
	int m_nType; //28h

	bool m_bCutsceneMode; //2ch, hard-coded volume reduction at 25%
	char p2d[3];
	int m_nCutsceneVolumeReductionPercent; //30h
};

struct CSoundMixer { //Size 2844h
	int u0;
	int u4;
	int u8;
	int uc;
	int u10;
	IECString m_sSongPath; //14h
	int u18;
	int u1c;
	int u20;
	int u24;
	int u28;
	int u2c;
	int u30;
	int u34;
	RECT u38; //CSoundProperties?
	int u48;
	int u4c;
	int u50;
	int u54;
	int u58;
	int u5c;
	CObArray u60;
	char m_cSqrtArray[10001]; //74h, contains sqrt(idx) used for spectral recording curve
	char p2785[3];
	int u2788;
	CObList m_lSoundQueue; //278ch, for new looping CSounds
	CObList m_lPlaylist; //27a8h, contains buffered CPlaylistElements
	CObList m_lAreaLoopSoundQueue; //27c4h, looping area CSounds in current area
	IECPtrList u27e0;
	CObArray m_aSoundChannels; //27fch
	int u2810;
	int u2814;
	int u2818;
	int m_nXPos; //281ch, for positional sound
	int m_nYPos; //2820h, for positional sound
	int m_nZPos; //2824h, not used
	int u2828;
	int u282c;
	int u2830;
	int u2834;
	int u2838;
	int u283c;
	int u2840;
};

struct CSoundMixerWrapper { //Size 4h
	CSoundMixer* m_pMixer; //0h
};

struct SongPosition { //Size Ch, FIX_ME
	int nSong;
	int nPart;
	int nCursorPos;
};

struct ResWavFile { //Size 10h
	BOOL m_bLoaded; //0h
	ResWav* m_pRes; //4h
	ResRef m_rName; //8h
};

class CSound : CObject { //Size 78h
public:
	ResWavFile m_wav; //4h
	int u14;
	BOOL m_bUsePosition; //18h, use positional volume
	int m_nBufferSize; //1ch
	int m_nFrequency; //20h (1/500 of Hz)
	int u24;
	int m_nSRCurveRadius; //28h
	int m_nPositionalVolumePercent; //2ch
	int m_xPos; //30h
	int m_yPos; //34h
	int m_zPos; //38h
	int m_nPan; //3ch, (1/5000 of dB)
	int m_nVolume; //40h (in %)
	BOOL m_bFrequencySet; //44h
	int m_nChannelIdx; //48h, channel to use
	int m_nPriority; //4ch, lower number, higher priority when all buffers full (nTotalChannels[21] - nChannelIdx - 1 ) * 100 + custom
	BOOL m_bLoop; //50h
	int m_nFrequencyShift; //54h (in Hz)
	int m_nVolumeShift; //58h (in %)
	BOOL m_bUpdatePosition; //5ch
	void* m_pSoundBuffer; //60h
	int u64;
	BOOL m_bAllowHighestPriority; //68h, bugged so does not do anything
	CArea* m_pArea; //6ch

	//bit 0: Use cutscene volume reduction (reduces sound volume 25%)
	//bit 1: Use custom SR curve radius
	//bit 2: Use random frequency variation
	//bit 3: Use random volume variation
	//bit 4: Do not use environmental audio
	unsigned int m_dwWfxFlags; //70h

	bool m_bCutsceneMode; //74h
	char p75[3];
};

class CSoundWrapper : CObject { //Size 18h
	ResWavFile m_wav; //4h
	CSound* m_snd; //14h
};

class CPlaylistElement : CObject { //Size 1Ch
public:
	CSound* m_pSound; //4h
	int* m_pSoundBuffer; //8h, IDirectSoundBuffer* (never used)
	int m_nChannel; //ch
	int u10;
	int u14;
	bool m_bCutsceneMode; //18h
	char p19[3];
};

#endif //SNDCORE_H