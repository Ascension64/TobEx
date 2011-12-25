#include "UserCommon.h"

#include "stdafx.h"
#include "objcre.h"
#include "resref.h"

bool UserCommon_HasSpell(CCreatureObject* pCre, ResRef& rSpell, CKnownSpellList* cplKnownSpell) {
	POSITION pos = cplKnownSpell->GetHeadPosition();
	while (pos != NULL) {
		CreFileKnownSpell* pcks = (CreFileKnownSpell*)cplKnownSpell->GetNext(pos);
		if (!(pcks->name != rSpell)) return true;
	}
	return false;
}

bool UserCommon_HasKnownSpell(CCreatureObject* pCre, ResRef& rSpell, int nLevel) {
	return UserCommon_HasSpell(pCre, rSpell, &pCre->m_KnownSpellsWizard[nLevel-1]);
}