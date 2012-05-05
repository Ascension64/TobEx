#include "dlgcore.h"

//CDlgResponse
CDlgNext& (CDlgResponse::*CDlgResponse_Execute)(CCreatureObject&) =
	SetFP(static_cast<CDlgNext& (CDlgResponse::*)(CCreatureObject&)>	(&CDlgResponse::Execute),	0x4E867F);

CDlgResponse::CDlgResponse() {
	dwFlags = 0;
	rText = -1;
	rTextJournal = -1;
	nNextDlgState = -1;
	u58 = NULL;
	u5c = 0;
	nResponseIdx = -1;
	char u61;
	bUseTextualTrigger = TRUE;
	bUseTextualAction = TRUE;
	bAddedInterrupts = FALSE;
}

CDlgNext& CDlgResponse::Execute(CCreatureObject& cre)	{ return (this->*CDlgResponse_Execute)(cre); }

//CGameDialog
void (CGameDialog::*CGameDialog_SetUserArgument)(int) =
	SetFP(static_cast<void (CGameDialog::*)(int)>	(&CGameDialog::SetUserArgument),	0x4E6955);

void CGameDialog::SetUserArgument(int n)	{ return (this->*CGameDialog_SetUserArgument)(n); }
