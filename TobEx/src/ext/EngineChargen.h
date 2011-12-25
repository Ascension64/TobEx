#ifndef ENGINECHARGEN_H
#define ENGINECHARGEN_H

#include "engchargen.h"

class DETOUR_CCharGen : public CCharGen {
public:
	void DETOUR_KitPanelOnLoad(CPanel&, CCreatureObject&);
	void DETOUR_MageBookPanelOnLoad(CPanel&, CCreatureObject&);
	void DETOUR_KitPanelOnUpdate(CPanel&, CCreatureObject&);
	void DETOUR_MageBookPanelOnUpdate(CPanel&, CCreatureObject&);
	void DETOUR_InitSoundset(CCreatureObject&);
};

#endif //ENGINECHARGEN_H