#ifndef VIDCORE_H
#define VIDCORE_H

#include "stdafx.h"
#include "datatypes.h"
#include "rescore.h"

#define CVIDIMG_TRANSPARENT				0x00000001
#define CVIDIMG_TRANSLUCENT				0x00000002
#define CVIDCELL_TRANSLUCENT_SHADOW		0x00000004
#define CVIDCELL_BRIGHTEST				0x00000008

struct CVidPolySurface;

typedef unsigned int ARGB; //[ALPHA.RED.GREEN.BLUE]

extern const ARGB* g_pColorRangeArray;
extern const ARGB g_ColorDefaultText;

struct CVidPolySurface { //Size 24h
	CVidPolySurface* pSurfacePrev; //0h
	int x; //4h
	int y; //8h
	int uc; //directionX - 1 = backward from previous x, -1 = fwd or same from previous x
	int u10; //((-(cntx - cnt+1x)) / (cnty - cnt+1y)) * cnt+1y
	int u14; //1 - (cnty - cnt+1y)
	int u18; //(-(cntx - cnt+1x)) % (cnty - cnt+1y)
	int u1c; //cnty - cnt+1y
	int u20; //cnty - cnt+1y
};

struct CVidPoly { //Size 14h?
//Constructor: 0x9F69C0
	int m_pVertexArray; //0h, one element is [WORDx.WORDy]
	int m_nVertices; //4h
	CVidPolySurface* u8; //LinkedList
	CVidPolySurface* uc; //LinkedList, derived from u8 
		
	//void CVidPoly::RenderLine(pSurface, startIdx, endIdx, rgbColor, pRectMirror, pPoint)
	//see CVidPoly::SetLineRenderFunc(dwFlags) for more info 0x9F8563
	int u10;
};

struct VidPal { //Size 24h
//Constructor: 0x9F3640
	void SetFxPaletteNo3d(ARGB* pPalette, int nBitsPerPixel, unsigned int dwFlags, int dwAlpha, BOOL bIgnoreBrighten);

	int* u0; //pRgbColor + nChitinUpdates?, gets an element from the palette
	int u4; //an alternative palette?
		
	int* pPalette; //8h, m_pPalette
	//TYPE_SET palette is an arrayptr (int size objects - 2 WORDs)

	//TYPE_RANGE palette is...
	//int u0[4]; //special colours
	//int u10[7][12]; //7x12
	//int u160[168]; //generated from the 7x12 colours

	int nColors; //ch, nSize
	int u10;
	short m_nType; //14h, Arg1, m_nType (0 = TYPE_SET, 1 = TYPE_RANGE)
	char u16;
	char u17; //pad
	BOOL u18;
	ColorRangeValues colors; //1ch
	char u23; //pad
};

extern void (VidPal::*VidPal_SetFxPaletteNo3d)(ARGB*, int, unsigned int, int, BOOL);

struct CVid : public VidPal { //Size 9Ch
//Constructor: 0x9C97F0
//vtable: NULL
	struct CColorSettings {
		//for TYPE_SET palette (also used for TYPE_RANGE)
		ARGB u24; //00ffffff, [A.R.G.B] lightmask
		int u28; //some brightness value to multiply
		ARGB u2c; //gammargb?, RGB value based on char 0xAB9AF6 (3)

		//for TYPE_RANGE palette; 7 colors for each range set
		//lightmask
		ARGB u30[7];
		char u4c[7]; //adjustments if not 1

		char u53; //pad

		//brightness
		int u54[7];
		char u70[7];

		char u77; //pad

		//gamma
		ARGB u78[7];
		char u94[7];

		char u9b;
	} m_ColorSettings;
};

class CVidCell : public CVid { //Size D6h
//Constructor: 0x9C9D57 (0 args; used for creature animations, non-overlapping BAM)
//Constructor: 0x9C9E7D (2 args; used in VVC projectiles, SPMAGMIS, GRNDGLOW, STATES, FLAG1, COLGRAD, STORTINT, BAMs with transparency)
//vtable: 0xAB9890 (aux 0xAB8FF4 ? identical)
//Note: due to virtual table, CVid offsets add 4h
public:
	virtual BOOL IncrementFrame() { return FALSE; } //v0
	virtual void v4() {} //BOOL CVidCell::FXRenderSoftNoPalette(lpSurface, dwLinearSize, x, y, pRect rClip, int, dwFlags, pLoc source)
	virtual void v8() {} //BltToBackSurface, 9CD125
	virtual void vc() {} //9CCA89(lpSurface, dwLinearSize, centreX, centreY, dispflags, 0)
	virtual void v10() {} //9FE56C
	virtual void v14() {}
	virtual void v18() {} //BOOL GetFrame(nFrame)

	struct ResBamContainer {
		BOOL bLoaded;
		ResBam* pBam;
		ResRef name; //init to "STATES"
	} ua0;
	struct ResBahContainer {
		BOOL bLoaded;
		ResBah* pBah;
		ResRef name;
	} ub0;
	short nFrameCurr; //c0h, current frame
	short nCycleCurr; //c2h, current cycle, related to ua2 in VisualEffect
	int uc4;
	BOOL bOwnPaletteSet; //c8h
	void* pFrameEntry; //cch, from BAM file - via GetFrame()
	char ud0; //bool bColorOneIsNotBlack; if 0, palette[1] is set to [0.0.0]; inits to 1; is never changed
	char ud1; //padding?
	BOOL ud2; //bAnimDataCompressed (from BAM file)
};

struct CVidMosaic : public CVid { //Size B0h
//Constructor: 0x9D0601 (0 args)
//Constructor: 0x9D069D (2 args, used for ImeUI)
//vtable: NULL
	struct ResMosContainer {
		BOOL bLoaded;
		Res* pRes; //ResMos
		ResRef name; //MOS files
	} u9c; //9ch
	int uac;
};

struct CTilesetBase : public CVid { //Size A4h
//Constructor: 0x9D1797
	int u9c;
	int ua0;
};

struct CTileset { //Size B8h
//Constructor: 0x6C1450
	int u0; //brightness
	ARGB u4; //ARGB lightmask, obtained from CInfinity.u1b8
	CTilesetBase u8;
	int uac;
	int* pArray; //b0h, ptrs to CObjects (0x72h size; inherits from ResTis, constructor 0x6C283C)
	int nArraySize; //b4h
};

struct CVidBitmap : public CVid { //Size B6h
//Constructor: 0x9D3AF8 (0 args; uses area light map, area height map, character small portrait)
//Constructor: 0x9D3C78 (2 args; uses lightmap night)
//Constructor: 0x9D3E55 (3 args; uses mpalette)
//vtable: NULL
	struct ResBmpContainer {
		BOOL bLoaded; //9ch, hasRes
		Res* pRes; //a0h, pResBmp
		ResRef name; //a4h
	} u9c;
	short m_nBitCount; //ach, CVIDBITMAP_8BIT = 8, CVIDBITMAP_4BIT = 4
	IECString uae;
	int ub2; //b8bit (default is 4bit)
};

class CVidFont : public CVidCell { //Size 4FCh
//Constructor: 0x9A94C0
public:
	char ud6[0x400];
	HGDIOBJ hFont; //4d6h
	BOOL bCreatedFont; //4dah
	int u4de;
	short u4e2;
	short wAscent; //4e4h
	short wHeight; //4e6h
	int u4e8;
	int u4ec;
	int u4f0;
	int u4f4;
	int u4f8;
};

class CVideoModeBase { //Size F4h
//Constructor: 0x9B3BED
public:
	//AB910C
	int* vtable; //0h
	int u4;
	int u8;
	unsigned int uc; //dwFlags
	int u10;
	int u14;
	int u18; //ff

	//DDCOLORKEY
	int u1c; //dwColorSpaceLowValue, ff00
	int u20; //dwColorSpaceHighValue, ff0000

	ARGB u24; //RgbTriple lightmask for wallgroup obscured animations, normally [0.0.0]

#ifdef _DEBUG
	_CCriticalSection ccs; //28h, for access to 8h, 8ah, 8eh
#else
	CCriticalSection ccs; //28h
#endif
	//Note char 0xB61512 sets the target brightness, 1 = normal, FF for slowest screen fade
	char FadeDirection; //48h, 0 = ToColor, 1 = FromColor
	char FractionalBrightness; //49h, used as a fraction of B61512; in FadeFromColor, decrements
#ifdef _DEBUG
	_CCriticalSection ccs2; //0x4a
#else
	CCriticalSection ccs2; //0x4a
#endif
	IECPtrList u6a; //AB5C50
	int u86;
	CVidCell* pCursorCurrent; //8ah
	char u8e;
	char u8f;
	int u90; //GetTickCount()
	int u94;
	int u98;
	int nSurfaces; //9ch

	int* ppSurfaceArray; //a0h, 20h size, contains pSurface
	//0 = CVIDINF_SURFACE_BACK
	//1 = CVIDINF_SURFACE_FRONT
	//2 = SURFACE_FX
	//3 = SURFACE_MIRROR_FX

	ARGB ua4; //Color Correction light mask, copied from CInfinity.u1b8
		
	//colors adjusted by 255 - (255-brightness)*(255-color)/256
	//essentially addition with capping at 255
	char m_brightness; //a8h, Brightness Correction (0-40)
		
	//colors adjusted by color * (1+gamma/8)
	char m_gamma; //a9h, Gamma Correction (0-5)

	//bitshifts for colours
	int nShiftLeftRed; //aah, 0 in 32bit, 11 in 16 bit
	int nShiftLeftGreen; //aeh, 8 in 32bit, 5 in 16 bit
	int nShiftLeftBlue; //b2h, 16 in 32bit, 0 in 16 bit
	int ub6; //8
	int uba; //not set
	int ube; //not set
	int nShiftRightRed; //c2h, 0 in 32bit, 3 in 16bit
	int nShiftRightGreen; //c6h, 0 in 32bit, 2 in 16bit
	int nShiftRightBlue; //cah, 0 in 32bit, 3 in 16bit
	int uce; //unused?
	short ud2; //unused?
	int ud4;
	int ud8;
	int udc;
	int ue0;
	int ue4;
	int ue8;
	int uec;
	int uf0;
};

class CVideoMode : public CVideoModeBase { //Size 732h
//Constructor: 0x9B68C5
public:
	//AB9238
	struct DDSURFACEDESC {
		int dwSize; //f4h
		unsigned int dwFlags; //f8h
		int dwHeight; //fch
		int dwWidth; //100h
		int dwLinearSize; //104h
		int dwBackBufferCount; //108h
		int dwRefreshRate; //10ch
		int dwAlphaBitDepth; //110h
		int dwReserved; //114h
		int lpSurface; //118h, FXSurface for non-3d
		
		int u11c; //ddckCKDestOverlay
		int u120;

		int u124; //ddckCKDestBlt
		int u128;

		int u12c; //ddckCKSrcOverlay
		int u130;

		int u134; //ddckCKSrcBlt
		int u138;

		int u13c; //ddpfPixelFormat
		int u140;
		int u144;
		int u148;
		int u14c;
		int u150;
		int u154;
		int u158;

		int u15c; //ddsCaps
	} m_SurfaceDesc; //f4h

	RECT rFxSurfaceLockedArea; //160h, area of FxSurface that has been locked for drawing
	int u170;
	CVidFont u174; //NORMAL.BAM
	int u670; //p4b00h size object (begins with IDirectDrawSurface array)
	int u674; //nElements in p4b00h size object
	CVidBitmap u678;
	IECString u72e;
};

struct CVideo { //Size 168h
//Constructor: 0x9AD29E
	short nBitsPerPixel; //0h
	short u2;
	bool bIs16Bit; //4h
	bool bIs24Bit; //5h
	bool bIs32Bit; //6h
	char u7; //pad?
	struct CSoftBlt {
		//Size: 0x100
		//Constructor: 0x9FCFA0
		char u0; //SoftSrcKeyBltFast
		char u1; //SoftBltFast
		char u2; //SoftSrcKeyBlt
		char u3; //SoftBlt
		char u4; //SoftMirrorBlt
		char u5[0xd9];
		int ude;
		int ue2;
		char ue6;
		char ue7; //pad?
		int* ue8; //funcptr - ? for Blt(), bltfunc
		int* uec; //funcptr - ? for SrcKeyBlt(),  bltfunc
		int* uf0; //funcptr - ? for MirrorBlt(),  bltfunc
		int* uf4; //funcptr - ? for MirrorBlt() [and SrcKeyBlt() when MirrorBlt not set],  bltfunc
		int* uf8; //funcptr - ? for BltFast()
		int* ufc; //funcptr - ? for SrcKeyBltFast()
	} m_SoftBlt; //8h, software blitter
	int dwRefreshRate16Bit; //108h
	int dwRefreshRate24Bit; //10ch
	int dwRefreshRate32Bit; //110h
	ResRef u114;
	short u11c;
	int u11e;
	int m_doubleSizeData; //122h, Double Size Data
	int u126;
	HDC dc; //12ah, HDC GetDC(hWnd) - DeviceContext
	int u12e; //HGLRC wglCreateContext(hdc)
	BOOL bIs3dAccelerated; //132h (3078h)
	int u136; //? glTextureFormat
	BOOL bBackwardsCompatible3d; //13ah, Backwards Compatible 3d (3080h)
	int u13e; //GLuint texture (for glBindTexture)
	int u142; //pIDirectDraw (DirectDrawCreate onto here)
	int u146; //pIDirectDraw2
	int u14a; //pIDirectDrawClipper
	CVideoMode* VideoModes[4]; //14eh
	int nCurrentVideoModeIdx; //15eh
	char u162;
	bool bFullScreen; //163h
	HWND hBaldurChitin; //164h
};

struct CSelectionCircle { //Size 24h
//Constructor: 0x95BFAF, also 0x95D095
	bool bCircle; //0: targetted pizza look, 1: unbroken circle
	char u1; //pad
	short u2;
	char u4;
	char u5;
	ARGB rgbCircle; //6h, for unbroken circle
	int ua;
	int ue;
	short u12;
	short u14;
	short u16;
	short u18;
	short u1a;
	short u1c;
	short u1e;
	short u20;
	char u22;
	char u23; //pad
};

#endif //VIDCORE_H