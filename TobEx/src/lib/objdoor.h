#ifndef OBJDOOR_H
#define OBJDOOR_H

#include "stdafx.h"
#include "objcore.h"
#include "rescore.h"
#include "sndcore.h"

class CDoorObject : public CGameSprite { //Size 544h
//Constructor: 0x4E9A8C
public:
	//AA7478
	int u3d4; //unused?
	ResRef rDoorId; //3d8h
	RECT BoundsOpen; //3e0h
	RECT BoundsClosed; //3f0h
	int nCursorIdx; //400h
	unsigned int dwFlags; //404h
	POINT* pVerticesOutlineOpen; //408h
	short nVerticesOutlineOpen; //40ch
	POINT* pVerticesOutlineClosed; //40eh
	short nVerticesOutlineClosed; //412h

	//refers to search map coordinates
	POINT* pPointsImpededWhenDoorOpen; //414h
	short nPointsImpededWhenDoorOpen; //418h
	POINT* pPointsImpededWhenDoorClosed; //41ah
	short nPointsImpededWhenDoorClosed; //41eh

	POINT ptToOpen; //420h
	POINT ptToClose; //428h
	char script[8]; //430h, doorScript
	struct Object18h {
		int u0;
		ResWed* pRes; //4h, same as Area 1fch
		short u8; //1 = open, 2 = closed
		short ua;
		POSITION* uc; //of owning list CArea::IECPtrList u9ca
		ResRef u10; //doorId
	} u438;
	char szDoorName[32]; //450h
	char szTriggerPointName[32]; //470h
	short u490; //if unk54h in door is 0, then = 20, otherwsie = unk54h
	short u492; //unk56h in door
	ResRef doorOpenSound; //494h
	ResRef doorCloseSound; //49ch
	short trapDetectDifficulty; //4a4h
	short trapDisarmDifficulty; //4a6h
	short isTrapped; //4a8h
	short isTrapDetected; //4aah
	short trapLaunchTargetX; //4ach
	short trapLaunchTargetY; //4aeh
	ResRef keyRequired; //4b0h
	int detectDifficulty; //4b8h
	int lockDifficulty; //4bch
	short u4c0; //set to 0

	//POINT
	int u4c2; //calculation of boundsOpenLeft and boundsOpenRight
	int u4c6; //boundsOpenBottom

	//POINT
	int u4ca; //calculation of boundsClosedLeft and boundsClosedRight
	int u4ce; //boundsClosedBottom

	CSound u4d2;
	STRREF lockPicked; //53ch
	int u540; //set to 0
};

#endif //OBJDOOR_H
