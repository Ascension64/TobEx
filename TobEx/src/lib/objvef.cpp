#include "objvef.h"
#include "chitin.h"

//CVisualEffectVidCell
void (CVisualEffectVidCell::*CVisualEffectVidCell_AddToArea)(CArea&, POINT&, int, char, int) =
	SetFP(static_cast<void (CVisualEffectVidCell::*)(CArea&, POINT&, int, char, int)>	(&CVisualEffectVidCell::AddToArea),	0x64E918);

void CVisualEffectVidCell::AddToArea(CArea& area, POINT& pt, int zPos, char cVertListType, int nStartDuration)	{ return (this->*CVisualEffectVidCell_AddToArea)(area, pt, zPos, cVertListType, nStartDuration); }

//ResVvcContainer
ResVvcContainer& (ResVvcContainer::*ResVvcContainer_Construct_1)(ResRef) =
	SetFP(static_cast<ResVvcContainer& (ResVvcContainer::*)(ResRef)>		(&ResVvcContainer::Construct),	0x64C310);
CVisualEffectVidCell& (ResVvcContainer::*ResVvcContainer_Unmarshal)() =
	SetFP(static_cast<CVisualEffectVidCell& (ResVvcContainer::*)()>			(&ResVvcContainer::Unmarshal),	0x64C49B);

ResVvcContainer::ResVvcContainer(ResRef r)			{ (this->*ResVvcContainer_Construct_1)(r); }
CVisualEffectVidCell& ResVvcContainer::Unmarshal()	{ return (this->*ResVvcContainer_Unmarshal)(); }

ResVvcContainer::~ResVvcContainer() {
	if (m_pRes && m_rName.IsNotEmpty()) {
		if (m_bLoaded) {
			m_pRes->RemoveFromHandler();
			m_bLoaded = FALSE;
		}
		g_pChitin->ResHandler.Free(*m_pRes);
		m_pRes = NULL;
	}
}

//CVisualEffect
CVisualEffect& (CVisualEffect::*CVisualEffect_Construct)() =
	SetFP(static_cast<CVisualEffect& (CVisualEffect::*)()>					(&CVisualEffect::Construct),		0x65467D);
void (CVisualEffect::*CVisualEffect_AddToArea)(CArea&, POINT&, int, char) =
	SetFP(static_cast<void (CVisualEffect::*)(CArea&, POINT&, int, char)>	(&CVisualEffect::AddToArea),		0x6561F8);

void* CVisualEffect::operator new(size_t size) { return ::operator new(size, 0); }
void CVisualEffect::operator delete(void* mem) { return ::operator delete(mem, 0); } 

CVisualEffect::CVisualEffect()	{ (this->*CVisualEffect_Construct)(); }
void CVisualEffect::AddToArea(CArea& area, POINT& pt, int zPos, char cVertListType)	{ return (this->*CVisualEffect_AddToArea)(area, pt, zPos, cVertListType); }
