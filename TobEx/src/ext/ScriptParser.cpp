#include "ScriptParser.h"

#include "chitin.h"

void __stdcall ScriptParser_CreateTrigger_ParseStatementIdx(int nStatementIdx, IECString& sLine, Object& o, int& i, int& i2, int& i3, IECString& sName1) {
	if (0) IECString("ScriptParser_CreateTrigger_ParseStatementIdx");

	CScriptParser* pThis = g_pChitin->pGame->m_pScriptParser;
	
	//these should already have passed empty checks
	IECString sTriggerName = pThis->SpanBefore(sLine, '(');
	IECString sParams = pThis->SpanAfter(sLine, '(');
	IECString sTriggerDesc = pThis->GetIdsValue(pThis->TRIGGER, sTriggerName);
	IECString sTemp;
	IECString sIdsName;

	switch (nStatementIdx) {
	case 28: //(S, S, O)
		//arg1
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first name");
		} else {
			sTemp = sTemp.Right(sTemp.GetLength() - 1); //remove left '"'
			sName1 = pThis->SpanBefore(sTemp, '"'); //remove right '"'
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg2
		sTemp = pThis->SpanBefore(sParams, ','); //-> "<str>"
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing second name");
		} else {
			sTemp = sTemp.Right(sTemp.GetLength() - 1); //remove left '"'
			sTemp = pThis->SpanBefore(sTemp, '"'); //remove right '"'
			sName1 += sTemp; //concatenate
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg3
		sTemp = sParams.Left(sParams.GetLength() - 1); //remove final ')'
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first object");
		} else {
			o = pThis->ParseObject(sTemp);
		}

		break;
	case 24: //(S, O, I, I, I)
		//arg1
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first name");
		} else {
			sTemp = sTemp.Right(sTemp.GetLength() - 1); //remove left '"'
			sName1 = pThis->SpanBefore(sTemp, '"'); //remove right '"'
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg2
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing object");
		} else {
			o = pThis->ParseObject(sTemp);
		}
		
		sParams = pThis->SpanAfter(sParams, ',');

		//arg3
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(3, sTriggerDesc));
			i = pThis->GetOpcode(sTemp, sIdsName);
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg4
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing second int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(4, sTriggerDesc));
			i2 = pThis->GetOpcode(sTemp, sIdsName);
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg5
		sTemp = sParams.Left(sParams.GetLength() - 1); //remove final ')'
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing third int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(5, sTriggerDesc));
			i3 = pThis->GetOpcode(sTemp, sIdsName);
		}

		break;
	case 23: //(S, O, I, I)
		//arg1
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first name");
		} else {
			sTemp = sTemp.Right(sTemp.GetLength() - 1); //remove left '"'
			sName1 = pThis->SpanBefore(sTemp, '"'); //remove right '"'
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg2
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing object");
		} else {
			o = pThis->ParseObject(sTemp);
		}
		
		sParams = pThis->SpanAfter(sParams, ',');

		//arg3
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(3, sTriggerDesc));
			i = pThis->GetOpcode(sTemp, sIdsName);
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg4
		sTemp = sParams.Left(sParams.GetLength() - 1); //remove final ')'
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing second int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(4, sTriggerDesc));
			i2 = pThis->GetOpcode(sTemp, sIdsName);
		}

		break;
	case 21: //(S, I, I, I)
		//arg1
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first name");
		} else {
			sTemp = sTemp.Right(sTemp.GetLength() - 1); //remove left '"'
			sName1 = pThis->SpanBefore(sTemp, '"'); //remove right '"'
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg2
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(2, sTriggerDesc));
			i = pThis->GetOpcode(sTemp, sIdsName);
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg3
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing second int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(3, sTriggerDesc));
			i2 = pThis->GetOpcode(sTemp, sIdsName);
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg4
		sTemp = sParams.Left(sParams.GetLength() - 1); //remove final ')'
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing third int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(4, sTriggerDesc));
			i3 = pThis->GetOpcode(sTemp, sIdsName);
		}

		break;
	case 20: //(S, I, I)
		//arg1
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first name");
		} else {
			sTemp = sTemp.Right(sTemp.GetLength() - 1); //remove left '"'
			sName1 = pThis->SpanBefore(sTemp, '"'); //remove right '"'
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg2
		sTemp = pThis->SpanBefore(sParams, ',');
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing first int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(2, sTriggerDesc));
			i = pThis->GetOpcode(sTemp, sIdsName);
		}

		sParams = pThis->SpanAfter(sParams, ',');

		//arg3
		sTemp = sParams.Left(sParams.GetLength() - 1); //remove final ')'
		if (sTemp.IsEmpty()) {
			pThis->SetError("Missing second int");
		} else {
			sIdsName = pThis->GetArgTextIdsName(pThis->GetArgText(3, sTriggerDesc));
			i2 = pThis->GetOpcode(sTemp, sIdsName);
		}

		break;
	case 17: //(S,P,I)
	case 16: //(S,P)
	case 10: //(O,A)
	case 8: //(O,O)
	case 7: //(O,P)
	default:
		pThis->SetError("Parser Error: Unknown statement");
		break;
	}
	return;
}
