#ifndef USERBUTTON_H
#define USERBUTTON_H

#include "uibutton.h"

extern unsigned int (CUICheckButtonChargenKit::*Tramp_CUICheckButtonChargenKit_GetKitId)(Object&);
extern STRREF (CUICheckButtonChargenKit::*Tramp_CUICheckButtonChargenKit_GetKitHelpText)(Object&);

class DETOUR_CUICheckButtonChargenKit : public CUICheckButtonChargenKit {
public:
	unsigned int DETOUR_GetKitId(Object& o);
	STRREF DETOUR_GetKitHelpText(Object& o);
};

#endif //USERBUTTON_H