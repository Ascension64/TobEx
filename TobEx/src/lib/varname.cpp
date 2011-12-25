#include "varname.h"

#include "utils.h"

static const char* szEmpty = reinterpret_cast<const char*>(0xB7473C);

void (VarName::*VarName_OpAssign)(IECString) =
	SetFP(static_cast<void (VarName::*)(IECString)>	(&VarName::OpAssign),	0x45FD80);
IECString (VarName::*VarName_ToCString)() =
	SetFP(static_cast<IECString (VarName::*)()>		(&VarName::ToCString),	0x54DE90);

VarName::VarName() {
	strncpy_s(buf, 32, szEmpty, 32);
}

void VarName::operator=(IECString s)	{ return (this->*VarName_OpAssign)(s); }
IECString VarName::ToCString()			{ return (this->*VarName_ToCString)(); }
