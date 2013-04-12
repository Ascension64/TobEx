//TobExEE
#ifndef OBJTEXT_H
#define OBJTEXT_H

#include "objcore.h"

class CGameText : public CGameObject { //Size 78h
public:
	int u48;
	CVidFont m_fntText; //4ch, FLOATTXT
	short m_nHeight; //70h
	short m_nWidth; //72h
	IECString m_sText; //74h
};

#endif //OBJTEXT_H