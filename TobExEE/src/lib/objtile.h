//TobExEE
#ifndef OBJTILE_H
#define OBJTILE_H

#include "objcore.h"

//area tile objects
class CTiledObject : public CGameSprite { //Size 3E8h
public:
	int u390;
	ResRef m_rTileID; //394h
	unsigned int m_dwFlags; //39ch
	int u3a0;
	int u3a4;
	int u3a8;
	int u3ac;
	struct CTile { //Size 18h
		int u0; //3ach
		int u4; //3b0h
		int u8; //3b4h
		int uc; //3b8h
		ResRef u10; //3bch
	} u3b0; //added to CArea.u9ca
	SCRIPTNAME m_szTileName; //3c8h
};

#endif //OBJTILE_H
