//TobExEE
#ifndef INFGAMECORE_H
#define INFGAMECORE_H

#include "infgame.h"

//CInfGame
DeclareTrampMemberFunc(void, CInfGame, SetLoseCutscene, (), SetLoseCutscene);

class DETOUR_CInfGame : public CInfGame {
public:
	void DETOUR_SetLoseCutscene();
};

#endif //INFGAMECORE_H