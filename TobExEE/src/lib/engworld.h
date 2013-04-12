//TobExEE
#ifndef ENGWORLD_H
#define ENGWORLD_H

#include "engine.h"
#include "cstringex.h"
#include "vidcore.h"
#include "uitext.h"

class CScreenWorld : public CEngine { //Size A74h
public:
	POSITION PrintToConsole(IECString& sLeft, IECString& sRight, ABGR colLeft, ABGR colRight, int nUserArg, bool bResetScrollbar);
	POSITION PrintToConsole(IECString& sLeft, IECString& sRight, int nUserArg, bool bResetScrollbar);

	int ud0;
	BOOL m_bInStartTOBArea; //d4h, AR4000
	int m_nTicksInStartTOBArea; //d8h
	int udc;
	int ue0;
	int ue4;
	int ue8;
	int uec;
	int uf0;
	int uf4;
	int uf8;
	int ufc;
	bool bPaused; //100h
	bool u101; //if 1, makes inventory inactive ;; (during rest, chapter info, or movie)
	char u102;
	char p103;
	int u104;
	int m_nCheatKeys; //108h
	short u10c;
	char p10e[2];
	int u110;
	int u114;
	int u118;
	CVidFont u11c;
	CVidFont u140;
	CHotkey keymap[96]; //164h
	int keybuffer[96]; //5e4h
	int nActiveBottomPanelIndex; //764h
	CUITextArea* pTextAreaCurrent; //768h
	CUITextArea* pTextArea2; //76ch
	CGameDialog dlgNotOwned; //770h, dlg set up here if neither parties have matching dialog to one being initiated
	CGameDialog* m_dlgCurrent; //7d4h
	CPoint ptDlgAreaScreen; //7d8h
	ResRef rDlgAreaName; //7e0h
	BOOL bNonPausingDialogue; //7e8h
	RECT rDlgGameArea; //7ech
	int u7fc;
	char u800;
	bool m_bChatBarState; //801h
	char p802[2];
	IECString u804;
	int u808;
	int u80c;
	char u810;
	char p811[3];

	struct unk1 { //Size 9Ch
		char u0;
		char p1;
		short u2;
		short u4;
		short u6;
		int u8;
		int uc;
		int u10;
		int u14;
		short u18;
		char p1a[2];
		ABGR u1c;
		int u20;

		struct unk2 { //Size 18h
			int u0;
			short u4;
			char p6[2];
			RECT u8;
		} u24;

		struct unk3 { //Size 1Ch
			int u0;
			short u4;
			char p6[2];
			RECT u8;
			short u18;
			char p1a[2];
		} u3c;

		CSoundWrapper u58;
		CSoundWrapper u70;

		char u88;
		char p89[3];
		int u8c;
		int u90;
		int u94;
		char u98;
		char p99[3];
	} u814;

	ENUM u8b0;
	short u8b4;
	char p8b6[2];
	int u8b8;
	ENUM u8bc;
	ENUM u8c0;
	IECString u8c4;
	int u8c8;
	int u8cc;
	int u8d0;
	ENUM u8d4;
	char u8d8;
	char u8d9;
	char p8da[2];
	int u8dc;
	int u8e0;
	int u8e4;
	ResRef u8e8;
	bool m_bUseNetworkDialog; //8f0h
	bool u8f1; //some overriding button active state setting
	char p8f2[2];
	int u8f4;
	ResRef u8f8;
	ENUM eAutoPauseObject; //900h
	STRREF strrefAutoPause; //904h
	int nAutoPauseOwnerColor; //908h, color skin of Cre
	STRREF strrefAutoPauseOwnerName; //90ch, long name
	int u910;
	int u914;
	int u918;
	int u91c;
	int u920;
	int u924;
	int u928;
	int u92c;
	int u930;
	int u934;
	int u938;
	int u93c;
	int u940;
	int u944;
	int u948;
	int u94c;
	int u950;
	int nPostDialogLogPanelIndex; //954h, stored before dialogue starts
	char u958;
	char u959;
	char u95a;
	char u95b;
	int u95c;
	int u960;
	int u964;
	char u968;
	char p969[3];
	int u96c;
	char u970;
	char u971;
	char p972[2];
	int u974;
	short u978;
	char u97a;
	char p97b;
	int u97c;
	int u980;
	char p984;
	char u985;
	char u986;
	char p987;
	int u988;
	int u98c;
	int u990;
	IECPtrList u994; //AB5884, 12h objects (int, ENUM, unsigned short, int, int)
	int u9b0;
	char u9b4;
	char u9b5;
	char u9b6;
	char u9b7;
	int u9b8;
	int u9bc;
	int u9c0;
	short u9c4;
	char p9c6[2];
	IECString u9c8;
	IECString u9cc;
	int u9d0;
	int u9d4;
	ENUM u9d8;
	BOOL u9dc; //bInDialogueMode?
	char u9e0;
	char p9e1[3];
	int u9e4;
	RECT u9e8;
	int u9f8;
	int u9fc;
	int ua00;
	int ua04;
	bool ua08; //set to whether or not MP settings checked when starting store
	char pa09[3];
	CEnumList ua0c;
	int ua28;
	int ua2c;
	int ua30;
	int ua34;
	int ua38;
	int ua3c;
	int ua40;
	int ua44;
	int ua48;

	char ua4c[12];
	char ua58[12];
	char ua64[12];
	int ua70;
};

#endif //ENGWORLD_H