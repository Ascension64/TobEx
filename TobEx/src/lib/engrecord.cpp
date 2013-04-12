#include "engrecord.h"

#include "stdafx.h"

DefineLibMemberFunc(void, CScreenRecord, MageBookPanelOnLoad, (CCreatureObject& cre), MageBookPanelOnLoad, MageBookPanelOnLoad, (cre), 0x6E0FE6);
DefineLibMemberFunc(void, CScreenRecord, MageBookPanelOnUpdate, (CCreatureObject& cre), MageBookPanelOnUpdate, MageBookPanelOnUpdate, (cre), 0x6E563F);
DefineLibMemberFunc(void, CScreenRecord, UpdatePanel, (int nPanelIdx, CCreatureObject& cre), UpdatePanel, UpdatePanel, (nPanelIdx, cre), 0x6E93BD);
DefineLibMemberFunc(CPanel&, CScreenRecord, GetTopPanel, (), GetTopPanel, GetTopPanel, (), 0x6E96B3);
DefineLibMemberFunc(void, CScreenRecord, UpdateCharacter, (), UpdateCharacter, UpdateCharacter, (), 0x6E9F57);
