#include "animext.h"

#include "stdafx.h"

//CAnimation1000
LPCTSTR (CAnimation1000::*CAnimation1000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation1000::*)(short)>	(&CAnimation1000::GetWalkingSound),				0x8379B6);

LPCTSTR CAnimation1000::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation1000_GetWalkingSound)(wTerrainCode); }

//CAnimation1200
LPCTSTR (CAnimation1200::*CAnimation1200_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation1200::*)(short)>	(&CAnimation1200::GetWalkingSound),				0x82FB9D);

LPCTSTR CAnimation1200::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation1200_GetWalkingSound)(wTerrainCode); }

//CAnimation1300
LPCTSTR (CAnimation1300::*CAnimation1300_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation1300::*)(short)>	(&CAnimation1300::GetWalkingSound),				0x875655);

LPCTSTR CAnimation1300::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation1300_GetWalkingSound)(wTerrainCode); }

//CAnimation2000
LPCTSTR (CAnimation2000::*CAnimation2000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation2000::*)(short)>	(&CAnimation2000::GetWalkingSound),				0x83EFBF);

LPCTSTR CAnimation2000::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation2000_GetWalkingSound)(wTerrainCode); }

//CAnimation5000
CAnimation5000& (CAnimation5000::*CAnimation5000_Construct)(unsigned short, ColorRangeValues&, int) =
	SetFP(static_cast<CAnimation5000& (CAnimation5000::*)(unsigned short, ColorRangeValues&, int)>
															(&CAnimation5000::Construct),		0x843678);
LPCTSTR (CAnimation5000::*CAnimation5000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation5000::*)(short)>	(&CAnimation5000::GetWalkingSound),	0x851DCA);

CAnimation5000::CAnimation5000(unsigned short wAnimId, ColorRangeValues& colors, int nOrientation)	{
	(this->*CAnimation5000_Construct)(wAnimId, colors, nOrientation);
}
LPCTSTR CAnimation5000::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation5000_GetWalkingSound)(wTerrainCode); }

//CAnimation6400
LPCTSTR (CAnimation6400::*CAnimation6400_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation6400::*)(short)>	(&CAnimation6400::GetWalkingSound),				0x8703A8);

LPCTSTR CAnimation6400::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation6400_GetWalkingSound)(wTerrainCode); }

//CAnimation7000
LPCTSTR (CAnimation7000::*CAnimation7000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation7000::*)(short)>	(&CAnimation7000::GetWalkingSound),				0x81B0D7);

LPCTSTR CAnimation7000::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation7000_GetWalkingSound)(wTerrainCode); }

//CAnimation7300
LPCTSTR (CAnimation7300::*CAnimation7300_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation7300::*)(short)>	(&CAnimation7300::GetWalkingSound),				0x80F669);

LPCTSTR CAnimation7300::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation7300_GetWalkingSound)(wTerrainCode); }

//CAnimation8000
LPCTSTR (CAnimation8000::*CAnimation8000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation8000::*)(short)>	(&CAnimation8000::GetWalkingSound),				0x83BB22);

LPCTSTR CAnimation8000::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation8000_GetWalkingSound)(wTerrainCode); }

//CAnimation9000
LPCTSTR (CAnimation9000::*CAnimation9000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimation9000::*)(short)>	(&CAnimation9000::GetWalkingSound),				0x828F52);

LPCTSTR CAnimation9000::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimation9000_GetWalkingSound)(wTerrainCode); }

//CAnimationA000
LPCTSTR (CAnimationA000::*CAnimationA000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimationA000::*)(short)>	(&CAnimationA000::GetWalkingSound),				0x82B278);

LPCTSTR CAnimationA000::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimationA000_GetWalkingSound)(wTerrainCode); }

//CAnimationC000
LPCTSTR (CAnimationC000::*CAnimationC000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimationC000::*)(short)>	(&CAnimationC000::GetWalkingSound),				0x805F7E);

LPCTSTR CAnimationC000::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimationC000_GetWalkingSound)(wTerrainCode); }

//CAnimationE000
LPCTSTR (CAnimationE000::*CAnimationE000_GetWalkingSound)(short) =
	SetFP(static_cast<LPCTSTR (CAnimationE000::*)(short)>	(&CAnimationE000::GetWalkingSound),				0x82483B);

LPCTSTR CAnimationE000::GetWalkingSound(short wTerrainCode)	{ return (this->*CAnimationE000_GetWalkingSound)(wTerrainCode); }
