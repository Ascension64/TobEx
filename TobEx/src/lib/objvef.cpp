#include "objvef.h"
#include "chitin.h"

//CVisualEffectVidCell
DefineLibMemberFunc(void, CVisualEffectVidCell, AddToArea, (
	CArea& area,
	CPoint& pt,
	int zPos,
	char cVertListType,
	int nStartDuration
	), AddToArea, AddToArea, (area, pt, zPos, cVertListType, nStartDuration), 0x64E918);

//ResVvcFile
DefineLibNoRetFunc(ResVvcFile&, ResVvcFile, ResVvcFile, (ResRef r), Construct, Construct, (r), 0x64C310);
DefineLibMemberFunc(CVisualEffectVidCell&, ResVvcFile, Unmarshal, (), Unmarshal, Unmarshal, (), 0x64C49B);

ResVvcFile::~ResVvcFile() {
	if (m_pRes && m_rName.IsNotEmpty()) {
		if (m_bLoaded) {
			m_pRes->RemoveFromHandler();
			m_bLoaded = FALSE;
		}
		g_pChitin->m_ResHandler.Free(*m_pRes);
		m_pRes = NULL;
	}
}

//CVisualEffect
DefineLibNoRetFunc(CVisualEffect&, CVisualEffect, CVisualEffect, (), Construct, Construct, (), 0x65467D);
DefineLibMemberFunc(void, CVisualEffect, AddToArea, (CArea& area, CPoint& pt, int zPos, char cVertListType), AddToArea, AddToArea, (area, pt, zPos, cVertListType), 0x6561F8);
