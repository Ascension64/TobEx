#ifndef FILEDLG_H
#define FILEDLG_H

#include "stdafx.h"
#include "resref.h"

//Dlg
struct DlgFileState { //Size 10h
	STRREF strref; //0h
	int nResponseIdx; //4h, first response index
	int nResponses; //8h
	int nTriggerIdx; //ch
};

struct DlgFileResponse { //Size 20h
	unsigned int flags; //0h
	STRREF strref; //4h
	STRREF strrefJournal; //8h
	int nTriggerIdx; //ch
	int nActionIdx; //10h
	ResRef NextDialog; //14h
	int nNextDialogState; //1ch
};

#endif //FILEDLG_H