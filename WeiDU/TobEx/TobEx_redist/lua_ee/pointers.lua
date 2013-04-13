-- pointers.lua

--CInfGame
func_CInfGame_GetActiveArea = hex2dec("0x408CF0")

--CArea
func_CArea_GetCursorTarget = hex2dec("0x493340")
off_CArea_ListFront = hex2dec("0x8E0")
off_CArea_ListBack = hex2dec("0x8FC")
off_CArea_List2 = hex2dec("0x918")

--CGameSprite
off_CGameSprite_ObjectAttackedBy = hex2dec("0x48")
off_CGameSprite_ObjectCommandedBy = hex2dec("0x60")
off_CGameSprite_ObjectProtectedBy = hex2dec("0x74")
off_CGameSprite_ObjectProtectorOf = hex2dec("0x88")
off_CGameSprite_ObjectTargetedBy = hex2dec("0x9C")
off_CGameSprite_ObjectHitBy = hex2dec("0xB0")
off_CGameSprite_ObjectHelp = hex2dec("0xC4")
off_CGameSprite_ObjectTrigger = hex2dec("0xD8")
off_CGameSprite_ObjectSeenBy = hex2dec("0xEC")
off_CGameSprite_ObjectTalkedToBy = hex2dec("0x100")
off_CGameSprite_ObjectHeardBy = hex2dec("0x114")
off_CGameSprite_ObjectSummonerOf = hex2dec("0x128")
off_CGameSprite_Object1 = hex2dec("0x13C")
off_CGameSprite_Object2 = hex2dec("0x150")
off_CGameSprite_Object3 = hex2dec("0x164")
off_CGameSprite_Object4 = hex2dec("0x178")
off_CGameSprite_Object5 = hex2dec("0x18C")
off_CGameSprite_Object6 = hex2dec("0x1A0")
off_CGameSprite_Object7 = hex2dec("0x1B4")
off_CGameSprite_Object8 = hex2dec("0x1C8")
off_CGameSprite_Object9 = hex2dec("0x1DC")
off_CGameSprite_Object10 = hex2dec("0x1F0")
off_CGameSprite_Object11 = hex2dec("0x204")
off_CGameSprite_Object12 = hex2dec("0x218")
off_CGameSprite_Object13 = hex2dec("0x22C")
off_CGameSprite_ScriptOverride = hex2dec("0x240")
off_CGameSprite_Script1 = hex2dec("0x244")
off_CGameSprite_ScriptAreaSpecific = hex2dec("0x248")
off_CGameSprite_ScriptClass = hex2dec("0x24C")
off_CGameSprite_ScriptRace = hex2dec("0x250")
off_CGameSprite_ScriptGeneral = hex2dec("0x254")
off_CGameSprite_ScriptDefault = hex2dec("0x258")
off_CGameSprite_Actions = hex2dec("0x25C")
off_CGameSprite_Triggers = hex2dec("0x278")
off_CGameSprite_CurrentResponseIndex = hex2dec("0x2B8")
off_CGameSprite_CurrentScriptBlockIndex = hex2dec("0x2BA")
off_CGameSprite_CurrentScriptIndex = hex2dec("0x2BC")

off_CGameSprite_ActionTicksElapsed = hex2dec("0x2C4")
off_CGameSprite_CurrentAction = hex2dec("0x2C8")

--CCreatureObject
func_CCreatureObject_GetDerivedStats = hex2dec("0x408ED0")

--CDerivedStats
func_CDerivedStats_GetStat = hex2dec("0x448430")
off_CDerivedStats_GeneralState = hex2dec("0x0")

--vtable addresses
vtable_CChunks = "0x71e428"
vtable_CSparkle = "0x90a610"
vtable_CProjectileBAM = "0x90aa70"
vtable_CVisualEffectVidCell = "0x90cf98"
vtable_CVisualEffect = "0x90d088"
vtable_CVisualEffectCastingGlow = "0x90b5d8"
vtable_CVisualEffectSpellHit = "0x90b660"