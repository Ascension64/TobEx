#ifndef ICON_H
#define ICON_H

struct CIcon { //Size 30h
//Constructor: 0x549D30
	ResRef name; //0h
	int u8; //-1
	ResRef uc; //second name?
	int u14;
	short u18;
	short u1a;
	short u1c;
	short u1e;
	ResRef u20; //third name?
	char u28;
	char u29;
	int u2a; //-1
	char u2e;
	char u2f;
};

#endif //ICON_H