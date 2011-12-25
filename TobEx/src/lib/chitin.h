#ifndef CHITIN_H
#define CHITIN_H

#include "utils.h"
#include "engchargen.h"
#include "engrecord.h"
#include "engpriestbk.h"
#include "engmagebk.h"
#include "engine.h"
#include "msgcore.h"
#include "network.h"
#include "rescore.h"
#include "sndcore.h"
#include "vidcore.h"
#include "infgame.h"
#include "cstringex.h"
#include "tlkcore.h"

class CBaldurChitin;

extern CBaldurChitin* g_pChitin;

class CBaldurChitin {
//Size: 0x720C
//Constructor: 0x432108
//vtable: 0xAA5F9C
public:
	virtual void v0() {}
	virtual void v4(HINSTANCE hInstance, int nShowCmd) {} //0x9A6746, Called from ChitinMain(), calls v3c, v4c, vbc

	//LoadStringA() uID functions
	//3 = This version will only run on English language operating systems!
	//4 = This version will only run in Canada and the United States!
	//8 = This version of the Baldur Key file has expired please contact Press@bioware.com for a valid file.
	//13 = Key File Expires June 15
	//Windows video mode not supported, use <ALT-Tab> to switch to Windows
	virtual int v8() { return 6; }
	//Can not open OpenGL DLL.
	virtual int vc() { return 7; }
	//This program needs to run in Direct Draw Exclusive Mode. Please restart after closing other Direct Draw programs.
	virtual int v10() { return 5; }
	//ChoosePixelFormat failed.
	virtual int v14() { return 1; }
	//SetPixelFormat failed.
	virtual int v18() { return 2; }
	//Can not set game resolution, user must change desktop resolution through Control Panel.
	virtual int v1c() { return 9; }
	//Can not set game bit depth, user must change desktop bit depth through Control Panel.
	virtual int v20() { return 10; }
	//Can not run 3d when desktop bit depth is less than 16 bit (65535 colors), running 2d instead.
	virtual int v24() { return 11; }
	//Window's fonts do not work with 3d, running 2d instead.
	virtual int v28() { return 12; }

	virtual void v2c() {} //ProcMain for threadDF4h (multiplayer?)
	virtual void v30() {} //0x436359, ProcMain for threadE14h (CResHandler loop)
	virtual void v34() {} //0x4363A6, ProcMain for threadF24h (Timer loop) - calls v8c
	virtual void CreateResObject(DWORD fileType) {} //v38, 0x434D1C
	virtual IECString v3c() { return IECString("IDI_BIOWARE"); } //0x43C8D0, GetChitinIcon(), "IDI_BIOWARE"
	virtual void v40(IECString* pStr) { pStr->operator =("Baldr"); return; } //Baldr (0xB77238)
	virtual int GetResTypeId(IECString* pStr) { return 0; } //v44, returns CRES_TYPE ID based on filetype (compares file extension), see CInfGame.h
	virtual IECString GetFileExtension(int ID) { return IECString(""); } //v48, returns IECString of filetype with ID as above
	virtual void v4c() {} //0x9A68CB, CreateChitinWindow(), calls v54
	virtual void v50() {} //returns Obj+6C66h
	virtual void v54(HWND hWnd) {} //0x436C0B, ? InitDirectDraw InitDirectSound, calls vb4, vf4
	virtual void v58() {} //?
	virtual void Set5D9C(DWORD dw) {}
	virtual void v60() {} //?
	virtual void v64() {} //?
	virtual void Set6B10(DWORD dw) {}
	virtual void v6c() {} //some multiplayer stuff? Uses GameSpy and RogerWilco
	virtual void v70() {} //sets Obj+6C44h to 1 (BYTE)
	virtual void v74() {} //uses RogerWilco
	virtual void v78() {} //?
	virtual void v7c() {} //multiplayer thing
	virtual void v80() {} //OnMultiplayerLeave
	virtual void v84() {} //?
	virtual void v88() {} //DebugBaldurMessage(dwDebugLevel, char*, pnLength)
	virtual void v8c() {} //0x43544C ? WindowUpdateProc - Executes all messages
	virtual void v90() {} //WriteWindowSettings
	virtual void v94() {} //0x9A5C17, LoadEngine(pEngine)
	virtual void v98() {} //ShowErrorAndQuit
	virtual const char* GetIniName() { return ".\\Baldur.ini"; } //v9c
	virtual const char* GetKeyName() { return ".\\Chitin.key"; } //va0
	virtual const char* GetLogName() { return ".\\Baldur.log"; } //va4
	virtual const char* GetErrName() { return ".\\Baldur.err"; } //va8
	virtual void vac() {} //void CBaldurChitin::WriteScreenDepth(nBitDepth)
	virtual void vb0() {} //GetScreenDepthSettings
	virtual BYTE GetNumSoundChannels() { return 15; } //vb4
	virtual void vb8() {} //0x43CB40, virtual address @ AA6054 so you can continue later
	virtual void vbc() {} //0x436FF2, load video options
	virtual void vc0() {} //0x43754E, load normal.bam into 6d04

	virtual void vc8() {} //0x43CB80, SetSoundChannelVolumes

	//virtual void vd4() {} //0x43CC20, sets global B14F78 to a BYTE
	//virtual void ve8() {} //0x43CAD0, GetGamespyGameName(IECString*), puts "bg2bhaal" into arg
	//virtual void vf4() {} //0x438C0A, InitSongListAndSoundChannels
	virtual void vf8() {} //0x43CA50, DoesSupportEAX(nChannel)
	virtual void vfc() {} //0x43CA90, GetEnvironmentalAudioState()

	//virtual void v104() {} //0x43CC40, bool GetSoundEnvironmentInfo(IECString* sAreaName, pdwEnv, pfDamping, pfDecay, pfVolume, pfReverb)
	//virtual void v108() {}
	//etc.

	//functions
	CBaldurChitin();
	CBaldurChitin& Construct(void) { return *this; } //dummy

	//members
	DWORD u4; //1 on normal mouse buttons, 2 on swap buttons
	DWORD u8; //2 on normal mouse buttons, 1 on swap buttons
	DWORD uc;
	DWORD u10;
	DWORD u14;
	DWORD u18; //copy of 3ch
	CWnd* pWnd; //1ch, pointer to 78h
	DWORD u20;
	DWORD u24;
	DWORD u28; //copy of 3ch
	DWORD u2c;
	DWORD u30;
	DWORD u34;
	DWORD u38; //copy of 3ch
	DWORD DoubleClickTime; //3ch
	DWORD nDoubleClkWidth; //40h, GetSystemMetrics(SM_CXDOUBLECLK)
	DWORD nDoubleClkHeight; //44h, GetSystemMetrics(SM_CYDOUBLECLK)
	BOOL bChitinLoaded; //48h, EngineLoaded
	DWORD u4c; //CResHandlerLoopThreadLoaded
	DWORD u50;
	CObList engines; //0x54
	DWORD u70;
	CEngine* pStartingEngine; //74h, pStartingEngine, 42beh
	CWnd m_CWnd; //78h
	HANDLE hProcess; //b4h, duplicate handle of current process
	HINSTANCE hInstance; //b8h, this instance
	DWORD ubc; //timer event CObject from timeSetEvent()
	DWORD uc0; //timer resolution from timeGetDevCaps()
	CRITICAL_SECTION uc4;
	IECString CmdLine; //dch
	BYTE bDisableWindow; //e0h, Window Disabled?
	BYTE bFullScreen; //e1h
	BYTE ue2; //copy of e1h
	BYTE ue3;
	DWORD ue4;
	DWORD ue8[4];
	BYTE uf8;
	BYTE uf9;
	DWORD dwPlatformId; //fah, from _OSVERSIONINFO of GetVersionExA()
	WORD ufe;
	DWORD nScreenWidth; //100h, GetSystemMetrics(SM_CX[FULL]SCREEN)
	DWORD nScreenHeight; //104h, GetSystemMetrics(SM_CY[FULL]SCREEN)
	DWORD nScreenPosX; //108h
	DWORD nScreenPosY; //10ch
	DWORD u110; //(+host)
	DWORD u114; //(+host)
	IECString connectParam; //118h for cmd (+connect)
	IECString hostParam; //11ch for cmd (+host)
	IECString nameParam; //120h for cmd (+name)
	IECString passwordParam; //124h for cmd (+password)
	DWORD u128; //(+newgame)
	DWORD u12c; //(+loadgame)
	IECString hostnameParam; //130h for cmd (+hostname)
	bool m_bAutoConnect; //134h, (+location)
	BYTE u135;
	IECString locationParam; //136h for cmd (+location)
	BYTE u13a; //(+tob)
	BYTE u13b;
	DWORD m_bDisableBrightest; //13ch - Disable Brighten (if 3d acceleration, never disabled)
	DWORD m_bLimitTransparency; //140h - Force 50% Transparency
	DWORD nMaxPlayers; //144h
	DWORD dwSong; //148h
	RECT u14c; //current PropertyData for CSoundProperties IKsPropertySet::Set()
	BOOL bInitSound; //15ch
	WORD u160;
	DWORD u162;
	CPtrList u166; //AA5C50
	DWORD u182; //SPI_GETWHEELSCROLLLINES
	DWORD u186; //LRESULT of SendMessageA(FindWindowA(MouseZ, MagellanMSWHEEL), RegisterWindowMessageA(MSH_WHEELSUPPORT_MSG), 0, 0)
	DWORD u18a; //UINT MSWHEEL_ROLLMSG WindowMessage CObject
	DWORD m_bFirstFrameOutline; //18eh
	DWORD m_bUseMirrorFX; //192h
	DWORD u196; //UINT QueryCancelAutoPlay WindowMessage CObject
	DWORD u19a;
	BYTE m_bOverConfirmEverything; //19eh
	BYTE m_bAlternateSRCurve; //19fh
	DWORD nSRCurveRadius; //1a0h, SR = spectral recording
	DWORD u1a4;
	DWORD u1a8; //cmp 24, assoc timer loop
	DWORD u1ac;
	DWORD u1b0;
	DWORD u1b4; //cmp 15, assoc timer loop
	DWORD u1b8;
	DWORD u1bc; //cmp 30, assoc timer loop
	BOOL m_bDoubleByteCharSupport; //1c0h
	DWORD u1c4; //copy of 1c0h

	struct CImeUI {
	//Constructor: 0x9A9000
	//Size: 0x140
		char u0[0x104];
		DWORD u104;
#ifdef _DEBUG
		_CCriticalSection u108;
#else
		CCriticalSection u108;
#endif
		DWORD u128;	
		DWORD u12c;
		IECString u130;
		IECString u134;
		IECString u138;
		CVidMosaic* u13c; //13ch, uses "IMEUI.MOS"
	} m_CImeUI; //1c8h

	IECString sFontName; //308h
	DWORD u30c;
	BOOL m_b16BitTextures; //310h, if 0 it means 32-bit
	HANDLE m_eventTimer; //314h, HANDLE to BaldurTimeEvent
	CRITICAL_SECTION u318; //for CResHandler::CObList (all of them)
	CRITICAL_SECTION u330; //for CResHandler::pResTemp
	CRITICAL_SECTION u348;
	DWORD u360[6]; //unused
	CRITICAL_SECTION u378;
	CRITICAL_SECTION u390;
	DWORD u3a8; //if 1, terminates thread E14 (v30)
	HANDLE u3ac; //hThread for CResHandler loop
	DWORD u3b0;
	HANDLE u3b4; //hThread for multiplayer?
	HANDLE u3b8; //hThread for Timer loop
	DWORD u3bc; //if 1, terminates thread DF4 and F24 (v2c)
	CEngine* pEngineActive; //3c0h
	CSoundMixer mixer; //3c4h
	CResHandler ResHandler; //2c9eh
	CVideo cVideo; //2f46h
	CNetwork cNetwork; //30aeh

	struct _9DAAEA {
	//Size: 0x2C
	//Constructor: 0x9DAAEA
		BYTE u0;
		BYTE u1;
		DWORD u2[6]; //unused?
		DWORD u1a;
		DWORD u1e;
		DWORD u22; //unused?
		DWORD u26;
		WORD u2a; //unused?
	} m_9DAAEA; //3fe8h

	struct _9DA0B0 {
	//Size: 0x2
	//Constructor: 0x9DA0B0
		WORD u0;
	} m_9DA0B0; //4014h

	CRogerWilco m_CRogerWilco; //4016h
	DWORD u4026;
	DWORD u402a;
	DWORD u402e;
	DWORD nChitinUpdates; //4032h
	DWORD u4036;
	CObList GameDirectories; //403ah, Contains 0x8 CObjects (vt, dwLoaded, IECString* directoryName) for directories for the game, AB8ED0
	DWORD u4056;
	DWORD u405a;
	DWORD u405e;
	DWORD u4062;
	DWORD nKeyboardDelay; //4066h
	DWORD nKeyboardSpeed; //406ah
#ifdef _DEBUG
	_CCriticalSection u406e;
#else
	CCriticalSection u406e;
#endif

	struct CProgressBar { //Size 6Ch
	//Constructor: 0x99BF5A
		DWORD u0;
		DWORD u4;
		DWORD u8;
		DWORD uc;
		DWORD m_nActionTarget; //10h
		BYTE u14;
		BYTE u15;
		DWORD u16;
		BYTE u1a;
		BYTE u1b;
		BYTE u1c;
		BYTE u1d[6]; //by player
		BYTE u23;
		DWORD u24[6]; //by player
		DWORD u3c[6]; //by player
		DWORD u54[6]; //by player
	} m_ProgressBar; //0x408e

	DWORD m_threadID[10]; //0x40fa
	HANDLE m_hThread[10]; //0x4122
	WORD m_nThreads; //0x414a, note CHITIN_MAX_THREADS = 10
	WORD u414c;
	DWORD u414e;
	DWORD u4152;
	DWORD u4156[16]; //init to 1000
	DWORD u4196[16];
	DWORD u41d6[16];
	DWORD u4216[16];
	DWORD u4256[16];
	KeyTableEntry* tempKey; //4296h - used during CResHandler::Demand()
	IECString F_NORMAL; //429ah
	IECString F_REALMS; //429eh
	IECString F_STONEBIG; //42a2h
	IECString F_STONESML; //42a6h
	IECString F_TOOLFONT; //42aah
	IECString F_FLOATTXT; //42aeh
	DWORD nDisplaySubtitles; //42b2h

	void* u42b6; //size 0x8f6, fonts cursors and tooltips?
	CInfGame* pGame; //0x42ba

	//21 objects in CHUIObjects CPtrList in this order
	void* u42be; //size 0xfe, CStartingEngine
	void* pBaldurProjector; //42c2h, size 0x6d0, uses NORMAL.BAM, for movies
	void* u42c6; //size 0x212, uses SPLASHSC.2DA
	CRecord* pCharacter; //0x42ca, size 0x1520
	CCharGen* pCreateChar; //0x42ce, GUICG
	void* u42d2; //size 0x1424, GUIINV
	void* u42d6; //size 0xeaa, GUIJRNL
	void* u42da; //size 0xb84, GUILOAD
	void* u42de; //size 0x1376, GUIMAP
	void* u42e2; //size 0xe9c, GUIOPT
	CPriestBook* pPriestSpell; //42e6h, size 0x1470, GUIPR
	void* u42ea; //size 0xe8c, GUISAVE
	CStart* pStart; //42eeh, START
	CMageBook* pWizSpell; //42f2h, size 0x14da, GUIMG
			
	void* pWorld; //42f6h, size 0x124c, GUIW
	//DWORD m_nCheatKeys; //14eh
	//Enum eAutoPauseObject; //1108h
	//STRREF strrefAutoPause; //110ch
	//DWORD nAutoPauseOwnerColor; //1110h, color skin off Cre
	//STRREF strrefAutoPauseOwnerName ; //1114h, long name

	CStore* pStore; //42fah, size 0x148a, GUISTORE
	void* u42fe; //size 0x1384, pMultiplayer, GUIMP
	void* u4302; //size 0xeb0, GUICONN
	void* u4306; //size 0x1a44, GUIWMAP
	void* pChapter; //430ah, size 0x70a, GUICHAP
	void* pMovies; //430eh, size 0x7a4, GUIMOVIE
	CTlkTbl TlkTbl; //4312h
			
	struct CGUIMain { //Size 19E8h
	//Constructor: 0x4659F0
		DWORD u0;
		DWORD u4;
		DWORD u8;
		DWORD uc;
		DWORD u10;
		DWORD u14;
		DWORD u18;
		DWORD u1c;
		DWORD u20;
		DWORD u24;
		DWORD u28;
		CVidMosaic u2c[4]; //for STON##L, R, T, B
		CVidMosaic u2ec; //GPROGBAR
		CVidMosaic u39c; //GTRSK05
		CVidFont u44c; //STONSML
		CVidFont u948; //INITIALS
		CVidFont ue44; //TOOLFONT
		CVidMosaic u1340;
		CVidCell u13f0; //LOADCNTR
		CVidCell u14c6; //LOADBAR
		CVidMosaic u159c; //GTRSPSK
		CVidMosaic u164c; //GTRSPSK2
		CVidMosaic u16fc; //GTRSPBG
		CVidMosaic u17ac; //GTRSPBAR
		CVidMosaic u185c; //GTRSPCAP
		CVidMosaic u190c; //GTRTITLE
#ifdef _DEBUG
		_CCriticalSection u19bc;
#else
		CCriticalSection u19bc;
#endif
		DWORD u19dc;
		DWORD u19e0;
		DWORD u19e4; //5d9ch
	} m_GUIMain; //43b8h

	struct _646726 { //Size D94h
	//Constructor: 0x646726
		DWORD u0;
		DWORD u4;
		CVidMosaic u8[4];
		CVidMosaic u2c8;
		CVidFont u378;
		CVidFont u874;
		DWORD ud70; //6b10h
#ifdef _DEBUG
		_CCriticalSection ud74;
#else
		CCriticalSection ud74;
#endif
	} m_646726; //5da0h

	CMessageHandler BaldurMessageHandler; //6b34h
	CPtrListMessage messages; //6c48h
	WORD u6c64;
	DWORD u6c66;
	DWORD u6c6a;
	STRREF OnWindowClosePrompt; //6c6eh
	BYTE u6c72;
	BYTE u6c73;
	IECString u6c74;
	BYTE u6c78;
	BYTE u6c79;
	BYTE u6c7a;
	BYTE u6c7b;

	struct _u6c7c {
		DWORD u6c7c;
		WORD u6c80;
		WORD u6c82;
		WORD u6c84;
		WORD u6c86;
		WORD u6c88;
		WORD u6c8a;
		IECString u6c8c; //STON##L
		DWORD u6c90;
		DWORD u6c94;
	} m_u6c7c;

	DWORD u6c98;
	WORD u6c9c;
	WORD u6c9e;
	WORD u6ca0;
	WORD u6ca2;
	WORD u6ca4;
	WORD u6ca6;
	IECString u6ca8; //STON##R
	DWORD u6cac;
	DWORD u6cb0;

	DWORD u6cb4;
	WORD u6cb8;
	WORD u6cba;
	WORD u6cbc;
	WORD u6cbe;
	WORD u6cc0;
	WORD u6cc2;
	IECString u6cc4; //STON##T
	DWORD u6cc8;
	DWORD u6ccc;

	DWORD u6cd0;
	WORD u6cd4;
	WORD u6cd6;
	WORD u6cd8;
	WORD u6cda;
	WORD u6cdc;
	WORD u6cde;
	IECString u6ce0; //STON##B
	DWORD u6ce4;
	DWORD u6ce8;

	DWORD u6cec;
	DWORD dropCapitals; //6cf0h
	DWORD u6cf4;
	DWORD u6cf8;
	BOOL m_bDisableMovies; //6cfch
	DWORD u6d00;
	CVidFont u6d04; //NORMAL.BAM
	DWORD u7200;
	BOOL m_bFirstRun; //7204h
	DWORD nInstallType; //7208h
};

extern CBaldurChitin& (CBaldurChitin::*CBaldurChitin_Construct0)(void);

#endif //CHITIN_H