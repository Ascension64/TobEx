//TobExEE
#ifndef OBJSPAWN_H
#define OBJSPAWN_H

#include "objcore.h"
#include "pathfind.h"

class CSpawningObject : public CGameObject { //Size 134h
public:
	AreFileRandomMonsterSpawningPoint m_spawn; //48h
	TerrainTable m_tt; //110h
	TerrainTable m_tt2; //120h
	int m_nSpawnTimer; //130h, ? countdown until spawn is ready
};

#endif //OBJSPAWN_H
