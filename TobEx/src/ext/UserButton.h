#ifndef USERBUTTON_H
#define USERBUTTON_H

#include "uibutton.h"

class DETOUR_CUICheckButtonChargenKit : public CUICheckButtonChargenKit {
public:
	DWORD DETOUR_GetKitId(Object&);
	STRREF DETOUR_GetKitHelpText(Object&);
};

#endif //USERBUTTON_H