#ifndef OBJTILE_H
#define OBJTILE_H

#include "objcore.h"

//area tile objects
class CTiledObject : public CGameSprite { //Size 428h
public:
	ResRef u3d8; //3d8h, from 20h
	int u3e0; //from 28h
	int u3e4;
	int u3e8;
	int u3ec;
	struct CTile { //Size 18h
		int u0; //3f0h
		int u4; //3f4h
		int u8; //3f8h
		int uc; //3fch
		ResRef u10; //400h
	} u3f0; //3f0h, added to CArea.u9ca
	char szTileName[32]; //408h
};

#endif //OBJTILE_H
