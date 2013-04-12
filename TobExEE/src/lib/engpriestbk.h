//TobExEE
#ifndef ENGPRIESTBK_H
#define ENGPRIESTBK_H

#include "engine.h"

class CScreenPriestBook : public CEngine { //Size 854h
public:
	CHotkey m_keymap[95]; //d0h, size 474h
	int m_keybuffer[95]; //544h, size 17Ch
	int u6c0;
	CVidCell u6c4;
	int u788;
	int u78c;
	int u790;
	int u794;
	int u798;
	int u79c;
	IECPtrList u7a0;
	ResRef u7bc;
	int u7c4;
	int u7c8;
	int u7cc;
	int u7d0;
	int u7d4;
	int u7d8;
	int u7dc;
	int u7e0;
	char u7e4;
	char p7e5[3];
	CVidFont u7e8;
	CVidFont u80c;
	CVidFont u830;
};

#endif //ENGPRIESTBK_H