//TobExEE
#include "infgame.h"
#include "p_infgame.h"

//CWorldTimer
DefineLibMemberFunc(void, CWorldTimer, UnpauseGame, (), UnpauseGame, UnpauseGame, (), CWORLDTIMER_UNPAUSEGAME);

//CPartySelection

//CRuleTable
DefineLibNoRetFunc(CRuleTable&, CRuleTable, CRuleTable, (), Construct, Construct, (), CRULETABLE_CONSTRUCT);
DefineLibNoRetFunc(void, CRuleTable, ~CRuleTable, (), Deconstruct, Deconstruct, (), CRULETABLE_DECONSTRUCT);
DefineLibMemberFunc(void, CRuleTable, LoadTable, (ResRef& r), LoadTable, LoadTable, (r), CRULETABLE_LOADTABLE);
DefineLibMemberFunc(IECString&, CRuleTable, GetStrValue, (IECString& sColName, IECString& sRowName), GetStrValue, GetStrValue_IECString, (sColName, sRowName), CRULETABLE_GETSTRVALUE_IECSTRING);
DefineLibMemberFunc(bool, CRuleTable, FindString, (IECString& s, POSITION* ppos, BOOL bCheckHeaders), FindString, FindString, (s, ppos, bCheckHeaders), CRULETABLE_FINDSTRING);
DefineLibMemberFunc(IECString, CRuleTable, GetDefaultValue, (), GetDefaultValue, GetDefaultValue, (), CRULETABLE_GETDEFAULTVALUE);
DefineLibMemberFunc(IECString&, CRuleTable, GetStrValue, (CPoint& ptColRow), GetStrValue, GetStrValue_CPoint, (ptColRow), CRULETABLE_GETSTRVALUE_CPOINT);
DefineLibMemberFunc(IECString&, CRuleTable, GetIntValue, (CPoint& ptColRow), GetIntValue, GetIntValue, (ptColRow), CRULETABLE_GETINTVALUE);

IECString& CRuleTable::GetRowName(int nRow) {
	if (nRow < m_nRows &&
		nRow >= 0) {
		return *(m_pRowHeaderArray + nRow);
	} else {
		return m_sDefaultVal;
	}
}

IECString& CRuleTable::GetColName(int nCol) {
	if (nCol < m_nCols &&
		nCol >= 0) {
		return *(m_pColHeaderArray + nCol);
	} else {
		return m_sDefaultVal;
	}
}

//CRuleTables
DefineLibNoRetFunc(CRuleTables&, CRuleTables, CRuleTables, (), Construct, Construct, (), CRULETABLES_CONSTRUCT);
DefineLibNoRetFunc(void, CRuleTables, ~CRuleTables, (), Deconstruct, Deconstruct, (), CRULETABLES_DECONSTRUCT);

//CMoveAreasList

//CInfGame
DefineLibMemberFunc(CWorldTimer&, CInfGame, GetWorldTimer, (), GetWorldTimer, GetWorldTimer, (), CINFGAME_GETWORLDTIMER);
DefineLibMemberFunc(CScriptParser&, CInfGame, GetScriptParser, (), GetScriptParser, GetScriptParser, (), CINFGAME_GETSCRIPTPARSER);
DefineLibMemberFunc(void, CInfGame, InitGame, (int nUnused, int nUnused2), InitGame, InitGame, (nUnused, nUnused2), CINFGAME_INITGAME);
DefineLibMemberFunc(short, CInfGame, GetCharacterPortraitNum, (ENUM e), GetCharacterPortraitNum, GetCharacterPortraitNum, (e), CINFGAME_GETCHARACTERPORTRAITNUM);
DefineLibMemberFunc(CArea&, CInfGame, GetLoadedArea, (IECString sAreaName), GetLoadedArea, GetLoadedArea, (sAreaName), CINFGAME_GETLOADEDAREA);
DefineLibMemberFunc(void, CInfGame, SetLoseCutscene, (), SetLoseCutscene, SetLoseCutscene, (), CINFGAME_SETLOSECUTSCENE);
