//TobExEE
#ifndef DLGCORE_H
#define DLGCORE_H

#include "stdafx.h"
#include "rescore.h"
#include "scrcore.h"
#include "vidcore.h"

typedef CPtrArray CPtrArrayDlgState; //AA73D0
typedef CPtrArray CPtrArrayDlgResponse; //AA73C4
typedef CPtrArray CPtrArrayDlgStateTrigger; //AA73B8
typedef CPtrArray CPtrArrayDlgResponseTrigger; //AA73AC
typedef CPtrArray CPtrArrayDlgAction; //AA73A0
typedef CPtrArray CPtrArrayCDlgResponse; //AA7388
typedef CPtrArray CPtrArrayCDlgState; //AA7414

struct ResDlgFile { //Size 10h
	BOOL m_bLoaded; //0h
	ResDlg* m_pRes; //4h
	ResRef m_rName; //8h
};

struct CDlgState { //Size 44h
	CPtrArrayCDlgResponse m_responses; //0h
	STRREF m_strref; //14h
	CTriggerList m_conditions; //18h, Starting Conditions

	ENUM u34;
	int m_nTriggerIdx; //38h
	int m_nStateIdx; //3ch
	short u40;
	char p42[2];
};

struct CDlgNext { //Size Ch, FIX_ME
	ResRef rDlgName; //0h
	int nDlgState; //8h
};

struct CDlgResponse { //Size 78
	CDlgResponse::CDlgResponse();

	unsigned int m_dwFlags; //0h
	STRREF m_strrefText; //4h
	STRREF m_strrefTextJournal; //8h
	CTriggerList m_conditions; //ch
	Response m_response; //28h
	ResRef m_rNextDlgName; //4ch
	int m_nNextDlgState; //54h
	int* u58;
	int u5c;
	char m_nResponseIdx; //60h
	char u61;
	char p62[2];
	IECString m_sTriggerText; //64h, for unencoded trigger text (e.g. dlg)
	BOOL m_bUseTextualTrigger; //68h
	IECString m_sActionText; //6ch, for unencoded action text (e.g. dlg)
	BOOL m_bUseTextualAction; //70h
	BOOL m_bAddedInterrupts; //74h, set to TRUE when SetInterrupts added to head and tail of response actions
};

struct CGameDialog { //Size 64h
	ResRef m_rName; //0h
	CPtrArrayCDlgState m_cprStatesStateOrder; //8h
	CPtrArrayCDlgState m_cprStatesTriggerOder; //1ch
	ENUM m_eGabber; //30h
	ENUM m_eTarget; //34h
	int m_nActiveDlgStateIdx; //38h
	int u3c;
	int m_nUserArg; //40h, contains the dialog choice that the user picked
	ABGR m_rgbCol; //44h, colorMajor of CRE
	IECString m_name; //48h, longName of CRE
	int u4c; //6
	int u50;
	int m_dwFlags; //54h, bits 0, 1, 2: non-pausing dialogue
	BOOL m_bDoNotPlaySound; //58h, skips playing soundset greeting if a valid initial state has STRREF
	int u5c; //from Arg4
	int u60;
};

#endif //DLGCORE_H