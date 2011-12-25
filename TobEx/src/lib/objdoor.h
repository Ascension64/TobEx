#ifndef OBJDOOR_H
#define OBJDOOR_H

#include "utils.h"
#include "objcore.h"
#include "resref.h"
#include "rescore.h"
#include "sndcore.h"

class CDoorObject : public CGameSprite {
//Size: 0x544
//Constructor: 0x4E9A8C
//vtable: 0xAA7478
public:
	virtual void v0() {} //~CDoorObject()
	virtual void v4() {}
	virtual void v8() {}
	virtual void vc() {}
	virtual Object& GetObject() { return o; } //return a value

	DWORD u3d4; //unused?
	ResRef doorId; //3d8h
	RECT BoundsOpen; //3e0h
	RECT BoundsClosed; //3f0h
	DWORD nCursorIdx; //400h
	DWORD dwFlags; //404h
	POINT* pVerticesOutlineOpen; //408h
	WORD nVerticesOutlineOpen; //40ch
	POINT* pVerticesOutlineClosed; //40eh
	WORD nVerticesOutlineClosed; //412h

	//refers to search map coordinates
	POINT* pPointsImpededWhenDoorOpen; //414h
	WORD nPointsImpededWhenDoorOpen; //418h
	POINT* pPointsImpededWhenDoorClosed; //41ah
	WORD nPointsImpededWhenDoorClosed; //41eh

	POINT ptToOpen; //420h
	POINT ptToCLose; //428h
	char script[8]; //430h, doorScript
	struct Object18h {
		DWORD u0;
		ResWed* pRes; //4h, same as Area 1fch
		WORD u8; //1 = open, 2 = closed
		WORD ua;
		POSITION* uc; //of owning list CArea::CPtrList u9ca
		ResRef u10; //doorId
	} u438;
	char doorName[32]; //450h
	char triggerPointName[32]; //470h
	WORD u490; //if unk54h in door is 0, then = 20, otherwsie = unk54h
	WORD u492; //unk56h in door
	ResRef doorOpenSound; //494h
	ResRef doorCloseSound; //49ch
	WORD trapDetectDifficulty; //4a4h
	WORD trapDisarmDifficulty; //4a6h
	WORD isTrapped; //4a8h
	WORD isTrapDetected; //4aah
	WORD trapLaunchTargetX; //4ach
	WORD trapLaunchTargetY; //4aeh
	ResRef keyRequired; //4b0h
	DWORD detectDifficulty; //4b8h
	DWORD lockDifficulty; //4bch
	WORD u4c0; //set to 0

	//POINT
	DWORD u4c2; //calculation of boundsOpenLeft and boundsOpenRight
	DWORD u4c6; //boundsOpenBottom

	//POINT
	DWORD u4ca; //calculation of boundsClosedLeft and boundsClosedRight
	DWORD u4ce; //boundsClosedBottom

	CSound u4d2;
	STRREF lockPicked; //53ch
	DWORD u540; //set to 0
};

#endif //OBJDOOR_H
