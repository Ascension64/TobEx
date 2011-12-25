#include "UserCommon.h"

#include "utils.h"
#include "objcre.h"
#include "resref.h"

bool UserCommon_HasSpell(CCreatureObject* pCre, ResRef& refSpell, CKnownSpellList* cplKnownSpell) {
	POSITION pos = cplKnownSpell->GetHeadPosition();
	while (pos != NULL) {
		CreFileKnownSpell* pcks = (CreFileKnownSpell*)cplKnownSpell->GetNext(pos);
		if (!(pcks->name != refSpell)) return true;
	}
	return false;
}

bool UserCommon_HasKnownSpell(CCreatureObject* pCre, ResRef& refSpell, DWORD nLevel) {
	return UserCommon_HasSpell(pCre, refSpell, &pCre->m_KnownSpellsWizard[nLevel-1]);
}