#ifndef OBJSOUND_H
#define OBJSOUND_H

#include "objcore.h"

//for area ambients
class CSoundObject : public CGameObject { //Size 192h
public:
	//ARE V1.0 ambient
	char szAmbientName[32]; //42h
	short x; //62h
	short y; //64h
	short radius; //66h
	int height; //68h
	int u6c; //6ch
	short volume; //70h
	ResRef rSounds[10]; //72h
	short nSounds; //c2h
	short uc4; //c4h
	int nPauseTime; //c6h
	int nPauseDeviation; //cah
	int nSchedule; //ceh
	unsigned int dwFlags; //d2h
	char ud6[0x40]; //d6h

	CSound u116;
};

#endif //OBJSOUND_H
