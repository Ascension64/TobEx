//TobExEE
#include "msgcore.h"
#include "p_msgcore.h"

#include "stdafx.h"
#include "objcre.h"

//CMessageHandler
DefineLibMemberFunc(short, CMessageHandler, AddMessage, (CMessage& msg, BOOL bForceAddToQueue), AddMessage, AddMessage, (msg, bForceAddToQueue), CMESSAGEHANDLER_ADDMESSAGE);

//CMessageModifyVariable
DefineLibNoRetFunc(CMessageModifyVariable&, CMessageModifyVariable, CMessageModifyVariable, (
	IECString& sVariable,
	IECString& sScope,
	int nValue,
	unsigned char cType,
	ENUM eSource,
	ENUM eTarget
	), Construct, Construct, (sVariable, sScope, nValue, cType, eSource, eTarget), CMESSAGEMODIFYVARIABLE_CONSTRUCT);
DefineLibNoRetFunc(void, CMessageModifyVariable, ~CMessageModifyVariable, (), Deconstruct, Deconstruct, (), CMESSAGEMODIFYVARIABLE_DECONSTRUCT);
