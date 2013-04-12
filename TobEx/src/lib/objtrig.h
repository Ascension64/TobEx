#ifndef OBJTRIG_H
#define OBJTRIG_H

#include "objcore.h"

//area regions/infopoints
class CTriggerObject : public CGameSprite { //Size 474h
public:
	int u3d4; //3d4h
	short nType; //3d8h
	RECT rectBounds; //3dah
	int nCursorIdx; //3eah
	ResRef rDestArea; //3eeh
	char szDestAreaEntranceName[32]; //3f6h
	unsigned int dwFlags; //416h
	STRREF strrefInfo; //41ah
	CPoint* pVertices; //41eh
	short wVertices; //422h
	short u424;
	ResRef rScript; //426h
	char szTriggerName[32]; //42eh
	short wTrapDetectDifficulty; //44eh
	short wTrapRemovalDifficulty; //450h
	short wIsTrapped; //452h
	short wIsDetected; //454h
	CPoint ptTrap; //456h
	ResRef rKey; //45eh
	int u466;
	int u46a;
	int u46e;
	short u472;

};

#endif //OBJTRIG_H
