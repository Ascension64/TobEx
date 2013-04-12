//TobExEE
#ifndef SNDMUS_H
#define SNDMUS_H

#include "stdafx.h"

#define SOSRESULT_NOERROR					0
#define SOSRESULT_SOS_DRIVER_NOT_LOADED		1 //SOS driver not loaded
#define SOSRESULT_SOS_INVALID_POINTER		2 //SOS invalid pointer
#define SOSRESULT_SOS_DETECT_INITIALIZED	3 //SOS detect initialized
#define SOSRESULT_SOS_FAIL_ON_FILE_OPEN		4 //SOS fail on file open
#define SOSRESULT_SOS_MEMORY_FAIL			5 //SOS memory fail
#define SOSRESULT_SOS_INVALID_DRIVER_ID		6 //SOS invalid driver ID
#define SOSRESULT_SOS_NO_DRIVER_FOUND		7 //SOS no driver found
#define SOSRESULT_SOS_DETECTION_FAILURE		8 //SOS detection failure
#define SOSRESULT_SOS_DRIVER_LOADED			9 //SOS driver loaded
#define SOSRESULT_SOS_INVALID_HANDLE		10 //SOS invalid handle
#define SOSRESULT_SOS_NO_HANDLES			11 //SOS no handles
#define SOSRESULT_SOS_PAUSED				12 //SOS paused
#define SOSRESULT_SOS_NOT_PAUSED			13 //SOS not paused
#define SOSRESULT_SOS_INVALID_DATA			14 //SOS invalid data
#define SOSRESULT_SOS_DRIVE_FILE_FAIL		15 //SOS drv file fail
#define SOSRESULT_SOS_INVALID_PORT			16 //SOS invalid port
#define SOSRESULT_SOS_INVALID_IRQ			17 //SOS invalid IRQ
#define SOSRESULT_SOS_INVALID_DMA			18 //SOS invalid DMA
#define SOSRESULT_SOS_INVALID_DMA_IRQA		19 //SOS invalid DMA IRQ
#define SOSRESULT_NO_DEVICE					20 //no device
#define SOSRESULT_NOT_INITIALIZED			21 //not initialized
#define SOSRESULT_NO_SOUND					22 //no sound
#define SOSRESULT_FUNCTION_NOT_SUPPORTED	23 //function not supported
#define SOSRESULT_NO_BUFFERS_AVAILABLE		24 //no buffers available
#define SOSRESULT_FILE_NOT_FOUND			25 //file not found
#define SOSRESULT_ALREADY_PLAYING			26 //already playing
#define SOSRESULT_NOT_PLAYING				27 //not playing
#define SOSRESULT_ALREADY_PAUSED			28 //already paused
#define SOSRESULT_NOT_PAUSED				29 //not paused
#define SOSRESULT_INVALID_HANDLE			30 //invalid handle
#define SOSRESULT_NO_MEMORY_AVAILABLE		31 //no memory available
#define SOSRESULT_UNKNOWN_ERROR				32 //unknown error

struct SongResource { //Size 104h, FIX_ME
	char m_szPath[256]; //0h
	int u100;
};

struct SosSoundBufferElement { //Size 18h
	int m_nSong; //0h, devs call this Song
	int m_nPart; //4h, Section
	int m_dwCursorPosStart; //8h, Start
	int m_dwBufferBytes; //ch, Size
	int m_dwCursorPosStartCumulative; //10h, updates on repeat
	SosSoundBufferElement* m_pNext; //14h
};

struct SosSoundBuffer { //Size 8h
	virtual ~SosSoundBuffer() {} //v0

	SosSoundBufferElement* m_pElement; //4h
};

struct SosSound { //Size A0h, FIX_ME
	void* m_pFuncOpen; //0h, dummy
	void* m_pFuncClose; //4h, dummy
	void* m_pFuncRead; //8h, Read(FILE* dummy, pBuffer, nBufSize)
	void* m_pFuncWrite; //ch, dummy
	void* m_pFuncSeek; //10h, Seek*(FILE* dummy, nOffset, int dummy)
	void* m_pFuncTell; //14h, dummy
	void* m_pFuncGetMaxBlockSize; //18h, GetMaxBlockSize()
	FILE* m_pFile; //1ch, dummy, set to 0x18181818
	void* m_pBuffer; //20h, size nBufferSize
	int* m_lpDirectSoundBuffer; //24h

	//DSBUFFERDESC {
	int m_dwSize; //28h
	int m_dwFlags; //2ch
	int m_dwBufferBytes; //30h
	int m_dwReserved; //34h
	int m_pWaveFormatEx; //38h, WAVEFORMATEX*
	//}

	unsigned int m_dwFlags2; //3ch, Arg2

	//bit0: loaded?
	//bit1: playing
	//bit2: has transition
	//bit3: paused
	unsigned int m_dwFlagsPlay; //40h

	unsigned int m_dwFlags1; //44h, Arg1
	int m_dwPausedCursorPos; //48h
	int m_dwVolume; //4ch
	int u50; //0, 1, -1
	int u54;
	int u58; //-1
	int u5c; //1
	int m_nMaxBlockSize; //60h
	int m_nCurrentPlayCursor; //64h
	int m_nCurrentPlayCursorCumulative; //68h, total nBufferSize
	int m_nBlockSize; //6ch, nBits * nBufferSize
	int m_nCurrentBlock; //70h
	int m_nCurrentBlockCumulative; //74h
	int m_nBits; //78h
	int m_nBufferSize; //7ch
	int u80;
	SosSound** m_ppSosSound; //84h, arg1, for 88h
	int m_pFuncOnTransition; //88h, pFunc(SosSound*, dwType)
	int u8c; //arg1 for u90
	int u90; //pFunc(Arg1)
	SosSound* m_pPrev; //94h
	SosSound* m_pNext; //98h
	SosSoundBuffer* m_pSosSoundBuffer; //9ch
};

struct SosSoundTransition { //Size 20h, FIX_ME
	SosSound* m_pSound; //0h
	int m_dwVolumeDelta; //4h, amount to inc/dec volume per timer event
	int m_dwVolumeTarget; //8h, target volume to DoTransition()
	int m_dwVolumeInitial; //ch
	int m_dwVolumeCurrent; //10h

	//0: stop and set all volume levels to delta
	//1: pause and reset volume to initial
	//2: none
	int m_dwBehaviourAtSilent; //14h

	SosSoundTransition* m_pPrev; //18h
	SosSoundTransition* m_pNext; //1ch
};

struct SosSong { //Size 1Ch, FIX_ME
	char m_szPrefix[8]; //0h
	char* m_pszPath; //8h
	char* m_pszPartLinkArray; //ch, char[idxSong][idxPart], size nParts * dwSosSongs, FF = end
	char* m_pszTagArray; //10h, char tagName[8]
	char* m_pszPartArray; //14h, char partName[8]
	int m_nParts; //18h
};

struct AcmDecoder { //Size 54h, FIX_ME
	void* m_pFunc; //0h, such as fread
	FILE* m_pFile; //4h
	char* m_pszStreamBuf; //8h
	int m_nBufSize; //ch, init to 200h
	char* m_pszStreamBufCursor; //10h, current cursor position
	int m_nCharRemaining; //14h, distance to end of buffer
	char m_pszFourCC[4]; //18h
	int m_nShiftLeft; //1ch, to shift chars

	int m_nLevels; //20h
	int u24; //2 ^ nLevels
	int m_nSubBlocks; //28h
	int m_nTotalBlockSize; //2ch, nSubBlocks * 2^nLevels
	int* u30; //30h, size (3/2 * u24 - 2) DWORDs
	int* u34; //34h, size nTotalBlockSize DWORDs
	int u38; //0x800 / u24 - 2
	int u3c; //u38 * u24
	int m_nChannels; //40h
	int m_nRate; //44h
	int m_nSamples; //48h

	int u4c;
	int u50;
};

struct CAcm { //Size 28h, FIX_ME
	//bit0: file opened
	//bit1: stream created
	unsigned int m_dwFlags; //0h
	FILE* m_pFile; //4h
	AcmDecoder* m_pStream; //8h
	int m_nSize; //10h, SFAD codec
	void* m_pData; //14h, SFAD codec
	int m_nSamples; //18h
	int m_nRate; //1ch
	int m_nChannels; //20h
	int m_nOffset; //24h
};

struct ACMHeader { //FIX_ME
	long m_fourcc; //0x01, 0x03, 0x28, 0x97
	long m_samples;
	unsigned short m_channels;
	unsigned short m_rate;
	unsigned short m_levels : 4;
	unsigned short m_subblocks : 12;
}; 

#endif //SNDMUS_H