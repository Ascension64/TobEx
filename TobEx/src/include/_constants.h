//stray constants - do not include

//0xAA5980 - action indices (up to 220)

//0xAA5D13 unsigned char Object_ENEMYALLY_GOODCUTOFF (30)
//0xAA5D18 unsigned char Object_ENEMYALLY_NEUTRAL (128)
//0xAA5D1A unsigned char Object_ENEMYALLY_ (198)
//0xAA5D1D unsigned char Object_ENEMYALLY_EVILCUTOFF (200)

//0xAA5D64 - class indices (up to 160)

//0xAA5E68 - trigger indices (up to 127)

//Vertical List Types
//0xAAA9EE unsigned char CGameObject::LIST_FRONT
//0xAAA9EF unsigned char CGameObject::LIST_MIDDLE?
//0xAAA9F0 unsigned char CGameObject::LIST_BACK?

//0xAAA9E1-D CGAMEOBJECT_TYPE
//0xAAA9E7 unsigned char CGAMEOBJECT_TYPE_CREATURE

//0xAAA9EE bool PROJ_SPARKTRAIL_OFF (0)
//0xAAA9EF bool PROJ_SPARKTRAIL_ON (1)

//0xAABC34 unsigned char PixelsPerSearchMapX (16)
//0xAABC35 unsigned char PixelsPerSearchMapY (12)

//0xAACCD4 unsigned char TICKS_PER_SECOND (15)
//0xAACCD8 int ONE_DAY (108000 ticks)
//0xAACCE4 int TIME_DAY (31500 ticks)
//0xAACCEC int TIME_DAWN (27000 ticks)
//0xAACCF4 int TIME_DUSK (94500 ticks)

//0xAACD24 int[34] PRIME_NUMBER_TABLE (for checksums)

//0xAACF4E short CVISMAP_DISCOVERED (0x8000)

//0xAAD1D0 Enum ENUM_INVALID_INDEX (-1)

//0xAAD1EE short CINFGAME_POINTSPERREPUTATIONVALUE (10)

//0xAAD230 unsigned char CINFGAME_SAVEIDX_AUTOSAVE (0)
//0xAAD231 unsigned char CINFGAME_SAVEIDX_QUIKSAVE (1)
//0xAAD232 unsigned char CINFGAME_SAVEIDX_FINALSAVE (2)
//0xAAD233 unsigned char CINFGAME_SAVEIDX_AUTOSAVETOB (3)
//0xAAD234 unsigned char CINFGAME_SAVEIDX_QUIKSAVETOB (4)
//0xAAD235 unsigned char CINFGAME_SAVEIDX_FINALSAVETOB (5)
//0xAAD290 unsigned char (1)
//0xAAD291 unsigned char (2)

//0xAAF5E3 unsigned char[10] CCHARGEN_BARDSPELLS_LEVEL [0, 6, 5, 4, 4, 3, 3, 2, 1, 1]
//note: sorcerer spells per level at chargen is based on SPLSRCKN.2DA
//0xAAF5CB unsigned char[10] CCHARGEN_MAGESPELLS_LEVEL [0, 7, 6, 5, 5, 4, 4, 3, 2, 2]
//0xAAF5D7 unsigned char[10] CCHARGEN_MINSPECIALISTSPELLS_LEVEL [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]

//0xAB3BCC BOOL G_ENABLEWILDMAGE (1) - if disabled, disables wild mage, SPWI124 in spell selection, wild magic surges

//0xAB7300 unsigned char ANIMSEQ_* [0, 1, 2, 3, 4, 5, E, 6, F, 7, 8, 10, 9, A, B, C]

//0xAB9108 GLsizei height (256) - for FXSurface B8E1B0
//0xAB9108 GLsizei width (256) - for FXSurface B8E1B0

//0xAB9368 CLSID_DirectDraw
//...
//0xAB97B8 IID_IA3dMaterial

//0xAB988E VIDPAL_TRANSLUCENCY_FACTOR (128; as fraction of 255)
//0xAB9AEA VIDPAL_TYPE_RANGE (1)
//0xAB9AF4 VIDPAL_COLOR_BLACK_INDEX (1)

//0xB15016 - g_nStringBuffer (size?)
//0xB2A1EC - g_nWaterAlpha

//0xB60400 - g_nVertexPadding (0x3E4CCCCD when VertexPadding on)
//0xB60628 - g_nMaxFrameRate (10-90)

//0xB61058 - g_nDisplayFrequency
//0xB6150C - g_wWindowWidth
//0xB6150E - g_wWindowHeight
//0xB61512 - g_nMaxBrightness
//0xB64D7C - g_nTranslucentShadows

//0xB72010 - g_sEmpty (empty CString)

//0xB74B50 - g_Action
//0xB75AA0 - g_ObjectAnything
//0xB75AB8 - g_ObjectInvalidAnything
//0xB75AD0 - g_ObjectInvalid

//0xB75AE8 - g_Object

//0xB83D0C - g_pCQuickObjectList (for the quickbar for listing spells, innates, quick items, etc.)

//0xB84810 - g_windowRect5
//0xB84828 - g_windowRect (full resolution)
//0xB84C58 - g_windowRect4
//0xB84C70 - g_windowRect7
//0xB84C80 - g_windowRect2
//0xB84C90 - g_windowRect
//0xB84CA0 - CInfinity::AREA_SIZE_MIN.cx (320)
//0xB84CA4 - CInfinity::AREA_SIZE_MIN.cy (384)
//0xB84CB0 - g_windowRect3
//0xB84CC8 - CInfinity::AREA_SIZE_MAX.cx (5120)
//0xB84CCC - CInfinity::AREA_SIZE_MAX.cy (3840)
//0xB84CD8 - g_windowRect6

//0xB88B40 - g_nLogMessages

//0xB8A304 - g_nSpriteMirror

//0xB8C5B8 - int logCreated
//0xB8C5D4 - int Logging On (in baldur.ini)
//0xB8C5D8 - CString PrivateBuild
//0xB8C5E4 - ForceLocalIP
//0xB8C5E8 - CString ProductVersion
//0xB8C5EC - CString ProductName
//0xB8C570 - g_FileBaldurLog (CFile)
//0xB8C588 - g_FileBaldurErr (CFile)
//0xB8C639 - g_bStrRefOn
//0xB8C700 - g_p3DArray - [64][64][32], size: 0x20000 constructor: 0x9C9BEC

//0xB8CB04 - ? active DirectDraw 256-color palette[256]
//elements are [ALPHA.RED.GREEN.BLUE]
//Note: for alpha, 255 is opaque, 0 is transparent

//0xB8CF04 - g_n3DArrayRefs
//0xB8CF64 - g_pSoundMixer
//0xB8CF68 - g_pSoundMixer
//0xB8CF6C - g_pChDimm
//0xB8CF70 - g_pCVideo (never used)
//0xB8CF74 - g_pChitin

//0xB8E1B0 - g_pFXSurface (for 3d accelerated)






//Audio constants
//0xB6A960 - nAcmDecoders

//0xB6B088 - uTimerID
//0xB6B090 - pFuncMAlloc(size)
//0xB6B094 - pFuncReAlloc(void*, newSize)
//0xB6B098 - pFuncFree(void*)

//relate to BDA870
//0xB6B0A0 - pFuncAcmOpen
//0xB6B0A4 - pFuncAcmClose
//0xB6B0A8 - pFuncAcmRead
//0xB6B0AC - pFuncAcmWrite
//0xB6B0B0 - pFuncAcmSeek
//0xB6B0B4 - pFuncAcmTell
//0xB6B0B8 - pFuncAcmGetNumChannels

//0xB6B0C0 - pFuncSosSoundDebug
//0xB6B0C4 - g_pSoundErrors[33]
//0xB6B148 - g_szSoundErrors (up to B6B4CC)
//0xB6B4CC - nSosSongTransitionTo
//0xB6B4D0 - nSosSongNext
//0xB6B4D4 - nSosPartNext
//0xB6B4D8 - nSosCursorPosNext
//0xB6B4DC - wSosVolumeMaster
//0xB6B4E0 - pFuncSos_donothing(char* szFilePath)
//0xB6B4E4 - char szSosAcmExt

//0xB6B534 - char szSosFOpenMode[4] ('r')
//0xB6B560 - char szSosFOpenMode[4] ('r')

//0xB6B874 - pFuncSos_fopen
//0xB6B878 - pFuncSos_fclose
//0xB6B87C - pFuncSos_fread
//0xB6B880 - pFuncSos_fseek
//0xB6B884 - pFuncSos_fgets

//0xB6B888 - pFuncOnLoadAcmDebugFunc(char* szFilename)

//0xBD2490 - pOffset 10000h of below
//0xBD2494 - p20000h size
//0xBD25D0 - pSosSoundCurrent
//0xBD25D4 - dwSosBufferSize
//0xBD25D8 - bSosInit
//0xBD25DC - hResultSetCurrentPosition
//0xBD25E0 - nSamplesPerSec
//0xBD25E4 - dwSosErrorLevel
//0xBD25E8 - 1
//0xBD25EC - dwSosBits
//0xBD25F0 - nSoundsPlaying
//0xBD25F4 - dwSosVolumeMax (0-32767)
//0xBD25F8 - pSosSoundTransitionCurrent
//0xBD25FC - pSosSoundTransitionNext
//0xBD2600 - bDriverAlreadyLoaded
//0xBD2608 - nSosPartCurrent
//0xBD260C - bSosDriverLoaded
//0xBD2610 - pSosSoundPrevious
//0xBD2614 - 32767
//0xBD2618 - bMemoryNotFail
//0xBD261C - nSosSongCurrent
//0xBD2620 - nSosCursorPosTransitionTo
//0xBD2624 - dwSosSongs
//0xBD2628 - SosSound* pSosSoundCurrent
//0xBD262C - pSosSongList
//0xBD2630 - char* pSosPartCurrent
//0xBD2634 - char szSosMusicPath[256]
//0xBD2734 - char g_pACMPath[256]
//0xBD2834 - nSosSoundPaused
//0xBD2838 - dwSosAcmIdxLast
//0xBD283C - char* pSosSongPrefixCurrent
//0xBD2840 - nSosPartTransitionTo
//0xBD2844 - nBufferSizeReduction
//0xBD2848 - pFuncSosMusicDebug

//Assoc with ACM file
//0xBD2860 - FILE* pSosFile
//0xBD2864 - char SosFileBuffer[8192]

//0xBDA864
//0xBDA868
//0xBDA86C - dwSosFileFlags
//0xBDA870 - pSosAcmArray
//0xBDA874 - nSosAcm

//0xBDD804 - ppDirectSound
//0xBDD808 - pDirectSoundBuffer




//Messages
//! means implemented

//! 0xAA5BF4 CMessageAddAction
//0xAA5C68, ch
//! 0xAA5C84 CMessageSetTrigger

//! 0xAA63CC CMessageDisplayDialogue
//0xAA68A8, eh, unsigned char bEnabled, pad (CMessageCutsceneLite)
//0xAA697C, 12h, W, unsigned char, unsigned char, unsigned char, pad
//0xAA69B4, eh, unsigned char, pad
//! 0xAA69D0 CMessageCutSceneMode
//0xAA69EC, 12h, DW, unsigned char, pad
//! 0xAA6A40 CMessageApplyEffect
//0xAA6A84, 10h, CString areaName (CMessageExploreArea)
//0xAA6AB0, 10h, DW
//0xAA6ACC, 6ah, Action
//0xAA6AE8, 16h, ResRef
//0xAA6B04, 10h, DW [treated as char] (CMessageSetBaseReaction)
//0xAA6B58, 20h, Object oAttacker (CMessageSetLastAttacker)
//0xAA6CE0, 1ah, CString (scope), CString (variable), DW nValueToAdd, unsigned char, CMessageSetVariable
//0xAA6CFC, 22h, CString areaName, DW (Windowwidth / 2 + ScreenOffsetX), DW (Windowheight / 2 + ScreenOffsetY), DW x, DW y, unsigned char int, pad
//0xAA6D18, 2ah, ResRef (visualeffectname), CString (areaname), POINT, Point2, W zPos (CMessageCreateVisualEffect)
//0xAA6D6C, eh unsigned char (SEQ.IDS ref), pad (CMessageSetAnimationSequence)
//0xAA6D88, ch
//0xAA6DA4, 14h, POINT (CMessageOrientToPoint)
//0xAA6DC0 38h, Response, DW, BOOL bSkipIfAlreadyQueued, BOOL bClearActionQueue (CMessageInsertResponse)
//0xAA6DDC, ch (CMessageClearAllActions)
//0xAA6E14, eh, W
//0xAA6E4C, 12h, DW, unsigned char, unsigned char
//0xAA6E68, 1ah, ResRef sound, unsigned char channel, unsigned char, int (CMessagePlaySound) //Constructor: 0x5684E0
//0xAA6E84, 14h, DW, W, W
//0xAA6EBC, 10h, DW
//0xAA6ED8, eh, unsigned char
//0xAA6EF4, 18h, CString, POINT (CMessageMoveGlobal)
//0xAA6F10, 10h, unsigned char FadeDirection (0 = ToColor, 1 = FromColor), unsigned char (FadeAmountBlue - all negative, so FF is -1 each time), unsigned char (Green), unsigned char (Red) (CMessageScreenFade) - B61512 = targetBrightness
//0xAA6F2C, eh, bool bOn, pad (CMessageSetSpawnPtState)
//0xAA6F48, 14h, POINT pt (CMessageSpawnPtSpawn)

//0xAA7134, ch
//0xAA727C, 14h, ResRef rAreaName (CMessageRemoveAreaAirEffects)
//0xAA72D0, 10ah, CItem, W, unsigned char, pad
//0xAA7334, 18h, CString sDialog, eTarget, int (CMessageLoadDialog)
//0xAA7350, 10h, unsigned char, pad, W
//0xAA736C, 14h, DW x, DW y (CMessageForceJump)
//0xAA73DC, 16h, DW (bPrintToConsole), DW (bSaveTo62AE), unsigned char (sndtype+1), pad (CMessagePlaySoundset)
//0xAA73F8, 1Ah, DW nStatedIdx, BYTE, pad, DW (CGameDialog 5ch), DW (CGameDialog 60h) (CMessageShowDialogueState)

//0xAA99F4, 10h, dwDuration, CMessageTimeStop
/*
sndtype+1

1 initial_meeting
2 morale
3 happy
4 unhappy_annoyed
5 unhappy_serious
6 unhappy_breaking_point
7 leader
8 tired
9 bored
a battle_cry
b attack
c damage
d dying
e hurt
f area_forest
10 area_city
11 area_dungeon
12 area_day
13 area_night
14 select_common (standard; sensitive to sound settings)
15 select_common2 (insensitive)
16 selection_action (standard; sensititve to sound settings)
17 select_rare (in-party sensitive)
18 interaction
19 insult
1a compliment
1b special
1c react_to_die_general
1d react_to_die_specific
1e miscellaneous_20
1f response_to_compliment
20 response_to_insult
21 dialog_hostile
22 dialog_default
23 existance
24 select_rare2 (insensitive)
25 critical_hit
26 critical_miss
27 target_immune
28 inventory_full
29 picked_pocket
2a existance1
2b existance2
2c existance3
*/
//0xAA73F8, 1ah, DW, unsigned char, pad, DW, DW
//0xAA7420, 1ch, CString, DW, DW, DW
//0xAA743C, 14h, int nTime, Enum eTarget
//0xAA7458, eh, W

//0xAA9758, eh, unsigned char, pad (CMessageInterruptDialogue)
//0xAA9774, 24h, CMessageStatic
//! 0xAA9790, eh, CMessageCreatureOverlay
//0xAA97C4, eh, unsigned char, pad

//0xAA9970, 14h, CString, Enum source (CMessageFireSpell)

//0xAAB528, 10h, DW mode (CMessageSetRemoteGameMode)
//0xAAB544, 28h, ResRef storename, ResRef itemname, W arg6, W usage1, W usage2, W usage3, B bIdentified (CMessageAddStoreItem)
//0xAAB598, 1ah, c, 10, 14, DW, unsigned char, pad (CMessageSetTarget)
//0xAAB5B4, eh, bool bOn, pad (CMessageSetInStoreState)
//0xAAB5EC, eh, W (action opcode)
//0xAAB608, eh, unsigned char, pad
//0xAAB65C, 14h, CString, Enum source (CMessageNonControlledDialogStart)
//0xAAB694, 16h, ResRef (filename), unsigned char (filetype, 1 = vvc, 2 = bam of nameanim1), pad (CMessageRemoveVisualEffectVidCell)
//0xAAB6E8, eh, unsigned char, pad
//0xAAB704, ch
//0xAAB720, ch (CMessagePrepareDialogue)
//0xAAB758, ch
//0xAAB7C8, ch
//0xAAB81C, 10h, DW
//0xAAB838, 14h, ResRef 
//0xAAB86C, 44h, IECPtrList, IECPtrList (constructor: 0x5BE891 (pSprite, enum, enum))
//0xAAB8A4, 16h, DW, W, W, pad?, unsigned char (constructor: 0x5C353B (pSprite, enum, enum))
//0xAAB8C0, 1eh, W (projIdx), Enum, x, y, zPos, constructor: 0x5C787F (CMessageCreateProjectile)
//0xAAB8DC, 24h, W, DW* , W, DW, DW, DW, CString
//0xAAB8F8, b4h, CCreInventory, DW (constructor: 0x5D7877 (pSprite, enum, enum)) (CMessageUpdateInventory)
//! 0xAAB914 CMessageSpriteUpdate
//0xAAB930, 28h, IECPtrList, constructor: 0x5E998E
//0xAAB94C, 2ah, unsigned char bUseList0, pad, CPtrListAAB968 (CMessageStorePartyLocations)
//0xAAB9B8, eh, bool bNonPausingDialogue, pad (CMessageSetNonPausingDialogue)
//0xAAB9D4, 14h, ResRef