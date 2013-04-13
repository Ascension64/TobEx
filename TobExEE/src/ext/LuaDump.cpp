//TobExEE
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
	CScriptParser& parser = g_pChitin->GetInfGame().GetScriptParser();
	Identifiers& idAction = g_pChitin->GetInfGame().GetScriptParser().ACTION;

	POSITION pos = idAction.m_entries.GetHeadPosition();
	IdsEntry* pEntry = NULL;
	while (pos) {
		pEntry = (IdsEntry*)idAction.m_entries.GetNext(pos);
		if (pEntry->m_nOpcode == pAction->m_wOpcode) break;
	}

	if (pEntry) {
		IECString sValue = pEntry->m_sValue;
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
				sStr.Format("\"%s\"", nStr == 0 ? pAction->m_s1 : pAction->m_s2);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sStr);
				nStr++;
			} else if (!sType.CompareNoCase("O")) {
				IECString sObj = nObj++ == 0 ? LUADump_object(&pAction->m_oObject) : LUADump_object(&pAction->m_oTarget);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sObj);
			} else if (!sType.CompareNoCase("P")) {
				IECString sPt;
				sPt.Format("[%d.%d]", pAction->m_pt.x, pAction->m_pt.y);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sPt);
			} else if (!sType.CompareNoCase("I")) {
				IECString sInt;
				int nValue = 0;
				switch (nInt) {
				case 1:
					nValue = pAction->m_i2;
					break;
				case 2:
					nValue = pAction->m_i3;
					break;
				case 0:
				default:
					nValue = pAction->m_i;
					break;
				}

				Identifiers ids(ResRef((LPCTSTR)sIds));
				if (ids.m_ids.m_bLoaded) {
					POSITION pos2 = ids.m_entries.GetHeadPosition();
					POSITION posTarget = pos2;
					IdsEntry* pIdsEntry = NULL;
					while (posTarget = pos2) {
						pIdsEntry = (IdsEntry*)ids.m_entries.GetNext(pos2);
						if (pIdsEntry->m_nOpcode == nValue) {
							sInt = pIdsEntry->m_sHead;
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
		s.Format("%d %s", pEntry->m_nOpcode, (LPCTSTR)sValue);
	}

	return s;
}

IECString LUADump_object(void* p) {
	Object* pO = (Object*)p;
	IECString s;

	if (pO->m_eTarget != ENUM_INVALID_INDEX) {
		CGameObject* pObject;
		if (g_pChitin->GetInfGame().m_GameObjectArray.GetObject(pO->m_eTarget, &pObject) == OBJECT_SUCCESS) {
			switch (pObject->GetType()) {
			case CGAMEOBJECT_TYPE_OBJECT:
				s.Format("<GEN %X>", pObject->m_e);
				break;
			case CGAMEOBJECT_TYPE_SPRITE:
				s.Format("<SPRITE %X> \"%.32s\"", pObject->m_e, ((CGameSprite*)pObject)->m_szScriptName);
				break;
			case CGAMEOBJECT_TYPE_SOUND:
				s.Format("<SND %X> \"%.32s\"", pObject->m_e, ((CSoundObject*)pObject)->m_sndObject.m_szScriptName);
				break;
			case CGAMEOBJECT_TYPE_CONTAINER:
				s.Format("<CONT %X> \"%.32s\"", pObject->m_e, ((CContainerObject*)pObject)->m_szContainerName);
				break;
			case CGAMEOBJECT_TYPE_SPAWNING:
				s.Format("<SPAWN %X> \"%.32s\"", pObject->m_e, ((CSpawningObject*)pObject)->m_spawnObject.m_szScriptName);
				break;
			case CGAMEOBJECT_TYPE_DOOR:
				s.Format("<DOOR %X> \"%.32s\"", pObject->m_e, ((CDoorObject*)pObject)->m_szDoorName);
				break;
			case CGAMEOBJECT_TYPE_STATIC:
				s.Format("<ANIM %X> \"%.32s\"", pObject->m_e, ((CStaticObject*)pObject)->m_staticObject.m_szScriptName);
				break;
			case CGAMEOBJECT_TYPE_CREATURE:
			{
				IECString sName;
				if (
					!stricmp(((CCreatureObject*)pObject)->m_szScriptName, "None") ||
					((CCreatureObject*)pObject)->m_szScriptName[0] == 0
				) {
					sName.Format("%c%s", ((CCreatureObject*)pObject)->u3940, (LPCTSTR)((CCreatureObject*)pObject)->m_rSaveName);
					sName.Remove('*');
				} else {
					sName.Format("\"%.32s\"", ((CCreatureObject*)pObject)->m_szScriptName);
				}
				s.Format("<CRE %X> %s", ((CCreatureObject*)pObject)->m_e, (LPCTSTR)sName);
				break;
			}
			case CGAMEOBJECT_TYPE_OBJECTMARKER:
				s.Format("<MARK %X>", pObject->m_e);
				break;
			case CGAMEOBJECT_TYPE_TRIGGER:
				s.Format("<TRIG %X> \"%.32s\"", pObject->m_e, ((CTriggerObject*)pObject)->m_szTriggerName);
				break;
			case CGAMEOBJECT_TYPE_PROJECTILE:
				s.Format("<PROJ %X> \"%.8s\"", pObject->m_e, ((CProjectileArea*)pObject)->m_rProjectileName);
				break;
			case CGAMEOBJECT_TYPE_TILE:
				s.Format("<TILE %X> \"%.32s\"", pObject->m_e, ((CTiledObject*)pObject)->m_szTileName);
				break;
			case CGAMEOBJECT_TYPE_SMOKE:
				s.Format("<SMOKE %X>", pObject->m_e);
				break;
			case CGAMEOBJECT_TYPE_AREA:
				s.Format("<AREA %X> \"%.32s\"", pObject->m_e, ((CAreaObject*)pObject)->m_szScriptName);
				break;
			case CGAMEOBJECT_TYPE_BALDUR:
				s.Format("<BALDUR %X>", pObject->m_e);
				break;
			default:
				s.Format("<UNK %X>", pObject->m_e);
				break;
			}

		}
	} else if (!pO->m_sName.IsEmpty()) {
		s = pO->m_sName;
	} else {
		bool bUseIds = false;
		bool bUseTypes = true;
		for (int i = 0; i < 5; i++) {
			if (pO->m_oids[i]) {
				bUseIds = true;
				break;
			}
		}
		if (bUseIds) {
			bUseTypes = false;

			CScriptParser& parser = *g_pChitin->GetInfGame().m_pScriptParser; 
			for (int i = 0; i < 5; i++) {
				if (pO->m_oids[i] == 0) continue;
				POSITION pos = parser.OBJECT.m_entries.GetHeadPosition();
				while (pos) {
					IdsEntry* pEntry = (IdsEntry*)parser.OBJECT.m_entries.GetNext(pos);
					if (pEntry->m_nOpcode == pO->m_oids[i]) {
						IECString sTemp = s;
						s.Format("%s(%s)", (LPCTSTR)pEntry->m_sHead, (LPCSTR)sTemp);
						break;
					}
				}
			}
		}

		if (bUseTypes &&
			!pO->IsEqualIncludeEnum(*g_poNothing)) {
			CScriptParser& parser = *g_pChitin->GetInfGame().m_pScriptParser; 
			ResRef files[] = {"EA", "GENERAL", "RACE", "CLASS", "SPECIFIC", "GENDER", "ALIGN"};
			unsigned char values[7];
			values[0] = pO->m_cEnemyAlly;
			values[1] = pO->m_cGeneral;
			values[2] = pO->m_cRace;
			values[3] = pO->m_cClass;
			values[4] = pO->m_cSpecific;
			values[5] = pO->m_cGender;
			values[6] = pO->m_cAlignment;
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
					if (ids.m_ids.m_bLoaded) {
						POSITION pos = ids.m_entries.GetHeadPosition();
						POSITION posTarget = NULL;
						while (posTarget = pos) {
							IdsEntry* pEntry = (IdsEntry*)ids.m_entries.GetNext(pos);
							if (pEntry->m_nOpcode == values[i]) {
								s += pEntry->m_sHead;
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
	s.Format("%X", pObject->m_e);
	return s;
}

IECString LUADump_sprite_area(void* p) {
	CAreaObject* pObject = (CAreaObject*)p;
	IECString s = "error";
	s.Format("%X", pObject->m_e);
	return s;
}

IECString LUADump_sprite_baldur(void* p) {
	CBaldurObject* pObject = (CBaldurObject*)p;
	IECString s = "error";
	s.Format("%X", pObject->m_e);
	return s;
}

IECString LUADump_sprite_container(void* p) {
	CContainerObject* pObject = (CContainerObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->m_e, pObject->m_szContainerName);
	return s;
}

IECString LUADump_sprite_creature(void* p) {
	CCreatureObject* pObject = (CCreatureObject*)p;
	IECString s = "error";
	IECString sName;

	if (
		!stricmp(pObject->m_szScriptName, "None") ||
		pObject->m_szScriptName[0] == 0
	) {
		sName.Format("%c%s", pObject->u3940, (LPCTSTR)pObject->m_rSaveName);
		sName.Remove('*');
	} else {
		sName.Format("\"%.32s\"", pObject->m_szScriptName);
	}

	s.Format("%X %s", pObject->m_e, sName);

	return s;
}

IECString LUADump_sprite_door(void* p) {
	CDoorObject* pObject = (CDoorObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->m_e, pObject->m_szDoorName);
	return s;
}

IECString LUADump_sprite_projectile(void* p) {
	CProjectileArea* pObject = (CProjectileArea*)p;
	IECString s = "error";
	s.Format("%X \"%.8s\"", pObject->m_e, pObject->m_rProjectileName);
	return s;
}

IECString LUADump_sprite_sound(void* p) {
	CSoundObject* pObject = (CSoundObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->m_e, pObject->m_sndObject.m_szScriptName);
	return s;
}

IECString LUADump_sprite_spawn(void* p) {
	CSpawningObject* pObject = (CSpawningObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->m_e, pObject->m_spawnObject.m_szScriptName);
	return s;
}

IECString LUADump_sprite_static(void* p) {
	CStaticObject* pObject = (CStaticObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->m_e, pObject->m_staticObject.m_szScriptName);
	return s;
}

IECString LUADump_sprite_tile(void* p) {
	CTiledObject* pObject = (CTiledObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->m_e, pObject->m_szTileName);
	return s;
}

IECString LUADump_sprite_trigger(void* p) {
	CTriggerObject* pObject = (CTriggerObject*)p;
	IECString s = "error";
	s.Format("%X \"%.32s\"", pObject->m_e, pObject->m_szTriggerName);
	return s;
}

IECString LUADump_trigger(void* p) {
	Trigger* pTrigger = (Trigger*)p;
	IECString s = "error";
	CScriptParser& parser = g_pChitin->GetInfGame().GetScriptParser();
	Identifiers& idTrigger = g_pChitin->GetInfGame().GetScriptParser().TRIGGER;

	POSITION pos = idTrigger.m_entries.GetHeadPosition();
	IdsEntry* pEntry = NULL;
	while (pos) {
		pEntry = (IdsEntry*)idTrigger.m_entries.GetNext(pos);
		if (pEntry->m_nOpcode == pTrigger->m_wOpcode) break;
	}

	if (pEntry) {
		IECString sValue = pEntry->m_sValue;
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
				sStr.Format("\"%s\"", nStr == 0 ? pTrigger->m_s1 : pTrigger->m_s2);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sStr);
				nStr++;
			} else if (!sType.CompareNoCase("O")) {
				IECString sObj = LUADump_object(&pTrigger->m_o);
				sValue.Replace((LPCTSTR)sArg, (LPCTSTR)sObj);
			} else if (!sType.CompareNoCase("I")) {
				IECString sInt;
				int nValue = 0;
				switch (nInt) {
				case 1:
					nValue = pTrigger->m_i2;
					break;
				case 2:
					nValue = pTrigger->m_i3;
					break;
				case 0:
				default:
					nValue = pTrigger->m_i;
					break;
				}

				Identifiers ids(ResRef((LPCTSTR)sIds));
				if (ids.m_ids.m_bLoaded) {
					POSITION pos2 = ids.m_entries.GetHeadPosition();
					POSITION posTarget = pos2;
					IdsEntry* pIdsEntry = NULL;
					while (posTarget = pos2) {
						pIdsEntry = (IdsEntry*)ids.m_entries.GetNext(pos2);
						if (pIdsEntry->m_nOpcode == nValue) {
							sInt = pIdsEntry->m_sHead;
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
		s.Format("%X %s", pEntry->m_nOpcode, (LPCTSTR)sValue);
	}

	return s;
}