#include "dlgcore.h"

//CDlgResponse
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

DefineLibMemberFunc(CDlgNext&, CDlgResponse, Execute, (CCreatureObject& cre), Execute, Execute, (cre), 0x4E867F);

//CGameDialog
DefineLibMemberFunc(void, CGameDialog, SetUserArgument, (int n), SetUserArgument, SetUserArgument, (n), 0x4E6955);
