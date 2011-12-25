#include "dlgcore.h"

CDlgNext& (CDlgResponse::*CDlgResponse_Execute)(CCreatureObject&) =
	SetFP(static_cast<CDlgNext& (CDlgResponse::*)(CCreatureObject&)>	(&CDlgResponse::Execute),	0x4E867F);

CDlgNext& CDlgResponse::Execute(CCreatureObject& cre)	{ return (this->*CDlgResponse_Execute)(cre); }

//CGameDialog
void (CGameDialog::*CGameDialog_SetUserArgument)(int) =
	SetFP(static_cast<void (CGameDialog::*)(int)>	(&CGameDialog::SetUserArgument),	0x4E6955);

void CGameDialog::SetUserArgument(int n)	{ return (this->*CGameDialog_SetUserArgument)(n); }
