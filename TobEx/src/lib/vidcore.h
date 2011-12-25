#ifndef VIDCORE_H
#define VIDCORE_H

#include "utils.h"
#include "resref.h"
#include "rescore.h"
#include "cstringex.h"

#define CVIDIMG_TRANSPARENT				0x00000001
#define CVIDIMG_TRANSLUCENT				0x00000002
#define CVIDCELL_TRANSLUCENT_SHADOW		0x00000004
#define CVIDCELL_BRIGHTEST				0x00000008

struct CVidPolySurface;

typedef DWORD ARGB; //[ALPHA.RED.GREEN.BLUE]

struct CVidPolySurface {
//Size: 0x24
	CVidPolySurface* pSurfacePrev; //0h
	DWORD x; //4h
	DWORD y; //8h
	DWORD uc; //directionX - 1 = backward from previous x, -1 = fwd or same from previous x
	DWORD u10; //((-(cntx - cnt+1x)) / (cnty - cnt+1y)) * cnt+1y
	DWORD u14; //1 - (cnty - cnt+1y)
	DWORD u18; //(-(cntx - cnt+1x)) % (cnty - cnt+1y)
	DWORD u1c; //cnty - cnt+1y
	DWORD u20; //cnty - cnt+1y
};

struct CVidPoly {
//Size: 0x14?
//Constructor: 0x9F69C0
	DWORD m_pVertexArray; //0h, one element is [WORDx.WORDy]
	DWORD m_nVertices; //4h
	CVidPolySurface* u8; //LinkedList
	CVidPolySurface* uc; //LinkedList, derived from u8 
		
	//void CVidPoly::RenderLine(pSurface, startIdx, endIdx, rgbColor, pRectMirror, pPoint)
	//see CVidPoly::SetLineRenderFunc(dwFlags) for more info 0x9F8563
	DWORD u10;
};

struct VidPal {
//Size: 0x24h
//Constructor: 0x9F3640
	void SetFxPaletteNo3d(ARGB*, DWORD, DWORD, DWORD, BOOL);

	DWORD* u0; //pRgbColor + nChitinUpdates?, gets an element from the palette
	DWORD u4; //an alternative palette?
		
	DWORD* pPalette; //8h, m_pPalette
	//TYPE_SET palette is an arrayptr (DWORD size objects - 2 WORDs)

	//TYPE_RANGE palette is...
	//DWORD u0[4]; //special colours
	//DWORD u10[7][12]; //7x12
	//DWORD u160[168]; //generated from the 7x12 colours

	DWORD nColors; //ch, nSize
	DWORD u10;
	WORD m_nType; //14h, Arg1, m_nType (0 = TYPE_SET, 1 = TYPE_RANGE)
	BYTE u16;
	BYTE u17; //pad
	BOOL u18;

	//struct ColorRangeValues {
	BYTE colorMetal; //1ch
	BYTE colorMinor; //1dh
	BYTE colorMajor; //1eh
	BYTE colorSkin; //1fh
	BYTE colorLeather; //20h
	BYTE colorArmor; //21h
	BYTE colorHair; //22h
	BYTE u23; //pad
	//};
};

extern void (VidPal::*VidPal_SetFxPaletteNo3d)(ARGB*, DWORD, DWORD, DWORD, BOOL);

struct CVid : public VidPal {
//Size: 0x9c
//Constructor: 0x9C97F0
//vtable: NULL
	struct CColorSettings {
		//for TYPE_SET palette (also used for TYPE_RANGE)
		ARGB u24; //00ffffff, [A.R.G.B] lightmask
		DWORD u28; //some brightness value to multiply
		ARGB u2c; //gammargb?, RGB value based on BYTE 0xAB9AF6 (3)

		//for TYPE_RANGE palette; 7 colors for each range set
		//lightmask
		ARGB u30[7];
		BYTE u4c[7]; //adjustments if not 1

		BYTE u53; //pad

		//brightness
		DWORD u54[7];
		BYTE u70[7];

		BYTE u77; //pad

		//gamma
		ARGB u78[7];
		BYTE u94[7];

		BYTE u9b;
	} m_ColorSettings;
};

class CVidCell : public CVid {
//Size: 0xd6
//Constructor: 0x9C9D57 (0 args; used for creature animations, non-overlapping BAM)
//Constructor: 0x9C9E7D (2 args; used in VVC projectiles, SPMAGMIS, GRNDGLOW, STATES, FLAG1, COLGRAD, STORTINT, BAMs with transparency)
//vtable: 0xAB9890 (aux 0xAB8FF4 ? identical)
//Note: due to virtual table, CVid offsets add 4h
public:
	virtual void v0() {} //BOOL IncrementFrame()
	virtual void v4() {} //BOOL Render(?, ?, x?, y?, ?, nFrame)
	virtual void v8() {} //9CD125
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
	WORD nFrameCurr; //c0h, current frame
	WORD nCycleCurr; //c2h, current cycle, related to ua2 in VisualEffect
	DWORD uc4;
	BOOL bOwnPaletteSet; //c8h
	void* pFrameEntry; //cch, from BAM file - via GetFrame()
	BYTE ud0; //bool bColorOneIsNotBlack; if 0, palette[1] is set to [0.0.0]; inits to 1; is never changed
	BYTE ud1; //padding?
	BOOL ud2; //bAnimDataCompressed (from BAM file)
};

struct CVidMosaic : public CVid {
//Size: 0xB0
//Constructor: 0x9D0601 (0 args)
//Constructor: 0x9D069D (2 args, used for ImeUI)
//vtable: NULL
	struct ResMosContainer {
		BOOL bLoaded;
		Res* pRes; //ResMos
		ResRef name; //MOS files
	} u9c; //9ch
	DWORD uac;
};

struct CTilesetBase : public CVid {
//Size: 0xa4
//Constructor: 0x9D1797
	DWORD u9c;
	DWORD ua0;
};

struct CTileset {
//Size: 0xb8
//Constructor: 0x6C1450
	DWORD u0; //brightness
	ARGB u4; //ARGB lightmask, obtained from CInfinity.u1b8
	CTilesetBase u8;
	DWORD uac;
	DWORD* pArray; //b0h, ptrs to CObjects (0x72h size; inherits from ResTis, constructor 0x6C283C)
	DWORD nArraySize; //b4h
};

struct CVidBitmap : public CVid {
//Size: 0xb6
//Constructor: 0x9D3AF8 (0 args; uses area light map, area height map, character small portrait)
//Constructor: 0x9D3C78 (2 args; uses lightmap night)
//Constructor: 0x9D3E55 (3 args; uses mpalette)
//vtable: NULL
	struct ResBmpContainer {
		BOOL bLoaded; //9ch, hasRes
		Res* pRes; //a0h, pResBmp
		ResRef name; //a4h
	} u9c;
	WORD m_nBitCount; //ach, CVIDBITMAP_8BIT = 8, CVIDBITMAP_4BIT = 4
	IECString uae;
	DWORD ub2; //b8bit (default is 4bit)
};

class CVidFont : public CVidCell {
//Size: 0x4FC
//Constructor: 0x9A94C0
public:
	char ud6[0x400];
	DWORD u4d6; //HGDIOBJ hObject
	DWORD u4da;
	DWORD u4de;
	WORD u4e2;
	WORD u4e4;
	WORD u4e6;
	DWORD u4e8;
	DWORD u4ec;
	DWORD u4f0;
	DWORD u4f4;
	DWORD u4f8;
};

class CVideoModeBase {
//Size: 0xf4
//Constructor: 0x9B3BED
//vtable: 0xAB910C
public:
	DWORD* vtable; //0h
	DWORD u4;
	DWORD u8;
	DWORD uc;
	DWORD u10;
	DWORD u14;
	DWORD u18; //ff

	//DDCOLORKEY
	DWORD u1c; //dwColorSpaceLowValue, ff00
	DWORD u20; //dwColorSpaceHighValue, ff0000

	ARGB u24; //RgbTriple lightmask for wallgroup obscured animations, normally [0.0.0]

#ifdef _DEBUG
	_CCriticalSection ccs; //0x28
#else
	CCriticalSection ccs; //0x28
#endif
	//Note BYTE 0xB61512 sets the target brightness, 1 = normal, FF for slowest screen fade
	BYTE FadeDirection; //48h, 0 = ToColor, 1 = FromColor
	BYTE FractionalBrightness; //49h, used as a fraction of B61512; in FadeFromColor, decrements
#ifdef _DEBUG
	_CCriticalSection ccs2; //0x4a
#else
	CCriticalSection ccs2; //0x4a
#endif
	CPtrList u6a; //AB5C50
	DWORD u86;
	DWORD u8a;
	BYTE u8e;
	BYTE u8f;
	DWORD u90; //GetTickCount()
	DWORD u94;
	DWORD u98;
	DWORD nSurfaces; //9ch

	DWORD* ppSurfaceArray; //a0h, 20h size, contains pSurface
	//0 = CVIDINF_SURFACE_BACK
	//1 = CVIDINF_SURFACE_FRONT
	//2 = SURFACE_FX
	//3 = SURFACE_MIRROR_FX

	ARGB ua4; //Color Correction light mask, copied from CInfinity.u1b8
		
	//colors adjusted by 255 - (255-brightness)*(255-color)/256
	//essentially addition with capping at 255
	BYTE m_brightness; //a8h, Brightness Correction (0-40)
		
	//colors adjusted by color * (1+gamma/8)
	BYTE m_gamma; //a9h, Gamma Correction (0-5)

	//bitshifts for colours
	DWORD nShiftLeftRed; //aah, 0 in 32bit, 11 in 16 bit
	DWORD nShiftLeftGreen; //aeh, 8 in 32bit, 5 in 16 bit
	DWORD nShiftLeftBlue; //b2h, 16 in 32bit, 0 in 16 bit
	DWORD ub6; //8
	DWORD uba; //not set
	DWORD ube; //not set
	DWORD nShiftRightRed; //c2h, 0 in 32bit, 3 in 16bit
	DWORD nShiftRightGreen; //c6h, 0 in 32bit, 2 in 16bit
	DWORD nShiftRightBlue; //cah, 0 in 32bit, 3 in 16bit
	DWORD uce; //unused?
	WORD ud2; //unused?
	DWORD ud4;
	DWORD ud8;
	DWORD udc;
	DWORD ue0;
	DWORD ue4;
	DWORD ue8;
	DWORD uec;
	DWORD uf0;
};

class CVideoMode : public CVideoModeBase {
//Size: 0x732
//Constructor: 0x9B68C5
//vtable: 0xAB9238
public:
	struct DDSURFACEDESC {
		DWORD dwSize; //f4h
		DWORD dwFlags; //f8h
		DWORD dwHeight; //fch
		DWORD dwWidth; //100h
		DWORD dwLinearSize; //104h
		DWORD dwBackBufferCount; //108h
		DWORD dwRefreshRate; //10ch
		DWORD dwAlphaBitDepth; //110h
		DWORD dwReserved; //114h
		DWORD lpSurface; //118h, FXSurface for non-3d
		
		DWORD u11c; //ddckCKDestOverlay
		DWORD u120;

		DWORD u124; //ddckCKDestBlt
		DWORD u128;

		DWORD u12c; //ddckCKSrcOverlay
		DWORD u130;

		DWORD u134; //ddckCKSrcBlt
		DWORD u138;

		DWORD u13c; //ddpfPixelFormat
		DWORD u140;
		DWORD u144;
		DWORD u148;
		DWORD u14c;
		DWORD u150;
		DWORD u154;
		DWORD u158;

		DWORD u15c; //ddsCaps
	} m_SurfaceDesc; //f4h

	RECT rFxSurfaceLockedArea; //160h, area of FxSurface that has been locked for drawing
	DWORD u170;
	CVidFont u174; //NORMAL.BAM
	DWORD u670; //p4b00h size object (begins with IDirectDrawSurface array)
	DWORD u674; //nElements in p4b00h size object
	CVidBitmap u678;
	IECString u72e;
};

struct CVideo {
//Size: 0x168
//Constructor: 0x9AD29E
	WORD nBitsPerPixel; //0h
	WORD u2;
	bool bIs16Bit; //4h
	bool bIs24Bit; //5h
	bool bIs32Bit; //6h
	BYTE u7; //pad?
	struct CSoftBlt {
		//Size: 0x100
		//Constructor: 0x9FCFA0
		BYTE u0; //SoftSrcKeyBltFast
		BYTE u1; //SoftBltFast
		BYTE u2; //SoftSrcKeyBlt
		BYTE u3; //SoftBlt
		BYTE u4; //SoftMirrorBlt
		char u5[0xd9];
		DWORD ude;
		DWORD ue2;
		BYTE ue6;
		BYTE ue7; //pad?
		DWORD* ue8; //funcptr - ? for Blt(), bltfunc
		DWORD* uec; //funcptr - ? for SrcKeyBlt(),  bltfunc
		DWORD* uf0; //funcptr - ? for MirrorBlt(),  bltfunc
		DWORD* uf4; //funcptr - ? for MirrorBlt() [and SrcKeyBlt() when MirrorBlt not set],  bltfunc
		DWORD* uf8; //funcptr - ? for BltFast()
		DWORD* ufc; //funcptr - ? for SrcKeyBltFast()
	} m_SoftBlt; //8h, software blitter
	DWORD dwRefreshRate16Bit; //108h
	DWORD dwRefreshRate24Bit; //10ch
	DWORD dwRefreshRate32Bit; //110h
	ResRef u114;
	WORD u11c;
	DWORD u11e;
	DWORD m_doubleSizeData; //122h, Double Size Data
	DWORD u126;
	HDC dc; //12ah, HDC GetDC(hWnd) - DeviceContext
	DWORD u12e; //HGLRC wglCreateContext(hdc)
	BOOL bIs3dAccelerated; //132h (3078h)
	DWORD u136; //? glTextureFormat
	BOOL bBackwardsCompatible3d; //13ah, Backwards Compatible 3d (3080h)
	DWORD u13e; //GLuint texture (for glBindTexture)
	DWORD u142; //pIDirectDraw (DirectDrawCreate onto here)
	DWORD u146; //pIDirectDraw2
	DWORD u14a; //pIDirectDrawClipper
	CVideoMode* VideoModes[4]; //14eh
	DWORD nCurrentVideoModeIdx; //15eh
	BYTE u162;
	bool bFullScreen; //163h
	HWND hBaldurChitin; //164h
};

#endif //VIDCORE_H