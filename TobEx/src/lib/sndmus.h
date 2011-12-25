#ifndef SNDMUS_H
#define SNDMUS_H

#include "utils.h"

#define SOSRESULT_NOERROR 0
#define SOSRESULT_SOS_DRIVER_NOT_LOADED 1 //SOS driver not loaded
#define SOSRESULT_SOS_INVALID_POINTER 2 //SOS invalid pointer
#define SOSRESULT_SOS_DETECT_INITIALIZED 3 //SOS detect initialized
#define SOSRESULT_SOS_FAIL_ON_FILE_OPEN 4 //SOS fail on file open
#define SOSRESULT_SOS_MEMORY_FAIL 5 //SOS memory fail
#define SOSRESULT_SOS_INVALID_DRIVER_ID 6 //SOS invalid driver ID
#define SOSRESULT_SOS_NO_DRIVER_FOUND 7 //SOS no driver found
#define SOSRESULT_SOS_DETECTION_FAILURE 8 //SOS detection failure
#define SOSRESULT_SOS_DRIVER_LOADED 9 //SOS driver loaded
#define SOSRESULT_SOS_INVALID_HANDLE 10 //SOS invalid handle
#define SOSRESULT_SOS_NO_HANDLES 11 //SOS no handles
#define SOSRESULT_SOS_PAUSED 12 //SOS paused
#define SOSRESULT_SOS_NOT_PAUSED 13 //SOS not paused
#define SOSRESULT_SOS_INVALID_DATA 14 //SOS invalid data
#define SOSRESULT_SOS_DRIVE_FILE_FAIL 15 //SOS drv file fail
#define SOSRESULT_SOS_INVALID_PORT 16 //SOS invalid port
#define SOSRESULT_SOS_INVALID_IRQ 17 //SOS invalid IRQ
#define SOSRESULT_SOS_INVALID_DMA 18 //SOS invalid DMA
#define SOSRESULT_SOS_INVALID_DMA_IRQA 19 //SOS invalid DMA IRQ
#define SOSRESULT_NO_DEVICE 20 //no device
#define SOSRESULT_NOT_INITIALIZED 21 //not initialized
#define SOSRESULT_NO_SOUND 22 //no sound
#define SOSRESULT_FUNCTION_NOT_SUPPORTED 23 //function not supported
#define SOSRESULT_NO_BUFFERS_AVAILABLE 24 //no buffers available
#define SOSRESULT_FILE_NOT_FOUND 25 //file not found
#define SOSRESULT_ALREADY_PLAYING 26 //already playing
#define SOSRESULT_NOT_PLAYING 27 //not playing
#define SOSRESULT_ALREADY_PAUSED 28 //already paused
#define SOSRESULT_NOT_PAUSED 29 //not paused
#define SOSRESULT_INVALID_HANDLE 30 //invalid handle
#define SOSRESULT_NO_MEMORY_AVAILABLE 31 //no memory available
#define SOSRESULT_UNKNOWN_ERROR 32 //unknown error

struct SongResource { //Size 104h
	char path[256]; //0h
	DWORD u100;
};

struct SosSoundBufferElement { //Size 18h
	DWORD nSong; //0h, devs call this Song
	DWORD nPart; //4h, Section
	DWORD dwCursorPosStart; //8h, Start
	DWORD dwBufferBytes; //ch, Size
	DWORD dwCursorPosStartCumulative; //10h, updates on repeat
	SosSoundBufferElement* pNext; //14h
};

struct SosSoundBuffer { //Size 8h
//Constructor: 0xA1B8B0
//vtable: 0xAB9F54
	virtual ~SosSoundBuffer() {} //v0

	SosSoundBufferElement* pElement; //4h
};

struct SosSound { //Size A0h
//Constructor: in 0xA1106C
	void* pFuncOpen; //0h, dummy
	void* pFuncClose; //4h, dummy
	void* pFuncRead; //8h, Read(FILE* dummy, pBuffer, nBufSize)
	void* pFuncWrite; //ch, dummy
	void* pFuncSeek; //10h, Seek*(FILE* dummy, nOffset, int dummy)
	void* pFuncTell; //14h, dummy
	void* pFuncGetMaxBlockSize; //18h, GetMaxBlockSize()
	FILE* pFile; //1ch, dummy, set to 0x18181818
	void* pBuffer; //20h, size nBufferSize
	DWORD* lpDirectSoundBuffer; //24h

	//DSBUFFERDESC {
	DWORD dwSize; //28h
	DWORD dwFlags; //2ch
	DWORD dwBufferBytes; //30h
	DWORD dwReserved; //34h
	DWORD pWaveFormatEx; //38h, WAVEFORMATEX*
	//}

	DWORD dwFlags2; //3ch, Arg2

	//bit0: loaded?
	//bit1: playing
	//bit2: has transition
	//bit3: paused
	DWORD dwFlagsPlay; //40h

	DWORD dwFlags1; //44h, Arg1
	DWORD dwPausedCursorPos; //48h
	DWORD dwVolume; //4ch
	DWORD u50; //0, 1, -1
	DWORD u54;
	DWORD u58; //-1
	DWORD u5c; //1
	DWORD nMaxBlockSize; //60h
	DWORD nCurrentPlayCursor; //64h
	DWORD nCurrentPlayCursorCumulative; //68h, total nBufferSize
	DWORD nBlockSize; //6ch, nBits * nBufferSize
	DWORD nCurrentBlock; //70h
	DWORD nCurrentBlockCumulative; //74h
	DWORD nBits; //78h
	DWORD nBufferSize; //7ch
	DWORD u80;
	SosSound** ppSosSound; //84h, arg1, for 88h
	DWORD pFuncOnTransition; //88h, pFunc(SosSound*, dwType)
	DWORD u8c; //arg1 for u90
	DWORD u90; //pFunc(Arg1)
	SosSound* pPrev; //94h
	SosSound* pNext; //98h
	SosSoundBuffer* pSosSoundBuffer; //9ch
};

struct SosSoundTransition { //Size 20h
	SosSound* pSound; //0h
	DWORD dwVolumeDelta; //4h, amount to inc/dec volume per timer event
	DWORD dwVolumeTarget; //8h, target volume to DoTransition()
	DWORD dwVolumeInitial; //ch
	DWORD dwVolumeCurrent; //10h

	DWORD dwBehaviourAtSilent; //14h
	//0: stop and set all volume levels to delta
	//1: pause and reset volume to initial
	//2: none

	SosSoundTransition* pPrev; //18h
	SosSoundTransition* pNext; //1ch
};

struct SosSong { //Size 1Ch
	char prefix[8]; //0h
	char* path; //8h
	BYTE* pPartLinkArray; //ch, BYTE[idxSong][idxPart], size nParts * dwSosSongs, FF = end
	char* pTagArray; //10h, char tagName[8]
	char* pPartArray; //14h, char partName[8]
	DWORD nParts; //18h
};

struct AcmDecoder { //Size 54h
	void* pFunc; //0h, such as fread
	FILE* pFile; //4h
	char* streamBuf; //8h
	DWORD nBufSize; //ch, init to 200h
	char* streamBufCursor; //10h, current cursor position
	DWORD nCharRemaining; //14h, distance to end of buffer
	char FourBuf[4]; //18h
	DWORD nShiftLeft; //1ch, to shift chars

	DWORD nLevels; //20h
	DWORD u24; //2 ^ nLevels
	DWORD nSubBlocks; //28h
	DWORD nTotalBlockSize; //2ch, nSubBlocks * 2^nLevels
	DWORD* u30; //30h, size (3/2 * u24 - 2) DWORDs
	DWORD* u34; //34h, size nTotalBlockSize DWORDs
	DWORD u38; //0x800 / u24 - 2
	DWORD u3c; //u38 * u24
	DWORD nChannels; //40h
	DWORD nRate; //44h
	DWORD nSamples; //48h

	DWORD u4c;
	DWORD u50;
};

struct CAcm { //Size 28h
	//bit0: file opened
	//bit1: stream created
	DWORD dwFlags; //0h
	FILE* pFile; //4h
	AcmDecoder* pStream; //8h
	DWORD nSize; //10h, SFAD codec
	void* pData; //14h, SFAD codec
	DWORD nSamples; //18h
	DWORD nRate; //1ch
	DWORD nChannels; //20h
	DWORD nOffset; //24h
};

struct ACMHeader {
	long fourcc; //0x01, 0x03, 0x28, 0x97
	long samples;
	unsigned short channels;
	unsigned short rate;
	unsigned short levels : 4;
	unsigned short subblocks : 12;
}; 

extern void (__cdecl *Sos_LoadSongPath)(LPTSTR, LPTSTR);
extern BOOL (__cdecl *Sos_InitSonglist)(SongResource**, DWORD);

#endif //SNDMUS_H