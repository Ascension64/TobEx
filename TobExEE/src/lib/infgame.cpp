//TobExEE
#include "infgame.h"
#include "p_infgame.h"

//CWorldTimer
DefineLibMemberFunc(void, CWorldTimer, UnpauseGame, (), UnpauseGame, UnpauseGame, (), CWORLDTIMER_UNPAUSEGAME);

//CPartySelection

//CRuleTable

//CRuleTables

//CMoveAreasList

//CInfGame
DefineLibMemberFunc(CWorldTimer&, CInfGame, GetWorldTimer, (), GetWorldTimer, GetWorldTimer, (), CINFGAME_GETWORLDTIMER);
DefineLibMemberFunc(CScriptParser&, CInfGame, GetScriptParser, (), GetScriptParser, GetScriptParser, (), CINFGAME_GETSCRIPTPARSER);
