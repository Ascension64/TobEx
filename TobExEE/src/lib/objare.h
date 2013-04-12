//TobExEE
#ifndef OBJARE_H
#define OBJARE_H

#include "objcore.h"

class CAreaObject : public CGameSprite { //Size 394h
public:
	int u390;
};

class CAreaObjectEnumList : public IECPtrList { //Size 1Ch
public:
};

class CObjectMarker : public CGameObject { //Size 64h
public:
	CAreaObjectEnumList m_lEnums; //48h, contains all AddToArea objects
};

#endif //OBJARE_H