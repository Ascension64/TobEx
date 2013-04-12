//TobExEE
#ifndef OBJTRIG_H
#define OBJTRIG_H

#include "objcore.h"

//area regions/infopoints
class CTriggerObject : public CGameSprite { //Size 434h
public:
	int u390;
	short m_nType; //394h
	char p396[2];
	RECT m_rectBounds; //398h
	int m_nCursorIdx; //3a8h
	char m_szDestArea[8];; //3ach
	SCRIPTNAME m_szDestAreaEntranceName; //3b4h
	unsigned int m_dwFlags; //3d4h
	STRREF m_strrefInfo; //3d8h
	CPoint* m_pVertices; //3dch
	short m_wVertices; //3e0h
	short u3e2;
	char m_szScript[8]; //3e4h
	SCRIPTNAME m_szTriggerName; //3ech
	short m_wTrapDetectDifficulty; //40ch
	short m_wTrapRemovalDifficulty; //40eh
	short m_wIsTrapped; //410h
	short m_wIsDetected; //412h
	CPoint m_ptTrap; //414h
	ResRef m_rKey; //41ch
	int u424;
	int u428;
	int u42c;
	short u430;
	char p432[2];
};

#endif //OBJTRIG_H
