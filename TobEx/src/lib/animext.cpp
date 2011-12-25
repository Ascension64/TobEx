#include "animext.h"

#include "utils.h"

//CAnimation1000
LPCTSTR (CAnimation1000::*CAnimation1000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation1000::*)(WORD)>	(&CAnimation1000::GetWalkingSound),				0x8379B6);

LPCTSTR CAnimation1000::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation1000_GetWalkingSound)(wTerrainCode); }

//CAnimation1200
LPCTSTR (CAnimation1200::*CAnimation1200_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation1200::*)(WORD)>	(&CAnimation1200::GetWalkingSound),				0x82FB9D);

LPCTSTR CAnimation1200::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation1200_GetWalkingSound)(wTerrainCode); }

//CAnimation1300
LPCTSTR (CAnimation1300::*CAnimation1300_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation1300::*)(WORD)>	(&CAnimation1300::GetWalkingSound),				0x875655);

LPCTSTR CAnimation1300::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation1300_GetWalkingSound)(wTerrainCode); }

//CAnimation2000
LPCTSTR (CAnimation2000::*CAnimation2000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation2000::*)(WORD)>	(&CAnimation2000::GetWalkingSound),				0x83EFBF);

LPCTSTR CAnimation2000::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation2000_GetWalkingSound)(wTerrainCode); }

//CAnimation5000
CAnimation5000& (CAnimation5000::*CAnimation5000_Construct)(WORD, ColorRangeValues&, DWORD) =
	SetFP(static_cast<CAnimation5000& (CAnimation5000::*)(WORD, ColorRangeValues&, DWORD)>	(&CAnimation5000::Construct),		0x843678);
LPCTSTR (CAnimation5000::*CAnimation5000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation5000::*)(WORD)>									(&CAnimation5000::GetWalkingSound),	0x851DCA);

CAnimation5000::CAnimation5000(WORD wAnimId, ColorRangeValues& colors, DWORD nOrientation)	{ (this->*CAnimation5000_Construct)(wAnimId, colors, nOrientation); }
LPCTSTR CAnimation5000::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation5000_GetWalkingSound)(wTerrainCode); }

//CAnimation6400
LPCTSTR (CAnimation6400::*CAnimation6400_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation6400::*)(WORD)>	(&CAnimation6400::GetWalkingSound),				0x8703A8);

LPCTSTR CAnimation6400::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation6400_GetWalkingSound)(wTerrainCode); }

//CAnimation7000
LPCTSTR (CAnimation7000::*CAnimation7000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation7000::*)(WORD)>	(&CAnimation7000::GetWalkingSound),				0x81B0D7);

LPCTSTR CAnimation7000::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation7000_GetWalkingSound)(wTerrainCode); }

//CAnimation7300
LPCTSTR (CAnimation7300::*CAnimation7300_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation7300::*)(WORD)>	(&CAnimation7300::GetWalkingSound),				0x80F669);

LPCTSTR CAnimation7300::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation7300_GetWalkingSound)(wTerrainCode); }

//CAnimation8000
LPCTSTR (CAnimation8000::*CAnimation8000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation8000::*)(WORD)>	(&CAnimation8000::GetWalkingSound),				0x83BB22);

LPCTSTR CAnimation8000::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation8000_GetWalkingSound)(wTerrainCode); }

//CAnimation9000
LPCTSTR (CAnimation9000::*CAnimation9000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimation9000::*)(WORD)>	(&CAnimation9000::GetWalkingSound),				0x828F52);

LPCTSTR CAnimation9000::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimation9000_GetWalkingSound)(wTerrainCode); }

//CAnimationA000
LPCTSTR (CAnimationA000::*CAnimationA000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimationA000::*)(WORD)>	(&CAnimationA000::GetWalkingSound),				0x82B278);

LPCTSTR CAnimationA000::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimationA000_GetWalkingSound)(wTerrainCode); }

//CAnimationC000
LPCTSTR (CAnimationC000::*CAnimationC000_GetWalkingSound)(WORD) =
	SetFP(static_cast<LPCTSTR (CAnimationC000::*)(WORD)>	(&CAnimationC000::GetWalkingSound),				0x805F7E);

LPCTSTR CAnimationC000::GetWalkingSound(WORD wTerrainCode)	{ return (this->*CAnimationC000_GetWalkingSound)(wTerrainCode); }