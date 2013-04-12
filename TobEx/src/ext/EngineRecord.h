#ifndef ENGINERECORD_H
#define ENGINERECORD_H

#include "engrecord.h"

DeclareTrampMemberFunc(void, CScreenRecord, MageBookPanelOnLoad, (CCreatureObject& cre), MageBookPanelOnLoad);
DeclareTrampMemberFunc(void, CScreenRecord, MageBookPanelOnUpdate, (CCreatureObject& cre), MageBookPanelOnUpdate);
DeclareTrampMemberFunc(void, CScreenRecord, UpdateCharacter, (), UpdateCharacter);

class DETOUR_CScreenRecord : public CScreenRecord {
public:
	void DETOUR_MageBookPanelOnLoad(CCreatureObject& cre);
	void DETOUR_MageBookPanelOnUpdate(CCreatureObject& cre);
	void DETOUR_UpdateCharacter();
};

#endif //ENGINERECORD_H
