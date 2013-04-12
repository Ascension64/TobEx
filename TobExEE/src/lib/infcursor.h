//TobExEE
#ifndef INFCURSOR_H
#define INFCURSOR_H

#include "vidcore.h"
#include "uicore.h"
#include "sndcore.h"

#define CURSOR_ARROW			0x64
#define CURSOR_TOOLTIP_SCROLL	0x65

class CInfTooltip : public CVidCell { //Size 114h
	//CVidCell m_vidScroll; //0h, TOOLSCRL
	IECString uc4;
	CVidFont m_fnt; //c8h, TOOLFONT
	short m_wFrameLeft; //ech
	short m_wFrameRight; //eeh
	short m_wCurrentWidth; //f0h, gets no larger than L/2+R/2+wTextWidth
	short m_wCurrentWidth2; //f2h

	//0: expanding
	//1: contracting
	//2: stationary after expand
	//3: stationary after contract
	char m_nMode; //f4

	char pf5;
	short m_wTextWidth; //f6h, this is the graphical text width in pixels
	short m_wNumFramesLeft; //f8h
	short m_wNumFramesRight; //fah
	CSoundWrapper m_snd; //fch, PAPER
};

struct CInfCursor { //Size 380h
	int u0;
	CVidCell u4; //CURSORS
	CVidCell uc8; //CURSARW
	CVidCell u18c;
	CInfTooltip m_Tooltip; //250h
	int u364;
	int u368;

	//others: CURSORS.BAM sequence
	//0x64: Cursor arrow
	//0x65: Tooltip scroll
	//0x66: u1b0
	int m_nCurrentCursorIdx; //36ch
	int m_nCursorArrowDirection; //370h, 0-7 (N-NE-E-SE-S-SW-W-SW)
	BOOL m_bLeftMouseDown; //374h, TRUE: will set to cursor index + 1
	CUIControl* m_pCtrlTarget; //378h
	char m_u37c;
	char p37d[3];
};

#endif //INFCURSOR_H