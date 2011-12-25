#ifndef SNDCORE_H
#define SNDCORE_H

#include "utils.h"
#include "resref.h"
#include "rescore.h"
#include "cstringex.h"

//Sound channels
#define CSOUNDCHANNEL_NARRATION 0
#define CSOUNDCHANNEL_AREAAMBIENT 1
#define CSOUNDCHANNEL_ACTIONS 2
#define CSOUNDCHANNEL_SWINGS 3
#define CSOUNDCHANNEL_CASTING 4
#define CSOUNDCHANNEL_GUI 5
#define CSOUNDCHANNEL_DIALOG 6
#define CSOUNDCHANNEL_PARTYSLOT0 7
#define CSOUNDCHANNEL_PARTYSLOT1 8
#define CSOUNDCHANNEL_PARTYSLOT2 9
#define CSOUNDCHANNEL_PARTYSLOT3 10
#define CSOUNDCHANNEL_PARTYSLOT4 11
#define CSOUNDCHANNEL_PARTYSLOT5 12
#define CSOUNDCHANNEL_MONSTER 13
#define CSOUNDCHANNEL_HITS 14
#define CSOUNDCHANNEL_MISSILE 15
#define CSOUNDCHANNEL_AMBIENTL 16
#define CSOUNDCHANNEL_AMBIENTN 17
#define CSOUNDCHANNEL_WALKINGC 18
#define CSOUNDCHANNEL_WALKINGM 19
#define CSOUNDCHANNEL_ARMOR 20

#define CSOUNDMIXER_MAX_SONGS 100

typedef CPtrList CPtrListSongPos; //AB9984

class CArea;

class CSoundChannel { //32h
//Constructor: 0x9DF8AC
//vtable: 0xAB9978
public:
	DWORD* vtable;
	
	//0: all SFX, no additional behaviour
	//1: nil, use CPlaylistElement sounds list, always highest priority, always highest channel
	//2: nil, plays one sound at a time, no interrupt
	//3: all speech, interruptible
	DWORD type; //4h

	DWORD nVolumeCurrent; //8h (0-100)
	DWORD nVolumeInternal; //ch, SNDCHANN.2DA (0-100)
	DWORD nCutsceneVolumeReductionPercent; //10h
	CObList Sounds; //14h, contains CSounds
	bool bCutsceneMode; //30h, hard-coded volume reduction at 25%
	BYTE u31; //pad
};

struct CSoundMixer { //Size 28DAh
//Constructor: 0x9DFADC
	//methods
	BOOL InitSonglist(DWORD, char**);

	//members
	BOOL bInitDsound; //0h
	DWORD* lpDirectSound; //4h, LPDIRECTSOUND
	DWORD* lpDirectSoundBuffer; //8h, LPDIRECTSOUNDBUFFER
#ifdef _DEBUG
	_CCriticalSection csSos; //ch, for music driver
#else
	CCriticalSection csSos;
#endif
	DWORD u2c[12]; //unused?
	BOOL bInit; //5ch
	DWORD u60;
	
	//locks for access to arrays and lists below
	BOOL bLockSoundChannelArray; //64h
	BOOL bLockLoopSoundQueue; //68h
	BOOL bLockPlaylist; //6ch
	BOOL bLockAreaLoopSoundQueue; //70h
	CObArray SoundChannels; //74h
	CObList SoundQueue; //88h, for new looping CSounds
	CObList Playlist; //a4h, contains buffered CPlaylistElements
	CObList AreaLoopSoundQueue; //c0h, looping area CSounds in current area

	HWND hWnd; //dch
	DWORD ue0[4]; //unused, has get and set functions
	UINT uDeviceID; //f0h
	DWORD nSoundChannels; //f4h
	DWORD nMaxSoundBuffers; //f8h, set to 8
	DWORD ufc; //1024, nMaxSoundChannels?
	
	//IDirectSound3dListener position
	DWORD xPos; //100h, for positional sound
	DWORD yPos; //104h, for positional sound
	DWORD zPos; //108h, not used

	CArea* pArea; //10ch
	DWORD nDeviceVolume; //110h, auxGetVolume() / 655
	DWORD u114;
	DWORD u118; //unused, has get and set functions

	CDWordArray u11c; //unused
	IECString sSongPath; //130h
	BOOL bSosDriverLoaded; //134h
	DWORD nSongCurrent; //138h
	DWORD nNumSongs; //13ch
	DWORD nSongPrev; //140h
	struct CSoundProperties { //Size 24h
	//Constructor: 0x9F9537
		DWORD* lpDirectSoundBuffer; //0h
		DWORD* pIKsPropertySet; //4h

		//bit0 = DSPROPSETID_EAX_ReverbProperties supports KSPROPERTY_SUPPORT_SET
		//bit1 = DSPROPSETID_EAXBUFFER_ReverbProperties supports KSPROPERTY_SUPPORT_SET
		//bit2 = DSPROPSETID_VoiceManager supports KSPROPERTY_SUPPORT_SET
		DWORD dwFlagsPropertySetSupportsSetFunction; //8h

		DWORD uc;

		//PropertyData for DSPROPSETID_EAX_ReverbProperties
		DWORD nEnvironment; //10h
		DWORD nDamping; //14h
		DWORD nDecayTime; //18h
		DWORD nVolume; //1ch

		DWORD nReverbLevel; //20h
	} m_CSoundProperties; //144h
	DWORD* u168; //LPDIRECTSOUND3DLISTENER
	DWORD dwFlagsPropertySetSupportsSetFunction; //16c, copy of CSoundProperties
	struct CA3d { //Size 2ch
	//Constructor: 0x9F9D68
		DWORD* u0; //IA3d4*
		DWORD* u4; //IA3dGeom*
		DWORD* u8; //IA3dListener*
		CPtrList uc; //AB9DF0, CA3dPlaylistElement (0x0 pIA3dSource, 0x4 pCSound, 0x8 DWORD)
		CSoundMixer* pSoundMixer; //28h
	} m_A3d; //170h
	DWORD u19c;
	DWORD nSRCurveRadius; //1a0h
	bool bUseAureal3d; //1a4h
	BYTE sqrtArray[10000]; //1a5h, contains sqrt(idx) used for spectral recording curve
	BYTE u28b5; //pad
	DWORD nCutsceneSounds; //28b6h
	CPtrListSongPos SavedSongs; //28bah
	DWORD nSavedMusicVolume; //28d6h, stores music volume when a cutscene sounds is played, restored when finished
};

extern BOOL (CSoundMixer::*CSoundMixer_InitSonglist)(DWORD, char**);

struct SongPosition { //Size Ch
	DWORD nSong;
	DWORD nPart;
	DWORD nCursorPos;
};

struct ResWavContainer { //Size 10h
	BOOL bLoaded; //0h
	ResWav* pResWav; //4h
	ResRef soundName; //8h
};

class CSound : CObject { //Size 6Ah
//Constructor: 0x9DCF80
//vtable: 0xAB9960
public:
	//DWORD* vt;
	ResWavContainer u4;
	BOOL bUsePosition; //14h, uses 24h
	DWORD nBufferSize; //18h
	DWORD nFrequency; //1ch (1/500 of Hz)
	DWORD nSRCurveRadius; //20h
	DWORD nPositionalVolumePercent; //24h
	DWORD xPos; //28h
	DWORD yPos; //2ch
	DWORD zPos; //30h
	DWORD nPan; //34h, (1/5000 of dB)
	DWORD nVolume; //38h (in %)
	BOOL bFrequencySet; //3ch
	DWORD nChannelIdx; //40h, channel to use
	DWORD nPriority; //44h, lower number, higher priority when all buffers full (nTotalChannels[21] - nChannelIdx - 1 ) * 100 + custom
	BOOL bLoop; //48h
	DWORD nFrequencyShift; //4ch (in Hz)
	DWORD nVolumeShift; //50h (in %)
	BOOL bUpdatePosition; //54h
	DWORD* m_pSoundBuffer; //58h, IDirectSoundBuffer*
	BOOL bAllowHighestPriority; //5ch, bugged so does not do anything
	CArea* pArea; //60h

	//bit 0: Use cutscene volume reduction (reduces sound volume 25%)
	//bit 1: Use custom SR curve radius
	//bit 2: Use random frequency variation
	//bit 3: Use random volume variation
	//bit 4: Do not use environmental audio
	DWORD dwWfxFlags; //64h

	bool bCutsceneMode; //68h
	BYTE u69; //pad
};

class CPlaylistElement : CObject { //Size 16h
//Constructor: 0x9DF55E
//vtable: 0xAB996C
public:
	//DWORD* vt; //0h, v0 (getName), v4 (deconstruct), v8 (donothing)
	CSound* pSound; //4h
	DWORD* m_pSoundBuffer; //8h, IDirectSoundBuffer* (never used)
	DWORD nChannel; //ch
	DWORD u10; //u44 of CSound
	bool bCutsceneMode; //14h
	BYTE u15; //pad
};

#endif //SNDCORE_H