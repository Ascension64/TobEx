#ifndef FILECHU_H
#define FILECHU_H

#include "stdafx.h"
#include "resref.h"

struct ChuFileControlInfoBase { //Size Eh
	int m_nId; //0h
	short m_wPosX; //4h
	short m_wPosY; //6h
	short m_wWidth; //8h
	short m_wHeight; //ah
	char m_cType; //ch
	char pd;
};

#endif //FILECHU_H