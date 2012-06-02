#ifndef OBJSTATIC_H
#define OBJSTATIC_H

#include "objcore.h"

//area animations
class CStaticObject : public CGameObject { //Size 23Eh
public:
	char szStaticName[32]; //42h
	short x; //62h
	short y; //64h
	int nSchedule; //66h
	ResRef rAnim; //6ah
	short nSeq; //72h
	short nFrame; //74h
	unsigned int dwFlags; //76h
	short z; //7ah
	short a; //7ch
	short nFrameStart; //7eh
	char cLoopChance; //80h
	char cSkipCycles; //81h
	ResRef rPalette; //82h
	int u8a; //8ah
	CVidCell u8e;
	int u164;
	IECPtrList u168;
	int u184;
	CVidBitmap u188;
};

#endif //OBJSTATIC_H
