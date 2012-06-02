#include "LuaDump.h"

#include "chitin.h"
#include "objare.h"
#include "objbaldur.h"
#include "objcore.h"
#include "objcont.h"
#include "objcre.h"
#include "objdoor.h"
#include "objsound.h"
#include "objspawn.h"
#include "objstatic.h"
#include "objtile.h"
#include "objtrig.h"

std::map<char*, LUA_DumpFunc, cmp_str> g_DumpFunctions;

void LUADump_Init() {
	g_DumpFunctions["notype"] = LUADump_notype;
	g_DumpFunctions["action"] = LUADump_action;
	g_DumpFunctions["object"] = LUADump_object;
	g_DumpFunctions["sprite"] = LUADump_sprite;
	g_DumpFunctions["sprite_area"] = LUADump_sprite_area;
	g_DumpFunctions["sprite_baldur"] = LUADump_sprite_baldur;
	g_DumpFunctions["sprite_castglow"] = LUADump_sprite;
	g_DumpFunctions["sprite_chunks"] = LUADump_sprite;
	g_DumpFunctions["sprite_container"] = LUADump_sprite_container;
	g_DumpFunctions["sprite_creature"] = LUADump_sprite_creature;
	g_DumpFunctions["sprite_door"] = LUADump_sprite_door;
	g_DumpFunctions["sprite_objmarker"] = LUADump_sprite;
	g_DumpFunctions["sprite_projbam"] = LUADump_sprite;
	g_DumpFunctions["sprite_projectile"] = LUADump_sprite_projectile;
	g_DumpFunctions["sprite_smoke"] = LUADump_sprite;
	g_DumpFunctions["sprite_sound"] = LUADump_sprite_sound;
	g_DumpFunctions["sprite_spawn"] = LUADump_sprite_spawn;
	g_DumpFunctions["sprite_spellhit"] = LUADump_sprite;
	g_DumpFunctions["sprite_static"] = LUADump_sprite_static;
	g_DumpFunctions["sprite_tile"] = LUADump_sprite_tile;
	g_DumpFunctions["sprite_trigger"] = LUADump_sprite_trigger;
	g_DumpFunctions["sprite_vef"] = LUADump_sprite;
	g_DumpFunctions["sprite_vvc"] = LUADump_sprite;
	g_DumpFunctions["trigger"] = LUADump_trigger;
	return;
}

IECString LUADump_notype(void* p) {
	return IECString("no info");
}

IECString LUADump_action(void* p) {
	Action* pAction = (Action*)p;
	IECString s = "error";
	CScriptParser& parser = *g_pChitin->pGame->m_pScriptParser;
	Identifiers& idAction = g_pChitin->pGame->m_pScriptParser->ACTION;

	POSITION pos = idAction.entries.GetHeadPosition();
	IdsEntry* pEntry = NULL;
	while (pos) {
		pEntry = (IdsEntry*)idAction.entries.GetNext(pos);
		if (pEntry->nOpcode == pAction->opcode) break;
	}

	if (pEntry) {
		IECString sValue = pEntry->value;
		IECString sTemp = parser.SpanAfter(sValue, '(');
		sTemp = parser.SpanBefore(sTemp, ')');
		while (!sTemp.IsEmpty()) {
			int nInt = 0;
			int nStr = 0;
			int nObj = 0;

			IECString sArg = parser.SpanBefore(sTemp, ',');
			IECString sType = parser.SpanBefore(sArg, ':');
			IECString sNameIds = parser.SpanAfter(sArg, ':');
			IECString sName = parser.SpanBefore(sNameIds, '*');
			IECString sIds = parser.SpanAfter(sNameIds, '*');

			if (!sType.CompareNoCase("S")) {
				IECString sStr;
				sStr.Format("\"%s\"", nStr == 0 ? pAction->sName1 : pAction->sName2);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sStr);
				nStr++;
			} else if (!sType.CompareNoCase("O")) {
				IECString sObj = nObj++ == 0 ? LUADump_object(&pAction->oObject) : LUADump_object(&pAction->oTarget);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sObj);
			} else if (!sType.CompareNoCase("P")) {
				IECString sPt;
				sPt.Format("[%d.%d]", pAction->pt.x, pAction->pt.y);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sPt);
			} else if (!sType.CompareNoCase("I")) {
				IECString sInt;
				int nValue = 0;
				switch (nInt) {
				case 1:
					nValue = pAction->i2;
					break;
				case 2:
					nValue = pAction->i3;
					break;
				case 0:
				default:
					nValue = pAction->i;
					break;
				}

				Identifiers ids(ResRef((LPCTSTR)sIds));
				if (ids.m_ids.bLoaded) {
					POSITION pos2 = ids.entries.GetHeadPosition();
					POSITION posTarget = pos2;
					IdsEntry* pIdsEntry = NULL;
					while (posTarget = pos2) {
						pIdsEntry = (IdsEntry*)ids.entries.GetNext(pos2);
						if (pIdsEntry->nOpcode == nValue) {
							sInt = pIdsEntry->head;
							break;
						}
					}
					if (posTarget == NULL) sInt.Format("%d", nValue);
				} else {
					sInt.Format("%d", nValue);
				}
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sInt);
				nInt++;
			}

			sTemp = parser.SpanAfter(sTemp, ',');
		}
		s.Format("%d %s", pEntry->nOpcode, (LPCTSTR)sValue);
	}

	return s;
}

IECString LUADump_object(void* p) {
	Object* pO = (Object*)p;
	IECString s;

	if (pO->eTarget != ENUM_INVALID_INDEX) {
		CGameObject* pObject;
		char nReturnVal;
		do {
			nReturnVal = g_pChitin->pGame->m_GameObjectArrayHandler.GetGameObjectShare(pO->eTarget, THREAD_ASYNCH, &pObject, INFINITE);
		} while (nReturnVal == OBJECT_SHARING || nReturnVal == OBJECT_DENYING);
		if (nReturnVal == OBJECT_SUCCESS) {
			switch (pObject->GetType()) {
			case CGAMEOBJECT_TYPE_OBJECT:
				s.Format("<GEN %X>", pObject->e);
				break;
			case CGAMEOBJECT_TYPE_SPRITE:
				s.Format("<SPRITE %X> \"%.32s\"", pObject->e, ((CGameSprite*)pObject)->szScriptName);
				break;
			case CGAMEOBJECT_TYPE_SOUND:
				s.Format("<SND %X> \"%.32s\"", pObject->e, ((CSoundObject*)pObject)->szAmbientName);
				break;
			case CGAMEOBJECT_TYPE_CONTAINER:
				s.Format("<CONT %X> \"%.32s\"", pObject->e, ((CContainerObject*)pObject)->szContainerName);
				break;
			case CGAMEOBJECT_TYPE_SPAWNING:
				s.Format("<SPAWN %X> \"%.32s\"", pObject->e, ((CSpawningObject*)pObject)->szSpawnName);
				break;
			case CGAMEOBJECT_TYPE_DOOR:
				s.Format("<DOOR %X> \"%.32s\"", pObject->e, ((CDoorObject*)pObject)->szDoorName);
				break;
			case CGAMEOBJECT_TYPE_STATIC:
				s.Format("<ANIM %X> \"%.32s\"", pObject->e, ((CStaticObject*)pObject)->szStaticName);
				break;
			case CGAMEOBJECT_TYPE_CREATURE:
			{
				IECString sName;
				if (
					!stricmp(((CCreatureObject*)pObject)->szScriptName, "None") ||
					((CCreatureObject*)pObject)->szScriptName[0] == 0
				) {
					sName.Format("%c%s", ((CCreatureObject*)pObject)->u6752, (LPCTSTR)((CCreatureObject*)pObject)->rSaveName);
					sName.Remove('*');
				} else {
					sName.Format("\"%.32s\"", ((CCreatureObject*)pObject)->szScriptName);
				}
				s.Format("<CRE %X> %s", ((CCreatureObject*)pObject)->e, (LPCTSTR)sName);
				break;
			}
			case CGAMEOBJECT_TYPE_OBJECTMARKER:
				s.Format("<MARK %X>", pObject->e);
				break;
			case CGAMEOBJECT_TYPE_TRIGGER:
				s.Format("<TRIG %X> \"%.32s\"", pObject->e, ((CTriggerObject*)pObject)->szTriggerName);
				break;
			case CGAMEOBJECT_TYPE_PROJECTILE:
				s.Format("<PROJ %X> \"%.8s\"", pObject->e, ((CProjectileArea*)pObject)->rProjectileName);
				break;
			case CGAMEOBJECT_TYPE_TILE:
				s.Format("<TILE %X> \"%.32s\"", pObject->e, ((CTiledObject*)pObject)->szTileName);
				break;
			case CGAMEOBJECT_TYPE_SMOKE:
				s.Format("<SMOKE %X>", pObject->e);
				break;
			case CGAMEOBJECT_TYPE_AREA:
				s.Format("<AREA %X> \"%.32s\"", pObject->e, ((CAreaObject*)pObject)->szScriptName);
				break;
			case CGAMEOBJECT_TYPE_BALDUR:
				s.Format("<BALDUR %X>", pObject->e);
				break;
			default:
				s.Format("<UNK %X>", pObject->e);
				break;
			}

			g_pChitin->pGame->m_GameObjectArrayHandler.FreeGameObjectShare(pO->eTarget, THREAD_ASYNCH, INFINITE);
		}
	} else if (!pO->Name.IsEmpty()) {
		s = pO->Name;
	} else {
		bool bUseIds = false;
		bool bUseTypes = true;
		for (int i = 0; i < 5; i++) {
			if (pO->oids[i]) {
				bUseIds = true;
				break;
			}
		}
		if (bUseIds) {
			bUseTypes = false;

			CScriptParser& parser = *g_pChitin->pGame->m_pScriptParser; 
			for (int i = 0; i < 5; i++) {
				if (pO->oids[i] == 0) continue;
				POSITION pos = parser.OBJECT.entries.GetHeadPosition();
				while (pos) {
					IdsEntry* pEntry = (IdsEntry*)parser.OBJECT.entries.GetNext(pos);
					if (pEntry->nOpcode == pO->oids[i]) {
						IECString sTemp = s;
						s.Format("%s(%s)", (LPCTSTR)pEntry->head, (LPCSTR)sTemp);
						break;
					}
				}
			}
		}

		if (bUseTypes &&
			!pO->IsNothing()) {
			CScriptParser& parser = *g_pChitin->pGame->m_pScriptParser; 
			ResRef files[] = {"EA", "GENERAL", "RACE", "CLASS", "SPECIFIC", "GENDER", "ALIGN"};
			unsigned char values[7];
			values[0] = pO->EnemyAlly;
			values[1] = pO->General;
			values[2] = pO->Race;
			values[3] = pO->Class;
			values[4] = pO->Specific;
			values[5] = pO->Gender;
			values[6] = pO->Alignment;
			int nNumToDump = 7;
			while (nNumToDump > 0) {
				if (values[nNumToDump - 1] != 0xFF &&
					values[nNumToDump - 1] != 0) break;
				nNumToDump--;
			}
			if (nNumToDump > 0) {
				for (int i = 0; i < nNumToDump; i++) {
					if (i == 0) s += '[';

					Identifiers ids(files[i]);
					if (ids.m_ids.bLoaded) {
						POSITION pos = ids.entries.GetHeadPosition();
						POSITION posTarget = NULL;
						while (posTarget = pos) {
							IdsEntry* pEntry = (IdsEntry*)ids.entries.GetNext(pos);
							if (pEntry->nOpcode == values[i]) {
								s += pEntry->head;
								break;
							}
						}
						if (posTarget == NULL) s += '0';
					} else {
						s += '0';
					}

					s += (i == nNumToDump - 1) ? ']' : '.';
				}
			}
		}
	}

	return s;
}

IECString LUADump_sprite(void* p) {
	CGameSprite* pObject = (CGameSprite*)p;
	IECString s = "error";
	s.Format("%X", pObject->e);
	return s;
}

IECString LUADump_sprite_area(void* p) {
	CAreaObject* pObject = (CAreaObject*)p;
	IECString s = "error";
	s.Format("%X", pObject->e);
	return s;
}

IECString LUADump_sprite_baldur(void* p) {
	CBaldurObject* pObject = (CBaldurObject*)p;
	IECString s = "error";
	s.Format("%X", pObject->e);
	return s;
}

IECString LUADump_sprite_container(void* p) {
	CContainerObject* pObject = (CContainerObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->e, pObject->szContainerName);
	return s;
}

IECString LUADump_sprite_creature(void* p) {
	CCreatureObject* pObject = (CCreatureObject*)p;
	IECString s = "error";
	IECString sName;

	if (
		!stricmp(pObject->szScriptName, "None") ||
		pObject->szScriptName[0] == 0
	) {
		sName.Format("%c%s", pObject->u6752, (LPCTSTR)pObject->rSaveName);
		sName.Remove('*');
	} else {
		sName.Format("\"%.32s\"", pObject->szScriptName);
	}

	s.Format("%X %s", pObject->e, sName);

	return s;
}

IECString LUADump_sprite_door(void* p) {
	CDoorObject* pObject = (CDoorObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->e, pObject->szDoorName);
	return s;
}

IECString LUADump_sprite_projectile(void* p) {
	CProjectileArea* pObject = (CProjectileArea*)p;
	IECString s = "error";
	s.Format("%X \"%.8s\"", pObject->e, pObject->rProjectileName);
	return s;
}

IECString LUADump_sprite_sound(void* p) {
	CSoundObject* pObject = (CSoundObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->e, pObject->szAmbientName);
	return s;
}

IECString LUADump_sprite_spawn(void* p) {
	CSpawningObject* pObject = (CSpawningObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->e, pObject->szSpawnName);
	return s;
}

IECString LUADump_sprite_static(void* p) {
	CStaticObject* pObject = (CStaticObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->e, pObject->szStaticName);
	return s;
}

IECString LUADump_sprite_tile(void* p) {
	CTiledObject* pObject = (CTiledObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->e, pObject->szTileName);
	return s;
}

IECString LUADump_sprite_trigger(void* p) {
	CTriggerObject* pObject = (CTriggerObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->e, pObject->szTriggerName);
	return s;
}

IECString LUADump_trigger(void* p) {
	Trigger* pTrigger = (Trigger*)p;
	IECString s = "error";
	CScriptParser& parser = *g_pChitin->pGame->m_pScriptParser;
	Identifiers& idTrigger = g_pChitin->pGame->m_pScriptParser->TRIGGER;

	POSITION pos = idTrigger.entries.GetHeadPosition();
	IdsEntry* pEntry = NULL;
	while (pos) {
		pEntry = (IdsEntry*)idTrigger.entries.GetNext(pos);
		if (pEntry->nOpcode == pTrigger->opcode) break;
	}

	if (pEntry) {
		IECString sValue = pEntry->value;
		IECString sTemp = parser.SpanAfter(sValue, '(');
		sTemp = parser.SpanBefore(sTemp, ')');
		while (!sTemp.IsEmpty()) {
			int nInt = 0;
			int nStr = 0;

			IECString sArg = parser.SpanBefore(sTemp, ',');
			IECString sType = parser.SpanBefore(sArg, ':');
			IECString sNameIds = parser.SpanAfter(sArg, ':');
			IECString sName = parser.SpanBefore(sNameIds, '*');
			IECString sIds = parser.SpanAfter(sNameIds, '*');

			if (!sType.CompareNoCase("S")) {
				IECString sStr;
				sStr.Format("\"%s\"", nStr == 0 ? pTrigger->sName1 : pTrigger->sName2);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sStr);
				nStr++;
			} else if (!sType.CompareNoCase("O")) {
				IECString sObj = LUADump_object(&pTrigger->o);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sObj);
			} else if (!sType.CompareNoCase("I")) {
				IECString sInt;
				int nValue = 0;
				switch (nInt) {
				case 1:
					nValue = pTrigger->i2;
					break;
				case 2:
					nValue = pTrigger->i3;
					break;
				case 0:
				default:
					nValue = pTrigger->i;
					break;
				}

				Identifiers ids(ResRef((LPCTSTR)sIds));
				if (ids.m_ids.bLoaded) {
					POSITION pos2 = ids.entries.GetHeadPosition();
					POSITION posTarget = pos2;
					IdsEntry* pIdsEntry = NULL;
					while (posTarget = pos2) {
						pIdsEntry = (IdsEntry*)ids.entries.GetNext(pos2);
						if (pIdsEntry->nOpcode == nValue) {
							sInt = pIdsEntry->head;
							break;
						}
					}
					if (posTarget == NULL) sInt.Format("%d", nValue);
				} else {
					sInt.Format("%d", nValue);
				}
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sInt);
				nInt++;
			}

			sTemp = parser.SpanAfter(sTemp, ',');
		}
		s.Format("%X %s", pEntry->nOpcode, (LPCTSTR)sValue);
	}

	return s;
}