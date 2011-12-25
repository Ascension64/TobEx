#ifndef ICON_H
#define ICON_H

struct CIcon {
	//Size: 0x30
	//Constructor: 0x549D30
	ResRef name; //0h
	DWORD u8; //-1
	ResRef uc; //second name?
	DWORD u14;
	WORD u18;
	WORD u1a;
	WORD u1c;
	WORD u1e;
	ResRef u20; //third name?
	BYTE u28;
	BYTE u29;
	DWORD u2a; //-1
	BYTE u2e;
	BYTE u2f;
};

#endif //ICON_H