//TobExEE
#include "objcre.h"
#include "p_objcre.h"

//CProtectedSplList

//CCreatureObject
DefineLibMemberFunc(BOOL, CCreatureObject, EvaluateTrigger, (Trigger& t), EvaluateTrigger, EvaluateTrigger, (t), CCREATUREOBJECT_EVALUATETRIGGER);
DefineLibMemberFunc(ACTIONRESULT, CCreatureObject, ExecuteAction, (), ExecuteAction, ExecuteAction, (), CCREATUREOBJECT_EXECUTEACTION);

DefineLibMemberFunc(CDerivedStats&, CCreatureObject, GetDerivedStats, (), GetDerivedStats, GetDerivedStats, (), CCREATUREOBJECT_GETDERIVEDSTATS);
