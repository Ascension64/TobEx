#ifndef OBJSPAWN_H
#define OBJSPAWN_H

#include "objcore.h"
#include "pathfind.h"

//area spawn points (corresponds exactly to ARE entry)
class CSpawningObject : public CGameObject { //Size 12Eh
public:
	//AAAA8C
	char name[32]; //42h
	short x; //62h
	short y; //64h
	ResRef rSpawnTypes[10]; //66h
	short wSpawnTypes; //b6h, how many ResRefs
	short nBaseNumber; //b8h
	short nSpawnDelay; //bah (seconds)

	//bit0: SPAWNFLAG_DISABLE?
	//bit1: SPAWNFLAG_ONCE_AND_FINITE
	//bit2: SPAWNFLAG_TEMP_DISABLE
	short wFlags; //bch

	int ube; //beh
	short nMaxMvtDistance; //c2h, as Actor3C
	short nMaxMvtDistanceToObject; //c4h, as Actor3E
	short nMaxNumSpawns; //c6h
	short nEnabled; //c8h
	int nSchedule; //cah
	short nProbDay; //ceh
	short nProbNight; //d0h
	int ud2[14]; //d2h

	TerrainTable tt; //10ah
	TerrainTable tt2; //11ah
	int nSpawnTimer; //12ah, ? countdown until spawn is ready
};

#endif //OBJSPAWN_H
