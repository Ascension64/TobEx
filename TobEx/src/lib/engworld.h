#ifndef ENGWORLD_H
#define ENGWORLD_H

#include "engine.h"
#include "cstringex.h"
#include "vidcore.h"
#include "uitext.h"

class CWorld : public CEngine { //Size 124Ch
//Constructor: 0x7C3EE0
public:
	//AB5768
	POSITION PrintToConsole(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar);
	POSITION PrintToConsole(IECString& sLeft, IECString& sRight, int nUserArg, bool bResetScrollbar);

	int ufe;
	BOOL m_bInStartTOBArea; //102h, AR4000
	int m_nTicksInStartTOBArea; //106h
	int u10a;
	CRITICAL_SECTION u10e;
	int u126;
	int u12a;
	int u12e;
	int u132;
	int u136;
	int u13a;
	int u13e;
	int u142;
	bool bPaused; //146h
	bool u147; //if 1, makes inventory inactive ;; (during rest, chapter info, or movie)
	char u148;
	char u149; //pad
	int u14a;
	int m_nCheatKeys; //14eh
	short u152;
	int u154;
	int u158;
	int u15c;
	CVidFont u160;
	CVidFont u65c;
	CHotkey keymap[93]; //b58h
	char keybuffer[92]; //e40h
	short ue9c;
	int nActiveBottomPanelIndex; //e9eh
	CUITextArea* pTextAreaCurrent; //ea2h
	CUITextArea* pTextArea2; //ea6h
	CGameDialog dlgNotOwned; //eaah, dlg set up here if neither parties have matching dialog to one being initiated
	CGameDialog* m_dlgCurrent; //f0eh
	POINT ptDlgAreaScreen; //f12h
	ResRef rDlgAreaName; //f1ah
	BOOL bNonPausingDialogue; //f22h
	RECT rDlgGameArea; //f26h
	int uf36;
	char uf3a;
	char uf3b;
	IECString uf3c;
	int uf40;
	int uf44;
	char uf48;
	char uf49; //pad
	struct _uf4a { //Size 174h
	//Constructor: 0x657A76
		char u0;
		char u1; //pad
		short u2;
		short u4;
		short u6;
		int u8;
		int uc;
		int u10;
		int u14;
		short u18;
		ABGR u1a;
		int u1e;

		struct _u22 { //Size 36h
		//Constructor: 0x65BBA5
			int u0;
			short u4;
			RECT u6;
#ifdef _DEBUG
			_CCriticalSection u16;
#else
			CCriticalSection u16;
#endif
		} u22;
		struct _u58 { //Size 38h
		//Constructor: 0x65B11B
			int u0;
			short u4;
			RECT u6;
			short u16;
#ifdef _DEBUG
			_CCriticalSection u18;
#else
			CCriticalSection u18;
#endif
		} u58;

		CSound u90;
		CSound ufa;
		char u164;
		char u165; //pad
		int u166;
		int u16a;
		int u16e;
		char u172;
		char u173; //pad
	} uf4a;

	Enum u10be;
	short u10c2;
	int u10c4;
	Enum u10c8;
	Enum u10cc;
	IECString u10d0;
	int u10d4;
	int u10d8;
	int u10dc;
	Enum u10e0;
	char u10e4;
	char u10e5;
	int u10e6;
	int u10ea;
	int u10ee;
	ResRef u10f2;
	bool bUseNetworkDialog; //10fah
	char u10fb; //pad
	int u10fc;
	ResRef u1100;
	Enum eAutoPauseObject; //1108h
	STRREF strrefAutoPause; //110ch
	int nAutoPauseOwnerColor; //1110h, color skin of Cre
	STRREF strrefAutoPauseOwnerName; //1114h, long name
	int u1118;
	int u111c;
	int u1120;
	int u1124;
	int u1128;
	int u112c;
	int u1130;
	int u1134;
	int u1138;
	int u113c;
	int u1140;
	int u1144;
	int u1148;
	int u114c;
	int u1150;
	int u1154;
	int u1158;
	int nPostDialogLogPanelIndex; //115ch, stored before dialogue starts
	char u1160;
	char u1161;
	char u1162;
	char u1163;
	int u1164;
	int u1168;
	int u116c;
	char u1170;
	char u1171; //pad
	int u1172;
	short u1176;
	char u1178;
	char u1179;
	int u117a;
	int u117e;
	char u1182;
	char u1183; //pad
	int u1184;
	short u1188;
	char u118a;
	char u118b;
	char u118c;
	char u118d; //pad
	int u118e;
	int u1192;
	int u1196;
	IECPtrList u119a; //AB5884, 12h objects (int, Enum, unsigned short, int, int)
	int u11b6;
	char u11ba;
	char u11bb;
	char u11bc;
	char u11bd;
	int u11be;
	int u11c2;
	int u11c6;
	short u11ca;
	IECString u11cc;
	IECString u11d0;
	int u11d4;
	int u11d8;
	Enum u11dc;
	BOOL u11e0; //bInDialogueMode?
	char u11e4;
	char u11e5; //pad
	int u11e6;
	RECT u11ea;
	int u11fa;
	int u11fe;
	int u1202;
	int u1206;
	char u120a;
	char u120b; //pad
	CEnumList u120c;
	int u1228;
	int u122c;
	int u1230;
	int u1234;
	int u1238;
	int u123c;
	int u1240;
	int u1244;
	int u1248;
};

extern POSITION (CWorld::*CWorld_PrintToConsole_6)(IECString&, IECString&, ABGR, ABGR, int, bool);
extern POSITION (CWorld::*CWorld_PrintToConsole_4)(IECString&, IECString&, int, bool);

#endif //ENGWORLD_H