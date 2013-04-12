//TobExEE
#ifndef OBJCONT_H
#define OBJCONT_H

#include "objcore.h"

class CContainerObject : public CGameSprite { //Size 6A0h
public:
	int u390;
	RECT m_rectBounds; //394h
	CPoint* m_ptVertexArray; //3a4h (of size 8h elements)
	short m_wNumVertices; //3a8h
	char p3aa[2];
	IECPtrList m_items; //3ach
	short m_wContainerType; //3c8h
	char p3ca[2];
	CPoint m_ptLoc; //3cch
	CVidCell m_vidGroundIcons[3]; //3d4h, for piles
	char m_nNumGroundIcons; //620h, for piles
	char u621;
	ResRef m_rTrapScript; //622h
	SCRIPTNAME m_szContainerName; //62ah
	short m_wLockDifficulty; //64ah

	//bit0: locked
	//bit3: trap resets
	//bit5: disabled
	int m_dwFlags; //64ch
	short m_wTrapDetectDifficulty; //650h
	short m_wTrapRemovalDifficulty; //652h
	short m_wIsTrapped; //654h
	short m_wIsTrapDiscovered; //656h
	CPoint m_ptTrapSource; //658h
	short m_wTriggerRange; //660h, 56h of area container data
	SCRIPTNAME m_szOwnedBy; //662h, 58h of area container data
	ResRef m_rKey; //682h
	int u68a; //80h of area container data
	short u68e;
	STRREF m_strrefLockpick; //690h
	int u694;
	BOOL m_bHasItems; //698h
	int u69c;
};

#endif //OBJCONT_H
