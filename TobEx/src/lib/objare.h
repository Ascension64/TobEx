#ifndef OBJARE_H
#define OBJARE_H

#include "objcore.h"

class CAreaObjectEnumList : public IECPtrList { //Size 1Ch
	//AB7654, has own procs
};

class CObjectMarker : public CGameObject { //Size 5Eh
//Constructor: 0x95BC40
public:
	//AB75F0
	virtual ~CObjectMarker() {} //v0

	CAreaObjectEnumList m_enumList; //42h, contains all AddToArea objects
};

#endif //OBJARE_H