#ifndef DLGCORE_H
#define DLGCORE_H

#include "utils.h"
#include "resref.h"
#include "rescore.h"
#include "scrcore.h"
#include "cstringex.h"

typedef CPtrArray CPtrArrayDlgState; //AA73D0
typedef CPtrArray CPtrArrayDlgResponse; //AA73C4
typedef CPtrArray CPtrArrayDlgStateTrigger; //AA73B8
typedef CPtrArray CPtrArrayDlgResponseTrigger; //AA73AC
typedef CPtrArray CPtrArrayDlgAction; //AA73A0
typedef CPtrArray CPtrArrayCDlgResponse; //AA7388
typedef CPtrArray CPtrArrayCDlgState; //AA7414

struct ResDlgContainer {
//size: 0x10
//constructor: 0x4E2C50
	BOOL bLoaded;
	ResDlg* pRes;
	ResRef name;
};

struct CDlgState {
//size: 0x42
//constructor: see 0x4E4591
//as in code
	CPtrArrayCDlgResponse responses; //0h
	STRREF strref; //14h
	CPtrListTrigger conditions; //18h, Starting Conditions

	//FIX_ME
	DWORD u34;
	DWORD nTriggerIdx; //38h
	DWORD u3c; //inherits from m_nSize from CPtrArray of CGameDialog
	WORD u40;
};

struct CDlgResponse {
//size: 0x76
//constructor: see 0x4E477E
//as in code
	DWORD dwFlags; //0h
	ResRef text; //4h
	ResRef textJournal; //8h
	CPtrListTrigger conditions; //ch
	CPtrList u28;
	DWORD u44;
	DWORD u48;
	ResRef nextDialogFilename; //4ch
	DWORD nNextDialogState; //54h
	DWORD u58;
	DWORD u5c;
	BYTE u60;
	BYTE u61; //pad

	IECString SingleTrigger; //62h, for single response trigger
	BOOL bUseSingleTrigger; //66h

	IECString SingleAction; //6ah, for single actions
	BOOL bUseSingleAction; //6eh

	DWORD u72;
};

struct CGameDialog {
	//Size: 0x64
	//Constructor: 0x4E554E
	ResRef u0;
	CPtrArrayCDlgState u8;
	CPtrArrayCDlgState u1c;
	Enum enum1; //30h
	Enum enum2; //34h
	DWORD u38;
	DWORD u3c;
	DWORD u40;
	DWORD color; //colorMajor of CRE
	IECString name; //longName of CRE
	DWORD u4c; //6
	DWORD u50;
	DWORD m_nStateTriggers; //54h
	DWORD u58;
	DWORD u5c; //from Arg4
	DWORD u60;
};

#endif //DLGCORE_H