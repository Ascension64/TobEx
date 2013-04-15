//TobExEE
#ifndef INFGAMECORE_H
#define INFGAMECORE_H

#include "infgame.h"

//CRuleTables
DeclareTrampMemberFunc(CRuleTables&, CRuleTables, Construct, (), Construct);
DeclareTrampMemberFunc(void, CRuleTables, Deconstruct, (), Deconstruct);


class DETOUR_CRuleTables : public CRuleTables {
public:
	CRuleTables& DETOUR_Construct();
	void DETOUR_Deconstruct();
};

//CInfGame
DeclareTrampMemberFunc(void, CInfGame, InitGame, (int nUnused, int nUnused2), InitGame);
DeclareTrampMemberFunc(void, CInfGame, SetLoseCutscene, (), SetLoseCutscene);

class DETOUR_CInfGame : public CInfGame {
public:
	void DETOUR_InitGame(int nUnused, int nUnused2);
	void DETOUR_SetLoseCutscene();
};

#endif //INFGAMECORE_H