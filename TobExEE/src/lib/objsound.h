//TobExEE
#ifndef OBJSOUND_H
#define OBJSOUND_H

#include "objcore.h"

class CSoundObject : public CGameObject { //Size 148h
public:
	AreFileSoundObject m_sndObject; //48h
	CSoundWrapper u11c;
	int u134;
	int u138;
	int u13c;
	int u140;
	int u144;
};

#endif //OBJSOUND_H
