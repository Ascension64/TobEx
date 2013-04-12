#ifndef OBJCONT_H
#define OBJCONT_H

#include "objcore.h"

class CContainerObject : public CGameSprite { //Size 712h
public:
	//AA71B0
	virtual ~CContainerObject() {} //v0

	int u3d4; //3d4h
	RECT rectBounds; //3d8h
	CPoint* ptVertexArray; //3e8h (of size 8h elements)
	short wNumVertices; //3ech
	IECPtrList m_items; //3eeh
	short wContainerType; //40ah
	CPoint ptLoc; //40ch
	CVidCell cvcGroundIcons[3]; //414h, for piles
	char nNumGroundIcons; //696h, for piles
	char u697;
	ResRef rTrapScript; //698h
	char szContainerName[32]; //6a0h
	short wLockDifficulty; //6c0h

	//bit0: locked
	//bit3: trap resets
	//bit5: disabled
	int dwFlags; //6c2h
	short wTrapDetectDifficulty; //6c6h
	short wTrapRemovalDifficulty; //6c8h
	short wIsTrapped; //6cah
	short wIsTrapDiscovered; //6cch
	CPoint ptTrapSource; //6ceh
	short u6d6; //56h of area container data
	char u6d8[32]; //58h of area container data
	ResRef rKey; //6f8h
	int u700; //80h of area container data
	short u704;
	STRREF strrefLockpick; //706h
	int u70ah;
	BOOL bHasItems; //70eh
};

#endif //OBJCONT_H
