//TobExEE
#ifndef CHITIN_H
#define CHITIN_H

#include "stdafx.h"
#include "engine.h"
#include "engchargen.h"
#include "enginv.h"
#include "engrecord.h"
#include "engpriestbk.h"
#include "engmagebk.h"
#include "engstore.h"
#include "engworld.h"
#include "msgcore.h"
#include "network.h"
#include "rescore.h"
#include "sndcore.h"
#include "vidcore.h"
#include "infcursor.h"
#include "infgame.h"
#include "tlkcore.h"

class CBaldurChitin { //Size 1DB8h
public:
	CBaldurChitin(int argc, char* argv[]);
	CBaldurChitin& Construct(int argc, char* argv[]) { return *this; } //dummy

	CInfGame& GetInfGame();
	CScreenWorld& GetWorld();

	virtual void v0() {}
	virtual void v4() {} 

	//LoadStringA() uID functions
	virtual UINT GetErrorStringIdVideoMode() { return 6; } //v8, Windows video mode not supported, use <ALT-Tab> to switch to Windows
	virtual UINT GetErrorStringIdOpenGL() { return 7; } //vc, Can not open OpenGL DLL.
	virtual UINT GetErrorStringIdDirectDraw() { return 5; } //v10, This program needs to run in Direct Draw Exclusive Mode. Please restart after closing other Direct Draw programs.
	virtual UINT GetErrorStringIdChoosePixelFormat() { return 1; } //v14, ChoosePixelFormat failed.
	virtual UINT GetErrorStringIdSetPixelFormat() { return 2; } //v18, SetPixelFormat failed.
	virtual UINT GetErrorStringIdResolution() { return 9; } //v1c, Can not set game resolution, user must change desktop resolution through Control Panel.
	virtual UINT GetErrorStringIdBitDepth() { return 10; } //v20, Can not set game bit depth, user must change desktop bit depth through Control Panel.
	virtual UINT GetErrorStringId3d() { return 11; } //v24, Can not run 3d when desktop bit depth is less than 16 bit (65535 colors), running 2d instead.
	virtual UINT GetErrorStringId3dFont() { return 12; } //v28, Window's fonts do not work with 3d, running 2d instead.

	virtual void CreateRes(unsigned int nResType) {} //v2c, 0x41CC60
	virtual IECString GetChitinIcon() { return IECString("IDI_BIOWARE"); } //v30
	virtual void v40(IECString* pStr) { pStr->operator =("Baldr"); return; } //v34
	virtual unsigned int GetResTypeId(IECString& sExt) { return 0; } //v38, returns CRES_TYPE ID based on filetype (compares file extension)
	virtual IECString GetResTypeExtension(unsigned int nResTypeId, IECString* ptr) { return IECString(""); } //v3c, returns IECString of filetype with CRES_TYPE ID
	virtual void v40() {} //returns 1CBCh
	virtual void v44() {} //init graphics?
	virtual void v48() {}
	virtual void v4c() {}
	virtual void v50() {}
	virtual void v54() {}
	virtual void v58() {}
	virtual void v5c() {}
	virtual void v60() {}
	virtual void v64() {}
	virtual void v68() {}
	virtual void v6c() {}
	virtual void v70() {}
	virtual void v74() {}
	virtual void v78() {}
	virtual void v7c() {}
	virtual void v80() {}
	virtual void DoExit(unsigned int dwLine, const char* szFile, const char* szReason); //v84
	virtual const char* GetKeyName() { return ".\\Chitin.key"; } //v88
	virtual char GetNumSoundChannels() { return 15; } //v8c
	virtual void v90() {}
	virtual void v94() {} //load video options
	virtual void LoadDefaultFont() {} //v98, STONESML
	virtual void v9c() {} //occurs in DoExit() before DeinitVideo()
	virtual void va0() {}
	virtual short GetGamespyPort() { return 0; } //va4
	virtual short GetMultiplayerPort() { return 0; } //va8
	virtual void vac() {}
	virtual IECString GetGamespyGameName() { return ""; } //vb0, puts "bg2bhaal" into arg
	virtual void vb4() {}
	virtual void vb8() {}
	virtual void InitSongList() {} //bc
	virtual void vc0() {}
	virtual void vc4() {}
	virtual void vc8() {}
	virtual void vcc() {}
	virtual void vd0() {}
	virtual void vd4() {}

	//class CBaldurChitinBase { //Size 13B0h
	int u4; //1 on normal mouse buttons, 2 on swap buttons
	int u8; //2 on normal mouse buttons, 1 on swap buttons
	int uc;
	int u10;
	int u14;
	int u18;
	int u1c;
	int u20;
	int u24;
	int u28;
	int u2c;
	int u30;
	int u34;
	int u38;
	int m_nDoubleClickTime; //3ch
	int m_nMouseDoubleClickWidth; //40h
	int m_nMouseDoubleClickHeight; //44h
	BOOL m_bEngineLoaded; //48h
	BOOL m_bResHandlerThreadLoad; //4ch
	int u50;
	CObList m_lEngines; //54h
	int u70;
	CEngine* m_pStartingEngine; //74h
	int u78;
	int m_sdlTimerId; //7ch, SDL_TimerID
	IECString m_sCmdLine; //80h
	int u84;
	int u88;
	int u8c;
	int u90;
	char u94;
	char u95;
	char p96[2];
	int u98;
	short u9c;
	char p9e[2];
	int m_nScreenPosX; //a0h
	int m_nScreenPosY; //a4h
	BOOL m_bIsHost; //a8h
	BOOL m_bIsClient; //ach
	IECString m_sClientArg; //b0h (+connect"<text>"), name to use as a client
	IECString m_sHostArg; //b4h (+host"<text>")
	IECString m_sNameArg; //b8h (+name"<text>")
	IECString m_sPasswordArg; //bch (+password"<text>")
	BOOL m_bNewGameParam; //c0h (+newgame)
	BOOL m_bLoadGameParam; //c4h (+loadgame)
	IECString sHostnameArg; //c8 (+hostname), for client to connect to
	bool m_bAutoConnect; //cch
	bool m_bHasLocationArg; //cdh (+location)
	char pce[2];
	IECString m_sLocationArg; //d0h (+location"<text>")
	char m_bHasTobArg; //d4h (+tob)
	char pd5[3];
	struct unk1 { //to do with languages
		IECString u0; //en_US
		IECString u4;
	} ud8;
	CSoundMixer** m_ppSoundMixer; //e0h
	int m_nMaxPlayers; //e4h (+maxplayers"<num>")
	unsigned int m_dwSong; //e8h
	__int64 uec; //int128
	__int64 uf4; //int128
	int ufc;
	int u100;
	int u104;
	IECPtrList u108;
	int u124;
	int u128;
	int u12c;
	BOOL m_bUseMirrorFX; //130h
	int u134;
	int u138;
	int u13c;
	int m_nSRCurveRadius; //140h
	int m_nTickCountRef; //144h, stores the GetTickCount() every second
	int u148; //cmp 24, assoc window loop, copied from 1ach when reference passes 1 sec
	int m_nTicksSinceRef; //14ch, stores the number of ticks since the reference count
	int u150;
	int u154; //cmp 15, assoc window loop
	int u158;
	int u15c; //cmp 30, assoc window loop
	BOOL m_bDoubleByteCharacterSupport; //160h
	int m_nBGRA; //164h
	IECString m_sFontName; //168h
	int u16c;
	CResHandler m_ResHandler; //170h
	CVideo* m_pVideo; //2b0h
	CNetwork m_Network; //2b4h (=> -18h)
	int u12c8;
	int u12cc;
	int u12d0;
	int u12d4;
	int u12d8;
	int u12dc;
	CObList m_lGameDirectories; //12e0h, 28h size objects
	int u12fc;
	int u1300;
	int u1304;
	int m_nKeyboardRepeatDelay; //1308h
	int m_nKeyboardRepeatRate; //130ch

	struct CProgressBar { //Size 70h
		int u0; //0FFh
		int u4;
		int u8;
		int uc;
		int m_nActionTarget; //10h
		char u14;
		bool m_bCaptionOn; //15h
		char p16[2];
		STRREF m_sCaption; //18h
		char u1c;
		char u1d;
		char u1e;
		char u1f[6];
		char p25[3];
		int u28[6];
		int u40[6];
		int u58[6];
	} m_ProgressBar; //1310h

	short u1380;
	char p1382[2];
	int u1384;
	int u1388;
	int u138c;
	int u1390;
	IECString m_sFontNormal; //1394h
	IECString m_sFontRealms; //1398h
	IECString m_sFontStoneBig; //139ch
	IECString m_sFontStoneSml; //13a0h
	IECString m_sFontToolFont; //13a4h
	IECString m_sFontFloatTxt; //13a8h
	//}; //end CBaldurChitinBase

	BOOL m_bDisplaySubtitles; //13ach
	BOOL m_bUpperCaseButtons; //13b0h
	BOOL m_bReverseMouseWheelZoom; //13b4h

	//Engine objects
	CInfCursor* m_pCursor; //13b8h
	CInfGame* m_pGame; //13bch
	void* u13c0; //size d0, Initial (first engine)
	void* u13c4; //size 168, 
	void* u13c8; //size 20c, Chapter
	void* u13cc; //size 938, Record
	void* u13d0; //size 8a4, CharGen
	void* u13d4; //size 188, Party
	void* u13d8; //size 834, Inventory
	void* u13dc; //size 77c, Journal
	void* u13e0; //size 1cc, Load
	void* u13e4; //size 784, Map
	void* u13e8; //size 78c, Options
	void* u13ec; //size 854, Priest
	void* u13f0; //size 76c, Save
	void* u13f4; //size 1a0, Start
	void* u13f8; //size 8c0, Mage
	CScreenWorld* m_pWorld; //13fch, size a74
	void* u1400; //size 894, Store
	void* u1404; //size 78c, Multiplayer
	void* u1408; //size 784, Connection
	void* u140c; //size e0c, WorldMap
	void* u1410; //size 1d4
	void* u1414; //size 6f0, Movie
	void* u1418; //size 770, DLC
	void* u141c; //size 76c, Help

	CTlkTbl m_TalkTable; //1420h

	struct CGUIMain { //Size 6FCh
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
		CVidMosaic u2c[6]; //for STON##L, R, T, B, GPROGBAR, GTRSK05
		CVidFont u44c; //STONSML
		CVidFont u470; //INITIALS
		CVidFont u494; //TOOLFONT
		CVidMosaic u4b8;
		CVidCell u568; //LOADCNTR
		CVidCell u62c; //LOADBAR
		int u6f0;
		int u6f4;
		int u6f8;
	} u14a8;

	CRemoteMessageHandler m_RemoteMessageHandler; //1ba4h
	CMessageHandler m_MessageHandler; //1c9ch
	int u1cbc;
	char u1cc0;
	char u1cc1;
	char p1cc2[2];
	IECString u1cc4;
	char u11c8;
	char u1cc9;
	char u1cca;
	char p1ccb;
	char u1ccc[0xa8];
	int u1d74;
	BOOL m_bDropCapitals; //1d78h
	int u1d7c;
	int u1d80;
	int u1d84;
	BOOL m_bFirstRun; //1d88h
	int m_nInstallType; //1d8ch
	BOOL m_bNewGui; //1d90h
	CVidFont u1d94;
};

extern CBaldurChitin* g_pChitin;

#endif //CHITIN_H