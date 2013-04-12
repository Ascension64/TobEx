//TobExEE
#ifndef VIDCORE_H
#define VIDCORE_H

#include "stdafx.h"
#include "rescore.h"

#define CVIDIMG_TRANSPARENT				0x00000001
#define CVIDIMG_TRANSLUCENT				0x00000002
#define CVIDCELL_TRANSLUCENT_SHADOW		0x00000004
#define CVIDCELL_BRIGHTEST				0x00000008

struct CVidPolySurface;

typedef unsigned int ABGR; //[ALPHA.BLUE.GREEN.RED]

//FIX_ME
//const ABGR* const g_prgbRangeArray = (const ABGR* const)0xAB9B78;
//const ABGR g_rgbDefaultText = 0xBED7D7;

struct CVidPolySurface { //Size 24h, FIX_ME
	CVidPolySurface* m_pSurfacePrev; //0h
	int m_nX; //4h
	int m_nY; //8h
	int uc; //directionX - 1 = backward from previous x, -1 = fwd or same from previous x
	int u10; //((-(cntx - cnt+1x)) / (cnty - cnt+1y)) * cnt+1y
	int u14; //1 - (cnty - cnt+1y)
	int u18; //(-(cntx - cnt+1x)) % (cnty - cnt+1y)
	int u1c; //cnty - cnt+1y
	int u20; //cnty - cnt+1y
};

struct CVidPoly { //Size 14h?, FIX_ME
	int m_pVertexArray; //0h, one element is [WORDx.WORDy]
	int m_nVertices; //4h
	CVidPolySurface* u8; //LinkedList
	CVidPolySurface* uc; //LinkedList, derived from u8 
		
	//void CVidPoly::RenderLine(pSurface, startIdx, endIdx, rgbColor, pRectMirror, pPoint)
	//see CVidPoly::SetLineRenderFunc(dwFlags) for more info 0x9F8563
	int u10;
};

struct VidPal { //Size 24h
	int* u0; //pRgbColor + nChitinUpdates?, gets an element from the palette
	int u4; //an alternative palette?
		
	void* m_pPalette; //8h
	//TYPE_SET palette is an arrayptr (int size objects - 2 WORDs)

	//TYPE_RANGE palette is...
	//int u0[4]; //special colours
	//int u10[7][12]; //7x12
	//int u160[168]; //generated from the 7x12 colours

	int m_nColors; //ch, nSize
	int u10;
	short m_nType; //14h, m_nType (0 = TYPE_SET, 1 = TYPE_RANGE)
	char u16;
	char p17;
	BOOL u18;
	CreFileColors m_colors; //1ch
	char p23;
};

struct CVid : public VidPal { //Size 9Ch
	struct CColorSettings {
		//for TYPE_SET palette (also used for TYPE_RANGE)
		ABGR m_rgbLightMask; //24h
		int m_nBrightness; //28h, some brightness value to multiply
		ABGR m_rgbGamma; //2ch, RGB value based on char 0xAB9AF6 (3)

		//for TYPE_RANGE palette; 7 colors for each range set
		//lightmask
		ABGR* u30[7];
		char u4c[7]; //adjustments if not 1

		char p53;

		//brightness
		ABGR* u54[7];
		char u70[7];

		char p77;

		//gamma
		ABGR* u78[7];
		char u94[7];

		char m_nColorRangeBitfield; //9bh, bits 0-7 for each nRangeId set
	} m_ColorSettings;
};

struct ResBamFile { //size 10h
	BOOL m_bLoaded; //0h
	ResBam* m_pRes; //4h
	ResRef m_rName; //8h
};

class CVidCell : public CVid { //Size C4h
public:
	virtual BOOL IncrementFrame() { return FALSE; } //v0
	virtual void v4() {}
	virtual void v8() {}
	virtual void vc() {}
	virtual BOOL LoadFrame(unsigned int nFrame) { return FALSE; } //v10

	//vtable @0h
	//CVid @4h
	ResBamFile m_bam; //a0h
	short m_nFrameCurr; //b0h, current frame
	short m_nCycleCurr; //b2h, current cycle, related to ua2 in VisualEffect
	int ub4;
	BOOL m_bOwnPaletteSet; //b8h
	void* m_pFrameEntry; //bch, from BAM file - via GetFrame()
	bool m_bColorOneIsNotBlack; //c0h, if 0, palette[1] is set to [0.0.0]; inits to 1; is never changed
	char uc1;
	short uc2;
};

struct ResMosFile { //Size 10h
	BOOL m_bLoaded; //0h
	Res* m_pRes; //4h, ResMos
	ResRef m_rName; //8h
};

struct CVidMosaic : public CVid { //Size B0h
	ResMosFile m_mos; //9ch
	int uac;
};

struct CTilesetBase : public CVid { //Size A4h, FIX_ME
	int u9c;
	int ua0;
};

struct CTileset { //Size B8h, FIX_ME
	int u0; //brightness
	ABGR u4; //ABGR lightmask, obtained from CInfinity.u1b8
	CTilesetBase u8;
	int uac;
	int* m_pArray; //b0h, ptrs to CObjects (0x72h size; inherits from ResTis, constructor 0x6C283C)
	int m_nArraySize; //b4h
};

struct ResBmpFile {
	BOOL m_bLoaded; //0h
	Res* m_pRes; //4h, ResBmp
	ResRef m_rName; //8h
};

struct CVidBitmap : public CVid { //Size B4h
	ResBmpFile m_res; //9ch
	short m_nBitCount; //ach, CVIDBITMAP_8BIT = 8, CVIDBITMAP_4BIT = 4
	char pbe[2];
	IECString ub0;
};

class CVidFont { //Size 24h
public:
	ResBmpFile m_res; //0h, FNT?
	int u10;
	char u14;
	char p15[3];
	int u18;
	int u1c;
	int u20;
};

struct CVideo { //Size 150h
	int u0;
	int u4;
	int u8;
	int uc;
	int u10;
	int u14;
	char u18;
	char u19;
	char p1a[2];
	int u1c;
	int m_nWidth; //20h
	int m_nHeight; //24h
	int u28;
	bool m_bRedrawEntireScreen; //2ch
	bool m_bHardwareMouseCursor; //2dh
	char u2e[2];
	int u30;
	char u34;
	char p35[3];
	int u38; //SDL_GetTicks
	int u3c;
	char u40;
	char u41;
	char p42[2];
	int u44;
	int u48;
	int u4c;
	int u50;
	int u54;
	int u58;
	int u5c;
	int u60;
	int u64;
	RECT u68;
	int u78;
	int u7c;
	int u80;
	int u84;
	int u88;
	int u8c;
	void* m_sdlCursor; //90h, SDLCursor*
	void* m_sdlSurface; //94h, SDLSurface*
	int u98;
	CVidBitmap u9c;
};

struct CSelectionCircle { //Size 2Ch
	bool m_bCircle; //0: targetted pizza look, 1: unbroken circle
	char p1;
	short m_wHighlights; //2h, number of times pizza look is requested
	char u4;
	char u5;
	char p6[2];
	ABGR m_rgbCircle; //8h, for unbroken circle
	char uc[0x1c];
	char u28;
	char p29[3];
};

#endif //VIDCORE_H