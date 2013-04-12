#ifndef USERBUTTON_H
#define USERBUTTON_H

#include "uibutton.h"

DeclareTrampMemberFunc(unsigned int, CUICheckButtonChargenKit, GetKitId, (Object& o), GetKitId);
DeclareTrampMemberFunc(STRREF, CUICheckButtonChargenKit, GetKitHelpText, (Object& o), GetKitHelpText);

class DETOUR_CUICheckButtonChargenKit : public CUICheckButtonChargenKit {
public:
	unsigned int DETOUR_GetKitId(Object& o);
	STRREF DETOUR_GetKitHelpText(Object& o);
};

#endif //USERBUTTON_H