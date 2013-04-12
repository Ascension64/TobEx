//TobExEE
#ifndef OBJDOOR_H
#define OBJDOOR_H

#include "stdafx.h"
#include "objcore.h"
#include "rescore.h"
#include "sndcore.h"

class CDoorObject : public CGameSprite { //Size 4B8h
public:
	int u390; //unused?
	ResRef m_rDoorId; //394h
	RECT m_rectBoundsOpen; //39ch
	RECT m_rectBoundsClosed; //3ach
	int m_nCursorIdx; //3bch
	unsigned int m_dwFlags; //3c0h
	CPoint* m_pVerticesOutlineOpen; //3c4h
	short m_nVerticesOutlineOpen; //3c8h
	char p3ca[2];
	CPoint* m_pVerticesOutlineClosed; //3cch
	short m_nVerticesOutlineClosed; //3d0h
	char p3d2[2];

	//refers to search map coordinates
	CPoint* m_pPointsImpededWhenDoorOpen; //3d4h
	short m_nPointsImpededWhenDoorOpen; //3d8h
	char p3da[2];
	CPoint* m_pPointsImpededWhenDoorClosed; //3dch
	short m_nPointsImpededWhenDoorClosed; //3e0h
	char p3e2[2];

	CPoint m_ptToOpen; //3e4h
	CPoint m_ptToClose; //3ech
	char m_szScript[8]; //3f4h, doorScript
	struct Object18h {
		int u0;
		ResWed* m_pRes; //4h, same as Area 1fch
		short u8; //1 = open, 2 = closed
		short ua;
		POSITION* uc; //of owning list CArea::IECPtrList u9ca
		ResRef u10; //doorId
	} u3fc;
	SCRIPTNAME m_szDoorName; //414h
	SCRIPTNAME m_szTriggerPointName; //434h
	short u454; //if unk54h in door is 0, then = 20, otherwsie = unk54h
	short u456; //unk56h in door
	ResRef m_doorOpenSound; //458h
	ResRef m_doorCloseSound; //460h
	short m_trapDetectDifficulty; //468h
	short m_trapDisarmDifficulty; //46ah
	short m_isTrapped; //46ch
	short m_isTrapDetected; //46eh
	short m_trapLaunchTargetX; //470h
	short m_trapLaunchTargetY; //472h
	ResRef m_keyRequired; //474h
	int m_detectDifficulty; //47ch
	int m_lockDifficulty; //480h
	short u484; //set to 0
	char p486[2];
	CPoint u488; //[calculation of boundsOpenLeft and boundsOpenRight . boundsOpenBottom]
	CPoint u490; //[ calculation of boundsClosedLeft and boundsClosedRight . boundsClosedBottom]
	CSoundWrapper u498;
	STRREF m_lockPicked; //4b0h
	int u4b4; //set to 0
};

#endif //OBJDOOR_H
