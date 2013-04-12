#ifndef FILECHU_H
#define FILECHU_H

#include "stdafx.h"
#include "resref.h"

struct ChuFileControlInfoBase { //Size Eh
	int id; //0h
	short posX; //4h
	short posY; //6h
	short width; //8h
	short height; //ah
	char type; //ch
	char ud; //dh
};

#endif //FILECHU_H