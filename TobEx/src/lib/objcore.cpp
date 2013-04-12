#include "objcore.h"

//CGameObject
DefineLibMemberFunc(ENUM, CGameObject, GetEnum, (), GetEnum, GetEnum, (), 0x494D00);

//CGameSprite
DefineLibMemberFunc(BOOL, CGameSprite, EvaluateTrigger, (Trigger& t), EvaluateTrigger, EvaluateTrigger, (t), 0x47F4F2);
DefineLibMemberFunc(void, CGameSprite, ClearAllActions, (BOOL bSkipFlagged), ClearAllActions, ClearAllActions, (bSkipFlagged), 0x47838F);
DefineLibMemberFunc(ACTIONRESULT, CGameSprite, ExecuteAction, (), ExecuteAction, ExecuteAction, (), 0x47891B);
DefineLibMemberFunc(void, CGameSprite, SetCurrentAction, (Action& a), SetCurrentAction, SetCurrentAction, (a), 0x48F85F);
DefineLibMemberFunc(Action&, CGameSprite, GetTopAction, (Action* pAction), GetTopAction, GetTopAction, (pAction), 0x48CC65);
DefineLibMemberFunc(void, CGameSprite, QueueActions, (Response& r, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue), QueueActions, QueueActions, (r, bSkipIfAlreadyQueued, bClearActionQueue), 0x48DA78);

//CGameObjectArray
DefineLibMemberFunc(char, CGameObjectArray, GetShare, (ENUM e, char threadNum, void* pptr, int dwTimeout), GetShare, GetShare, (e, threadNum, pptr, dwTimeout), 0x67626B);
DefineLibMemberFunc(char, CGameObjectArray, Get, (ENUM e, char threadNum, void* pptr, int dwTimeout), Get, Get, (e, threadNum, pptr, dwTimeout), 0x6764E5);
DefineLibMemberFunc(char, CGameObjectArray, GetDeny, (ENUM e, char threadNum, void* pptr, int dwTimeout), GetDeny, GetDeny, (e, threadNum, pptr, dwTimeout), 0x676570);
DefineLibMemberFunc(char, CGameObjectArray, FreeShare, (ENUM e, char threadNum, int dwTimeout), FreeShare, FreeShare, (e, threadNum, dwTimeout), 0x676808);
DefineLibMemberFunc(char, CGameObjectArray, FreeDeny, (ENUM e, char threadNum, int dwTimeout), FreeDeny, FreeDeny, (e, threadNum, dwTimeout), 0x676A16);
