//TobExEE
#include "objcore.h"
#include "p_objcore.h"

//CGameObject

//CGameSprite
DefineLibMemberFunc(BOOL, CGameSprite, EvaluateTrigger, (Trigger& t), EvaluateTrigger, EvaluateTrigger, (t), CGAMESPRITE_EVALUATETRIGGER);
DefineLibMemberFunc(void, CGameSprite, ClearAllActions, (BOOL bSkipFlagged), ClearAllActions, ClearAllActions, (bSkipFlagged), CGAMESPRITE_CLEARALLACTIONS);
DefineLibMemberFunc(ACTIONRESULT, CGameSprite, ExecuteAction, (), ExecuteAction, ExecuteAction, (), CGAMESPRITE_EXECUTEACTION);
DefineLibMemberFunc(Action&, CGameSprite, GetTopAction, (Action* pAction), GetTopAction, GetTopAction, (pAction), CGAMESPRITE_GETTOPACTION);
DefineLibMemberFunc(void, CGameSprite, QueueActions, (Response& r, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue), QueueActions, QueueActions, (r, bSkipIfAlreadyQueued, bClearActionQueue), CGAMESPRITE_QUEUEACTIONS);

//CGameObjectArray
DefineLibMemberFunc(char, CGameObjectArray, GetObject, (ENUM e, void* ppObject), GetObject, GetObject, (e, ppObject), CGAMEOBJECTARRAY_GETOBJECT);
