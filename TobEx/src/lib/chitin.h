#ifndef CHITIN_H
#define CHITIN_H

#include "stdafx.h"
#include "engine.h"
#include "engchargen.h"
#include "enginv.h"
#include "engrecord.h"
#include "engpriestbk.h"
#include "engmagebk.h"
#include "engworld.h"
#include "msgcore.h"
#include "network.h"
#include "rescore.h"
#include "sndcore.h"
#include "vidcore.h"
#include "infcursor.h"
#include "infgame.h"
#include "tlkcore.h"

class CBaldurChitin;

extern CBaldurChitin* g_pChitin;

class CBaldurChitin { //Size 720Ch
//Constructor: 0x432108
public:
	CBaldurChitin();
	CBaldurChitin& Construct() { return *this; } //dummy

	//AA5F9C
	virtual void v0() {}
	virtual void v4(HINSTANCE hInstance, int nShowCmd) {} //0x9A6746, Called from ChitinMain(), calls v3c, v4c, vbc

	//LoadStringA() uID functions
	//3 = This version will only run on English language operating systems!
	//4 = This version will only run in Canada and the United States!
	//8 = This version of the Baldur Key file has expired please contact Press@bioware.com for a valid file.
	//13 = Key File Expires June 15
	virtual UINT GetStringVideoMode() { return 6; } //v8, Windows video mode not supported, use <ALT-Tab> to switch to Windows
	virtual UINT GetStringOpenGL() { return 7; } //vc, Can not open OpenGL DLL.
	virtual UINT GetStringDirectDraw() { return 5; } //v10, This program needs to run in Direct Draw Exclusive Mode. Please restart after closing other Direct Draw programs.
	virtual UINT GetStringChoosePixelFormat() { return 1; } //v14, ChoosePixelFormat failed.
	virtual UINT GetStringSetPixelFormat() { return 2; } //v18, SetPixelFormat failed.
	virtual UINT GetStringResolution() { return 9; } //v1c, Can not set game resolution, user must change desktop resolution through Control Panel.
	virtual UINT GetStringBitDepth() { return 10; } //v20, Can not set game bit depth, user must change desktop bit depth through Control Panel.
	virtual UINT GetString3D() { return 11; } //v24, Can not run 3d when desktop bit depth is less than 16 bit (65535 colors), running 2d instead.
	virtual UINT GetString3DFont() { return 12; } //v28, Window's fonts do not work with 3d, running 2d instead.
	virtual void v2c() {} //0x4362A1, ProcMain for multiplayer loop (NetworkProcMain)
	virtual void v30() {} //0x436359, ProcMain for CResHandler loop (ResHandlerProcMain)
	virtual void v34() {} //0x4363A6, ProcMain for timer loop - calls v8c (WindowProcMain)
	virtual void CreateResObject(int fileType) {} //v38, 0x434D1C
	virtual IECString GetChitinIcon() { return IECString("IDI_BIOWARE"); } //v3c, 0x43C8D0
	virtual void v40(IECString* pStr) { pStr->operator =("Baldr"); return; } //Baldr (0xB77238)
	virtual int GetResTypeId(IECString* pStr) { return 0; } //v44, returns CRES_TYPE ID based on filetype (compares file extension)
	virtual IECString GetFileExtension(unsigned int nResTypeId, IECString* ptr) { return IECString(""); } //v48, returns IECString of filetype with CRES_TYPE ID
	virtual void v4c() {} //0x9A68CB, CreateChitinWindow(), calls v54
	virtual void v50() {} //returns Obj+6C66h
	virtual void v54(HWND hWnd) {} //0x436C0B, ? InitDirectDraw InitDirectSound, calls vb4, vf4
	virtual void v58() {} //?
	virtual void Set5D9C(int dw) {}
	virtual void v60() {} //?
	virtual void v64() {} //?
	virtual void Set6B10(int dw) {}
	virtual void v6c() {} //some multiplayer stuff? Uses GameSpy and RogerWilco
	virtual void SetCloseNetworkSession() {} //70h, sets 6C44h to true
	virtual void v74() {} //uses RogerWilco
	virtual void v78() {} //?
	virtual void v7c() {} //multiplayer thing
	virtual void v80() {} //OnMultiplayerLeave
	virtual void v84() {} //?
	virtual void v88() {} //DebugBaldurMessage(dwDebugLevel, char*, pnLength)
	virtual void v8c() {} //0x43544C ? WindowUpdateProc(5 ints) - Executes all messages
	virtual void v90() {} //WriteWindowSettings
	virtual void v94() {} //0x9A5C17, LoadEngine(pEngine)
	virtual void v98() {} //ShowErrorAndQuit
	virtual const char* GetIniName() { return ".\\Baldur.ini"; } //v9c
	virtual const char* GetKeyName() { return ".\\Chitin.key"; } //va0
	virtual const char* GetLogName() { return ".\\Baldur.log"; } //va4
	virtual const char* GetErrName() { return ".\\Baldur.err"; } //va8
	virtual void vac() {} //void CBaldurChitin::WriteScreenDepth(nBitDepth)
	virtual void vb0() {} //GetScreenDepthSettings
	virtual char GetNumSoundChannels() { return 15; } //vb4
	virtual void vb8() {} //0x43CB40, virtual address @ AA6054 so you can continue later
	virtual void vbc() {} //0x436FF2, load video options
	virtual void vc0() {} //0x43754E, load normal.bam into 6d04

	virtual void vc8() {} //0x43CB80, SetSoundChannelVolumes

	//virtual void vd4() {} //0x43CC20, sets global B14F78 to a char
	//virtual void ve8() {} //0x43CAD0, GetGamespyGameName(IECString*), puts "bg2bhaal" into arg
	//virtual void vf4() {} //0x438C0A, InitSongListAndSoundChannels
	virtual void vf8() {} //0x43CA50, DoesSupportEAX(nChannel)
	virtual void vfc() {} //0x43CA90, GetEnvironmentalAudioState()

	//virtual void v104() {} //0x43CC40, bool GetSoundEnvironmentInfo(IECString* sAreaName, pdwEnv, pfDamping, pfDecay, pfVolume, pfReverb)
	//virtual void v108() {}
	//etc.

	int u4; //1 on normal mouse buttons, 2 on swap buttons
	int u8; //2 on normal mouse buttons, 1 on swap buttons
	int uc;
	int u10;
	int u14;
	int u18; //copy of 3ch
	CWnd* pWnd; //1ch, pointer to 78h
	int u20;
	int u24;
	int u28; //copy of 3ch
	int u2c;
	int u30;
	int u34;
	int u38; //copy of 3ch
	int DoubleClickTime; //3ch
	int nDoubleClkWidth; //40h, GetSystemMetrics(SM_CXDOUBLECLK)
	int nDoubleClkHeight; //44h, GetSystemMetrics(SM_CYDOUBLECLK)
	BOOL m_bEngineLoaded; //48h
	BOOL m_bResHandlerThreadLoad; //4ch
	int u50;
	CObList engines; //0x54
	int u70;
	CEngine* pStartingEngine; //74h, pStartingEngine, 42beh
	CWnd m_CWnd; //78h
	HANDLE hProcess; //b4h, duplicate handle of current process
	HINSTANCE hInstance; //b8h, this instance
	int ubc; //timer event CObject from timeSetEvent()
	int uc0; //timer resolution from timeGetDevCaps()
	CRITICAL_SECTION uc4;
	IECString sCmdLine; //dch
	char bDisableWindow; //e0h, Window Disabled?
	char bFullScreen; //e1h
	char ue2; //copy of e1h
	char ue3;
	int ue4;
	int ue8[4];
	char uf8;
	char uf9;
	int dwPlatformId; //fah, from _OSVERSIONINFO of GetVersionExA()
	short ufe;
	int nScreenWidth; //100h, GetSystemMetrics(SM_CX[FULL]SCREEN)
	int nScreenHeight; //104h, GetSystemMetrics(SM_CY[FULL]SCREEN)
	int nScreenPosX; //108h
	int nScreenPosY; //10ch
	BOOL bIsHost; //110h, (+host"<text>")
	BOOL bIsClient; //114h (+connect"<text>")
	IECString sClientArg; //118h for cmd (+connect"<text>"), name to use as a client
	IECString sHostArg; //11ch for cmd (+host"<text>")
	IECString sNameArg; //120h for cmd (+name"<text>")
	IECString sPasswordArg; //124h for cmd (+password"<text>")
	BOOL bNewGameParam; //128h (+newgame)
	BOOL bLoadGameParam; //u2ch (+loadgame)
	IECString sHostnameArg; //130h (+hostname), for client to connect to
	bool m_bAutoConnect; //134h
	bool bHasLocationArg; //135h (+location)
	IECString sLocationArg; //136h for cmd (+location"<text>")
	bool bHasTobArg; //13ah for cmd (+tob)
	char u13b;
	BOOL m_bDisableBrightest; //13ch - Disable Brighten (if 3d acceleration, never disabled)
	BOOL m_bLimitTransparency; //140h - Force 50% Transparency
	int nMaxPlayers; //144h for cmd (+maxplayers"<num>")
	int dwSong; //148h
	RECT u14c; //current PropertyData for CSoundProperties IKsPropertySet::Set()
	BOOL bInitSound; //15ch
	short u160;
	int u162;
	IECPtrList u166; //AA5C50
	int u182; //SPI_GETWHEELSCROLLLINES
	int u186; //LRESULT of SendMessageA(FindWindowA(MouseZ, MagellanMSWHEEL), RegisterWindowMessageA(MSH_WHEELSUPPORT_MSG), 0, 0)
	int u18a; //UINT MSWHEEL_ROLLMSG WindowMessage CObject
	int m_bFirstFrameOutline; //18eh
	int m_bUseMirrorFX; //192h
	int u196; //UINT QueryCancelAutoPlay WindowMessage CObject
	int u19a;
	char m_bOverConfirmEverything; //19eh
	char m_bAlternateSRCurve; //19fh
	int nSRCurveRadius; //1a0h, SR = spectral recording
	int m_nTickCountRef; //1a4h, stores the GetTickCount() every second
	int u1a8; //cmp 24, assoc window loop, copied from 1ach when reference passes 1 sec
	int m_nTicksSinceRef; //1ach, stores the number of ticks since the reference count
	int u1b0;
	int u1b4; //cmp 15, assoc window loop
	int u1b8;
	int u1bc; //cmp 30, assoc window loop
	BOOL m_bDoubleByteCharSupport; //1c0h
	int u1c4; //copy of 1c0h

	struct CImeUI { //Size 140h
	//Constructor: 0x9A9000
		char u0[0x104];
		int u104;
#ifdef _DEBUG
		_CCriticalSection u108;
#else
		CCriticalSection u108;
#endif
		int u128;	
		int u12c;
		IECString u130;
		IECString u134;
		IECString u138;
		CVidMosaic* u13c; //13ch, uses "IMEUI.MOS"
	} m_CImeUI; //1c8h

	IECString sFontName; //308h
	int u30c;
	BOOL m_b16BitTextures; //310h, if 0 it means 32-bit
	HANDLE m_eventTimer; //314h, HANDLE to BaldurTimeEvent
	CRITICAL_SECTION u318; //for CResHandler::CObList (all of them)
	CRITICAL_SECTION u330; //for CResHandler::pResTemp
	CRITICAL_SECTION u348;
	int u360[6]; //unused
	CRITICAL_SECTION csFileWrite; //378h, used when writing to files
	CRITICAL_SECTION u390;
	BOOL m_bTerminateResHandlerThread; //3a8h
	HANDLE m_hThreadResHandler; //3ach
	BOOL m_bTerminateNetworkThread; //3b0h
	HANDLE m_hThreadNetwork; //3b4h
	HANDLE m_hThreadWindow; //3b8h
	BOOL m_bTerminateWindowThread; //3bch
	CEngine* pEngineActive; //3c0h
	CSoundMixer mixer; //3c4h
	CResHandler ResHandler; //2c9eh
	CVideo cVideo; //2f46h
	CNetwork cNetwork; //30aeh

	struct _9DAAEA { //Size 2Ch
	//Constructor: 0x9DAAEA
		char u0;
		char u1;
		int u2[6]; //unused?
		int u1a;
		int u1e;
		int u22; //unused?
		int u26;
		short u2a; //unused?
	} m_9DAAEA; //3fe8h

	struct _9DA0B0 { //Size 2h
	//Constructor: 0x9DA0B0
		short u0;
	} m_9DA0B0; //4014h

	CRogerWilco m_CRogerWilco; //4016h
	int u4026;
	POINT ptCursor; //402ah
	int nChitinUpdates; //4032h
	BOOL m_bRunningWindowUpdateProc; //4036h
	CObList GameDirectories; //403ah, Contains 0x8 CObjects (vt, dwLoaded, IECString* directoryName) for directories for the game, AB8ED0
	int u4056;
	int u405a;
	int u405e;
	int u4062;
	int nKeyboardDelay; //4066h
	int nKeyboardSpeed; //406ah
#ifdef _DEBUG
	_CCriticalSection u406e;
#else
	CCriticalSection u406e;
#endif

	struct CProgressBar { //Size 6Ch
	//Constructor: 0x99BF5A
		int u0;
		int u4;
		int u8;
		int uc;
		int m_nActionTarget; //10h
		char u14;
		char u15;
		int u16;
		char u1a;
		char u1b;
		char u1c;
		char u1d[6]; //by player
		char u23;
		int u24[6]; //by player
		int u3c[6]; //by player
		int u54[6]; //by player
	} m_ProgressBar; //408eh

	int m_threadID[10]; //40fah
	HANDLE m_hThread[10]; //4122h
	short m_nThreads; //414ah, note CHITIN_MAX_THREADS = 10
	short m_bCheckedWindowThreadPriority; //414ch
	int u414e;
	int u4152;
	int u4156[16]; //init to 1000
	int u4196[16];
	int u41d6[16];
	int u4216[16];
	int u4256[16];
	KeyTableEntry* tempKey; //4296h - used during CResHandler::Demand()
	IECString F_NORMAL; //429ah
	IECString F_REALMS; //429eh
	IECString F_STONEBIG; //42a2h
	IECString F_STONESML; //42a6h
	IECString F_TOOLFONT; //42aah
	IECString F_FLOATTXT; //42aeh
	int nDisplaySubtitles; //42b2h

	CInfCursor* pCursor; //42b6h, size 0x8f6, fonts cursors and tooltips?
	CInfGame* pGame; //42bah

	//21 objects in CHUIObjects IECPtrList in this order
	void* u42be; //size 0xfe, CStartingEngine
	void* pBaldurProjector; //42c2h, size 0x6d0, uses NORMAL.BAM, for movies
	void* u42c6; //size 0x212, uses SPLASHSC.2DA
	CRecord* pCharacter; //42cah, size 0x1520
	CCharGen* pCreateChar; //42ceh, GUICG
	CInventory* pInventory; //42d2h, GUIINV
	void* u42d6; //size 0xeaa, GUIJRNL
	void* u42da; //size 0xb84, GUILOAD
	void* u42de; //size 0x1376, GUIMAP
	void* u42e2; //size 0xe9c, GUIOPT
	CPriestBook* pPriestSpell; //42e6h, size 0x1470, GUIPR
	void* u42ea; //size 0xe8c, GUISAVE
	CStart* pStart; //42eeh, START
	CMageBook* pWizSpell; //42f2h, size 0x14da, GUIMG
	CWorld* pWorld; //42f6h, GUIW
	CStore* pStore; //42fah, size 0x148a, GUISTORE
	void* u42fe; //size 0x1384, pMultiplayer, GUIMP
	void* u4302; //size 0xeb0, GUICONN
	void* u4306; //size 0x1a44, GUIWMAP
	void* pChapter; //430ah, size 0x70a, GUICHAP, 0x138 nDreamIdx, 0x13C rDrmTxtFileName, 0x144 m_pTextList (CStrRefList), 0x148 m_pBmpList, 0x1FE rPower
	void* pMovies; //430eh, size 0x7a4, GUIMOVIE
	CTlkTbl m_TlkTbl; //4312h
			
	struct CGUIMain { //Size 19E8h
	//Constructor: 0x4659F0
		int u0;
		int u4;
		int u8;
		int uc;
		int u10;
		int u14;
		int u18;
		int u1c;
		int u20;
		int u24;
		int u28;
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
		int u19dc;
		int u19e0;
		int u19e4; //5d9ch
	} m_GUIMain; //43b8h

	struct _646726 { //Size D94h
	//Constructor: 0x646726
		int u0;
		int u4;
		CVidMosaic u8[4];
		CVidMosaic u2c8;
		CVidFont u378;
		CVidFont u874;
		int ud70; //6b10h
#ifdef _DEBUG
		_CCriticalSection ud74;
#else
		CCriticalSection ud74;
#endif
	} m_646726; //5da0h

	CMessageHandler BaldurMessageHandler; //6b34h
	CPtrListMessage messages; //6c48h
	int u6c66;
	int u6c6a;
	STRREF OnWindowClosePrompt; //6c6eh
	char u6c72;
	char u6c73;
	IECString u6c74;
	char u6c78;
	char u6c79;
	char u6c7a;
	char u6c7b;

	struct _u6c7c {
		int u6c7c;
		short u6c80;
		short u6c82;
		short u6c84;
		short u6c86;
		short u6c88;
		short u6c8a;
		IECString u6c8c; //STON##L
		int u6c90;
		int u6c94;
	} m_u6c7c;

	int u6c98;
	short u6c9c;
	short u6c9e;
	short u6ca0;
	short u6ca2;
	short u6ca4;
	short u6ca6;
	IECString u6ca8; //STON##R
	int u6cac;
	int u6cb0;

	int u6cb4;
	short u6cb8;
	short u6cba;
	short u6cbc;
	short u6cbe;
	short u6cc0;
	short u6cc2;
	IECString u6cc4; //STON##T
	int u6cc8;
	int u6ccc;

	int u6cd0;
	short u6cd4;
	short u6cd6;
	short u6cd8;
	short u6cda;
	short u6cdc;
	short u6cde;
	IECString u6ce0; //STON##B
	int u6ce4;
	int u6ce8;

	int u6cec;
	int dropCapitals; //6cf0h
	int u6cf4;
	int u6cf8;
	BOOL m_bDisableMovies; //6cfch
	int u6d00;
	CVidFont u6d04; //NORMAL.BAM
	BOOL u7200;
	BOOL m_bFirstRun; //7204h
	int nInstallType; //7208h
};

extern CBaldurChitin& (CBaldurChitin::*CBaldurChitin_Construct)(void);

#endif //CHITIN_H