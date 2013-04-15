//TobExEE
#ifndef OBJECTCREATURE_H
#define OBJECTCREATURE_H

#include "objcre.h"

DeclareTrampMemberFunc(BOOL, CCreatureObject, EvaluateTrigger, (Trigger& t), EvaluateTrigger);
DeclareTrampMemberFunc(ACTIONRESULT, CCreatureObject, ExecuteAction, (), ExecuteAction);

class DETOUR_CCreatureObject : public CCreatureObject {
public:
	BOOL DETOUR_EvaluateTrigger(Trigger& t);
	ACTIONRESULT DETOUR_ExecuteAction();
};

#endif //OBJECTCREATURE_H