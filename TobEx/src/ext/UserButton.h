#ifndef USERBUTTON_H
#define USERBUTTON_H

#include "uibutton.h"

extern DWORD (CUICheckButtonChargenKit::*Tramp_CUICheckButtonChargenKit_GetKitId)(Object&);
extern STRREF (CUICheckButtonChargenKit::*Tramp_CUICheckButtonChargenKit_GetKitHelpText)(Object&);

class DETOUR_CUICheckButtonChargenKit : public CUICheckButtonChargenKit {
public:
	DWORD DETOUR_GetKitId(Object&);
	STRREF DETOUR_GetKitHelpText(Object&);
};

#endif //USERBUTTON_H