#ifndef DLGCORE_H
#define DLGCORE_H

#include "stdafx.h"
#include "rescore.h"
#include "scrcore.h"

typedef CPtrArray CPtrArrayDlgState; //AA73D0
typedef CPtrArray CPtrArrayDlgResponse; //AA73C4
typedef CPtrArray CPtrArrayDlgStateTrigger; //AA73B8
typedef CPtrArray CPtrArrayDlgResponseTrigger; //AA73AC
typedef CPtrArray CPtrArrayDlgAction; //AA73A0
typedef CPtrArray CPtrArrayCDlgResponse; //AA7388
typedef CPtrArray CPtrArrayCDlgState; //AA7414

struct ResDlgContainer { //Size 10h
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

	//FIX_ME
	int u34;
	int nTriggerIdx; //38h
	int u3c; //inherits from m_nSize from CPtrArray of CGameDialog
	short u40;
};

struct CDlgResponse { //Size 76h
//constructor: see 0x4E477E
//as in code
	unsigned int dwFlags; //0h
	ResRef text; //4h
	ResRef textJournal; //8h
	CTriggerList conditions; //ch
	IECPtrList u28;
	int u44;
	int u48;
	ResRef nextDialogFilename; //4ch
	int nNextDialogState; //54h
	int u58;
	int u5c;
	char u60;
	char u61; //pad

	IECString SingleTrigger; //62h, for single response trigger
	BOOL bUseSingleTrigger; //66h

	IECString SingleAction; //6ah, for single actions
	BOOL bUseSingleAction; //6eh

	int u72;
};

struct CGameDialog { //Size 64h
//Constructor: 0x4E554E
	ResRef u0;
	CPtrArrayCDlgState u8;
	CPtrArrayCDlgState u1c;
	Enum enum1; //30h
	Enum enum2; //34h
	int u38;
	int u3c;
	int u40;
	int color; //colorMajor of CRE
	IECString name; //longName of CRE
	int u4c; //6
	int u50;
	int m_nStateTriggers; //54h
	int u58;
	int u5c; //from Arg4
	int u60;
};

#endif //DLGCORE_H