#ifndef OBJTEXT_H
#define OBJTEXT_H

#include "objcore.h"

class CGameText : public CGameObject { //Size 620h
public:
	//AAAB78
	virtual ~CGameText() {} //v0

	CVidCell u42;
	CVidFont m_fontText; //118h, FLOATTXT
	short m_nHeight; //614h
	short m_nWidth; //616h
	char m_nMaxRows; //618h
	char u619; //pad
	IECString* sText; //61ah
	char m_nRows; //61eh, number of rows after format
	char u61f; //pad
};

#endif //OBJTEXT_H