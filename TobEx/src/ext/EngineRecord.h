#ifndef ENGINERECORD_H
#define ENGINERECORD_H

#include "engrecord.h"

extern void (CScreenRecord::*Tramp_CScreenRecord_MageBookPanelOnLoad)(CCreatureObject&);
extern void (CScreenRecord::*Tramp_CScreenRecord_MageBookPanelOnUpdate)(CCreatureObject&);
extern void (CScreenRecord::*Tramp_CScreenRecord_UpdateCharacter)();

class DETOUR_CScreenRecord : public CScreenRecord {
public:
	void DETOUR_MageBookPanelOnLoad(CCreatureObject& cre);
	void DETOUR_MageBookPanelOnUpdate(CCreatureObject& cre);
	void DETOUR_UpdateCharacter();
};

#endif //ENGINERECORD_H
