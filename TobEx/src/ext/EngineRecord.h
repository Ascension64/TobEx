#ifndef ENGINERECORD_H
#define ENGINERECORD_H

#include "engrecord.h"

extern void (CRecord::*Tramp_CRecord_MageBookPanelOnLoad)(CCreatureObject&);
extern void (CRecord::*Tramp_CRecord_MageBookPanelOnUpdate)(CCreatureObject&);
extern void (CRecord::*Tramp_CRecord_UpdateCharacter)(void);

class DETOUR_CRecord : public CRecord {
public:
	void DETOUR_MageBookPanelOnLoad(CCreatureObject&);
	void DETOUR_MageBookPanelOnUpdate(CCreatureObject&);
	void DETOUR_UpdateCharacter();
};

#endif //ENGINERECORD_H
