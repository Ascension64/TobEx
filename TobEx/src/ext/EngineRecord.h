#ifndef ENGINERECORD_H
#define ENGINERECORD_H

#include "engrecord.h"

class DETOUR_CRecord : public CRecord {
public:
	void DETOUR_MageBookPanelOnLoad(CCreatureObject&);
	void DETOUR_MageBookPanelOnUpdate(CCreatureObject&);
	void DETOUR_UpdateCharacter();
};

#endif //ENGINERECORD_H
