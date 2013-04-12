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
//constructor: 0x4E2C50
	BOOL bLoaded;
	ResDlg* pRes;
	ResRef name;
};

struct CDlgState { //Size 42h
//constructor: see 0x4E4591
//as in code
	CPtrArrayCDlgResponse responses; //0h
	STRREF strref; //14h
	CTriggerList conditions; //18h, Starting Conditions

	ENUM u34;
	int nTriggerIdx; //38h
	int nStateIdx; //3ch
	short u40;
};

struct CDlgNext { //Size Ch
//constructor: see 0x4E8F42
	ResRef rDlgName; //0h
	int nDlgState; //8h
};

struct CDlgResponse { //Size 76h
//constructor: see 0x4E477E
//as in code
	CDlgResponse::CDlgResponse();

	CDlgNext& Execute(CCreatureObject& cre);

	unsigned int dwFlags; //0h
	STRREF rText; //4h
	STRREF rTextJournal; //8h
	CTriggerList m_conditions; //ch
	Response m_response; //28h
	ResRef rNextDlgName; //4ch
	int nNextDlgState; //54h
	int* u58;
	int u5c;
	char nResponseIdx; //60h
	char u61;
	IECString sTriggerText; //62h, for unencoded trigger text (e.g. dlg)
	BOOL bUseTextualTrigger; //66h
	IECString sActionText; //6ah, for unencoded action text (e.g. dlg)
	BOOL bUseTextualAction; //6eh
	BOOL bAddedInterrupts; //72h, set to TRUE when SetInterrupts added to head and tail of response actions
};

struct CGameDialog { //Size 64h
//Constructor: 0x4E554E
	void SetUserArgument(int n);

	ResRef rName; //0h
	CPtrArrayCDlgState cprStatesStateOrder; //8h
	CPtrArrayCDlgState cprStatesTriggerOder; //1ch
	ENUM eGabber; //30h
	ENUM eTarget; //34h
	int nActiveDlgStateIdx; //38h
	int u3c;
	int nUserArg; //40h, contains the dialog choice that the user picked
	ABGR col; //44h, colorMajor of CRE
	IECString name; //48h, longName of CRE
	int u4c; //6
	int u50;
	int dwFlags; //54h, bits 0, 1, 2: non-pausing dialogue
	BOOL bDoNotPlaySound; //58h, skips playing soundset greeting if a valid initial state has STRREF
	int u5c; //from Arg4
	int u60;
};

#endif //DLGCORE_H