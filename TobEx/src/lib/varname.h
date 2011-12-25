#ifndef VARNAME_H
#define VARNAME_H

#include "win32def.h"

#include "cstringex.h"

class VarName { //Size 20h
public:
	VarName();
	
	void operator=(IECString s);
	void OpAssign(IECString s) {} //dummy

	IECString ToCString();
protected:
	char buf[32];
};

extern void (VarName::*VarName_OpAssign)(IECString);
extern IECString (VarName::*VarName_ToCString)();

#endif //VARNAME_H