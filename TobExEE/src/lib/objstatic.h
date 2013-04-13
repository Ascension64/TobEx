//TobExEE
#ifndef OBJSTATIC_H
#define OBJSTATIC_H

#include "objcore.h"

class CStaticObject : public CGameObject { //Size 230h
public:
	AreFileStaticObject m_staticObject; //48h
	CVidCell u94;
	int u158;
	IECPtrList u15c;
	int u178;
	CVidBitmap u17c;
};

#endif //OBJSTATIC_H
